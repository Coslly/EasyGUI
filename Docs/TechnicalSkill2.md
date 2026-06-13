# Memory resource management
Optimize memory usage and performance through hash-based data structures and periodic garbage collection/resource release.
## - Problem
In EasyGUI, the vast majority of shapes are rendered using gradients. Unlike [`solid color brush`](https://learn.microsoft.com/windows/win32/direct2d/how-to-create-a-solid-color-brush), Direct2D's [`gradient brush`](https://learn.microsoft.com/windows/win32/direct2d/how-to-create-a-linear-gradient-brush) lack a simple [`.SetColor()`](https://learn.microsoft.com/windows/win32/direct2d/id2d1solidcolorbrush-setcolor) method for dynamic updates. However, frequently creating and destroying gradient brushes carries an immense performance penalty. Doing so on a per-frame basis triggers heavy resource allocation overhead, causing frame rates to plummet from 600 FPS to a sluggish 100 FPS, which severely wastes [`CPU time`](https://en.wikipedia.org/wiki/CPU_time) slices and degrades overall UI smoothness.
## - Solution
To solve this, I implemented a hash-based resource pool leveraging [`unordered_map`](https://learn.microsoft.com/cpp/standard-library/unordered-map-class?view=msvc-170). Unlike [`vector`](https://learn.microsoft.com/cpp/standard-library/vector-class?view=msvc-170), which risks out-of-bounds crashes, `unordered_map` allows us to safely query elements using C++20’s `.contains()` or `.find()` Furthermore, its `operator[]` semantics automatically perform default-insertion when a key is absent. This behavior is ideal for managing our Direct2D brush cache via unique hash IDs, enabling elegant lazy initialization and eliminating redundant asset recreation.

While [`unordered_map`](https://learn.microsoft.com/cpp/standard-library/unordered-map-class?view=msvc-170) can store an arbitrary number of brush resources, a GUI with dynamic or continuously shifting color themes will suffer from severe memory bloat. Without proper management, continuous color shifts can drive memory consumption past 300MB within 30 seconds—making the UI incredibly heavy and bloated.

To reclaim this memory, I initially considered an [`Least Recently Used`](https://en.wikipedia.org/wiki/Cache_replacement_policies) cache eviction policy to remove the oldest items. However, this approach keeps the cache constantly pinned at its maximum defined threshold, which remains resource-heavy. Ultimately, I opted for a simpler yet highly effective batch-flush strategy: once the cache hits its capacity limit, the framework completely purges all cached gradient brushes at once. This avoids keeping the memory footprint at its peak limits and results in a highly intuitive, easy-to-maintain codebase.
## - Implementation
### - bottom layer
```cpp
// Core Optimization: Hash-based Brush Cache with Batch Flush
ID2D1LinearGradientBrush* CacheGradientBrush(...)
{
    // Generate a unique hash key combining the RenderTarget pointer and color data
    uint64_t HashKey = uint64_t(Target); 
    for (const auto& Col : Color) Hash_combine(HashKey, Col.Pack());

    // If the brush is not cached, look to create a new one
    if (CacheGraBrush.find(HashKey) == CacheGraBrush.end()) 
    {
        // Memory Protection: Threshold-Triggered Batch Flush
        if (CacheGraBrush.size() > D2DMaxCache) { 
            for (auto& Pair : CacheGraBrush) if (Pair.second) Pair.second->Release(); 
            CacheGraBrush.clear(); // Instantly wipe the map to prevent unbounded memory bloat
        }

        /* Direct2D boilerplate: Create GradientStops & Collection... */

        // Create the new LinearGradientBrush and cache it using the unique HashKey
        Target->CreateLinearGradientBrush(..., &CacheGraBrush[HashKey]);
        SafeRelease(GraStopCollection);
    }

    return CacheGraBrush[HashKey]; // Direct hit! Return the cached brush instantly
}

// Rendering Layer: Zero-Allocation Dynamic Gradient Drawing
void Render_GradientRect(...)
{
    /* Color saturation adjustment... */

    // Fetch the brush from the cache (No runtime creation/destruction!)
    const auto GradBrush = CacheGradientBrush(Target, Color);

    // Reposition the brush on the fly to fit the current rectangle's dimensions
    if (Direction) { 
        GradBrush->SetStartPoint({ X, Y }); 
        GradBrush->SetEndPoint({ X, Y + Height }); // Vertical gradient
    } else { 
        GradBrush->SetStartPoint({ X, Y }); 
        GradBrush->SetEndPoint({ X + Width, Y });  // Horizontal gradient
    }

    // Perform the high-performance hardware-accelerated drawing
    Target->FillRoundedRectangle(..., GradBrush);
}
```
