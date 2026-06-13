# Block refresh delay
Introduce a throttled/debounced redraw delay for each block to improve rendering performance without compromising user experience.
## - Problem
In scenarios such as debugging or navigation menus, UIs often host dozens or even hundreds of interactive widgets. These components can become a major performance bottleneck, draining hardware resources and causing frame rate drops. This overhead not only degrades the UI's responsiveness but can also cause system-wide stuttering, affecting other running applications.

I previously considered optimization techniques like [`partial rendering`](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-1-2-presentation-improvements), but this only mitigates rendering bottlenecks. Since EasyGUI operates as a [`real-time GUI`](https://en.wikipedia.org/wiki/Immediate_mode_(computer_graphics)), it cannot rely on browser-like page-refresh mechanics. More importantly, the primary performance bottleneck lies in the logical computation of the widgets rather than the actual drawing process.
## - Solution
In EasyGUI, parent `Block` govern whether their child widgets are rendered and executed. To optimize this, I leveraged Direct2D’s persistent surface rendering alongside an internal framework Tick system to intermitently execute widget logic. Instead of updating every frame, logic computation within a Block (ex. managing 10 child controls) is throttled to a set interval, such as every 100ms, while the visual frame buffer is retained. This decoupled approach drastically boosts frame rates and slashes hardware dependency under heavy workloads.

| Widget count | Standard per-Second execution count | Optimized per-Second execution count (100ms delay) | Overhead reduction |
| --- | --- | --- | --- |
| 5 | ~900 times | ~9 times | ~99% drop |
| 10 | ~800 times | ~9 times | ~98% drop |
| 50 (Average) | ~300 times | ~9 times | ~97% drop |
| 100 (Heavy) | ~100 times | ~9 times | ~91% drop |
## - Implementation
### - bottom layer
```cpp
bool GUI_Block(...) 
{
    // Automatically allocate a unique ID for each Block
    static int64_t GlobalBlockID{}; 
    if (!Block.ID)Block.ID = (GlobalBlockID += 10000);

    // Core Optimization: Timed Throttling (Decouple Logic from Rendering)
    bool ControlDraw = Block.IsInBlock; 
    static unordered_map<int64_t, double> OldTick{};
    
    // If user is interacting (e.g., dragging a slider), refresh faster (30ms), otherwise sleep (100ms)
    if (!ControlDraw && (EasyGUI_Tick - OldTick[Block.ID] > (InputState_IsSlider ? 30 : 100))) { 
        ControlDraw = true; // Trigger logic update & redraw for this frame
        OldTick[Block.ID] = EasyGUI_Tick; 
    }

    // Handle Mouse Interaction & Mouse Wheel Scrolling
    Block.IsInBlock = !Lock && MouseJudgment(...); 
    if (InputState_IsWindShow && Block.IsInBlock) {
        Block.Start -= EasyGUI_MouseWheelDelta; // Update scroll offset
        /* Boundary clipping logic here... */
    }

    // Smooth Scrolling Animation
    const auto PaintStartPos = Animation(Block.Start, ...);

    // Direct2D Bitmaps Retention (Leveraging hardware persistence)
    Block.Target = CreateBitmapRenderTarget(..., Block.ID);
    
    ID2D1Bitmap* BlockBitmap{}; 
    Block.Target->GetBitmap(&BlockBitmap);
    
    // Draw the cached/retained bitmap from the previous state onto the main canvas
    if (BlockBitmap) { 
        EasyGUI_RenderTarget->DrawBitmap(BlockBitmap, ...); 
        SafeRelease(BlockBitmap); 
    }

    // Execute child widgets logic only when the timer ticks (ControlDraw == true)
    Block.Target->BeginDraw(); 
    if (ControlDraw)Block.Target->Clear({0, 0, 0, 0}); // Wipe container to recalculate and redraw

    /* Background borders, scrollbars, and title rendering... */

    return ControlDraw; // Returns true to tell child widgets
}
```
### - application layer
```cpp
static EasyGUI_Direct2D::EasyGUI_Block Block{};
// The block returns 'true' only when the internal timer ticks or interaction occurs
if (GUI_Variable.GUI_Block(Block, 30, 30, 300, 300, "Block"))
{
    /* Your intensive widgets go here (ex. Sliders, Buttons, Inputs) */
    /* They will only execute their logic and redraw when needed! */
}
```
