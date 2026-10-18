constexpr const char* FileDate_EasyGUI = "2026-10-18 20:00";
#pragma once
#include <Vector>
#include <String>
#include <Chrono>
#include <Thread>
#include <Unordered_map>
#include <Algorithm>
#include <Dwmapi.h>
#include <Dwrite.h>
#include <D2D1.h>
#include <Wincodec.h>
#include <Shlwapi.h>
#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "Dwrite.lib")
#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "Mfplat.lib")
#pragma comment(lib, "Mfreadwrite.lib")
#pragma execution_character_set("utf-8")
namespace EasyGUI
{
    using std::string, std::wstring, std::vector, std::unordered_map, std::to_string;
    namespace String
    {
        inline wstring stringTowstring(const string& Raw) noexcept
        {
            if (Raw.empty())return {};
            const auto StringSize = MultiByteToWideChar(CP_UTF8, 0, Raw.c_str(), -1, 0, 0); if (StringSize <= 0)return {};
            wstring Result(StringSize, L'\0'); if (!MultiByteToWideChar(CP_UTF8, 0, Raw.c_str(), -1, Result.data(), StringSize))return {}; Result.pop_back();
            return Result;
        }
        inline string wstringTostring(const wstring& Raw) noexcept
        {
            if (Raw.empty())return {};
            const auto StringSize = WideCharToMultiByte(CP_UTF8, 0, Raw.c_str(), -1, 0, 0, 0, 0); if (StringSize <= 0)return {};
            string Result(StringSize, '\0'); if (!WideCharToMultiByte(CP_UTF8, 0, Raw.c_str(), -1, Result.data(), StringSize, 0, 0))return {}; Result.pop_back();
            return Result;
        }
    }
    namespace Vector
    {
        struct Vector2
        {
            float x{}, y{};
            constexpr Vector2(float x = 0.f, float y = 0.f) noexcept : x(x), y(y) {}
            template<typename Type> constexpr Vector2(Type Other) noexcept { x = Other.x, y = Other.y; }
            template<typename Type1, typename Type2> constexpr Vector2(Type1 OtherX, Type2 OtherY) noexcept { x = OtherX, y = OtherY; }
            constexpr bool operator==(const Vector2& Other) const noexcept { return x == Other.x && y == Other.y; }
            constexpr bool operator!=(const Vector2& Other) const noexcept { return x != Other.x || y != Other.y; }
            constexpr Vector2 operator-() const noexcept { return { -x, -y }; }
            constexpr Vector2 operator+(const Vector2& Other) const noexcept { return { x + Other.x, y + Other.y }; }
            constexpr Vector2 operator-(const Vector2& Other) const noexcept { return { x - Other.x, y - Other.y }; }
            constexpr Vector2& operator+=(const Vector2& Other) noexcept { x += Other.x, y += Other.y; return *this; }
            constexpr Vector2& operator-=(const Vector2& Other) noexcept { x -= Other.x, y -= Other.y; return *this; }
            constexpr Vector2 operator*(float Other) const noexcept { return { x * Other, y * Other }; }
            constexpr Vector2 operator/(float Other) const noexcept { if (!Other)return *this; return { x / Other, y / Other }; }
            constexpr Vector2& operator*=(float Other) noexcept { x *= Other, y *= Other; return *this; }
            constexpr Vector2& operator/=(float Other) noexcept { if (!Other)return *this; x /= Other, y /= Other; return *this; }
        };
        struct Vector3
        {
            float x{}, y{}, z{};
            constexpr Vector3(float x = 0.f, float y = 0.f, float z = 0.f) noexcept : x(x), y(y), z(z) {}
            template<typename Type> constexpr Vector3(Type Other) noexcept { x = Other.x, y = Other.y, z = Other.z; }
            template<typename Type1, typename Type2, typename Type3> constexpr Vector3(Type1 OtherX, Type2 OtherY, Type3 OtherZ) noexcept { x = OtherX, y = OtherY, z = OtherZ; }
            constexpr bool operator==(const Vector3& Other) const noexcept { return x == Other.x && y == Other.y && z == Other.z; }
            constexpr bool operator!=(const Vector3& Other) const noexcept { return x != Other.x || y != Other.y || z != Other.z; }
            constexpr Vector3 operator-() const noexcept { return { -x, -y, -z }; }
            constexpr Vector3 operator+(const Vector3& Other) const noexcept { return { x + Other.x, y + Other.y, z + Other.z }; }
            constexpr Vector3 operator-(const Vector3& Other) const noexcept { return { x - Other.x, y - Other.y, z - Other.z }; }
            constexpr Vector3& operator+=(const Vector3& Other) noexcept { x += Other.x, y += Other.y, z += Other.z; return *this; }
            constexpr Vector3& operator-=(const Vector3& Other) noexcept { x -= Other.x, y -= Other.y, z -= Other.z; return *this; }
            constexpr Vector3 operator*(float Other) const noexcept { return { x * Other, y * Other, z * Other }; }
            constexpr Vector3 operator/(float Other) const noexcept { if (!Other)return *this; return { x / Other, y / Other, z / Other }; }
            constexpr Vector3& operator*=(float Other) noexcept { x *= Other, y *= Other, z *= Other; return *this; }
            constexpr Vector3& operator/=(float Other) noexcept { if (!Other)return *this; x /= Other, y /= Other, z /= Other; return *this; }
        };
        struct Vector4
        {
            float r{}, g{}, b{}, a = 255;
            constexpr Vector4(float r = 0.f, float g = 0.f, float b = 0.f, float a = 255.f) noexcept : r(r), g(g), b(b), a(a) {}
            template<typename Type> constexpr Vector4(Type Other) noexcept { r = Other.r, g = Other.g, b = Other.b, a = Other.a; }
            template<typename Type1, typename Type2, typename Type3, typename Type4> constexpr Vector4(Type1 OtherR, Type2 OtherG, Type3 OtherB, Type4 OtherA) noexcept { r = OtherR, g = OtherG, b = OtherB, a = OtherA; }
            constexpr bool operator==(const Vector4& Other) const noexcept { return r == Other.r && g == Other.g && b == Other.b && a == Other.a; }
            constexpr bool operator!=(const Vector4& Other) const noexcept { return r != Other.r || g != Other.g || b != Other.b || a != Other.a; }
            constexpr Vector4 operator+(const Vector4& Other) const noexcept { return { r + Other.r, g + Other.g, b + Other.b, a }; }
            constexpr Vector4 operator-(const Vector4& Other) const noexcept { return { r - Other.r, g - Other.g, b - Other.b, a }; }
            constexpr Vector4& operator+=(const Vector4& Other) noexcept { r += Other.r, g += Other.g, b += Other.b, a += Other.a; return *this; }
            constexpr Vector4& operator-=(const Vector4& Other) noexcept { r -= Other.r, g -= Other.g, b -= Other.b, a -= Other.a; return *this; }
            constexpr Vector4 operator*(float Other) const noexcept { return { r * Other, g * Other, b * Other, a }; }
            constexpr Vector4 operator/(float Other) const noexcept { if (!Other)return *this; return { r / Other, g / Other, b / Other, a }; }
            constexpr Vector4 operator*=(float Other) noexcept { r *= Other, g *= Other, b *= Other; return *this; }
            constexpr Vector4 operator/=(float Other) noexcept { if (!Other)return *this; r /= Other, g /= Other, b /= Other; return *this; }
            constexpr Vector4 Alpha(int Alpha) const noexcept { return { r, g, b, Alpha }; }
            constexpr Vector4 Min_Bri(int Bright) const noexcept { return { max(r, Bright),max(g, Bright),max(b, Bright),a }; }
            constexpr Vector4 Max_Bri(int Bright) const noexcept { return { min(r, Bright),min(g, Bright),min(b, Bright),a }; }
            constexpr string Hex(bool RemoveAlpha = false) const noexcept { if (RemoveAlpha)return std::format("#{:02X}{:02X}{:02X}", (int)r, (int)g, (int)b); return std::format("#{:02X}{:02X}{:02X}{:02X}", (int)r, (int)g, (int)b, (int)a); }//转换16进制字符串
            constexpr size_t Pack(float Step = 4) const noexcept { return (size_t(r / Step) << 24) | (size_t(g / Step) << 16) | (size_t(b / Step) << 8) | size_t(a / Step); }
            const D2D1::ColorF D2DColor() const noexcept { return D2D1::ColorF(r / 255.f, g / 255.f, b / 255.f, a / 255.f); }
        };
    }
    namespace Render
    {
        template<typename Type> inline void SafeRelease(Type*& Pointer) noexcept { if (Pointer) { Pointer->Release(); Pointer = nullptr; } }//安全释放指针
        template<typename Type> inline void HashCombine(size_t& Seed, const Type& Value) { std::hash<Type> Hasher{}; Seed ^= Hasher(Value) + 0x9e3779b9 + (Seed << 6) + (Seed >> 2); }//哈希混合
        namespace Resource
        {
            constexpr size_t MaxCache = 256;//最大缓存数量
            class SolidBrush//实心画笔
            {
            private:
                unordered_map<size_t, ID2D1SolidColorBrush*> Brushes{};
                void Release() noexcept { for (auto& Brush : Brushes)SafeRelease(Brush.second); Brushes.clear(); }
            public:
                ~SolidBrush() noexcept { Release(); }
                ID2D1SolidColorBrush* Configure(ID2D1RenderTarget* Target, const Vector::Vector4& Color) noexcept//配置画笔
                {
                    if (!Target)return nullptr;//目标空指针检查
                    if (Brushes.size() > MaxCache / 10)Release();//超过最大缓存数量时释放资源
                    size_t Hash{}; HashCombine(Hash, Target);//计算哈希值
                    auto [Iterator, Inserted] = Brushes.try_emplace(Hash);//尝试插入值
                    if (Inserted) { if (FAILED(Target->CreateSolidColorBrush(Color.D2DColor(), &Iterator->second))) { Brushes.erase(Hash); return nullptr; } }//插入成功时创建画笔
                    else Iterator->second->SetColor(Color.D2DColor());//插入失败时修改颜色
                    return Iterator->second;
                }
            };
            class GradientBrush//渐变画笔
            {
            private:
                ID2D1GradientStopCollection* Collection{}; unordered_map<size_t, ID2D1LinearGradientBrush*> Brushes{};
                void Release() noexcept { SafeRelease(Collection); for (auto& Brush : Brushes)SafeRelease(Brush.second); Brushes.clear(); }
            public:
                ~GradientBrush() noexcept { Release(); }
                ID2D1LinearGradientBrush* Configure(ID2D1RenderTarget* Target, const vector<Vector::Vector4>& Colors) noexcept//配置画笔
                {
                    if (!Target)return nullptr;//目标空指针检查
                    if (Brushes.size() > MaxCache)Release();//超过最大缓存数量时释放资源
                    size_t Hash{}; HashCombine(Hash, Target); for (const auto& Color : Colors) { HashCombine(Hash, Color.Pack()); }//计算哈希值
                    auto [Iterator, Inserted] = Brushes.try_emplace(Hash);//尝试插入值
                    if (Inserted) {//插入成功时
                        vector<D2D1_GRADIENT_STOP> GraStops{}; GraStops.reserve(Colors.size()); for (size_t i = 0; i < Colors.size(); ++i)GraStops.push_back({ (Colors.size() > 1) ? float(i) / (Colors.size() - 1) : 0, Colors[i].D2DColor() });//配置渐变路径
                        SafeRelease(Collection); if (FAILED(Target->CreateGradientStopCollection(GraStops.data(), UINT32(GraStops.size()), D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &Collection)))return nullptr;//创建渐变路径类型
                        if (Collection && FAILED(Target->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), D2D1::Point2F(0, 0)), Collection, &Iterator->second)))return nullptr;//创建渐变画笔
                    }
                    return Iterator->second;//插入失败时直接返回
                }
            };
            class WriteText//文字格式
            {
            private:
                IDWriteFactory* WriteFactory{};
                unordered_map<size_t, IDWriteTextFormat*> TextFormat{};
                unordered_map<size_t, IDWriteTextLayout*> TextLayout{};
                void Release_Format() noexcept { for (auto& Format : TextFormat)SafeRelease(Format.second); TextFormat.clear(); }
                void Release_Layout() noexcept { for (auto& Layout : TextLayout)SafeRelease(Layout.second); TextLayout.clear(); }
            public:
                WriteText() noexcept { DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&WriteFactory)); }
                ~WriteText() noexcept { Release_Format(); Release_Layout(); SafeRelease(WriteFactory); }
                IDWriteTextFormat* ConfigureFormat(const string& FontName, int FontSize, int FontWeight) noexcept//文字格式缓存
                {
                    if (TextFormat.size() > MaxCache / 10) { Release_Format(); Release_Layout(); }//超过最大缓存数量时释放资源
                    size_t Hash{}; HashCombine(Hash, FontName); HashCombine(Hash, FontSize); HashCombine(Hash, FontWeight);//计算哈希值
                    auto [Iterator, Inserted] = TextFormat.try_emplace(Hash);//尝试插入值
                    if (Inserted)if (FAILED(WriteFactory->CreateTextFormat(String::stringTowstring(FontName).c_str(), 0, (DWRITE_FONT_WEIGHT)FontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, FontSize, L"", &Iterator->second)))return nullptr;
                    return Iterator->second;
                }
                IDWriteTextLayout* ConfigureLayout(IDWriteTextFormat* Format, const string& Text, Vector::Vector2 PixelLimit = {}) noexcept//文字布局缓存
                {
                    if (TextLayout.size() > MaxCache)Release_Layout();//超过最大缓存数量时释放资源
                    if (!PixelLimit.x)PixelLimit.x = 9999; if (!PixelLimit.y)PixelLimit.y = 9999;//默认最大值
                    size_t Hash{}; HashCombine(Hash, Format); HashCombine(Hash, Text); HashCombine(Hash, PixelLimit.x); HashCombine(Hash, PixelLimit.y);//计算哈希值
                    auto [Iterator, Inserted] = TextLayout.try_emplace(Hash);//尝试插入值
                    if (Inserted)
                    {
                        const auto WideText = String::stringTowstring(Text);
                        if (FAILED(WriteFactory->CreateTextLayout(WideText.c_str(), (UINT32)WideText.size(), Format, PixelLimit.x, PixelLimit.y, &Iterator->second)))return nullptr;
                    }
                    return Iterator->second;
                }
            };
            class ImageBitmap
            {
            private:
                unordered_map<size_t, ID2D1Bitmap*> Bitmaps{};
                void Release() noexcept { for (auto& Map : Bitmaps)SafeRelease(Map.second); Bitmaps.clear(); }
            public:
                ~ImageBitmap() noexcept { Release(); }
                ID2D1Bitmap* Configure(ID2D1RenderTarget* Target, const void* Data, size_t DataSize) noexcept//文字格式缓存
                {
                    if (!Target)return nullptr;//目标空指针检查
                    if (Bitmaps.size() > MaxCache / 10)Release();//超过最大缓存数量时释放资源
                    const auto Hash = std::hash<const void*>{}(Data) ^ (std::hash<size_t>{}(DataSize) << 1);
                    auto [Iterator, Inserted] = Bitmaps.try_emplace(Hash);//尝试插入值
                    if (Inserted) {//插入成功时
                        IWICImagingFactory* WicFactory{}; CoCreateInstance(CLSID_WICImagingFactory, 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&WicFactory));
                        if (auto Stream = SHCreateMemStream((const BYTE*)Data, (UINT)DataSize))
                        {
                            IWICBitmapDecoder* Decoder{}; WicFactory->CreateDecoderFromStream(Stream, 0, WICDecodeMetadataCacheOnLoad, &Decoder);
                            if (Decoder)
                            {
                                IWICBitmapFrameDecode* Frame{}; Decoder->GetFrame(0, &Frame);
                                if (Frame)
                                {
                                    IWICFormatConverter* Converter{}; WicFactory->CreateFormatConverter(&Converter);
                                    if (Converter)
                                    {
                                        Converter->Initialize(Frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, 0, 0, WICBitmapPaletteTypeCustom);
                                        Target->CreateBitmapFromWicBitmap(Converter, 0, &Iterator->second);
                                        SafeRelease(Converter);
                                    }
                                    SafeRelease(Frame);
                                }
                                SafeRelease(Decoder);
                            }
                            SafeRelease(Stream);
                        }
                        SafeRelease(WicFactory);
                    }
                    return Iterator->second;//插入失败时直接返回
                }
            };
            class BitmapTarget//位图目标
            {
            public:
                ID2D1BitmapRenderTarget* Target{};
                void Release() noexcept { SafeRelease(Target); }
                ~BitmapTarget() noexcept { Release(); }
                bool Create(ID2D1RenderTarget* MainTarget, Vector::Vector2 Size) noexcept//创建位图目标
                {
                    Release();
                    if (!MainTarget)return false;
                    if (FAILED(MainTarget->CreateCompatibleRenderTarget(D2D1::SizeF(Size.x, Size.y), &Target)))return false;
                    return true;
                }
            };
            class WindowTarget//绘制目标
            {
            public:
                ID2D1Factory* Factory{}; ID2D1HwndRenderTarget* Target{}; ID2D1Bitmap* Bitmap{};
                void Release() noexcept { SafeRelease(Factory); SafeRelease(Target); Render::SafeRelease(Bitmap); }
                ~WindowTarget() noexcept { Release(); }
                bool Create(HWND Handle, Vector::Vector2 Size) noexcept//创建渲染目标
                {
                    Release();
                    if (!Handle)return false;
                    if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &Factory)))return false;
                    if (FAILED(Factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_HARDWARE, D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)),
                        D2D1::HwndRenderTargetProperties(Handle, D2D1::SizeU(Size.x, Size.y), D2D1_PRESENT_OPTIONS_IMMEDIATELY), &Target)))return false;
                    return true;
                }
                void BeginDraw(Vector::Vector4 ClearColor = { 0,0,0,0 }) noexcept { if (!Target)return; Target->BeginDraw(); Target->Clear(ClearColor.D2DColor()); }//开始绘制
                void EndDraw() noexcept { if (Target)Target->EndDraw(); }//结束绘制
                void Clear(Vector::Vector4 ClearColor = { 0,0,0,0 }) noexcept { if (Target)Target->Clear(ClearColor.D2DColor()); }//清除画板
                void Resize(Vector::Vector2 Size) noexcept { if (!Target)return; Target->EndDraw(); Target->Resize(D2D1::SizeU(Size.x, Size.y)); }//修改大小
                void DrawBitmap(ID2D1BitmapRenderTarget* BitmapTarget, D2D1_RECT_F Destination, D2D1_RECT_F Source) noexcept//绘制位图
                {
                    if (!Target || !BitmapTarget)return; BitmapTarget->GetBitmap(&Bitmap);//获取位图
                    if (Bitmap)Target->DrawBitmap(Bitmap, Destination, 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, Source);//绘制位图
                }
            };
        }
    }
    wstring EasyGUI_InputBuffer = L"";//接收字符的缓冲区
    LPWSTR EasyGUI_MouseIcon = IDC_ARROW;//鼠标图标 (修改鼠标图标时更改该变量即可)
    POINT EasyGUI_MousePosDelta{}; short EasyGUI_MouseWheelDelta{};//鼠标增量
    static LRESULT CALLBACK EasyGUI_WindowProcess(HWND Handle, UINT Message, WPARAM wParam, LPARAM lParam) noexcept//窗口消息循环
    {
        static RAWINPUTDEVICE RawInputDevice{ .usUsagePage = 0x01,.usUsage = 0x02,.dwFlags = RIDEV_INPUTSINK,.hwndTarget = Handle };//输入设备参数
        if (RawInputDevice.hwndTarget) { RegisterRawInputDevices(&RawInputDevice, 1, sizeof(RawInputDevice)); RawInputDevice.hwndTarget = 0; }//配置输入设备
        if (Message == WM_CLOSE)exit(0);//关闭窗口时关闭全部线程
        else if (Message == WM_CHAR)EasyGUI_InputBuffer.push_back(wParam);//输入字符串事件
        else if (Message == WM_INPUT) {//鼠标输入事件
            static BYTE Data[sizeof(RAWINPUT)]; UINT Size = sizeof(RAWINPUT);
            GetRawInputData((HRAWINPUT)lParam, RID_INPUT, Data, &Size, sizeof(RAWINPUTHEADER));
            const auto Raw = (RAWINPUT*)Data; if (Raw->header.dwType == RIM_TYPEMOUSE)EasyGUI_MousePosDelta.x += Raw->data.mouse.lLastX, EasyGUI_MousePosDelta.y += Raw->data.mouse.lLastY;
        }
        else if (Message == WM_MOUSEWHEEL)EasyGUI_MouseWheelDelta += GET_WHEEL_DELTA_WPARAM(wParam) / 3;//鼠标滚轮事件
        else if (Message == WM_SETCURSOR) { SetCursor(LoadCursor(0, EasyGUI_MouseIcon)); EasyGUI_MouseIcon = IDC_ARROW; }//鼠标图标事件
        return DefWindowProcW(Handle, Message, wParam, lParam);//定义回调函数的返回值
    }
    struct EasyGUI_Block { string Title{}; Vector::Vector2 Pos{}, Size{}, Offset{}; int64_t ID{}, Line{}, Start{}, RefreshDelay = 200; bool IsInBlock{}, IsInScrollArea{}; Render::Resource::BitmapTarget Bitmap{}; int64_t Hash() { return ID + Line + (Offset.x + Offset.y) * 10000; } };//控件块结构体
    class EasyGUI
    {
    private:
        //-------------------------------------------------------------------------------------------------
        HWND EasyGUI_WindowHWND{}, EasyGUI_ControlWindowHWND{};//窗口句柄
        Render::Resource::WindowTarget EasyGUI_RenderTarget{}, EasyGUI_ControlRenderTarget{};//窗口绘制目标
        Render::Resource::SolidBrush CacheSolidBrush{};//实心画笔资源
        Render::Resource::GradientBrush CacheGradientBrush{};//渐变画笔资源
        Render::Resource::WriteText CacheWriteText{};//文字格式资源
        Render::Resource::ImageBitmap CacheImage{};//图片位图资源
        //-------------------------------------------------------------------------------------------------
        string EasyGUI_Font = "Verdana";//字体名称
        int EasyGUI_FontSize = 12;//字体大小
        Vector::Vector4 EasyGUI_Color = { 255,255,255 };//主题颜色
        float EasyGUI_RoundRadius = 4, EasyGUI_AnimationSmooth = 5;//圆角半径,动画速度
        //-------------------------------------------------------------------------------------------------
        POINT EasyGUI_MousePos{}; RECT EasyGUI_WindowRect{}, EasyGUI_ControlWindowRect{};//鼠标坐标,窗口坐标
        bool InputState_InBlock{}, InputState_IsSlider{}, InputState_InControl{};//防止控件函数冲突
        double EasyGUI_Tick{}, EasyGUI_DrawFrame{}, EasyGUI_DrawFPS{}, EasyGUI_MaxFPS = 100;//绘制帧数
        //-------------------------------------------------------------------------------------------------
        bool KeyEvent(int KeyCode, bool Release = false) noexcept//检测按键是否被按下
        {
            if (Release && InputState_IsSlider)return false;//修复冲突
            const bool Key_State = GetAsyncKeyState(KeyCode) & 0x8000;
            if (Release && Key_State)keybd_event(KeyCode, 0, KEYEVENTF_KEYUP, 0);//释放按键
            return Key_State;
        }
        bool MouseJudgment(HWND Handle, int X = 0, int Y = 0, int Width = MAXINT, int Height = MAXINT) noexcept//检测鼠标坐标是否在窗口矩形坐标内
        {
            if (InputState_InControl && Handle != EasyGUI_ControlWindowHWND)return false;//修复冲突
            if (WindowFromPoint(EasyGUI_MousePos) != Handle)return false;//当光标不指向窗口时
            RECT WindowRect{}; GetWindowRect(Handle, &WindowRect);//获取窗口坐标
            return EasyGUI_MousePos.x - WindowRect.left >= X && EasyGUI_MousePos.x - WindowRect.left <= X + Width && EasyGUI_MousePos.y - WindowRect.top >= Y && EasyGUI_MousePos.y - WindowRect.top <= Y + Height;
        }
        void MoveControlWindow(int X, int Y, int Width, int Height) noexcept//移动控件窗口位置
        {
            if (X + Width > GetSystemMetrics(SM_CXSCREEN))X = GetSystemMetrics(SM_CXSCREEN) - Width;
            if (Y + Height > GetSystemMetrics(SM_CYSCREEN))Y = GetSystemMetrics(SM_CYSCREEN) - Height;
            MoveWindow(EasyGUI_ControlWindowHWND, X, Y, Width, Height, true);
            EasyGUI_ControlRenderTarget.Resize({ Width, Height });
            ShowWindow(EasyGUI_ControlWindowHWND, SW_SHOW); SetForegroundWindow(EasyGUI_ControlWindowHWND);
        }
        template<typename Identifier> float Animation(float Value, float Speed, int64_t Key = 0) noexcept//平滑动画效果
        {
            thread_local unordered_map<int64_t, float> CacheValue{};
            thread_local unordered_map<int64_t, double> OldTick{};
            if (!CacheValue.count(Key)) { CacheValue[Key] = Value; OldTick[Key] = EasyGUI_Tick; }
            if (Speed <= 0.f) { CacheValue[Key] = Value; OldTick[Key] = EasyGUI_Tick; return CacheValue[Key]; }
            const float dt = (EasyGUI_Tick - OldTick[Key]) * 0.001f; OldTick[Key] = EasyGUI_Tick;
            CacheValue[Key] += (Value - CacheValue[Key]) * (1.f - std::exp(-(120.f / Speed) * dt));
            return CacheValue[Key];
        }
        //-------------------------------------------------------------------------------------------------
    public:
        //------------------------------------------------------------------------------------------------------------------------------
        EasyGUI(const string& Title, Vector::Vector2 Position, Vector::Vector2 Size, bool TopMost = false) noexcept//初始化EasyGUI
        {
            const auto WideTitle = String::stringTowstring(Title);
            WNDCLASSW WindowClass{}; WindowClass.lpfnWndProc = EasyGUI_WindowProcess; WindowClass.lpszClassName = WideTitle.c_str(); RegisterClassW(&WindowClass);//窗口注册类
            EasyGUI_WindowHWND = CreateWindowExW((TopMost ? WS_EX_TOPMOST : 0) | WS_EX_LAYERED, WideTitle.c_str(), WideTitle.c_str(), WS_POPUP, Position.x, Position.y, Size.x, Size.y, 0, 0, 0, 0);
            EasyGUI_ControlWindowHWND = CreateWindowExW((TopMost ? WS_EX_TOPMOST : 0) | WS_EX_LAYERED, WideTitle.c_str(), WideTitle.c_str(), WS_POPUP, 0, 0, 0, 0, EasyGUI_WindowHWND, 0, 0, 0);
            //---------------------------------------------------------------------------------------------------
            SetLayeredWindowAttributes(EasyGUI_WindowHWND, 0, 255, LWA_ALPHA); SetLayeredWindowAttributes(EasyGUI_ControlWindowHWND, 0, 255, LWA_ALPHA);//设置窗口透明度
            MARGINS Margin{ -1 }; DwmExtendFrameIntoClientArea(EasyGUI_WindowHWND, &Margin); DwmExtendFrameIntoClientArea(EasyGUI_ControlWindowHWND, &Margin);//设置窗口模糊化
            ShowWindow(EasyGUI_WindowHWND, SW_SHOW); SetForegroundWindow(EasyGUI_WindowHWND); UpdateWindow(EasyGUI_WindowHWND);//显示窗口
            //---------------------------------------------------------------------------------------------------Direct2D初始化
            EasyGUI_RenderTarget.Create(EasyGUI_WindowHWND, Size);
            EasyGUI_ControlRenderTarget.Create(EasyGUI_ControlWindowHWND, Size);
        }
        ~EasyGUI() noexcept//释放全部资源
        {
            if (EasyGUI_WindowHWND) { DestroyWindow(EasyGUI_WindowHWND); EasyGUI_WindowHWND = nullptr; }
            if (EasyGUI_ControlWindowHWND) { DestroyWindow(EasyGUI_ControlWindowHWND); EasyGUI_ControlWindowHWND = nullptr; }
        }
        void Draw(bool State = false) noexcept//绘制全部内容 0:开始绘制 1:结束绘制
        {
            if (!State)
            {
                GetCursorPos(&EasyGUI_MousePos); GetWindowRect(EasyGUI_WindowHWND, &EasyGUI_WindowRect); GetWindowRect(EasyGUI_ControlWindowHWND, &EasyGUI_ControlWindowRect);//刷新鼠标,窗口坐标
                EasyGUI_RenderTarget.Resize({ EasyGUI_WindowRect.right - EasyGUI_WindowRect.left, EasyGUI_WindowRect.bottom - EasyGUI_WindowRect.top });//刷新画布大小
                EasyGUI_RenderTarget.BeginDraw(); EasyGUI_ControlRenderTarget.BeginDraw();//开始绘制
            }
            else {
                EasyGUI_RenderTarget.EndDraw(); EasyGUI_ControlRenderTarget.EndDraw();//结束绘制
                if (InputState_InControl) { if (!MouseJudgment(EasyGUI_ControlWindowHWND) && (KeyEvent(VK_LBUTTON, true) || KeyEvent(VK_RBUTTON, true)))InputState_InControl = false; }
                else ShowWindow(EasyGUI_ControlWindowHWND, SW_HIDE);//隐藏控件窗口
                EasyGUI_MousePosDelta = {}; EasyGUI_MouseWheelDelta = {};//重置鼠标增量
                if (EasyGUI_MaxFPS > 0)//锁定帧数 降低硬件占用
                {
                    const float TargetFrameTime = 1000.f / EasyGUI_MaxFPS;
                    timeBeginPeriod(1);
                    while (true)
                    {
                        const auto WorkTime = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now().time_since_epoch()).count() - EasyGUI_DrawFrame;
                        if (WorkTime >= TargetFrameTime)break;
                        const auto RemainingTime = TargetFrameTime - WorkTime;
                        if (RemainingTime >= 1)Sleep(RemainingTime); else std::this_thread::yield();
                    }
                    timeEndPeriod(1);
                }
                EasyGUI_Tick = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now().time_since_epoch()).count();//获取当前滴答值
                EasyGUI_DrawFPS = 1000.f / max(EasyGUI_Tick - EasyGUI_DrawFrame, 1), EasyGUI_DrawFrame = EasyGUI_Tick;//计算绘制帧数
                MSG Message{}; while (PeekMessage(&Message, 0, 0, 0, 1)) { TranslateMessage(&Message); DispatchMessage(&Message); }//窗口消息循环
                if (MouseJudgment(EasyGUI_WindowHWND) && !InputState_InBlock && !InputState_IsSlider && !InputState_InControl && KeyEvent(VK_LBUTTON))SendMessage(EasyGUI_WindowHWND, WM_NCLBUTTONDOWN, HTCAPTION, 0); InputState_InBlock = false;//拖动窗口
            }
        }
        //------------------------------------------------------------------------------------------------------------------------------
        void Render_SolidRect(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, Vector::Vector4 Color, float Radius = -1) noexcept//绘制实心矩形
        {
            if (const auto Brush = CacheSolidBrush.Configure(Target, Color))
            {
                if (Radius == -1)Radius = EasyGUI_RoundRadius;
                Target->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(X, Y, X + Width, Y + Height), Radius, Radius), Brush);
            }
        }
        void Render_HollowRect(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, Vector::Vector4 Color, float Thickness = 1, float Radius = -1) noexcept//绘制空心矩形
        {
            if (const auto Brush = CacheSolidBrush.Configure(Target, Color))
            {
                if (Radius == -1)Radius = EasyGUI_RoundRadius;
                Target->DrawRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(X, Y, X + Width, Y + Height), Radius, Radius), Brush, Thickness);
            }
        }
        void Render_GradientRect(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, const vector<Vector::Vector4>& Colors, bool Direction, float Radius = -1) noexcept//绘制实心渐变矩形
        {
            if (const auto Brush = CacheGradientBrush.Configure(Target, Colors))
            {
                Brush->SetStartPoint(D2D1::Point2F(X, Y)); if (Direction)Brush->SetEndPoint(D2D1::Point2F(X, Y + Height)); else Brush->SetEndPoint(D2D1::Point2F(X + Width, Y));
                if (Radius == -1)Radius = EasyGUI_RoundRadius;
                Target->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(X, Y, X + Width, Y + Height), Radius, Radius), Brush);
            }
        }
        void Render_Line(ID2D1RenderTarget* Target, float StartX, float StartY, float EndX, float EndY, Vector::Vector4 Color, float Thickness = 1) noexcept//绘制线条
        {
            if (Thickness <= 0.f)return;
            if (const auto Brush = CacheSolidBrush.Configure(Target, Color))Target->DrawLine(D2D1::Point2F(StartX, StartY), D2D1::Point2F(EndX, EndY), Brush, Thickness);
        }
        void Render_Circle(ID2D1RenderTarget* Target, float X, float Y, float Size, Vector::Vector4 Color) noexcept//绘制实心圆
        {
            if (Size <= 0.f)return;
            if (const auto Brush = CacheSolidBrush.Configure(Target, Color))Target->FillEllipse(D2D1::Ellipse(D2D1::Point2F(X, Y), Size / 2, Size / 2), Brush);
        }
        Vector::Vector2 Render_String(ID2D1RenderTarget* Target, int X, int Y, string String, Vector::Vector4 Color, const string& FontName, int FontSize, int FontWeight = 400, Vector::Vector2 PixelLimit = {}) noexcept//绘制文字
        {
            if (String.empty() || FontSize <= 0 || FontWeight <= 0)return {};
            if (String.find('<') != string::npos)//当转义符号存在
            {
                size_t FinedPos = 0;
                if ((FinedPos = String.find("<COLOR>")) != string::npos) { String.erase(FinedPos, 7); Color = EasyGUI_Color.Alpha(Color.a); }
                if ((FinedPos = String.find("<%")) != string::npos)
                {
                    const auto EndPos = String.find('>', FinedPos + 2);
                    if (EndPos != string::npos && EndPos > FinedPos + 2)
                    {
                        FontWeight = std::stoi(String.substr(FinedPos + 2, EndPos - (FinedPos + 2)));
                        String.erase(FinedPos, EndPos - FinedPos + 1);
                    }
                }
                if ((FinedPos = String.find("<#")) != string::npos)
                {
                    if (FinedPos + 8 < String.size() && String[FinedPos + 8] == '>')
                    {
                        const auto Hex = [](char c) { return c <= '9' ? c - '0' : ((c & ~0x20) - 'A' + 10); };
                        Color.r = (Hex(String[FinedPos + 2]) << 4) | Hex(String[FinedPos + 3]);
                        Color.g = (Hex(String[FinedPos + 4]) << 4) | Hex(String[FinedPos + 5]);
                        Color.b = (Hex(String[FinedPos + 6]) << 4) | Hex(String[FinedPos + 7]);
                        String.erase(FinedPos, 9);
                    }
                }
            }
            const auto TextFormat = CacheWriteText.ConfigureFormat(FontName, FontSize, FontWeight);//预先缓存文字格式
            TextFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);//防止自动换行
            const auto TextLayout = CacheWriteText.ConfigureLayout(TextFormat, String, PixelLimit);//预先缓存文字布局
            DWRITE_TEXT_METRICS Metrics{}; TextLayout->GetMetrics(&Metrics);//获取文字布局像素大小
            if (X || Y)
            {
                if (X > 10000)X -= 10000 + Metrics.width / 2.f; if (Y > 10000)Y -= 10000 + Metrics.height / 2.f;//文字居中
                if (const auto Brush = CacheSolidBrush.Configure(Target, Vector::Vector4{ 0,0,0,Color.a }))
                    Target->DrawTextLayout(D2D1::Point2F(X + 1, Y + 1), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                if (const auto Brush = CacheSolidBrush.Configure(Target, Color))
                    Target->DrawTextLayout(D2D1::Point2F(X, Y), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
            }
            return { Metrics.width,Metrics.height };
        }
        Vector::Vector2 Render_MiniString(ID2D1RenderTarget* Target, int X, int Y, string String, Vector::Vector4 Color, int FontSize, const string& FontName = "Verdana", int FontWeight = 600, Vector::Vector2 PixelLimit = {}) noexcept//绘制简单文字
        {
            if (String.empty() || FontSize <= 0 || FontWeight <= 0)return {};
            if (String.find('<') != string::npos)//当转义符号存在
            {
                size_t FinedPos = 0;
                if ((FinedPos = String.find("<COLOR>")) != string::npos) { String.erase(FinedPos, 7); Color = EasyGUI_Color.Alpha(Color.a); }
                if ((FinedPos = String.find("<%")) != string::npos)
                {
                    const auto EndPos = String.find('>', FinedPos + 2);
                    if (EndPos != string::npos && EndPos > FinedPos + 2)
                    {
                        FontWeight = std::stoi(String.substr(FinedPos + 2, EndPos - (FinedPos + 2)));
                        String.erase(FinedPos, EndPos - FinedPos + 1);
                    }
                }
                if ((FinedPos = String.find("<#")) != string::npos)
                {
                    if (FinedPos + 8 < String.size() && String[FinedPos + 8] == '>')
                    {
                        const auto Hex = [](char c) { return c <= '9' ? c - '0' : ((c & ~0x20) - 'A' + 10); };
                        Color.r = (Hex(String[FinedPos + 2]) << 4) | Hex(String[FinedPos + 3]);
                        Color.g = (Hex(String[FinedPos + 4]) << 4) | Hex(String[FinedPos + 5]);
                        Color.b = (Hex(String[FinedPos + 6]) << 4) | Hex(String[FinedPos + 7]);
                        String.erase(FinedPos, 9);
                    }
                }
            }
            const auto TextFormat = CacheWriteText.ConfigureFormat(FontName, FontSize, FontWeight);//预先缓存文字格式
            TextFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_WRAP);//防止自动换行
            const auto TextLayout = CacheWriteText.ConfigureLayout(TextFormat, String, PixelLimit);//预先缓存文字布局
            DWRITE_TEXT_METRICS Metrics{}; TextLayout->GetMetrics(&Metrics);//获取文字布局像素大小
            if (X || Y)
            {
                if (X > 10000)X -= 10000 + Metrics.width / 2.f; if (Y > 10000)Y -= 10000 + Metrics.height / 2.f;//文字居中
                if (const auto Brush = CacheSolidBrush.Configure(Target, Vector::Vector4{ 0,0,0,Color.a }))
                {
                    Target->DrawTextLayout(D2D1::Point2F(X + 1, Y + 1), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                    Target->DrawTextLayout(D2D1::Point2F(X - 1, Y - 1), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                    Target->DrawTextLayout(D2D1::Point2F(X + 1, Y - 1), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                    Target->DrawTextLayout(D2D1::Point2F(X - 1, Y + 1), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                }
                if (const auto Brush = CacheSolidBrush.Configure(Target, Color))
                    Target->DrawTextLayout(D2D1::Point2F(X, Y), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
            }
            return { Metrics.width,Metrics.height };
        }
        void Render_Icon(ID2D1RenderTarget* Target, int X, int Y, long IconID, Vector::Vector4 Color, const string& FontName, int FontSize = 20, int FontWeight = 400) noexcept//绘制字体图标
        {
            if (FontSize <= 0 || FontWeight <= 0)return;
            wstring IconIDStr = L""; IconIDStr.push_back(0xE000 + IconID);
            const auto TextFormat = CacheWriteText.ConfigureFormat(FontName, FontSize, FontWeight);
            const auto TextLayout = CacheWriteText.ConfigureLayout(TextFormat, String::wstringTostring(IconIDStr));
            DWRITE_TEXT_METRICS Metrics{}; TextLayout->GetMetrics(&Metrics); X -= Metrics.width / 2; Y -= Metrics.height / 2;
            if (const auto Brush = CacheSolidBrush.Configure(Target, Vector::Vector4{ 0,0,0,Color.a }))
                Target->DrawTextLayout(D2D1::Point2F(X + 1, Y + 1), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_NONE);
            if (const auto Brush = CacheSolidBrush.Configure(Target, Color))
                Target->DrawTextLayout(D2D1::Point2F(X, Y), TextLayout, Brush, D2D1_DRAW_TEXT_OPTIONS_NONE);
        }
        void Render_Image(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, const void* Data, size_t DataSize, float Alpha = 255) noexcept//绘制图片
        {
            if (Alpha <= 0.f)return;
            if (const auto Map = CacheImage.Configure(Target, Data, DataSize))Target->DrawBitmap(Map, D2D1::RectF(X, Y, X + Width, Y + Height), Alpha / 255);
        }
        //------------------------------------------------------------------------------------------------------------------------------
        string Style_GetFont() noexcept { return EasyGUI_Font; }//获取字体
        void Style_SetFont(const string& Name) noexcept { EasyGUI_Font = Name.empty() ? "Verdana" : Name; }//设置字体
        int Style_GetFontSize() noexcept { return EasyGUI_FontSize; }//获取字体大小
        void Style_SetFontSize(int Size) noexcept { EasyGUI_FontSize = (Size > 0) ? Size : 12; }//设置字体大小
        Vector::Vector4 Style_GetColor() noexcept { return EasyGUI_Color; }//获取主题颜色
        void Style_SetColor(Vector::Vector4 Color) noexcept { EasyGUI_Color = Color.Alpha(255); }//设置主题颜色
        float Style_GetRoundRadius() noexcept { return EasyGUI_RoundRadius; }//获取圆角半径
        void Style_SetRoundRadius(float Radius) noexcept { EasyGUI_RoundRadius = max(Radius, 0); }//设置圆角半径
        float Style_GetAnimationSmooth() noexcept { return EasyGUI_AnimationSmooth; }//获取动画速度
        void Style_SetAnimationSmooth(float Speed) noexcept { EasyGUI_AnimationSmooth = max(Speed, 0.1f); }//设置动画速度
        //------------------------------------------------------------------------------------------------------------------------------
        HWND Window_HWND() noexcept { return EasyGUI_WindowHWND; }//获取窗口句柄
        string Window_GetTitle() noexcept { wchar_t WideTitle[1024]{}; GetWindowTextW(EasyGUI_WindowHWND, WideTitle, _countof(WideTitle)); return String::wstringTostring(WideTitle); }//获取窗口标题
        void Window_SetTitle(const string& Title) noexcept { SetWindowTextW(EasyGUI_WindowHWND, String::stringTowstring(Title).c_str()); }//修改窗口标题
        Vector::Vector2 Window_GetPos() noexcept { RECT Rect{}; GetWindowRect(EasyGUI_WindowHWND, &Rect); return { Rect.left,Rect.top }; }//获取窗口坐标
        void Window_SetPos(int X, int Y) noexcept { SetWindowPos(EasyGUI_WindowHWND, 0, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE); }//修改窗口坐标
        Vector::Vector2 Window_GetSize() noexcept { RECT Rect{}; GetWindowRect(EasyGUI_WindowHWND, &Rect); return { Rect.right - Rect.left,Rect.bottom - Rect.top }; }//获取窗口大小
        void Window_SetSize(int Width, int Height) noexcept { SetWindowPos(EasyGUI_WindowHWND, 0, 0, 0, max(Width, 100), max(Height, 100), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE); }//修改窗口大小
        int Window_GetAlpha() noexcept { BYTE Alpha{}; DWORD Flags{}; GetLayeredWindowAttributes(EasyGUI_WindowHWND, 0, &Alpha, &Flags); return (Flags & LWA_ALPHA) ? Alpha : 255; }//获取窗口透明度
        void Window_SetAlpha(int Alpha) noexcept { SetLayeredWindowAttributes(EasyGUI_WindowHWND, 0, min(max(Alpha, 0), 255), LWA_ALPHA); }//修改窗口透明度
        void Window_Show() noexcept { if (GetForegroundWindow() == EasyGUI_ControlWindowHWND)return; ShowWindow(EasyGUI_WindowHWND, SW_SHOW); SetForegroundWindow(EasyGUI_WindowHWND); }//显现窗口
        void Window_Hide() noexcept { ShowWindow(EasyGUI_WindowHWND, SW_HIDE); ShowWindow(EasyGUI_ControlWindowHWND, SW_HIDE); }//隐藏窗口
        float Window_DrawFPS() noexcept { return (float)EasyGUI_DrawFPS; }//获取窗口绘制帧数
        void Window_SetMaxFPS(float FPS) noexcept { EasyGUI_MaxFPS = FPS; }//锁定窗口绘制帧数
        //------------------------------------------------------------------------------------------------------------------------------
        void GUI_BackGround() noexcept//背景
        {
            const Vector::Vector2 WindowSize = { EasyGUI_WindowRect.right - EasyGUI_WindowRect.left ,EasyGUI_WindowRect.bottom - EasyGUI_WindowRect.top }; const float RectRadius = EasyGUI_RoundRadius * 2;
            Render_SolidRect(EasyGUI_RenderTarget.Target, 0, 0, WindowSize.x, WindowSize.y, { 0,0,0 }, RectRadius);
            Render_SolidRect(EasyGUI_RenderTarget.Target, 1, 1, WindowSize.x - 2, WindowSize.y - 2, { 60,60,60 }, RectRadius);
            Render_SolidRect(EasyGUI_RenderTarget.Target, 2, 2, WindowSize.x - 4, WindowSize.y - 4, { 30,30,30 }, RectRadius);
            Render_SolidRect(EasyGUI_RenderTarget.Target, 5, 5, WindowSize.x - 10, WindowSize.y - 10, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_BackGround_ColorLine>(MouseJudgment(EasyGUI_WindowHWND) ? 1.f : 3.f, EasyGUI_AnimationSmooth), RectRadius);
            Render_GradientRect(EasyGUI_RenderTarget.Target, 7, 7, WindowSize.x - 14, WindowSize.y - 14, { { 0,0,0 }, EasyGUI_Color / 10 }, true, RectRadius);
        }
        bool GUI_Mark(const string& Mark, int X, int Y, int Width, int Height, const string& Font = "") noexcept//标识
        {
            Render_SolidRect(EasyGUI_RenderTarget.Target, X, Y, Width, Height, { 0,0,0 });
            Render_GradientRect(EasyGUI_RenderTarget.Target, X + 1, Y + 1, Width - 2, Height - 2, { EasyGUI_Color / 2.f, EasyGUI_Color / 3.f }, true);
            Render_GradientRect(EasyGUI_RenderTarget.Target, X + 2, Y + 2, Width - 4, Height - 4, { { 10,10,10 }, EasyGUI_Color / 10.f }, true);
            Render_String(EasyGUI_RenderTarget.Target, 10000 + X + Width / 2, 10000 + Y + Height / 2, Mark, EasyGUI_Color / 2.f, Font.empty() ? EasyGUI_Font : Font, EasyGUI_FontSize + 7, 800);
            Render_String(EasyGUI_RenderTarget.Target, 10000 + X + Width / 2, 10000 + Y + Height / 2 + 1, Mark, EasyGUI_Color.Min_Bri(200), Font.empty() ? EasyGUI_Font : Font, EasyGUI_FontSize + 7, 800);
            return MouseJudgment(EasyGUI_WindowHWND, X, Y, Width, Height);
        }
        template<typename Type> void GUI_RadioBlock(const string& Title, int X, int Y, int Width, int Height, const vector<string>& List, Type& Value) noexcept//大区块选择器
        {
            Value = min(max(Value, 0), List.size() - 1);//区间限制
            const auto IsInRadioBlock = MouseJudgment(EasyGUI_WindowHWND, X + 2, Y + 2, Width - 4, Height - 4); if (IsInRadioBlock)InputState_InBlock = true;//鼠标是否在区块内
            int64_t HashKey{}; for (const string& text : List)HashKey ^= (std::hash<string>{}(text)+0x9e3779b9 + (HashKey << 6) + (HashKey >> 2));//生成哈希值 防止多函数冲突
            Render_SolidRect(EasyGUI_RenderTarget.Target, X, Y, Width, Height, { 0,0,0 });//黑色外边框
            Render_SolidRect(EasyGUI_RenderTarget.Target, X + 1, Y + 1, Width - 2, Height - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_Block_DetMouAni>(IsInRadioBlock ? 2 : 3, EasyGUI_AnimationSmooth, HashKey));//外边框
            Render_GradientRect(EasyGUI_RenderTarget.Target, X + 2, Y + 2, Width - 4, Height - 4, { EasyGUI_Color / 10, { 10,10,10 } }, true);//主题色渐变背景
            if (!Title.empty())Render_SolidRect(EasyGUI_RenderTarget.Target, X + 10, Y, Render_String(EasyGUI_RenderTarget.Target, 0, 0, Title, { 0,0,0 }, EasyGUI_Font, EasyGUI_FontSize + 1, 600).x + 10, 3, EasyGUI_Color / 10);//文字后遮挡边框
            Render_String(EasyGUI_RenderTarget.Target, X + 15, 10000 + Y, Title, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize + 1, 600);
            for (size_t i = 0; i < List.size(); ++i)//遍历坐标
            {
                const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, X, Y + 14 + 30 * i, Width, 23);
                if (DetectMousePos && KeyEvent(VK_LBUTTON, true))Value = i;
                int SelectAlpha = 0; if (Value == i)SelectAlpha = 255; else if (DetectMousePos)SelectAlpha = 100;
                const auto SelectAniAlpha = Animation<class EasyGUI_RadioBlock_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth * 1.2f, HashKey + i);
                Render_SolidRect(EasyGUI_RenderTarget.Target, X + 2, Y + 16 + 30 * i, Width - 4, 23 + 1, EasyGUI_Color.Alpha(SelectAniAlpha) / 4);
                Render_GradientRect(EasyGUI_RenderTarget.Target, X + 2, Y + 16 + 30 * i, Width - 4, 23, { EasyGUI_Color.Alpha(SelectAniAlpha) / 4, { 20,20,20,SelectAniAlpha } }, true);
                Render_String(EasyGUI_RenderTarget.Target, 10000 + X + Width / 2, 10000 + Y + 28 + 30 * i, List[i], EasyGUI_Color.Min_Bri(180).Max_Bri(220) * ((Value == i) ? 1.f : 0.5f), EasyGUI_Font, EasyGUI_FontSize + 2, 600);
            }
        }
        bool GUI_Block(EasyGUI_Block& Block, const string& Title, int X, int Y, int Width, int Height, bool Lock = false) noexcept//区块
        {
            Width = min(max(Width, 300), 800);//宽度限制
            thread_local int64_t BlockID{}; if (!Block.ID)Block.ID = BlockID += 10000;//分配ID
            bool ControlDraw = Block.IsInBlock; static unordered_map<int64_t, double> OldTick{}; if (!ControlDraw && EasyGUI_Tick - OldTick[Block.ID] > (InputState_IsSlider ? Block.RefreshDelay / 3 : Block.RefreshDelay)) { ControlDraw = true; OldTick[Block.ID] = EasyGUI_Tick; }//间隔更新画板
            const auto CreateMapSize = Vector::Vector2{ Width,Height * 10 }; const auto CurrentMapSize = Block.Bitmap.Target ? Block.Bitmap.Target->GetSize() : D2D1_SIZE_F{};//位图大小
            if (CreateMapSize.x != CurrentMapSize.width || CreateMapSize.y != CurrentMapSize.height)Block.Bitmap.Create(EasyGUI_RenderTarget.Target, CreateMapSize);//当大小变化时创建位图目标
            Block.Title = Title; Block.Pos = { X,Y }; Block.Size = { Width,Height }; Block.IsInBlock = !Lock && MouseJudgment(EasyGUI_WindowHWND, X + 2, Y + 2, Width - 4, Height - 4); if (Block.IsInBlock)InputState_InBlock = true;
            if (Block.IsInBlock && !Block.IsInScrollArea)//滚轮滚动
            {
                Block.Start -= EasyGUI_MouseWheelDelta;//滚轮增量判定
                if (Block.Start < 0 || Block.Line <= Height)Block.Start = 0; else if (Block.Line > Height && Block.Start > Block.Line - Height)Block.Start = Block.Line - Height;//限制滚动区域
            }
            short ScrollBar{}; if (Block.Line > Height)ScrollBar = Block.Line;//右侧滚动条绘制判断
            const auto PaintStartPos = Animation<class EasyGUI_Block_ScroolAni>(Block.Start, EasyGUI_AnimationSmooth * 0.7f, Block.ID);//滑动动画
            if (ControlDraw) { Block.IsInScrollArea = false; Block.Line = 30; Block.Offset = {}; }//刷新行列信息
            Render_SolidRect(EasyGUI_RenderTarget.Target, X, Y, Width, Height, { 0,0,0 });//黑色外边框
            Render_SolidRect(EasyGUI_RenderTarget.Target, X + 1, Y + 1, Width - 2, Height - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_Block_DetMouAni>(Block.IsInBlock ? 2 : 3, EasyGUI_AnimationSmooth, Block.ID));//外边框
            Render_GradientRect(EasyGUI_RenderTarget.Target, X + 2, Y + 2, Width - 4, Height - 4, { { 10,10,10 }, EasyGUI_Color / 10 }, true);//渐变背景
            if (!Title.empty())Render_SolidRect(EasyGUI_RenderTarget.Target, X + 15, Y, Render_String(EasyGUI_RenderTarget.Target, 0, 0, Title, {}, EasyGUI_Font, EasyGUI_FontSize + 1, 600).x + 10, 3, { 10,10,10 });//文字后遮挡边框
            Y += 2; Height -= 4;
            Block.Bitmap.Target->EndDraw();//结束绘制
            EasyGUI_RenderTarget.DrawBitmap(Block.Bitmap.Target, D2D1::RectF(X, Y, X + Width, Y + Height), D2D1::RectF(0, PaintStartPos, Width, PaintStartPos + Height));//获取区块渲染目标的位图并绘制到主画布上
            Block.Bitmap.Target->BeginDraw(); if (ControlDraw)Block.Bitmap.Target->Clear(D2D1::ColorF(0, 0, 0, 0));//开始绘制并且清理画布
            Y -= 2; Height += 4;
            Render_GradientRect(EasyGUI_RenderTarget.Target, X + 2, Y + 2, Width - 4, 20, { { 10,10,10,200 }, { 10,10,10,0 } }, true);//顶部遮罩
            Render_GradientRect(EasyGUI_RenderTarget.Target, X + 2, Y + Height - 20 - 2, Width - 4, 20, { EasyGUI_Color.Alpha(0) / 10, EasyGUI_Color.Alpha(200) / 10 }, true);//底部遮罩
            if (ScrollBar)Render_GradientRect(EasyGUI_RenderTarget.Target, X + Width - 5, Y + 3 + PaintStartPos / (float)ScrollBar * (Height - 6), 2, (float)Height / (float)ScrollBar * (Height - 6) + 1, { EasyGUI_Color / 2, EasyGUI_Color / 5 }, true);//内容超出高度时绘制滚动条
            if (Lock)Render_SolidRect(EasyGUI_RenderTarget.Target, X, Y, Width, Height, EasyGUI_Color.Alpha(150) / 15);//锁定时半透明遮罩
            Render_String(EasyGUI_RenderTarget.Target, X + 20, 10000 + Y, Title, Vector::Vector4{ 200,200,200 } / (Lock ? 2 : 1), EasyGUI_Font, EasyGUI_FontSize + 1, 600);
            return ControlDraw;
        }
        int GUI_Text(EasyGUI_Block& Block, const string& Text) noexcept//行文字
        {
            //Render_SolidRect(Block.Bitmap.Target, 0, Block.Line, 9999, 1, { 255,0,0 });//Debug
            const auto ReturnValue = Render_String(Block.Bitmap.Target, 45 + Block.Offset.x, 10000 + Block.Line + Block.Offset.y, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize); Block.Line += 25; return ReturnValue.x;
        }
        void GUI_Line(EasyGUI_Block& Block) noexcept//分割线
        {
            Render_SolidRect(Block.Bitmap.Target, 25 + Block.Offset.x, Block.Line + Block.Offset.y, Block.Size.x - 50, 1, EasyGUI_Color.Alpha(255) / 3); Block.Line += 20;
        }
        template<typename Type> void GUI_Checkbox(EasyGUI_Block& Block, const string& Text, Type& Value) noexcept//单选框
        {
            Vector::Vector2 CheckboxPos = { 25,Block.Line - 6 }, CheckboxSize = { 12,12 }; CheckboxPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + CheckboxPos.x, Block.Pos.y - Block.Start + CheckboxPos.y, Render_String(Block.Bitmap.Target, 0, 0, Text, {}, EasyGUI_Font, EasyGUI_FontSize).x + CheckboxSize.x + 15, CheckboxSize.y);
            if (Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true))Value = !Value;
            const auto SelectAlpha = Animation<class EasyGUI_Checkbox_SelectAni>(Value ? 255 : 0, EasyGUI_AnimationSmooth, Block.Hash());
            Render_SolidRect(Block.Bitmap.Target, CheckboxPos.x, CheckboxPos.y, CheckboxSize.x, CheckboxSize.y, { 0,0,0 });
            Render_GradientRect(Block.Bitmap.Target, CheckboxPos.x + 1, CheckboxPos.y + 1, CheckboxSize.x - 2, CheckboxSize.y - 2, { EasyGUI_Color / Animation<class EasyGUI_Checkbox_DetMouAni>(DetectMousePos ? 3 : 4, EasyGUI_AnimationSmooth, Block.Hash()), { 25,25,25 } }, true);
            Render_GradientRect(Block.Bitmap.Target, CheckboxPos.x + 1, CheckboxPos.y + 1, CheckboxSize.x - 2, CheckboxSize.y - 2, { EasyGUI_Color.Alpha(SelectAlpha), (EasyGUI_Color / 5).Alpha(SelectAlpha) }, true);
            Render_String(Block.Bitmap.Target, CheckboxPos.x + 20, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
            Block.Line += 25;
        }
        bool GUI_Button(EasyGUI_Block& Block, const string& Text) noexcept//单击按钮
        {
            Block.Line += 3;
            Vector::Vector2 ButtonPos = { 45,Block.Line - 15 }, ButtonSize = { Block.Size.x / 1.5f,28 }; ButtonPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);
            const auto IsPressed = Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true);//是否按下按钮
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_Button_DetMouAni>(DetectMousePos ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { EasyGUI_Color / 8, { 20,20,20 } }, true);
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color.Alpha(Animation<class EasyGUI_Button_PressEffAni>(IsPressed ? 40 : 0, IsPressed ? 0 : EasyGUI_AnimationSmooth * 1.5f, Block.Hash())));
            Render_String(Block.Bitmap.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, Text, { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            Block.Line += 26;
            return IsPressed;
        }
        void GUI_Button_UnDir(EasyGUI_Block& Block, const string& Text, bool& Value) noexcept//单击按钮 单向赋值
        {
            Block.Line += 3;
            Vector::Vector2 ButtonPos = { 45,Block.Line - 15 }, ButtonSize = { Block.Size.x / 1.5f,28 }; ButtonPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);
            if (Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true))Value = true;//是否按下按钮
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_Button_DetMouAni>(DetectMousePos ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { EasyGUI_Color / 8, { 20,20,20 } }, true);
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color.Alpha(Animation<class EasyGUI_Button_PressEffAni>(Value ? 40 : 0, Value ? 0 : EasyGUI_AnimationSmooth * 1.5f, Block.Hash())));
            Render_String(Block.Bitmap.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, Text, { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            Block.Line += 26;
        }
        bool GUI_Button_LP(EasyGUI_Block& Block, const string& Text) noexcept//长按按钮
        {
            Block.Line += 3;
            Vector::Vector2 ButtonPos = { 45,Block.Line - 15 }, ButtonSize = { Block.Size.x / 1.5f,28 }; ButtonPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);
            thread_local unordered_map<int64_t, float> PressTimes{}; auto& PressTime = PressTimes[Block.Hash()]; bool IsPressed = false;
            if (!InputState_IsSlider && Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON)) { PressTime += 1.f / EasyGUI_DrawFPS * 1.4f; if (PressTime >= 1.f) { KeyEvent(VK_LBUTTON, true); IsPressed = true; } }
            else PressTime = 0.f;
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_LongPressButton_DetMouAni>(DetectMousePos ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { EasyGUI_Color / 8, { 20,20,20 } }, true);
            Render_GradientRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, (ButtonSize.x - 4) * PressTime, ButtonSize.y - 4, { { 0,0,0,0 }, EasyGUI_Color.Alpha(70) }, false);//触发进度条
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color.Alpha(Animation<class EasyGUI_LongPressButton_PressEffAni>(IsPressed ? 40 : 0, IsPressed ? 0 : EasyGUI_AnimationSmooth * 1.5f, Block.Hash())));//按下动画
            Render_String(Block.Bitmap.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, "*" + Text + "*", { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            Block.Line += 26;
            return IsPressed;
        }
        bool GUI_Button_Mini(EasyGUI_Block& Block, const string& Text = "...") noexcept//小单击按钮
        {
            Vector::Vector2 ButtonPos = { 5,Block.Line - 10 }, ButtonSize = { 15,20 }; ButtonPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);
            const auto IsPressed = Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true);//是否按下按钮
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_MiniButton_DetMouAni>(DetectMousePos ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { EasyGUI_Color / 8, { 20,20,20 } }, true);
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color.Alpha(Animation<class EasyGUI_MiniButton_PressEffAni>(IsPressed ? 40 : 0, IsPressed ? 0 : EasyGUI_AnimationSmooth * 1.5f, Block.Hash())));//按下动画
            Render_String(Block.Bitmap.Target, 10000 + ButtonPos.x + ButtonSize.x / 2 + 1, 10000 + Block.Line, Text, { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize - 3);
            return IsPressed;
        }
        template<typename Type> void GUI_Slider(EasyGUI_Block& Block, const string& Text, const Type& StartValue, const Type& EndValue, Type& Value, string Unit = "") noexcept//滑条
        {
            Vector::Vector2 SliderPos = { 45,Block.Line + 4 }, SliderSize = { Block.Size.x / 1.5f,10 }; SliderPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + SliderPos.x, Block.Pos.y - Block.Start + SliderPos.y + 1, SliderSize.x, SliderSize.y);
            thread_local unordered_map<int64_t, bool> IsPresses{}; auto& IsPress = IsPresses[Block.Hash()];
            const auto ValueGap = abs(EndValue - StartValue);
            if (Block.IsInBlock && !IsPress && DetectMousePos && KeyEvent(VK_LBUTTON))IsPress = true;//防止脱落造成失控
            if (IsPress && KeyEvent(VK_LBUTTON))
            {
                Value = ((EasyGUI_MousePos.x - Block.Pos.x - EasyGUI_WindowRect.left - SliderPos.x) * (EndValue - StartValue) / SliderSize.x) + StartValue;//鼠标坐标转换为数值
                if (ValueGap >= 2.f) { const auto Near = roundf(Value); if (abs(Value - Near) < 0.05f)Value = Near; }//接近整数时吸附整数
                Value = min(max(Value, StartValue), EndValue);//区间限制
                InputState_IsSlider = true;//正在拖动滑条
            }
            else if (!KeyEvent(VK_LBUTTON)) { IsPress = false; InputState_IsSlider = false; }//松开鼠标后重置状态
            const int SliderLength = min(max((float)(Value - StartValue) / (float)(EndValue - StartValue) * SliderSize.x, 0), SliderSize.x - 2);//滑条长度计算
            const int SliderLength_Animation = Animation<class EasyGUI_SliderLength_Animation>(SliderLength, EasyGUI_AnimationSmooth * 0.6f, Block.Hash());//滑条长度动画
            std::stringstream FloatPre{}; FloatPre << std::fixed << std::setprecision(ValueGap >= 100 ? 0 : 3) << Value;//保留小数点后数
            if (!Unit.empty())//数值单位
            {
                if (Unit.find("%delete") != string::npos)Unit.erase(Unit.find("%delete"), 7);//删除掉数值字符串
                else if (Unit.find("%string") != string::npos)Unit.replace(Unit.find("%string"), 7, FloatPre.str());//替换掉原本字符串
                else Unit = FloatPre.str() + Unit;//不存在特殊字符串时
            }
            else Unit = FloatPre.str();
            Render_String(Block.Bitmap.Target, SliderPos.x, 10000 + SliderPos.y - 8, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
            Render_SolidRect(Block.Bitmap.Target, SliderPos.x, SliderPos.y, SliderSize.x, SliderSize.y, { 0,0,0 });//黑色外边框
            Render_GradientRect(Block.Bitmap.Target, SliderPos.x + 1, SliderPos.y + 1, SliderSize.x - 2, SliderSize.y - 2, { { 20,20,20 }, EasyGUI_Color / Animation<class EasyGUI_Slider_DetMouAni>((DetectMousePos || IsPress) ? 5 : 6, EasyGUI_AnimationSmooth, Block.Hash()) }, true);//滑条背景
            Render_GradientRect(Block.Bitmap.Target, SliderPos.x + 1, SliderPos.y + 1, SliderLength_Animation, SliderSize.y - 2, { EasyGUI_Color, EasyGUI_Color / 4 }, true);//滑条
            Render_MiniString(Block.Bitmap.Target, 10000 + SliderPos.x + SliderLength_Animation, SliderPos.y + 1, Unit, { 150,150,150 }, 10);//居中返回值绘制
            Block.Line += 30;
        }
        template<typename Type> void GUI_KeySelector(EasyGUI_Block& Block, Type& Value, string Identifier = "-") noexcept//按键选取按钮
        {
            Vector::Vector2 SelectorPos = { Block.Size.x - 33,Block.Line }, SelectorSize = { 30,12 }; SelectorPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + SelectorPos.x - SelectorSize.x / 2, Block.Pos.y - Block.Start + SelectorPos.y - SelectorSize.y / 2, SelectorSize.x, SelectorSize.y);
            thread_local unordered_map<int64_t, bool> IsInputs{}; auto& IsInput = IsInputs[Block.Hash()];
            if (Block.IsInBlock && DetectMousePos && !IsInput && KeyEvent(VK_LBUTTON, true))IsInput = true;//进入输入状态
            if (IsInput)//在输入状态时
            {
                Block.IsInBlock = true;//修复画板刷新冲突
                if (KeyEvent(VK_ESCAPE, true)) { Value = 0; IsInput = false; }//默认无值
                for (int i = 0; i < 255; ++i)if (KeyEvent(i, true)) { Value = i; IsInput = false; }//当按下任意键
                Render_MiniString(Block.Bitmap.Target, 10000 + SelectorPos.x, 10000 + SelectorPos.y, "(-)", EasyGUI_Color / 1.5f, EasyGUI_FontSize - 4);//激活读取时
            }
            else {
                switch (Value)
                {
                case 0x00: break;
                case 0x01: Identifier = "M1"; break;
                case 0x02: Identifier = "M2"; break;
                case 0x03: Identifier = "CAN"; break;
                case 0x04: Identifier = "M3"; break;
                case 0x05: Identifier = "M4"; break;
                case 0x06: Identifier = "M5"; break;
                case 0x07: Identifier = "NON"; break;
                case 0x08: Identifier = "BAK"; break;
                case 0x09: Identifier = "TAB"; break;
                case 0x0C: Identifier = "CLE"; break;
                case 0x0D: Identifier = "ENT"; break;
                case 0x10: Identifier = "SHF"; break;
                case 0x11: Identifier = "CLR"; break;
                case 0x12: Identifier = "ALT"; break;
                case 0x13: Identifier = "PAU"; break;
                case 0x14: Identifier = "CAP"; break;
                case 0x15: Identifier = "KAN"; break;
                case 0x16: Identifier = "KAN"; break;
                case 0x17: Identifier = "JUN"; break;
                case 0x18: Identifier = "FIN"; break;
                case 0x19: Identifier = "HAN"; break;
                case 0x1B: Identifier = "ESC"; break;
                case 0x1C: Identifier = "CON"; break;
                case 0x1D: Identifier = "NON"; break;
                case 0x1E: Identifier = "ACC"; break;
                case 0x1F: Identifier = "MOD"; break;
                case 0x20: Identifier = "SPA"; break;
                case 0x21: Identifier = "PRI"; break;
                case 0x22: Identifier = "NEX"; break;
                case 0x23: Identifier = "END"; break;
                case 0x24: Identifier = "HOM"; break;
                case 0x25: Identifier = "LEF"; break;
                case 0x26: Identifier = "UP"; break;
                case 0x27: Identifier = "RIG"; break;
                case 0x28: Identifier = "DN"; break;
                case 0x29: Identifier = "SEL"; break;
                case 0x2A: Identifier = "PRI"; break;
                case 0x2B: Identifier = "EXE"; break;
                case 0x2C: Identifier = "SNA"; break;
                case 0x2D: Identifier = "INS"; break;
                case 0x2E: Identifier = "DEL"; break;
                case 0x2F: Identifier = "HEL"; break;
                case 0x30: Identifier = "0"; break;
                case 0x31: Identifier = "1"; break;
                case 0x32: Identifier = "2"; break;
                case 0x33: Identifier = "3"; break;
                case 0x34: Identifier = "4"; break;
                case 0x35: Identifier = "5"; break;
                case 0x36: Identifier = "6"; break;
                case 0x37: Identifier = "7"; break;
                case 0x38: Identifier = "8"; break;
                case 0x39: Identifier = "9"; break;
                case 0x41: Identifier = "A"; break;
                case 0x42: Identifier = "B"; break;
                case 0x43: Identifier = "C"; break;
                case 0x44: Identifier = "D"; break;
                case 0x45: Identifier = "E"; break;
                case 0x46: Identifier = "F"; break;
                case 0x47: Identifier = "G"; break;
                case 0x48: Identifier = "H"; break;
                case 0x49: Identifier = "I"; break;
                case 0x4A: Identifier = "J"; break;
                case 0x4B: Identifier = "K"; break;
                case 0x4C: Identifier = "L"; break;
                case 0x4D: Identifier = "M"; break;
                case 0x4E: Identifier = "N"; break;
                case 0x4F: Identifier = "O"; break;
                case 0x50: Identifier = "P"; break;
                case 0x51: Identifier = "Q"; break;
                case 0x52: Identifier = "R"; break;
                case 0x53: Identifier = "S"; break;
                case 0x54: Identifier = "T"; break;
                case 0x55: Identifier = "U"; break;
                case 0x56: Identifier = "V"; break;
                case 0x57: Identifier = "W"; break;
                case 0x58: Identifier = "X"; break;
                case 0x59: Identifier = "Y"; break;
                case 0x5A: Identifier = "Z"; break;
                case 0x5B: Identifier = "WIN"; break;
                case 0x5C: Identifier = "WIN"; break;
                case 0x5D: Identifier = "APP"; break;
                case 0x5F: Identifier = "SLP"; break;
                case 0x60: Identifier = "0"; break;
                case 0x61: Identifier = "1"; break;
                case 0x62: Identifier = "2"; break;
                case 0x63: Identifier = "3"; break;
                case 0x64: Identifier = "4"; break;
                case 0x65: Identifier = "5"; break;
                case 0x66: Identifier = "6"; break;
                case 0x67: Identifier = "7"; break;
                case 0x68: Identifier = "8"; break;
                case 0x69: Identifier = "9"; break;
                case 0x6A: Identifier = "*"; break;
                case 0x6B: Identifier = "+"; break;
                case 0x6C: Identifier = "SEP"; break;
                case 0x6D: Identifier = "-"; break;
                case 0x6E: Identifier = "."; break;
                case 0x6F: Identifier = "/"; break;
                case 0x70: Identifier = "F1"; break;
                case 0x71: Identifier = "F2"; break;
                case 0x72: Identifier = "F3"; break;
                case 0x73: Identifier = "F4"; break;
                case 0x74: Identifier = "F5"; break;
                case 0x75: Identifier = "F6"; break;
                case 0x76: Identifier = "F7"; break;
                case 0x77: Identifier = "F8"; break;
                case 0x78: Identifier = "F9"; break;
                case 0x79: Identifier = "F10"; break;
                case 0x7A: Identifier = "F11"; break;
                case 0x7B: Identifier = "F12"; break;
                case 0x7C: Identifier = "F13"; break;
                case 0x7D: Identifier = "F14"; break;
                case 0x7E: Identifier = "F15"; break;
                case 0x7F: Identifier = "F16"; break;
                case 0x80: Identifier = "F17"; break;
                case 0x81: Identifier = "F18"; break;
                case 0x82: Identifier = "F19"; break;
                case 0x83: Identifier = "F20"; break;
                case 0x84: Identifier = "F21"; break;
                case 0x85: Identifier = "F22"; break;
                case 0x86: Identifier = "F23"; break;
                case 0x87: Identifier = "F24"; break;
                case 0x90: Identifier = "NUM"; break;
                case 0x91: Identifier = "SCR"; break;
                case 0xA0: Identifier = "SHF"; break;
                case 0xA1: Identifier = "SHF"; break;
                case 0xA2: Identifier = "CLR"; break;
                case 0xA3: Identifier = "CLR"; break;
                case 0xA4: Identifier = "ALT"; break;
                case 0xA5: Identifier = "ALT"; break;
                case 0xC0: Identifier = "~"; break;
                case 0xBB: Identifier = "="; break;
                case 0xBC: Identifier = ","; break;
                case 0xBD: Identifier = "-"; break;
                case 0xBE: Identifier = "."; break;
                case 0xBF: Identifier = "/"; break;
                case 0xBA: Identifier = ";"; break;
                case 0xDE: Identifier = "'"; break;
                case 0xDB: Identifier = "["; break;
                case 0xDD: Identifier = "]"; break;
                case 0xDC: Identifier = "|"; break;
                default: Identifier = to_string(Value); break;//如果什么都不是直接返回编码
                }
                Render_MiniString(Block.Bitmap.Target, 10000 + SelectorPos.x, 10000 + SelectorPos.y, "(" + Identifier + ")", EasyGUI_Color.Min_Bri(190) / Animation<class EasyGUI_KeySelector_DetMouAni>(DetectMousePos ? 2.f : 2.5f, EasyGUI_AnimationSmooth, Block.Hash()), EasyGUI_FontSize - 4);
            }
        }
        void GUI_InputText(EasyGUI_Block& Block, const string& DefaultText, string& Value, bool Hide = false) noexcept//字符串输入框
        {
            Vector::Vector2 ButtonPos = { 45,Block.Line - 12 }, ButtonSize = { Block.Size.x / 1.5f,26 }; ButtonPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y - 1);
            thread_local unordered_map<int64_t, bool> IsInputs{}; auto& IsInput = IsInputs[Block.Hash()];
            if (Block.IsInBlock)//鼠标在区块内部
            {
                if (!Value.empty() && MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ButtonPos.x + ButtonSize.x - 25, Block.Pos.y - Block.Start + ButtonPos.y + 3, 20, ButtonSize.y - 6)) { if (KeyEvent(VK_LBUTTON, true))Value.clear(); }//清除全部内容
                else if (DetectMousePos)EasyGUI_MouseIcon = IDC_IBEAM;//输入框鼠标图标
                if (!IsInput && DetectMousePos && KeyEvent(VK_LBUTTON, true)) { EasyGUI_InputBuffer.clear(); IsInput = true; }//进入输入状态
            }
            if (IsInput)//在输入状态时
            {
                Block.IsInBlock = true;//修复画板刷新冲突
                if ((!DetectMousePos && (KeyEvent(VK_LBUTTON) || KeyEvent(VK_RBUTTON))) || KeyEvent(VK_ESCAPE) || KeyEvent(VK_RETURN))IsInput = false;//鼠标解除输入状态
                if (KeyEvent(VK_CONTROL) && OpenClipboard(0))//Ctrl键脚本
                {
                    if (!Hide && !Value.empty() && KeyEvent('C', true) && EmptyClipboard())//复制
                    {
                        const auto WideText = String::stringTowstring(Value);
                        if (const auto Alloc = GlobalAlloc(GMEM_MOVEABLE, (WideText.size() + 1) * sizeof(wchar_t)))
                        {
                            if (const auto Data = static_cast<wchar_t*>(GlobalLock(Alloc)))
                            {
                                wcscpy_s(Data, WideText.size() + 1, WideText.c_str());
                                GlobalUnlock(Alloc);
                                SetClipboardData(CF_UNICODETEXT, Alloc);
                            }
                            else GlobalFree(Alloc);
                        }
                    }
                    if (KeyEvent('V', true) && IsClipboardFormatAvailable(CF_UNICODETEXT))//粘贴
                    {
                        if (const auto Handle = GetClipboardData(CF_UNICODETEXT))
                        {
                            if (const auto Data = static_cast<wchar_t*>(GlobalLock(Handle)))
                            {
                                Value += String::wstringTostring(Data);
                                Value.erase(std::remove_if(Value.begin(), Value.end(), [](char c) { return c == '\n' || c == '\r'; }), Value.end());
                                GlobalUnlock(Handle);
                            }
                        }
                    }
                    CloseClipboard();
                }
                else if (!EasyGUI_InputBuffer.empty())//输入字符串
                {
                    const auto InputContent = String::wstringTostring(EasyGUI_InputBuffer);
                    if (InputContent == "\b")while (!Value.empty()) { const uint8_t BackChar = Value.back(); Value.pop_back(); if ((BackChar & 0xC0) != 0x80)break; }
                    else if (uint8_t(InputContent[0]) >= 32)Value += InputContent;
                    EasyGUI_InputBuffer.clear();
                }
            }
            string DrawString = Value;
            if (Hide)DrawString = DrawString.assign(DrawString.size(), '*');//隐藏字符串时
            if (IsInput)DrawString += ((int64_t(EasyGUI_Tick / 250) % 2) ? "" : "_");//输入时
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_InputText_DetMouAni>((DetectMousePos || IsInput) ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { { 18,18,18 }, EasyGUI_Color / 8 }, true);
            if (!IsInput && Value.empty())Render_String(Block.Bitmap.Target, ButtonPos.x + 10, 10000 + ButtonPos.y + 13, DefaultText, EasyGUI_Color.Min_Bri(160) / 4, EasyGUI_Font, EasyGUI_FontSize, 400, { ButtonSize.x - 40 });//默认显示文字
            Render_String(Block.Bitmap.Target, ButtonPos.x + 10, 10000 + ButtonPos.y + 13, DrawString, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ButtonSize.x - 40 });//已输入的文字
            if (!Value.empty())Render_MiniString(Block.Bitmap.Target, ButtonPos.x + ButtonSize.x - 18, 10000 + ButtonPos.y + ButtonSize.y / 2, "✕", { 60,60,60 }, 12);//删除全部字符叉叉
            Block.Line += 27;
        }
        void GUI_Tip(EasyGUI_Block& Block, const string& Text, const string& Identifier = "(?)") noexcept//提示
        {
            Vector::Vector2 TipPos = { 15,Block.Line }, TipSize = { 18,14 }; TipPos += Block.Offset;
            const auto DetectMousePos = Block.IsInBlock && !KeyEvent(VK_LBUTTON) && MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + TipPos.x - TipSize.x / 2, Block.Pos.y - Block.Start + TipPos.y - TipSize.y / 2, TipSize.x, TipSize.y);
            const auto TipBoxAni = Animation<class EasyGUI_Tip_BoxAni>(DetectMousePos, EasyGUI_AnimationSmooth, Block.Hash());//提示框透明度动画
            Render_MiniString(Block.Bitmap.Target, 10000 + TipPos.x, 10000 + TipPos.y, Identifier, EasyGUI_Color.Min_Bri(170) * (TipBoxAni * 0.5f + 0.4f), 10);
            if (Block.IsInBlock && TipBoxAni > 0.01f)
            {
                const Vector::Vector2 VoidSize = { 13,13 }, StringSize = Render_MiniString(EasyGUI_RenderTarget.Target, 0, 0, Text, {}, EasyGUI_FontSize - 1, EasyGUI_Font, 600, { Block.Size.x * 0.8f,0 }) + VoidSize;
                const Vector::Vector2 TipRectPos = { EasyGUI_MousePos.x - EasyGUI_WindowRect.left + 15,EasyGUI_MousePos.y - EasyGUI_WindowRect.top + 5 };
                Render_SolidRect(EasyGUI_RenderTarget.Target, TipRectPos.x, TipRectPos.y, StringSize.x, StringSize.y, { 0,0,0,TipBoxAni * 255 });
                Render_SolidRect(EasyGUI_RenderTarget.Target, TipRectPos.x + 1, TipRectPos.y + 1, StringSize.x - 2, StringSize.y - 2, EasyGUI_Color.Alpha(TipBoxAni * 255) / 2);
                Render_GradientRect(EasyGUI_RenderTarget.Target, TipRectPos.x + 2, TipRectPos.y + 2, StringSize.x - 4, StringSize.y - 4, { EasyGUI_Color.Alpha(TipBoxAni * 255) / 15, EasyGUI_Color.Alpha(TipBoxAni * 255) / 10 }, true);
                Render_MiniString(EasyGUI_RenderTarget.Target, TipRectPos.x + VoidSize.x / 2, TipRectPos.y + VoidSize.y / 2, Text, { 200,200,200,TipBoxAni * 255 }, EasyGUI_FontSize - 1, EasyGUI_Font, 600, { Block.Size.x * 0.8f,0 });
            }
        }
        template<typename Type> int GUI_Drag(EasyGUI_Block& Block, Type& Value, const Type& Multiple) noexcept//拖块
        {
            std::stringstream FloatPre{}; FloatPre << std::fixed << std::setprecision(2) << Value;//保留小数点后数
            const auto StrSize = Render_String(Block.Bitmap.Target, 0, 0, FloatPre.str(), {}, EasyGUI_Font, EasyGUI_FontSize - 2, 400);
            Vector::Vector2 DragPos = { Block.Size.x - StrSize.x - 35,Block.Line - 10 }, DragSize = { StrSize.x + 12,20 }; DragPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + DragPos.x, Block.Pos.y - Block.Start + DragPos.y, DragSize.x, DragSize.y);
            thread_local unordered_map<int64_t, bool> IsPresses{}; auto& IsPress = IsPresses[Block.Hash()];
            bool HasAnotherPress = false; for (const auto& Press : IsPresses)if (Press.first != Block.Hash() && Press.second)HasAnotherPress = true;
            if (Block.IsInBlock && !IsPress && DetectMousePos && !HasAnotherPress && KeyEvent(VK_LBUTTON))IsPress = true;//防止脱落造成失控
            if (IsPress && KeyEvent(VK_LBUTTON)) { Value += Multiple * (EasyGUI_MousePosDelta.x + EasyGUI_MousePosDelta.y); InputState_IsSlider = true; }
            else if (!KeyEvent(VK_LBUTTON)) { IsPress = false; InputState_IsSlider = false; }//松开鼠标后重置状态
            if (Block.IsInBlock && DetectMousePos && KeyEvent(VK_MBUTTON))Value = {};//重制值
            Render_SolidRect(Block.Bitmap.Target, DragPos.x, DragPos.y, DragSize.x, DragSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, DragPos.x + 1, DragPos.y + 1, DragSize.x - 2, DragSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_Drag_DetMouAni>((DetectMousePos || IsPress) ? 2.f : 3.f, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, DragPos.x + 2, DragPos.y + 2, DragSize.x - 4, DragSize.y - 4, { EasyGUI_Color / 8, { 20,20,20 } }, true);
            Render_String(Block.Bitmap.Target, 10000 + DragPos.x + DragSize.x / 2.f, 10000 + DragPos.y + DragSize.y / 2.f, FloatPre.str(), { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize - 2, 400, DragSize);
            return DragSize.x;
        }
        template<typename Type> void GUI_ColorSelector3(EasyGUI_Block& Block, Type& Value) noexcept//颜色选择器
        {
            Vector::Vector2 ColorRectPos = { Block.Size.x - 43,Block.Line - 6 }, ColorPickerSize = { 200,75 }; ColorRectPos += Block.Offset;
            thread_local unordered_map<int64_t, bool> IsInputs{}; auto& IsInput = IsInputs[Block.Hash()];//颜色选择器开关
            thread_local unordered_map<int64_t, Type> BaseColors{}; auto& BaseColor = BaseColors[Block.Hash()];//基础颜色值备份
            if (!InputState_InControl && Block.IsInBlock && !IsInput && MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ColorRectPos.x, Block.Pos.y - Block.Start + ColorRectPos.y, 20, 12) && KeyEvent(VK_LBUTTON, true))
            {
                IsInput = true; BaseColor = Value.Alpha(255); InputState_InControl = true;
                MoveControlWindow(EasyGUI_MousePos.x + 15, EasyGUI_MousePos.y + 5, ColorPickerSize.x, ColorPickerSize.y);
            }
            if (IsInput)//颜色选择器打开时
            {
                Block.IsInBlock = true;//修复画板刷新冲突
                if (!InputState_InControl)IsInput = false;//关闭颜色选择器
                if (KeyEvent(VK_CONTROL) && OpenClipboard(0))//Ctrl键脚本
                {
                    if (KeyEvent('C', true))//复制
                    {
                        EmptyClipboard();
                        const auto ColorHex = Value.Hex();
                        if (const auto hHandle = GlobalAlloc(GMEM_MOVEABLE, ColorHex.size() + 1))
                        {
                            if (const auto pMem = (char*)GlobalLock(hHandle))
                            {
                                strcpy_s(pMem, ColorHex.size() + 1, ColorHex.c_str());
                                GlobalUnlock(hHandle);
                                SetClipboardData(CF_TEXT, hHandle);
                            }
                        }
                    }
                    if (KeyEvent('V', true) && IsClipboardFormatAvailable(CF_TEXT))//粘贴
                    {
                        if (const auto hClipboard = GetClipboardData(CF_TEXT))
                        {
                            if (const auto pMem = (char*)GlobalLock(hClipboard))
                            {
                                string DataStr(pMem, strnlen(pMem, GlobalSize(hClipboard)));
                                if (DataStr.size() >= 7 && DataStr.front() == '#')
                                {
                                    auto Hex = [](char c) { return c <= '9' ? c - '0' : ((c & ~0x20) - 'A' + 10); };
                                    Value.r = min(max((Hex(DataStr[1]) << 4) | Hex(DataStr[2]), 0), 255);
                                    Value.g = min(max((Hex(DataStr[3]) << 4) | Hex(DataStr[4]), 0), 255);
                                    Value.b = min(max((Hex(DataStr[5]) << 4) | Hex(DataStr[6]), 0), 255);
                                }
                                GlobalUnlock(hClipboard);
                            }
                        }
                    }
                    CloseClipboard();
                }
                const auto SelectBar_1 = MouseJudgment(EasyGUI_ControlWindowHWND, 5, 5, ColorPickerSize.x - 10, 18), SelectBar_2 = MouseJudgment(EasyGUI_ControlWindowHWND, 5, 5 + 25, ColorPickerSize.x - 10, 18);
                if (MouseJudgment(EasyGUI_ControlWindowHWND) && KeyEvent(VK_LBUTTON))
                {
                    const auto Window_HDC = GetDC(EasyGUI_ControlWindowHWND);//获取窗口HDC
                    const auto Pixel = GetPixel(Window_HDC, EasyGUI_MousePos.x - EasyGUI_ControlWindowRect.left, EasyGUI_MousePos.y - EasyGUI_ControlWindowRect.top);
                    const Type MouseColor = { GetRValue(Pixel),GetGValue(Pixel),GetBValue(Pixel),255 };
                    if (MouseColor.Alpha(255) != Type{ 0, 0, 1 })
                    {
                        if (SelectBar_1) { BaseColor = MouseColor; Value = MouseColor; }
                        else if (SelectBar_2)Value = MouseColor;
                        if (Value.r < 5)Value.r = 0; else if (Value.r > 255 - 5)Value.r = 255;
                        if (Value.g < 5)Value.g = 0; else if (Value.g > 255 - 5)Value.g = 255;
                        if (Value.b < 5)Value.b = 0; else if (Value.b > 255 - 5)Value.b = 255;
                    }
                    ReleaseDC(EasyGUI_ControlWindowHWND, Window_HDC);
                }
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 0, 0, ColorPickerSize.x, ColorPickerSize.y, { 0,0,0 });
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 1, 1, ColorPickerSize.x - 2, ColorPickerSize.y - 2, EasyGUI_Color.Alpha(255) / 2);
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 2, 2, ColorPickerSize.x - 4, ColorPickerSize.y - 4, { EasyGUI_Color / 15, EasyGUI_Color / 10 }, true);
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 5, 5, ColorPickerSize.x - 10, 20, { 0,0,0 }, 0);//彩虹颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 6, 6, ColorPickerSize.x - 12, 18, { { 255,0,0 },{ 255,255,0 },{ 0,255,0 },{ 0,255,255 },{ 0,0,255 },{ 255,0,255 },{ 255,0,0 } }, false, -1);
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 5, 5 + 25, ColorPickerSize.x - 10, 20, { 0,0,0 }, 0);//明暗颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 6, 6 + 25, ColorPickerSize.x - 12, 18, { { 0,0,0 },BaseColor.Alpha(255),{ 255,255,255 } }, false, -1);
                Render_String(EasyGUI_ControlRenderTarget.Target, 10000 + ColorPickerSize.x / 2, 10000 + 6 + 50 + 5, "RGB(" + to_string((int)Value.r) + ", " + to_string((int)Value.g) + ", " + to_string((int)Value.b) + ")", Value.Min_Bri(100).Max_Bri(220).Alpha(255), EasyGUI_Font, EasyGUI_FontSize, 500);//颜色字符串
                if (KeyEvent(VK_LBUTTON))//绘制选择标识
                {
                    int VerticalOffset = 0; if (SelectBar_1)VerticalOffset = 0; else if (SelectBar_2)VerticalOffset = 25;
                    Render_SolidRect(EasyGUI_ControlRenderTarget.Target, EasyGUI_MousePos.x - EasyGUI_ControlWindowRect.left + 1, 6 + VerticalOffset, 1, 18, { 0,0,1 }, 0);
                }
            }
            Render_SolidRect(Block.Bitmap.Target, ColorRectPos.x, ColorRectPos.y, 20, 12, { 0,0,0 });//黑色边框
            Render_GradientRect(Block.Bitmap.Target, ColorRectPos.x + 1, ColorRectPos.y + 1, 18, 10, { Value.Alpha(255), Value.Alpha(255) / 3 }, true, -1);//颜色预览框
        }
        template<typename Type> void GUI_ColorSelector4(EasyGUI_Block& Block, Type& Value) noexcept//颜色选择器
        {
            Vector::Vector2 ColorRectPos = { Block.Size.x - 43,Block.Line - 6 }, ColorPickerSize = { 200,100 }; ColorRectPos += Block.Offset;
            thread_local unordered_map<int64_t, bool> IsInputs{}; auto& IsInput = IsInputs[Block.Hash()];//颜色选择器开关
            thread_local unordered_map<int64_t, Type> BaseColors{}; auto& BaseColor = BaseColors[Block.Hash()];//基础颜色值备份
            if (!InputState_InControl && Block.IsInBlock && !IsInput && MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ColorRectPos.x, Block.Pos.y - Block.Start + ColorRectPos.y, 20, 12) && KeyEvent(VK_LBUTTON, true))
            {
                IsInput = true; BaseColor = Value.Alpha(255); InputState_InControl = true;
                MoveControlWindow(EasyGUI_MousePos.x + 15, EasyGUI_MousePos.y + 5, ColorPickerSize.x, ColorPickerSize.y);
            }
            if (IsInput)//颜色选择器打开时
            {
                Block.IsInBlock = true;//修复画板刷新冲突
                if (!InputState_InControl)IsInput = false;//关闭颜色选择器
                if (KeyEvent(VK_CONTROL) && OpenClipboard(0))//Ctrl键脚本
                {
                    if (KeyEvent('C', true))//复制
                    {
                        EmptyClipboard();
                        const auto ColorHex = Value.Hex();
                        if (const auto hHandle = GlobalAlloc(GMEM_MOVEABLE, ColorHex.size() + 1))
                        {
                            if (const auto pMem = (char*)GlobalLock(hHandle))
                            {
                                strcpy_s(pMem, ColorHex.size() + 1, ColorHex.c_str());
                                GlobalUnlock(hHandle);
                                SetClipboardData(CF_TEXT, hHandle);
                            }
                        }
                    }
                    if (KeyEvent('V', true) && IsClipboardFormatAvailable(CF_TEXT))//粘贴
                    {
                        if (const auto hClipboard = GetClipboardData(CF_TEXT))
                        {
                            if (const auto pMem = (char*)GlobalLock(hClipboard))
                            {
                                string DataStr(pMem, strnlen(pMem, GlobalSize(hClipboard)));
                                if (DataStr.size() >= 7 && DataStr.front() == '#')
                                {
                                    auto Hex = [](char c) { return c <= '9' ? c - '0' : ((c & ~0x20) - 'A' + 10); };
                                    Value.r = min(max((Hex(DataStr[1]) << 4) | Hex(DataStr[2]), 0), 255);
                                    Value.g = min(max((Hex(DataStr[3]) << 4) | Hex(DataStr[4]), 0), 255);
                                    Value.b = min(max((Hex(DataStr[5]) << 4) | Hex(DataStr[6]), 0), 255);
                                    Value.a = (DataStr.size() >= 9) ? min(max((Hex(DataStr[7]) << 4) | Hex(DataStr[8]), 0), 255) : 255;
                                }
                                GlobalUnlock(hClipboard);
                            }
                        }
                    }
                    CloseClipboard();
                }
                const auto SelectBar_1 = MouseJudgment(EasyGUI_ControlWindowHWND, 5, 5, ColorPickerSize.x - 10, 18), SelectBar_2 = MouseJudgment(EasyGUI_ControlWindowHWND, 5, 5 + 25, ColorPickerSize.x - 10, 18), SelectBar_3 = MouseJudgment(EasyGUI_ControlWindowHWND, 5, 5 + 50, ColorPickerSize.x - 10, 18);
                if (MouseJudgment(EasyGUI_ControlWindowHWND) && KeyEvent(VK_LBUTTON))
                {
                    const auto Window_HDC = GetDC(EasyGUI_ControlWindowHWND);
                    const auto Pixel = GetPixel(Window_HDC, EasyGUI_MousePos.x - EasyGUI_ControlWindowRect.left, EasyGUI_MousePos.y - EasyGUI_ControlWindowRect.top);
                    const Type MouseColor = { GetRValue(Pixel),GetGValue(Pixel),GetBValue(Pixel),Value.a };
                    if (MouseColor.Alpha(255) != Type{ 0, 0, 1 })
                    {
                        if (SelectBar_1) { BaseColor = MouseColor; Value = MouseColor; }
                        else if (SelectBar_2)Value = MouseColor;
                        else if (SelectBar_3)Value.a = (1.f - (EasyGUI_MousePos.x - EasyGUI_ControlWindowRect.left - 5.f) / (ColorPickerSize.x - 10.f)) * 255.f;
                        if (Value.r < 5)Value.r = 0; else if (Value.r > 255 - 5)Value.r = 255;
                        if (Value.g < 5)Value.g = 0; else if (Value.g > 255 - 5)Value.g = 255;
                        if (Value.b < 5)Value.b = 0; else if (Value.b > 255 - 5)Value.b = 255;
                        if (Value.a < 5)Value.a = 0; else if (Value.a > 255 - 5)Value.a = 255;
                    }
                    ReleaseDC(EasyGUI_ControlWindowHWND, Window_HDC);
                }
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 0, 0, ColorPickerSize.x, ColorPickerSize.y, { 0,0,0 });
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 1, 1, ColorPickerSize.x - 2, ColorPickerSize.y - 2, EasyGUI_Color.Alpha(255) / 2);
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 2, 2, ColorPickerSize.x - 4, ColorPickerSize.y - 4, { EasyGUI_Color / 15, EasyGUI_Color / 10 }, true);
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 5, 5, ColorPickerSize.x - 10, 20, { 0,0,0 }, 0);//彩虹颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 6, 6, ColorPickerSize.x - 12, 18, { { 255,0,0 },{ 255,255,0 },{ 0,255,0 },{ 0,255,255 },{ 0,0,255 },{ 255,0,255 },{ 255,0,0 } }, false, -1);
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 5, 5 + 25, ColorPickerSize.x - 10, 20, { 0,0,0 }, 0);//明暗颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 6, 6 + 25, ColorPickerSize.x - 12, 18, { { 0,0,0 },BaseColor.Alpha(255),{ 255,255,255 } }, false, -1);
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 5, 5 + 50, ColorPickerSize.x - 10, 20, { 0,0,0 }, 0);//透明颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 6, 6 + 50, ColorPickerSize.x - 12, 18, { {0,0,0},{255,255,255},{0,0,0},{255,255,255},{0,0,0},{255,255,255},{0,0,0},{255,255,255},{0,0,0},{255,255,255} }, true, -1);
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 6, 6 + 50, ColorPickerSize.x - 12, 18, { Value.Alpha(255), Value.Alpha(0) }, false, -1);
                Render_String(EasyGUI_ControlRenderTarget.Target, 10000 + ColorPickerSize.x / 2, 10000 + 6 + 75 + 5, "RGBA(" + to_string((int)Value.r) + ", " + to_string((int)Value.g) + ", " + to_string((int)Value.b) + ", " + to_string((int)Value.a) + ")", Value.Min_Bri(100).Max_Bri(220).Alpha(255), EasyGUI_Font, EasyGUI_FontSize, 500);//颜色字符串
                if (KeyEvent(VK_LBUTTON))//绘制选择标识
                {
                    int VerticalOffset = 0; if (SelectBar_1)VerticalOffset = 0; else if (SelectBar_2)VerticalOffset = 25; else if (SelectBar_3)VerticalOffset = 50;
                    Render_SolidRect(EasyGUI_ControlRenderTarget.Target, EasyGUI_MousePos.x - EasyGUI_ControlWindowRect.left + 1, 6 + VerticalOffset, 1, 18, { 0,0,1 }, 0);
                }
            }
            Render_SolidRect(Block.Bitmap.Target, ColorRectPos.x, ColorRectPos.y, 20, 12, { 0,0,0 });//黑色边框
            Render_GradientRect(Block.Bitmap.Target, ColorRectPos.x + 1, ColorRectPos.y + 1, 18, 10, { {0,0,0},{255,255,255},{0,0,0},{255,255,255},{0,0,0},{255,255,255},{0,0,0},{255,255,255},{0,0,0},{255,255,255} }, true, -1);//透明格子绘制
            Render_GradientRect(Block.Bitmap.Target, ColorRectPos.x + 1, ColorRectPos.y + 1, 18, 10, { Value, Value / 3 }, true, -1);//颜色预览框
        }
        template<typename Type> void GUI_Combobox(EasyGUI_Block& Block, const vector<string>& List, Type& Value) noexcept//单选组合框
        {
            if (Value > List.size() - 1)Value = 0; else Value = min(max(Value, 0), List.size() - 1);//限制区间
            Vector::Vector2 ComboboxPos = { 45,Block.Line - 12 }, ComboboxSize = { Block.Size.x / 1.5f,24 }, ComboboxWindowSize = { ComboboxSize.x, List.size() * ComboboxSize.y + 3 }; ComboboxPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ComboboxPos.x, Block.Pos.y - Block.Start + ComboboxPos.y, ComboboxSize.x, ComboboxSize.y);
            thread_local unordered_map<int64_t, bool> IsOpens{}; auto& IsOpen = IsOpens[Block.Hash()];//判断是否打开选择变量
            if (!InputState_InControl && Block.IsInBlock && !IsOpen && DetectMousePos && KeyEvent(VK_LBUTTON, true))//当最前端窗口为GUI窗口接收事件
            {
                IsOpen = true; InputState_InControl = true;
                MoveControlWindow(EasyGUI_WindowRect.left + Block.Pos.x + ComboboxPos.x, EasyGUI_WindowRect.top + Block.Pos.y - Block.Start + ComboboxPos.y + ComboboxSize.y + 3, ComboboxWindowSize.x, ComboboxWindowSize.y);
            }
            if (IsOpen)
            {
                Block.IsInBlock = true;//修复画板刷新冲突
                if (!InputState_InControl)IsOpen = false;
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 0, 0, ComboboxWindowSize.x, ComboboxWindowSize.y, { 0,0,0 });
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 1, 1, ComboboxWindowSize.x - 2, ComboboxWindowSize.y - 2, EasyGUI_Color.Alpha(255) / 2);
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 2, 2, ComboboxWindowSize.x - 4, ComboboxWindowSize.y - 4, { EasyGUI_Color.Alpha(255) / 10, { 10,10,10 } }, true);
                for (size_t i = 0; i < List.size(); ++i)//遍历选项绘制
                {
                    const int Pos_Y = i * 24 + 2, PosHeight = 22; int SelectAlpha{};
                    if (MouseJudgment(EasyGUI_ControlWindowHWND, 2, Pos_Y, ComboboxWindowSize.x - 4, PosHeight)) { if (KeyEvent(VK_LBUTTON, true)) { Value = i; IsOpen = false; InputState_InControl = false; } SelectAlpha = 255; }
                    const auto SelectAniAlpha = Animation<class EasyGUI_Combobox_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth, i);
                    Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 2, Pos_Y, ComboboxWindowSize.x - 4, PosHeight, { EasyGUI_Color.Alpha(SelectAniAlpha / 10), EasyGUI_Color.Alpha(SelectAniAlpha / 50) }, true);
                    if (Value == i)Render_String(EasyGUI_ControlRenderTarget.Target, 10, 10000 + Pos_Y + PosHeight / 2, List[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600, { ComboboxSize.x - 20 });
                    else Render_String(EasyGUI_ControlRenderTarget.Target, 10, 10000 + Pos_Y + PosHeight / 2, List[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 20 });
                }
            }
            Render_SolidRect(Block.Bitmap.Target, ComboboxPos.x, ComboboxPos.y, ComboboxSize.x, ComboboxSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_Combobox_DetMouAni>((DetectMousePos || IsOpen) ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, ComboboxPos.x + 2, ComboboxPos.y + 2, ComboboxSize.x - 4, ComboboxSize.y - 4, { { 20,20,20 }, EasyGUI_Color / 7 }, true);
            if (!List.empty())Render_String(Block.Bitmap.Target, ComboboxPos.x + 10, 10000 + ComboboxPos.y + 13, List[Value], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 35 });
            Render_MiniString(Block.Bitmap.Target, ComboboxPos.x + ComboboxSize.x - 17, 10000 + Block.Line + 1, IsOpen ? "▲" : "▼", { 200,200,200 }, 10);
            Block.Line += 25;
        }
        void GUI_MultiCombobox(EasyGUI_Block& Block, const vector<string>& List, vector<bool>& Value) noexcept//多选组合框
        {
            Vector::Vector2 ComboboxPos = { 45,Block.Line - 12 }, ComboboxSize = { Block.Size.x / 1.5f,24 }, ComboboxWindowSize = { ComboboxSize.x, List.size() * ComboboxSize.y + 3 }; ComboboxPos += Block.Offset;
            const auto DetectMousePos = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ComboboxPos.x, Block.Pos.y - Block.Start + ComboboxPos.y, ComboboxSize.x, ComboboxSize.y);
            thread_local unordered_map<int64_t, bool> IsOpens{}; auto& IsOpen = IsOpens[Block.Hash()];//判断是否打开选择变量
            if (!InputState_InControl && Block.IsInBlock && !IsOpen && DetectMousePos && KeyEvent(VK_LBUTTON, true))//当最前端窗口为GUI窗口接收事件
            {
                IsOpen = true; InputState_InControl = true;
                MoveControlWindow(EasyGUI_WindowRect.left + Block.Pos.x + ComboboxPos.x, EasyGUI_WindowRect.top + Block.Pos.y - Block.Start + ComboboxPos.y + ComboboxSize.y + 3, ComboboxWindowSize.x, ComboboxWindowSize.y);
            }
            if (IsOpen)
            {
                Block.IsInBlock = true;//修复画板刷新冲突
                if (!InputState_InControl)IsOpen = false;
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 0, 0, ComboboxWindowSize.x, ComboboxWindowSize.y, { 0,0,0 });
                Render_SolidRect(EasyGUI_ControlRenderTarget.Target, 1, 1, ComboboxWindowSize.x - 2, ComboboxWindowSize.y - 2, EasyGUI_Color.Alpha(255) / 2);
                Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 2, 2, ComboboxWindowSize.x - 4, ComboboxWindowSize.y - 4, { EasyGUI_Color.Alpha(255) / 10, { 10,10,10 } }, true);
                for (size_t i = 0; i < List.size(); ++i)//遍历选项绘制
                {
                    const int Pos_Y = i * 24 + 2, PosHeight = 22; int SelectAlpha{};
                    if (MouseJudgment(EasyGUI_ControlWindowHWND, 2, Pos_Y, ComboboxWindowSize.x - 4, PosHeight)) { if (KeyEvent(VK_LBUTTON, true))Value[i] = !Value[i]; SelectAlpha = 255; }
                    const auto SelectAniAlpha = Animation<class EasyGUI_MultiCombobox_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth, i);
                    Render_GradientRect(EasyGUI_ControlRenderTarget.Target, 2, Pos_Y, ComboboxWindowSize.x - 4, PosHeight, { EasyGUI_Color.Alpha(SelectAniAlpha / 10), EasyGUI_Color.Alpha(SelectAniAlpha / 50) }, true);
                    if (Value[i])Render_String(EasyGUI_ControlRenderTarget.Target, 10, 10000 + Pos_Y + PosHeight / 2, List[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600, { ComboboxSize.x - 20 });
                    else Render_String(EasyGUI_ControlRenderTarget.Target, 10, 10000 + Pos_Y + PosHeight / 2, List[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 20 });
                }
            }
            string Selected = ""; for (size_t i = 0; i < List.size(); ++i)if (Value[i]) { if (!Selected.empty())Selected += ", "; Selected += List[i]; } if (Selected.empty())Selected = "-";//字符串格式排列
            Render_SolidRect(Block.Bitmap.Target, ComboboxPos.x, ComboboxPos.y, ComboboxSize.x, ComboboxSize.y, { 0,0,0 });
            Render_SolidRect(Block.Bitmap.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_Combobox_DetMouAni>((DetectMousePos || IsOpen) ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));
            Render_GradientRect(Block.Bitmap.Target, ComboboxPos.x + 2, ComboboxPos.y + 2, ComboboxSize.x - 4, ComboboxSize.y - 4, { { 20,20,20 }, EasyGUI_Color / 7 }, true);
            Render_String(Block.Bitmap.Target, ComboboxPos.x + 10, 10000 + ComboboxPos.y + 13, Selected, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 35 });
            Render_MiniString(Block.Bitmap.Target, ComboboxPos.x + ComboboxSize.x - 17, 10000 + Block.Line + 1, IsOpen ? "▲" : "▼", { 200,200,200 }, 10);
            Block.Line += 25;
        }
        template<typename Type> void GUI_List(EasyGUI_Block& Block, const vector<string>& LineString, Type& Value, int LineLimit = 0) noexcept//单选列表
        {
            Block.Line += 3;
            const auto LineStringSize = LineString.size();//获取行列数
            Value = min(max(Value, 0), LineStringSize - 1);//赋值范围限制
            if (!LineLimit)LineLimit = LineStringSize; if (!LineStringSize)Value = -1;//防止过量访问崩溃
            Vector::Vector2 ListPos = { 45,Block.Line - 15 }, ListSize = { Block.Size.x / 1.5f,LineLimit * 25 + 5 }; ListPos += Block.Offset;
            thread_local unordered_map<int64_t, int> StartLines{}; auto& StartLine = StartLines[Block.Hash()];
            const auto IsInList = MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ListPos.x, Block.Pos.y - Block.Start + ListPos.y, ListSize.x, ListSize.y);
            if (IsInList && Block.IsInBlock && LineStringSize > LineLimit) { StartLine -= EasyGUI_MouseWheelDelta / 20; Block.IsInScrollArea = true; } StartLine = min(max(StartLine, 0), LineStringSize - LineLimit);//鼠标滚轮调整绘制起始位置
            Render_SolidRect(Block.Bitmap.Target, ListPos.x, ListPos.y, ListSize.x, ListSize.y, { 0,0,0 });//黑色外边框
            Render_SolidRect(Block.Bitmap.Target, ListPos.x + 1, ListPos.y + 1, ListSize.x - 2, ListSize.y - 2, EasyGUI_Color.Alpha(255) / Animation<class EasyGUI_List_DetMouAni>(IsInList ? 2 : 3, EasyGUI_AnimationSmooth, Block.Hash()));//主题色外边框
            Render_GradientRect(Block.Bitmap.Target, ListPos.x + 2, ListPos.y + 2, ListSize.x - 4, ListSize.y - 4, { EasyGUI_Color / 10, { 10,10,10 } }, true);//主题色渐变背景
            for (size_t i = StartLine; i < LineStringSize; ++i)//行列内容遍历
            {
                if (i - StartLine >= LineLimit)continue;//限制行数
                const auto LineY = ListPos.y + (i - StartLine) * 25 + 5;//当前行的Y坐标
                int SelectAlpha = 0; if (Value == i)SelectAlpha = 255;
                else if (Block.IsInBlock && MouseJudgment(EasyGUI_WindowHWND, Block.Pos.x + ListPos.x, Block.Pos.y - Block.Start + LineY, ListSize.x, 20)) { if (KeyEvent(VK_LBUTTON, true))Value = i; SelectAlpha = 150; }
                const auto SelectAniAlpha = Animation<class EasyGUI_Combobox_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth, Block.Hash() + i);
                Render_GradientRect(Block.Bitmap.Target, ListPos.x + 2, LineY, ListSize.x - 4, 20, { EasyGUI_Color.Alpha(SelectAniAlpha / 10), EasyGUI_Color.Alpha(SelectAniAlpha / 50) }, true);
                if (Value == i)Render_String(Block.Bitmap.Target, ListPos.x + 12, 10000 + LineY + 10, LineString[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600, { ListSize.x - 24 });
                else Render_String(Block.Bitmap.Target, ListPos.x + 12, 10000 + LineY + 10, LineString[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ListSize.x - 24 });
            }
            if (LineStringSize > LineLimit)//只有在内容超出可视区域时才会绘制滚动条
            {
                const auto ListHeight = LineLimit * 25, ScrollBarHeight = max(int(ListHeight * float(LineLimit) / LineStringSize), 10);
                Render_GradientRect(Block.Bitmap.Target, ListPos.x + ListSize.x - 5, ListPos.y + 4 + ((LineStringSize - LineLimit) > 0 ? float(StartLine) / (LineStringSize - LineLimit) * (ListHeight - ScrollBarHeight) : 0.f), 2, ScrollBarHeight - 3, { EasyGUI_Color / 2, EasyGUI_Color / 5 }, true);//滚动条
            }
            Block.Line += LineLimit * 25 + 5;
        }
        //------------------------------------------------------------------------------------------------------------------------------
    };
}