#pragma once
#include <Vector>
#include <String>
#include <Chrono>
#include <Unordered_map>
#include <Algorithm>
#include <Dwmapi.h>
#include <Dwrite.h>
#include <D2D1.h>
#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "Dwrite.lib")
#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "Winmm.lib")
namespace EasyGUI_Direct2D
{
    using std::hash, std::string, std::wstring, std::vector, std::unordered_map;
    namespace EasyGUI_Vector
    {
        struct Vector2
        {
            inline Vector2(const int x = 0, const int y = 0) noexcept :x(x), y(y) {} int x, y;
            inline bool operator==(Vector2 other) const noexcept { return x == other.x && y == other.y; }
            inline bool operator!=(Vector2 other) const noexcept { return x != other.x || y != other.y; }
            inline Vector2 operator+(Vector2 other) const noexcept { return Vector2{ x + other.x, y + other.y }; }
            inline Vector2 operator-(Vector2 other) const noexcept { return Vector2{ x - other.x, y - other.y }; }
            inline Vector2 operator+=(Vector2 other) noexcept { x += other.x, y += other.y; return *this; }
            inline Vector2 operator-=(Vector2 other) noexcept { x -= other.x, y -= other.y; return *this; }
            inline Vector2 operator*(int other) const noexcept { return Vector2{ x * other, y * other }; }
            inline Vector2 operator/(int other) const noexcept { return Vector2{ x / other, y / other }; }
            inline Vector2 operator*=(int other) noexcept { x *= other, y *= other; return *this; }
            inline Vector2 operator/=(int other) noexcept { x /= other, y /= other; return *this; }
            inline Vector2 operator*(float other) const noexcept { return Vector2{ (int)(x * other), (int)(y * other) }; }
            inline Vector2 operator/(float other) const noexcept { return Vector2{ (int)(x / other), (int)(y / other) }; }
            inline Vector2 operator*=(float other) noexcept { x *= other, y *= other; return *this; }
            inline Vector2 operator/=(float other) noexcept { x /= other, y /= other; return *this; }
            inline Vector2 operator*(double other) const noexcept { return Vector2{ (int)(x * other), (int)(y * other) }; }
            inline Vector2 operator/(double other) const noexcept { return Vector2{ (int)(x / other), (int)(y / other) }; }
            inline Vector2 operator*=(double other) noexcept { x *= other, y *= other; return *this; }
            inline Vector2 operator/=(double other) noexcept { x /= other, y /= other; return *this; }
            inline bool IsZero() const noexcept { return !x && !y; }
        };
        struct Vector3
        {
            inline Vector3(const float x = 0, const float y = 0, const float z = 0) noexcept :x(x), y(y), z(z) {} float x, y, z;
            inline bool operator==(Vector3 other) const noexcept { return x == other.x && y == other.y && z == other.z; }
            inline bool operator!=(Vector3 other) const noexcept { return x != other.x || y != other.y || z != other.z; }
            inline Vector3 operator+(Vector3 other) const noexcept { return Vector3{ x + other.x, y + other.y, z + other.z }; }
            inline Vector3 operator-(Vector3 other) const noexcept { return Vector3{ x - other.x, y - other.y, z - other.z }; }
            inline Vector3 operator+=(Vector3 other) noexcept { x += other.x, y += other.y, z += other.z; return *this; }
            inline Vector3 operator-=(Vector3 other) noexcept { x -= other.x, y -= other.y, z -= other.z; return *this; }
            inline Vector3 operator*(int other) const noexcept { return Vector3{ x * other, y * other, z * other }; }
            inline Vector3 operator/(int other) const noexcept { return Vector3{ x / other, y / other, z / other }; }
            inline Vector3 operator*=(int other) noexcept { x *= other, y *= other, z *= other; return *this; }
            inline Vector3 operator/=(int other) noexcept { x /= other, y /= other, z /= other; return *this; }
            inline Vector3 operator*(float other) const noexcept { return Vector3{ x * other, y * other, z * other }; }
            inline Vector3 operator/(float other) const noexcept { return Vector3{ x / other, y / other, z / other }; }
            inline Vector3 operator*=(float other) noexcept { x *= other, y *= other, z *= other; return *this; }
            inline Vector3 operator/=(float other) noexcept { x /= other, y /= other, z /= other; return *this; }
            inline Vector3 operator*(double other) const noexcept { return Vector3{ (float)(x * other), (float)(y * other), (float)(z * other) }; }
            inline Vector3 operator/(double other) const noexcept { return Vector3{ (float)(x / other), (float)(y / other), (float)(z / other) }; }
            inline Vector3 operator*=(double other) noexcept { x *= other, y *= other, z *= other; return *this; }
            inline Vector3 operator/=(double other) noexcept { x /= other, y /= other, z /= other; return *this; }
            inline bool IsZero() const noexcept { return !x && !y && !z; }
        };
        struct Vector4
        {
            inline Vector4(const int r = 0, const int g = 0, const int b = 0, const int a = 255) noexcept :r(r), g(g), b(b), a(a) {} int r, g, b, a = 255;
            inline bool operator==(Vector4 other) const noexcept { return r == other.r && g == other.g && b == other.b && a == other.a; }
            inline bool operator!=(Vector4 other) const noexcept { return r != other.r || g != other.g || b != other.b || a != other.a; }
            inline Vector4 operator+(Vector4 other) const noexcept { return Vector4{ r + other.r, g + other.g, b + other.b, a }; }
            inline Vector4 operator-(Vector4 other) const noexcept { return Vector4{ r - other.r, g - other.g, b - other.b, a }; }
            inline Vector4 operator+=(Vector4 other) noexcept { r += other.r, g += other.g, b += other.b, a += other.a; return *this; }
            inline Vector4 operator-=(Vector4 other) noexcept { r -= other.r, g -= other.g, b -= other.b, a -= other.a; return *this; }
            inline Vector4 operator*(int other) const noexcept { return Vector4{ r * other, g * other, b * other, a }; }
            inline Vector4 operator/(int other) const noexcept { return Vector4{ r / other, g / other, b / other, a }; }
            inline Vector4 operator*(float other) const noexcept { return Vector4{ (int)(r * other), (int)(g * other), (int)(b * other), a }; }
            inline Vector4 operator/(float other) const noexcept { return Vector4{ (int)(r / other), (int)(g / other), (int)(b / other), a }; }
            inline Vector4 operator*(double other) const noexcept { return Vector4{ (int)(r * other), (int)(g * other), (int)(b * other), a }; }
            inline Vector4 operator/(double other) const noexcept { return Vector4{ (int)(r / other), (int)(g / other), (int)(b / other), a }; }
            inline bool IsZero() const noexcept { return !r && !g && !b; }
            inline uint64_t Pack(int Step = 4) const noexcept { return (uint64_t(r / Step) << 24) | (uint64_t(g / Step) << 16) | (uint64_t(b / Step) << 8) | uint64_t(a / Step); }
            inline Vector4 Alpha(int alpha) const noexcept { return { r, g, b, std::clamp(alpha, 0, 255) }; }
            inline Vector4 Reverse() const noexcept { return Vector4{ 255 - r, 255 - g, 255 - b, a }; }
            inline Vector4 Limit() noexcept { r = std::clamp(r, 0, 255); g = std::clamp(g, 0, 255); b = std::clamp(b, 0, 255); a = std::clamp(a, 0, 255); return *this; }
            inline Vector4 Min_Bri(int bright = 0) const noexcept { return Vector4{ max(r, bright),max(g, bright),max(b, bright),a }; }
            inline Vector4 Max_Bri(int bright = 0) const noexcept { return Vector4{ min(r, bright),min(g, bright),min(b, bright),a }; }
            inline Vector4 Sat(float saturation = 1.f, float grey = 0.f) const noexcept
            {
                static constexpr float inv255 = 1.f / 255.f;
                const float fr = r * inv255, fg = g * inv255, fb = b * inv255;
                const float max_v = max(fr, max(fg, fb)), delta = max_v - min(fr, min(fg, fb));
                float h_div = 0.f;
                if (delta > 0.f)
                {
                    if (max_v == fr)h_div = (fg - fb) / delta + (fg < fb ? 6.f : 0.f);
                    else if (max_v == fg)h_div = (fb - fr) / delta + 2.f;
                    else h_div = (fr - fg) / delta + 4.f;
                }
                const float s = std::clamp(((max_v <= 0.f) ? 0.f : (delta / max_v)) * saturation, 0.f, 1.f), v = std::clamp(max_v + grey, 0.f, 1.f);
                float nr, ng, nb;
                const float f = h_div - (int)h_div, p = v * (1.f - s), q = v * (1.f - s * f), t = v * (1.f - s * (1.f - f));
                switch ((int)h_div % 6)
                {
                case 0: nr = v; ng = t; nb = p; break; case 1: nr = q; ng = v; nb = p; break;
                case 2: nr = p; ng = v; nb = t; break; case 3: nr = p; ng = q; nb = v; break;
                case 4: nr = t; ng = p; nb = v; break; default:nr = v; ng = p; nb = q; break;
                }
                return Vector4{ (int)(nr * 255.f),(int)(ng * 255.f),(int)(nb * 255.f),this->a };
            }
        };
    }
    using namespace EasyGUI_Vector;
    LPWSTR EasyGUI_MouseIcon = IDC_ARROW;//鼠标图标 (修改鼠标图标时更改该变量即可)
    static LRESULT CALLBACK EasyGUI_WindowProcess(HWND Hwnd, UINT Message, WPARAM wParam, LPARAM lParam) noexcept//窗口消息循环
    {
        if (Message == WM_CLOSE)exit(0);//接收到关闭窗口事件时关闭全部线程
        else if (Message == WM_SETCURSOR) { SetCursor(LoadCursor(0, EasyGUI_MouseIcon)); EasyGUI_MouseIcon = IDC_ARROW; }//鼠标图标事件
        else if (Message == WM_MOUSEWHEEL)//鼠标滚轮事件
        {
            const auto Delta = GET_WHEEL_DELTA_WPARAM(wParam);
            if (Delta > 0)keybd_event(VK_UP, 0, 0, 0); else if (Delta < 0)keybd_event(VK_DOWN, 0, 0, 0);
        }
        return DefWindowProc(Hwnd, Message, wParam, lParam);//定义回调函数的返回值
    }
    struct EasyGUI_Block { string Title = ""; Vector2 Pos{}, Size{}; int ID = 0, Line = 0, Start = 0, Offset = 0; bool IsInBlock = false, IsInScrollArea = false; ID2D1BitmapRenderTarget* Target{}; };
    class EasyGUI
    {
    private:
        HWND EasyGUI_WindowHWND{}, EasyGUI_ControlWindowHWND{};//窗口句柄
        ID2D1HwndRenderTarget* EasyGUI_RenderTarget{}; ID2D1HwndRenderTarget* EasyGUI_ControlRenderTarget{};//Direct2D绘制目标
        static const short D2DMaxCache = 2048; IDWriteFactory* WriteFactory{}; unordered_map<ID2D1RenderTarget*, ID2D1SolidColorBrush*> CacheBrush{}; unordered_map<uint64_t, ID2D1LinearGradientBrush*> CacheGraBrush{}; unordered_map<size_t, IDWriteTextFormat*> CacheTextFormat{}; unordered_map<size_t, IDWriteTextLayout*> CacheTextLayout{};//Direct2D绘制资源缓存
        POINT EasyGUI_MousePos{}; RECT EasyGUI_WindowPos{}, EasyGUI_ControlWindowPos{};//窗口鼠标坐标
        string EasyGUI_Font = "Verdana";//字体名称
        float EasyGUI_FontSize = 12;//字体大小
        Vector4 EasyGUI_Color = { 255,255,255 };//主题颜色
        int EasyGUI_Alpha = 250;//窗口透明度
        float EasyGUI_AnimationSmooth = 3;//控件动画速度
        float EasyGUI_RectRadius = 4;//矩形圆角半径
        float EasyGUI_ColorSat = 0.8, EasyGUI_ColorGrey = 0.03;//主题色调
        double EasyGUI_Tick{}, EasyGUI_DrawFPS{}, EasyGUI_DrawFrame{};//绘制帧数
        bool InputState_IsWindShow = false, InputState_InBlock = false, InputState_IsSlider = false, InputState_ControlWindowShow = false;//防止控件函数之间冲突的判断变量
        template<class CLASS> inline void SafeRelease(CLASS*& Point) noexcept { if (Point) { Point->Release(); Point = 0; } }//安全释放
        inline void MoveControlWindow(int X, int Y, int Width, int Height, int Alpha = 0) noexcept//移动控件窗口位置
        {
            if (!Alpha)Alpha = EasyGUI_Alpha; SetLayeredWindowAttributes(EasyGUI_ControlWindowHWND, 0, Alpha, LWA_ALPHA);
            if (X + Width > GetSystemMetrics(0))X = GetSystemMetrics(0) - Width - 10; if (Y + Height > GetSystemMetrics(1))Y = GetSystemMetrics(1) - Height - 10;//防止超出屏幕
            MoveWindow(EasyGUI_ControlWindowHWND, X, Y, Width, Height, true);
            EasyGUI_ControlRenderTarget->EndDraw(); EasyGUI_ControlRenderTarget->Resize(D2D1::SizeU(Width, Height));
            ShowWindow(EasyGUI_ControlWindowHWND, SW_SHOW);
        }
        inline void CreateHWNDRenderTarget(HWND WindowHWND, Vector2 PaintSize, ID2D1HwndRenderTarget*& Target) noexcept//创建单独渲染目标
        {
            ID2D1Factory* EasyGUI_RenderFactory{}; D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &EasyGUI_RenderFactory);
            EasyGUI_RenderFactory->CreateHwndRenderTarget(
                D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_HARDWARE, D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)),
                D2D1::HwndRenderTargetProperties(WindowHWND, D2D1::SizeU(PaintSize.x, PaintSize.y), D2D1_PRESENT_OPTIONS_IMMEDIATELY), &Target);
            SafeRelease(EasyGUI_RenderFactory);
            if (WriteFactory)WriteFactory->Release(); DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&WriteFactory));
            if (!CacheBrush[Target])Target->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &CacheBrush[Target]);
        }
        inline ID2D1BitmapRenderTarget* CreateBitmapRenderTarget(ID2D1RenderTarget* MainTarget, Vector2 PaintSize, long CreateID) noexcept//创建控件渲染目标
        {
            static unordered_map<long, ID2D1BitmapRenderTarget*> RenderBitMap{};
            if (!RenderBitMap[CreateID])
            {
                MainTarget->CreateCompatibleRenderTarget(D2D1::SizeF(PaintSize.x, PaintSize.y), &RenderBitMap[CreateID]);
                if (!CacheBrush[RenderBitMap[CreateID]])RenderBitMap[CreateID]->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &CacheBrush[RenderBitMap[CreateID]]);
            }
            else {
                const auto OldSize = RenderBitMap[CreateID]->GetSize();
                if (OldSize.width != PaintSize.x || OldSize.height != PaintSize.y)
                {
                    SafeRelease(RenderBitMap[CreateID]);
                    MainTarget->CreateCompatibleRenderTarget(D2D1::SizeF(PaintSize.x, PaintSize.y), &RenderBitMap[CreateID]);
                }
            }
            return RenderBitMap[CreateID];
        }
        inline D2D1::ColorF D2DCol(Vector4 Color) noexcept { Color = Color.Limit(); return D2D1::ColorF((float)Color.r / 255.f, (float)Color.g / 255.f, (float)Color.b / 255.f, (float)Color.a / 255.f); };//颜色转换
        inline ID2D1LinearGradientBrush* CacheGradientBrush(ID2D1RenderTarget* Target, const Vector4& Color_1, const Vector4& Color_2) noexcept//渐变色画笔缓存
        {
            const auto HashKey = ((Color_1.Pack() << 32) | Color_2.Pack()) ^ (uintptr_t)Target;//唯一性哈希值
            if (CacheGraBrush.find(HashKey) == CacheGraBrush.end())//如果缓存中没有则创建新的渐变画笔
            {
                if (CacheGraBrush.size() > D2DMaxCache) { for (auto& Pair : CacheGraBrush)if (Pair.second)Pair.second->Release(); CacheGraBrush.clear(); }
                const D2D1_GRADIENT_STOP GraStop[2] = { {0, D2DCol(Color_1)},{1, D2DCol(Color_2)} };
                ID2D1GradientStopCollection* GraStopCollection{}; Target->CreateGradientStopCollection(GraStop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &GraStopCollection);
                Target->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), D2D1::Point2F(0, 0)), GraStopCollection, &CacheGraBrush[HashKey]);
                GraStopCollection->Release();//画笔已持有引用释放Collection
            }
            return CacheGraBrush[HashKey];
        }
        inline IDWriteTextFormat* CacheWriteTextFormat(const string& FontName, int FontSize, int FontWeight) noexcept//文字格式缓存
        {
            const auto HashKey = hash<string>{}(FontName) ^ (hash<int>{}(FontSize) << 1) ^ (hash<int>{}(FontWeight) << 2);//唯一性哈希值
            if (CacheTextFormat.find(HashKey) == CacheTextFormat.end())
            {
                if (CacheTextFormat.size() > D2DMaxCache / 8) { for (auto& Pair : CacheTextFormat)if (Pair.second)Pair.second->Release(); CacheTextFormat.clear(); }
                WriteFactory->CreateTextFormat(wstring(FontName.begin(), FontName.end()).c_str(), 0, (DWRITE_FONT_WEIGHT)FontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, FontSize, L"", &CacheTextFormat[HashKey]);
            }
            return CacheTextFormat[HashKey];
        }
        inline IDWriteTextLayout* CacheWriteTextLayout(IDWriteTextFormat* Format, const string& Text, int Limit_X = 0, int Limit_Y = 0, int CodePage = 0) noexcept//文本布局缓存
        {
            if (!Limit_X)Limit_X = 9999; if (!Limit_Y)Limit_Y = 9999;
            const auto HashKey = hash<string>{}(Text) ^ (hash<void*>{}(Format) << 1) ^ (hash<int>{}(Limit_X) << 2) ^ (hash<int>{}(Limit_Y) << 3);//唯一性哈希值
            if (CacheTextLayout.find(HashKey) == CacheTextLayout.end())
            {
                if (CacheTextLayout.size() > D2DMaxCache) { for (auto& Pair : CacheTextLayout)if (Pair.second)Pair.second->Release(); CacheTextLayout.clear(); }
                const auto TextSize = MultiByteToWideChar(CodePage, 0, Text.c_str(), -1, 0, 0);
                wstring wText(TextSize - 1, 0); MultiByteToWideChar(CodePage, 0, Text.c_str(), -1, &wText[0], TextSize);
                WriteFactory->CreateTextLayout(wText.c_str(), (UINT32)wText.length(), Format, Limit_X, Limit_Y, &CacheTextLayout[HashKey]);
            }
            return CacheTextLayout[HashKey];
        }
        inline bool KeyEvent(int VK_CODE, bool Release = false) noexcept//检测按键是否被按下 (后者参数为按下后是否立马释放)
        {
            if (InputState_IsSlider && Release)return false;//滑条滑动时阻止按键释放
            const bool Key_State = GetAsyncKeyState(VK_CODE) & 0x8000;
            if (Release && Key_State)//释放按键
            {
                INPUT input{};
                if (VK_CODE >= VK_LBUTTON && VK_CODE <= VK_MBUTTON) { input.type = INPUT_MOUSE; input.mi.dwFlags = (VK_CODE == VK_LBUTTON) ? MOUSEEVENTF_LEFTUP : (VK_CODE == VK_RBUTTON) ? MOUSEEVENTF_RIGHTUP : MOUSEEVENTF_MIDDLEUP; }
                else { input.type = INPUT_KEYBOARD; input.ki.wVk = (WORD)VK_CODE; input.ki.wScan = (WORD)MapVirtualKey(VK_CODE, MAPVK_VK_TO_VSC); input.ki.dwFlags = KEYEVENTF_KEYUP; }
                SendInput(1, &input, sizeof(INPUT));
            }
            return Key_State;
        }
        inline bool MouseJudgment(int X, int Y, int Width, int Height) noexcept//检测鼠标坐标是否在窗口矩形坐标内
        {
            if (InputState_ControlWindowShow)return false; Y += 2;
            return EasyGUI_MousePos.x - EasyGUI_WindowPos.left >= X && EasyGUI_MousePos.x - EasyGUI_WindowPos.left <= X + Width && EasyGUI_MousePos.y - EasyGUI_WindowPos.top >= Y && EasyGUI_MousePos.y - EasyGUI_WindowPos.top <= Y + Height;
        }
        template<class CreateClassName> inline float Animation(float Value, float Speed, long Key = 0) noexcept//快到慢动画
        {
            static unordered_map<long, double> ReturnValue{}, OldTick{}; if (!ReturnValue.count(Key))ReturnValue[Key] = Value;
            if (Speed <= 1.1f) { ReturnValue[Key] = Value; return ReturnValue[Key]; }//无动画速度时直接赋值并返回
            if (EasyGUI_Tick - OldTick[Key] > 5)//每5毫秒更新一次动画 (控制动画在极快循环速度下依然保持正常速度)
            {
                OldTick[Key] = EasyGUI_Tick;//重置时间
                if (Value > ReturnValue[Key])ReturnValue[Key] += (Value - ReturnValue[Key]) / Speed;
                else if (Value < ReturnValue[Key])ReturnValue[Key] -= (ReturnValue[Key] - Value) / Speed;
            }
            return ReturnValue[Key];
        }
    public:
        inline ID2D1RenderTarget* Render_Target() noexcept { return EasyGUI_RenderTarget; }//主窗口绘制目标
        inline void Render_Rect(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, Vector4 Color, bool Sat = true, float Radius = -1) noexcept//绘制实心矩形
        {
            if (Color.a < 3)return;
            if (Sat)Color = Color.Sat(EasyGUI_ColorSat, EasyGUI_ColorGrey);
            CacheBrush[Target]->SetColor(D2DCol(Color));
            if (Radius == -1)Radius = EasyGUI_RectRadius;
            Target->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(X, Y, X + Width, Y + Height), Radius, Radius), CacheBrush[Target]);
        }
        inline void Render_GradientRect(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, Vector4 Color_1, Vector4 Color_2, bool Direction, bool Sat = true, float Radius = -1) noexcept//绘制渐变矩形
        {
            if (Color_1.a < 3 && Color_2.a < 3)return;
            if (Sat)Color_1 = Color_1.Sat(EasyGUI_ColorSat, EasyGUI_ColorGrey), Color_2 = Color_2.Sat(EasyGUI_ColorSat, EasyGUI_ColorGrey);
            const auto GradBrush = CacheGradientBrush(Target, Color_1, Color_2);
            if (Direction) { GradBrush->SetStartPoint(D2D1::Point2F(X, Y)); GradBrush->SetEndPoint(D2D1::Point2F(X, Y + Height)); }
            else { GradBrush->SetStartPoint(D2D1::Point2F(X, Y)); GradBrush->SetEndPoint(D2D1::Point2F(X + Width, Y)); }
            if (Radius == -1)Radius = EasyGUI_RectRadius;
            Target->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(X, Y, X + Width, Y + Height), Radius, Radius), GradBrush);
        }
        inline void Render_Circle(ID2D1RenderTarget* Target, int X, int Y, float Size, Vector4 Color) noexcept//绘制实心圆
        {
            if (Color.a < 3)return;
            Color = Color.Sat(EasyGUI_ColorSat, EasyGUI_ColorGrey);
            CacheBrush[Target]->SetColor(D2DCol(Color));
            Target->FillEllipse(D2D1::Ellipse(D2D1::Point2F(X, Y), Size / 2, Size / 2), CacheBrush[Target]);
        }
        inline void Render_Line(ID2D1RenderTarget* Target, float X_1, float Y_1, float X_2, float Y_2, Vector4 Color, float StrokeWidth = 1.f, bool Sat = true) noexcept//绘制线段
        {
            if (Color.a < 3)return;
            if (Sat)Color = Color.Sat(EasyGUI_ColorSat, EasyGUI_ColorGrey);
            CacheBrush[Target]->SetColor(D2DCol(Color));
            Target->DrawLine(D2D1::Point2F(X_1, Y_1), D2D1::Point2F(X_2, Y_2), CacheBrush[Target], StrokeWidth);
        }
        inline Vector2 Render_String(ID2D1RenderTarget* Target, int X, int Y, string String, Vector4 Color, const string& FontName, float FontSize, int FontWeight = 400, Vector2 StringLimit = { 0,0 }) noexcept//绘制文字
        {
            if (String.empty() || FontSize <= 0 || Color.a < 3)return {};
            replace(String.begin(), String.end(), '\n', ' '); replace(String.begin(), String.end(), '\r', ' ');
            int CodePage = 0, NoShadow = 0;//转义符号判断变量
            if (String.find("<") != string::npos)//当有转义符号
            {
                if (String.find("<UTF>") != string::npos) { String.erase(String.find("<UTF>"), 5); CodePage = CP_UTF8; }//转换UTF-8
                if (String.find("<NOSHADOW>") != string::npos) { String.erase(String.find("<NOSHADOW>"), 10); NoShadow = true; }//无阴影
                if (String.find("<COLOR>") != string::npos) { String.erase(String.find("<COLOR>"), 7); Color = EasyGUI_Color.Alpha(Color.a); }
                else if (String.find("<RED>") != string::npos) { String.erase(String.find("<RED>"), 5); Color = { 255,0,0,Color.a }; }
                else if (String.find("<GREEN>") != string::npos) { String.erase(String.find("<GREEN>"), 7); Color = { 0,255,0,Color.a }; }
                else if (String.find("<BLUE>") != string::npos) { String.erase(String.find("<BLUE>"), 6); Color = { 0,0,255,Color.a }; }
                else if (String.find("<YELLOW>") != string::npos) { String.erase(String.find("<YELLOW>"), 8); Color = { 255,255,0,Color.a }; }
                else if (String.find("<GREY>") != string::npos) { String.erase(String.find("<GREY>"), 6); Color = { 100,100,100,Color.a }; }
                else if (String.find("<WHITE>") != string::npos) { String.erase(String.find("<WHITE>"), 7); Color = { 255,255,255,Color.a }; }
                else if (String.find("<RED_>") != string::npos) { String.erase(String.find("<RED_>"), 6); Color = { 255,150,150,Color.a }; }
                else if (String.find("<YELLOW_>") != string::npos) { String.erase(String.find("<YELLOW_>"), 9); Color = { 200,200,150,Color.a }; }
                else if (String.find("<GREEN_>") != string::npos) { String.erase(String.find("<GREEN_>"), 8); Color = { 150,255,150,Color.a }; }
                if (String.find("<DIM>") != string::npos) { String.erase(String.find("<DIM>"), 5); Color = Color * 0.75f; }
            }
            Color = Color.Sat(EasyGUI_ColorSat, EasyGUI_ColorGrey);
            const auto TextFormat = CacheWriteTextFormat(FontName, FontSize, FontWeight);
            if (!TextFormat)return {};//防止字体过小时崩溃
            TextFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);//防止自动换行
            const auto TextLayout = CacheWriteTextLayout(TextFormat, String, StringLimit.x, StringLimit.y, CodePage);
            DWRITE_TEXT_METRICS Metrics{}; TextLayout->GetMetrics(&Metrics); if (X > 10000)X -= 10000 + Metrics.width / 2; if (Y > 10000)Y -= 10000 + Metrics.height / 2;
            if (X || Y)
            {
                if (!NoShadow)
                {
                    CacheBrush[Target]->SetColor(D2DCol({ 0,0,0,Color.a }));
                    Target->DrawTextLayout(D2D1::Point2F(X + 1, Y + 1), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                }
                CacheBrush[Target]->SetColor(D2DCol(Color));
                Target->DrawTextLayout(D2D1::Point2F(X, Y), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
            }
            return { (int)Metrics.width,(int)Metrics.height };
        }
        inline Vector2 Render_MiniString(ID2D1RenderTarget* Target, int X, int Y, string String, Vector4 Color, float FontSize = 10, int FontWeight = 600, Vector2 StringLimit = { 0,0 }) noexcept//绘制简单文字
        {
            if (String.empty() || FontSize <= 0 || Color.a < 3)return {};
            if (String.find("<") != string::npos)//当有转义符号
            {
                if (String.find("<COLOR>") != string::npos) { String.erase(String.find("<COLOR>"), 7); Color = EasyGUI_Color.Alpha(Color.a); }
                else if (String.find("<RED>") != string::npos) { String.erase(String.find("<RED>"), 5); Color = { 255,0,0,Color.a }; }
                else if (String.find("<GREEN>") != string::npos) { String.erase(String.find("<GREEN>"), 7); Color = { 0,255,0,Color.a }; }
                else if (String.find("<BLUE>") != string::npos) { String.erase(String.find("<BLUE>"), 6); Color = { 0,0,255,Color.a }; }
                else if (String.find("<YELLOW>") != string::npos) { String.erase(String.find("<YELLOW>"), 8); Color = { 255,255,0,Color.a }; }
                else if (String.find("<GREY>") != string::npos) { String.erase(String.find("<GREY>"), 6); Color = { 100,100,100,Color.a }; }
                else if (String.find("<WHITE>") != string::npos) { String.erase(String.find("<WHITE>"), 7); Color = { 255,255,255,Color.a }; }
                else if (String.find("<RED_>") != string::npos) { String.erase(String.find("<RED_>"), 6); Color = { 255,150,150,Color.a }; }
                else if (String.find("<YELLOW_>") != string::npos) { String.erase(String.find("<YELLOW_>"), 9); Color = { 200,200,150,Color.a }; }
                else if (String.find("<GREEN_>") != string::npos) { String.erase(String.find("<GREEN_>"), 8); Color = { 150,255,150,Color.a }; }
                if (String.find("<DIM>") != string::npos) { String.erase(String.find("<DIM>"), 5); Color = Color * 0.75f; }
            }
            Color = Color.Sat(EasyGUI_ColorSat, EasyGUI_ColorGrey);
            const auto TextFormat = CacheWriteTextFormat("Verdana", FontSize, FontWeight);
            if (!TextFormat)return {};//防止字体过小时崩溃
            const auto TextLayout = CacheWriteTextLayout(TextFormat, String, StringLimit.x, StringLimit.y);
            DWRITE_TEXT_METRICS Metrics{}; TextLayout->GetMetrics(&Metrics); if (X > 10000)X -= 10000 + Metrics.width / 2; if (Y > 10000)Y -= 10000 + Metrics.height / 2;
            if (X || Y)
            {
                CacheBrush[Target]->SetColor(D2DCol({ 0,0,0,Color.a }));
                Target->DrawTextLayout(D2D1::Point2F(X + 1, Y + 1), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X - 1, Y - 1), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X + 1, Y - 1), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X - 1, Y + 1), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                //Target->DrawTextLayout(D2D1::Point2F(X + 1, Y), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                //Target->DrawTextLayout(D2D1::Point2F(X, Y + 1), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                //Target->DrawTextLayout(D2D1::Point2F(X - 1, Y), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                //Target->DrawTextLayout(D2D1::Point2F(X, Y - 1), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
                CacheBrush[Target]->SetColor(D2DCol(Color));
                Target->DrawTextLayout(D2D1::Point2F(X, Y), TextLayout, CacheBrush[Target], D2D1_DRAW_TEXT_OPTIONS_CLIP);
            }
            return { (int)Metrics.width,(int)Metrics.height };
        }
        //------------------------------------------------------------------------------------------------------------------------------
        EasyGUI(string WindowTitle = "EasyGUI", Vector2 WindowSize = { 0,0 }) noexcept//初始化EasyGUI
        {
            if (WindowSize.IsZero())return;//兼容无值初始化
            const auto WindowName = wstring(WindowTitle.begin(), WindowTitle.end());//窗口类名
            WNDCLASS WindowClass{}; WindowClass.lpfnWndProc = EasyGUI_WindowProcess; WindowClass.hInstance = GetModuleHandle(0); WindowClass.lpszClassName = WindowName.c_str(); RegisterClass(&WindowClass);//窗口注册类
            while (true)//防止创建失败
            {
                EasyGUI_WindowHWND = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW, WindowName.c_str(), WindowName.c_str(), WS_POPUP, GetSystemMetrics(0) / 2 - WindowSize.x / 2, GetSystemMetrics(1) / 2 - WindowSize.y / 2, WindowSize.x, WindowSize.y, 0, 0, WindowClass.hInstance, 0); if (!EasyGUI_WindowHWND)continue;
                EasyGUI_ControlWindowHWND = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW, WindowName.c_str(), WindowName.c_str(), WS_POPUP, 0, 0, 0, 0, EasyGUI_WindowHWND, 0, WindowClass.hInstance, 0);
                //---------------------------------------------------------------------------------------------------
                ShowWindow(EasyGUI_WindowHWND, SW_SHOW); SetForegroundWindow(EasyGUI_WindowHWND); UpdateWindow(EasyGUI_WindowHWND);//显示窗口
                SetLayeredWindowAttributes(EasyGUI_WindowHWND, 0, EasyGUI_Alpha, LWA_ALPHA);//设置窗口透明度
                MARGINS Margin{ -1 }; DwmExtendFrameIntoClientArea(EasyGUI_WindowHWND, &Margin); DwmExtendFrameIntoClientArea(EasyGUI_ControlWindowHWND, &Margin);//设置窗口模糊化
                //---------------------------------------------------------------------------------------------------Direct2D初始化
                CreateHWNDRenderTarget(EasyGUI_WindowHWND, WindowSize, EasyGUI_RenderTarget);
                CreateHWNDRenderTarget(EasyGUI_ControlWindowHWND, WindowSize, EasyGUI_ControlRenderTarget);
                return;
            }
        }
        inline void Draw(bool State = false) noexcept//绘制全部内容 0:开始绘制 1:结束绘制
        {
            if (!State)
            {
                MSG Message{}; while (PeekMessage(&Message, 0, 0, 0, 1)) { TranslateMessage(&Message); DispatchMessage(&Message); }//窗口消息循环
                if (GetForegroundWindow() == EasyGUI_WindowHWND && !InputState_ControlWindowShow && !InputState_IsSlider && !InputState_InBlock && KeyEvent(VK_LBUTTON))SendMessage(EasyGUI_WindowHWND, WM_NCLBUTTONDOWN, HTCAPTION, 0);//拖动窗口
                InputState_IsWindShow = GetForegroundWindow() == EasyGUI_WindowHWND, InputState_InBlock = false;//重置控件冲突判断变量
                GetCursorPos(&EasyGUI_MousePos); GetWindowRect(EasyGUI_WindowHWND, &EasyGUI_WindowPos); GetWindowRect(EasyGUI_ControlWindowHWND, &EasyGUI_ControlWindowPos);//刷新鼠标窗口坐标
                if (InputState_ControlWindowShow && !(EasyGUI_MousePos.x > EasyGUI_ControlWindowPos.left && EasyGUI_MousePos.x < EasyGUI_ControlWindowPos.right && EasyGUI_MousePos.y > EasyGUI_ControlWindowPos.top && EasyGUI_MousePos.y < EasyGUI_ControlWindowPos.bottom) && (KeyEvent(VK_LBUTTON, true) || KeyEvent(VK_RBUTTON)))InputState_ControlWindowShow = false; if (!InputState_ControlWindowShow)ShowWindow(EasyGUI_ControlWindowHWND, SW_HIDE);//保持控件窗口最前端
                EasyGUI_RenderTarget->Resize(D2D1::SizeU(EasyGUI_WindowPos.right - EasyGUI_WindowPos.left, EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top));//刷新画布大小
                EasyGUI_RenderTarget->BeginDraw(); EasyGUI_ControlRenderTarget->BeginDraw();//开始绘制
                EasyGUI_RenderTarget->Clear(D2DCol({ 0,0,0,0 })); EasyGUI_ControlRenderTarget->Clear(D2DCol({ 0,0,0,0 }));//清空绘制内容
            }
            else {
                //Render_String(EasyGUI_RenderTarget, 5, 5, "<NOSHADOW>FPS: " + to_string(EasyGUI_DrawFPS), EasyGUI_Color.Alpha(230), "Verdana", 13, 600);//绘制帧数
                EasyGUI_RenderTarget->EndDraw(); EasyGUI_ControlRenderTarget->EndDraw();//结束绘制
                EasyGUI_Tick = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now().time_since_epoch()).count();//获取当前滴答值
                EasyGUI_DrawFrame = EasyGUI_Tick - EasyGUI_DrawFrame; if (EasyGUI_DrawFrame > 0)EasyGUI_DrawFPS = 1000.f / EasyGUI_DrawFrame; EasyGUI_DrawFrame = EasyGUI_Tick;//计算绘制帧率
                KeyEvent(VK_UP, true); KeyEvent(VK_DOWN, true);//释放滚轮按键消息
                if (!InputState_IsSlider || !InputState_IsWindShow) { timeBeginPeriod(1); Sleep(4); timeEndPeriod(1); }//降低硬件占用
            }
        }
        inline void Release() noexcept//释放全部资源
        {
            SafeRelease(EasyGUI_RenderTarget); SafeRelease(EasyGUI_ControlRenderTarget);
            DestroyWindow(EasyGUI_WindowHWND); DestroyWindow(EasyGUI_ControlWindowHWND);
            EasyGUI_WindowHWND = 0; EasyGUI_ControlWindowHWND = 0;
        }
        //------------------------------------------------------------------------------------------------------------------------------
        inline string Style_GetFont() noexcept { return EasyGUI_Font; }//获取全局字体
        inline void Style_SetFont(string FontName) noexcept { if (FontName.empty())EasyGUI_Font = "Verdana"; else EasyGUI_Font = FontName; }//设置全局字体
        inline float Style_GetFontSize() noexcept { return EasyGUI_FontSize; }//获取全局字体大小
        inline void Style_SetFontSize(float FontSize) noexcept { if (!FontSize)EasyGUI_FontSize = 12; else EasyGUI_FontSize = FontSize; }//设置全局字体大小
        inline Vector4 Style_GetColor() noexcept { return EasyGUI_Color; }//获取全局主题颜色
        inline void Style_SetColor(Vector4 MainColor) noexcept { EasyGUI_Color = MainColor.Alpha(255); }//设置全局主题颜色
        inline float Style_GetAnimationSmooth() noexcept { return EasyGUI_AnimationSmooth; }//获取全局控件动画速度
        inline void Style_SetAnimationSmooth(float AnimationSpeed) noexcept { if (AnimationSpeed <= 0.1f)AnimationSpeed = 0.1f; EasyGUI_AnimationSmooth = AnimationSpeed; }//设置全局控件动画速度
        inline float Style_GetRectRadius() noexcept { return EasyGUI_RectRadius; }//获取全局矩形圆角
        inline void Style_SetRectRadius(float Radius) noexcept { if (Radius < 0)Radius = 0; EasyGUI_RectRadius = Radius; }//设置全局矩形圆角
        inline void Style_SetColorHue(float Sat = -1, float Grey = -1) noexcept { if (Sat >= 0)EasyGUI_ColorSat = Sat; if (Grey >= 0)EasyGUI_ColorGrey = Grey; }//设置全局主题色调
        //------------------------------------------------------------------------------------------------------------------------------
        inline HWND Window_HWND() noexcept { return EasyGUI_WindowHWND; }//获取窗口HWND
        inline Vector2 Window_GetPos() noexcept//获取窗口坐标
        {
            RECT WindowRect{}; GetWindowRect(EasyGUI_WindowHWND, &WindowRect);
            return { WindowRect.left ,WindowRect.top };
        }
        inline void Window_SetPos(Vector2 WindowPos) noexcept//修改窗口坐标
        {
            RECT WindowRect{}; GetWindowRect(EasyGUI_WindowHWND, &WindowRect);
            MoveWindow(EasyGUI_WindowHWND, WindowPos.x, WindowPos.y, WindowRect.right - WindowRect.left, WindowRect.bottom - WindowRect.top, true);
        }
        inline Vector2 Window_GetSize() noexcept//获取窗口大小
        {
            RECT WindowRect{}; GetWindowRect(EasyGUI_WindowHWND, &WindowRect);
            return { WindowRect.right - WindowRect.left ,WindowRect.bottom - WindowRect.top };
        }
        inline void Window_SetSize(Vector2 WindowSize) noexcept//修改窗口大小
        {
            RECT WindowRect{}; GetWindowRect(EasyGUI_WindowHWND, &WindowRect);
            MoveWindow(EasyGUI_WindowHWND, WindowRect.left, WindowRect.top, WindowSize.x, WindowSize.y, true);
        }
        inline int Window_GetAlpha() noexcept { return EasyGUI_Alpha; }//获取窗口透明度
        inline void Window_SetAlpha(int WindowAlpha) noexcept//修改窗口透明度
        {
            if (WindowAlpha < 10)WindowAlpha = 10; else if (WindowAlpha > 255)WindowAlpha = 255;
            if (EasyGUI_Alpha == WindowAlpha)return; EasyGUI_Alpha = WindowAlpha;
            SetLayeredWindowAttributes(EasyGUI_WindowHWND, 0, WindowAlpha, LWA_ALPHA);
        }
        inline void Window_Show() noexcept//修改窗口为最前端
        {
            SetForegroundWindow(EasyGUI_WindowHWND);
            ShowWindow(EasyGUI_WindowHWND, SW_SHOW);
        }
        inline void Window_Hide() noexcept//隐藏窗口
        {
            ShowWindow(EasyGUI_WindowHWND, SW_HIDE);
            ShowWindow(EasyGUI_ControlWindowHWND, SW_HIDE);
            InputState_ControlWindowShow = false;
        }
        inline bool Window_IsShow() noexcept//获取窗口是否最前端
        {
            return GetForegroundWindow() == EasyGUI_WindowHWND;
        }
        inline string Window_GetTitle() noexcept//获取窗口标题
        {
            CHAR pszMem[1024]{}; GetWindowTextA(EasyGUI_WindowHWND, pszMem, GetWindowTextLength(EasyGUI_WindowHWND) + 1); return pszMem;
        }
        inline void Window_SetTitle(string WindowTitle) noexcept//修改窗口标题
        {
            SetWindowTextA(EasyGUI_WindowHWND, WindowTitle.c_str());
        }
        inline float Window_DrawFPS() noexcept { return (float)EasyGUI_DrawFPS; }//获取窗口绘制帧数
        //------------------------------------------------------------------------------------------------------------------------------
        inline void GUI_BackGround(int StyleCode = 2, bool ParticleEffect = false, string Mark = "") noexcept//背景
        {
            const Vector2 Window_Size = { EasyGUI_WindowPos.right - EasyGUI_WindowPos.left ,EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top };
            vector<int> LineColor = { 0,255,255,255,0,255,255,255,0 }, StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,5,5,5,30,30,30 };
            if (StyleCode == 0)//默认
            {
                LineColor = { 16,16,16,16,16,16,16,16,16 };
                StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,15,15,15,EasyGUI_Color.r / 10,EasyGUI_Color.g / 10,EasyGUI_Color.b / 10 };
            }
            else if (StyleCode == 1)//彩虹色
            {
                static const auto AnimaSpeed = 3000.f;//渐变条变化速度
                LineColor = {
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 3) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 5) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 7) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 2) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 4) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 6) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 1) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 3) * 127 + 128),
                    (int)floor(sin(EasyGUI_Tick / AnimaSpeed * 2 + 5) * 127 + 128),
                };
                StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,3,3,3,EasyGUI_Color.r / 10,EasyGUI_Color.g / 10,EasyGUI_Color.b / 10 };
                EasyGUI_Color = { LineColor[3],LineColor[4], LineColor[5] };
            }
            else if (StyleCode == 2)//主题色
            {
                static const auto AnimaSpeed = 600.f;//渐变条变化速度
                const Vector3 Sins = { (float)sin(EasyGUI_Tick / AnimaSpeed), (float)sin(EasyGUI_Tick / AnimaSpeed + 1), (float)sin(EasyGUI_Tick / AnimaSpeed + 2) };
                LineColor = {
                    (int)(Sins.z * EasyGUI_Color.r / 2 + EasyGUI_Color.r / 2),
                    (int)(Sins.z * EasyGUI_Color.g / 2 + EasyGUI_Color.g / 2),
                    (int)(Sins.z * EasyGUI_Color.b / 2 + EasyGUI_Color.b / 2),
                    (int)(Sins.y * EasyGUI_Color.r / 2 + EasyGUI_Color.r / 2),
                    (int)(Sins.y * EasyGUI_Color.g / 2 + EasyGUI_Color.g / 2),
                    (int)(Sins.y * EasyGUI_Color.b / 2 + EasyGUI_Color.b / 2),
                    (int)(Sins.x * EasyGUI_Color.r / 2 + EasyGUI_Color.r / 2),
                    (int)(Sins.x * EasyGUI_Color.g / 2 + EasyGUI_Color.g / 2),
                    (int)(Sins.x * EasyGUI_Color.b / 2 + EasyGUI_Color.b / 2)
                };
                for (int i = 0; i <= 8; ++i)if (LineColor[i] < 40)LineColor[i] = 40;//颜色最小值
                StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,0,0,0,EasyGUI_Color.r / 10,EasyGUI_Color.g / 10,EasyGUI_Color.b / 10 };
            }
            Render_Rect(EasyGUI_RenderTarget, 0, 0, Window_Size.x, Window_Size.y, { StyleColor[0], StyleColor[1], StyleColor[2] });
            Render_Rect(EasyGUI_RenderTarget, 1, 1, Window_Size.x - 2, Window_Size.y - 2, { StyleColor[3], StyleColor[4], StyleColor[5] });
            Render_Rect(EasyGUI_RenderTarget, 2, 2, Window_Size.x - 4, Window_Size.y - 4, { StyleColor[6], StyleColor[7], StyleColor[8] });
            Render_Rect(EasyGUI_RenderTarget, 5, 5, Window_Size.x - 10, Window_Size.y - 10, { StyleColor[3], StyleColor[4], StyleColor[5] });
            Render_GradientRect(EasyGUI_RenderTarget, 6, 6, Window_Size.x - 12, Window_Size.y - 12, { StyleColor[12], StyleColor[13], StyleColor[14] }, { StyleColor[15], StyleColor[16], StyleColor[17] }, true);
            if (ParticleEffect)//星空粒子特效
            {
                const auto MaxYSize = GetSystemMetrics(1);
                for (int i = 0; i <= 150; ++i)//背景粒子
                {
                    const auto Base_X = (i * 37 % 1000) / 1000.f * Window_Size.x, Base_Y = (i * 73 % 1000) / 1000.f * MaxYSize, MoveSpeed = float(0.01f + float((i * 13) % 10) / 100);
                    float MovingPos = fmodf(Base_Y - MoveSpeed * EasyGUI_Tick, MaxYSize); if (MovingPos < 0)MovingPos += MaxYSize;
                    if (MovingPos > 10)Render_Circle(EasyGUI_RenderTarget, Base_X, MovingPos, MoveSpeed * 40, EasyGUI_Color.Alpha((0.5f + 0.5f * sinf(i * 0.1f + EasyGUI_Tick * 0.005f)) * 255));
                }
            }
            if (StyleCode)//渐变条
            {
                Render_GradientRect(EasyGUI_RenderTarget, 7, 7, (Window_Size.x - 14) / 2 + 3, 2, { LineColor[0] / 2, LineColor[1] / 2, LineColor[2] / 2 }, { LineColor[3] / 2, LineColor[4] / 2, LineColor[5] / 2 }, false);
                Render_GradientRect(EasyGUI_RenderTarget, 7 + (Window_Size.x - 14) / 2, 7, (Window_Size.x - 14) / 2, 2, { LineColor[3] / 2, LineColor[4] / 2, LineColor[5] / 2 }, { LineColor[6] / 2, LineColor[7] / 2, LineColor[8] / 2 }, false);
                Render_GradientRect(EasyGUI_RenderTarget, 7, 7, (Window_Size.x - 14) / 2 + 3, 1, { LineColor[0], LineColor[1], LineColor[2] }, { LineColor[3], LineColor[4], LineColor[5] }, false);
                Render_GradientRect(EasyGUI_RenderTarget, 7 + (Window_Size.x - 14) / 2, 7, (Window_Size.x - 14) / 2, 1, { LineColor[3], LineColor[4], LineColor[5] }, { LineColor[6], LineColor[7], LineColor[8] }, false);
            }
            if (!Mark.empty())//水印
            {
                const auto TextSize = Render_String(EasyGUI_RenderTarget, 0, 0, Mark, {}, EasyGUI_Font, EasyGUI_FontSize - 2, 600);//获取文字大小
                Render_String(EasyGUI_RenderTarget, Window_Size.x - 10 - TextSize.x, Window_Size.y - 10 - TextSize.y, Mark, EasyGUI_Color.Alpha(80), EasyGUI_Font, EasyGUI_FontSize - 2, 600);
            }
        }
        inline void GUI_Block(EasyGUI_Block& Block, int X, int Y, int Width, int Height, const string& BlockTitle) noexcept//区块
        {
            if (Width < 300)Width = 300; else if (Width > 800)Width = 800;//宽度限制
            static int BlockID = 0; if (!Block.ID) { BlockID += 1337; Block.ID = BlockID; }//分配ID
            if (Block.Target)Block.Target->EndDraw();//结束绘制
            Block.Title = BlockTitle; Block.Pos = { X,Y }; Block.Size = { Width,Height }; Block.IsInBlock = MouseJudgment(X, Y, Width, Height); if (Block.IsInBlock)InputState_InBlock = true;
            if (InputState_IsWindShow && Block.IsInBlock && !InputState_ControlWindowShow && !Block.IsInScrollArea)//滚轮滚动
            {
                if (KeyEvent(VK_UP, true))Block.Start -= 50; else if (Block.Line > Height && KeyEvent(VK_DOWN, true))Block.Start += 50;//滚轮按键判定与滚动幅度
                if (Block.Start < 0)Block.Start = 0; else if (Block.Line > Height && Block.Start > Block.Line - Height)Block.Start = Block.Line - Height;//限制滚动区域
            }
            int ScrollBar = 0; if (Block.Line > Height)ScrollBar = Block.Line;//右侧滚动条绘制判断
            Block.IsInScrollArea = false; Block.Line = 30; Block.Offset = 0; Block.Target = CreateBitmapRenderTarget(EasyGUI_RenderTarget, { Width,Height * 10 }, Block.ID);//创建区块渲染目标
            Render_Rect(EasyGUI_RenderTarget, X, Y, Width, Height, { 0,0,0 });//黑色外边框
            Render_Rect(EasyGUI_RenderTarget, X + 1, Y + 1, Width - 2, Height - 2, { 60,60,60 });//白色外边框
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 2, Width - 4, Height - 4, { 10,10,10 }, EasyGUI_Color / 10, true);//渐变背景
            if (BlockTitle != "")
            {
                const auto TextSize = Render_String(EasyGUI_RenderTarget, 0, 0, BlockTitle, {}, EasyGUI_Font, EasyGUI_FontSize + 1, 600).x + 1;//获取文字大小
                Render_GradientRect(EasyGUI_RenderTarget, X + TextSize + 15, Y + 1, Width - TextSize - 18, 1, { 20,20,20 }, { 60,60,60 }, false);//渐变头条
                Render_Rect(EasyGUI_RenderTarget, X + 15, Y, TextSize + 10, 3, { 10,10,10 });//文字后遮挡边框
            }
            Y += 2; Height -= 4;
            const auto PaintStartPos = Animation<class EasyGUI_Block_ScroolAni>(Block.Start, EasyGUI_AnimationSmooth * 0.7f, Block.ID);//滑动动画
            ID2D1Bitmap* BitMap{}; Block.Target->GetBitmap(&BitMap); EasyGUI_RenderTarget->DrawBitmap(BitMap, D2D1::RectF(X, Y, X + Width, Y + Height), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, D2D1::RectF(0, PaintStartPos, Width, PaintStartPos + Height)); SafeRelease(BitMap);
            Block.Target->BeginDraw(); Block.Target->Clear(D2DCol({ 0,0,0,0 }));
            Y -= 2; Height += 4;
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 2, Width - 4, 20, { 10,10,10,200 }, { 10,10,10,0 }, true);//顶部遮罩
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + Height - 20 - 2, Width - 4, 20, EasyGUI_Color.Alpha(0) / 10, EasyGUI_Color.Alpha(200) / 10, true);//底部遮罩
            if (ScrollBar)//只有内容超出高度时绘制滚动条
            {
                Render_GradientRect(EasyGUI_RenderTarget, X + Width - 4, Y + 3, 1, Height - 6, EasyGUI_Color / 10, { 10,10,10 }, true);//背景轨道
                Render_GradientRect(EasyGUI_RenderTarget, X + Width - 4, Y + 3 + PaintStartPos / (float)ScrollBar * (Height - 6), 1, (float)Height / (float)ScrollBar * (Height - 6) + 1, EasyGUI_Color / 2, EasyGUI_Color / 4, true);//绘制滑块
            }
            Render_String(EasyGUI_RenderTarget, X + 20, 10000 + Y, BlockTitle, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize + 1, 600);
        }
        inline void GUI_RadioBlock(int X, int Y, int Width, int Height, const string& BlockTitle, const vector<string>& BlockText, int& BlockPage) noexcept//区块_大区块选择器
        {
            if (BlockPage < 0)BlockPage = 0; else if (BlockPage >= BlockText.size())BlockPage = BlockText.size() - 1;//范围限制
            if (MouseJudgment(X, Y, Width, Height))InputState_InBlock = true;//鼠标在区块内
            Render_Rect(EasyGUI_RenderTarget, X, Y, Width, Height, { 0,0,0 });//黑色外边框
            Render_Rect(EasyGUI_RenderTarget, X + 1, Y + 1, Width - 2, Height - 2, { 60,60,60 });//白色外边框
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 2, Width - 4, Height - 4, EasyGUI_Color / 10, { 10,10,10 }, true);//主题色渐变背景
            if (BlockTitle != "")
            {
                const auto TextSize = Render_String(EasyGUI_RenderTarget, 0, 0, BlockTitle, { 0,0,0 }, EasyGUI_Font, EasyGUI_FontSize + 1, 600).x + 1;//获取文字大小
                Render_GradientRect(EasyGUI_RenderTarget, X + TextSize + 10, Y + 1, Width - TextSize - 16, 1, { 20,20,20 }, { 60,60,60 }, false);//渐变头条
                Render_Rect(EasyGUI_RenderTarget, X + 10, Y, TextSize + 10, 3, EasyGUI_Color / 10);//文字后遮挡边框
            }
            Render_String(EasyGUI_RenderTarget, X + 15, 10000 + Y, BlockTitle, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize + 1, 600);
            for (int i = 0; i < BlockText.size(); ++i)//遍历坐标
            {
                const auto DetectMousePos = MouseJudgment(X, Y + 14 + 30 * i, Width, 23);
                if (InputState_IsWindShow && DetectMousePos && BlockPage != i && KeyEvent(VK_LBUTTON, true))BlockPage = i;//鼠标赋值选择
                int SelectAlpha = 0; if (BlockPage == i)SelectAlpha = 255; else if (DetectMousePos)SelectAlpha = 100;
                const auto SelectAniAlpha = Animation<class EasyGUI_RadioBlock_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth * 1.2f, i);
                Render_Rect(EasyGUI_RenderTarget, X + 2, Y + 16 + 30 * i, Width - 4, 23 + 1, EasyGUI_Color.Alpha(SelectAniAlpha) / 4);
                Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 16 + 30 * i, Width - 4, 23, EasyGUI_Color.Alpha(SelectAniAlpha) / 4, Vector4{ 20,20,20 }.Alpha(SelectAniAlpha), true);
                if (BlockPage == i)Render_String(EasyGUI_RenderTarget, 10000 + X + Width / 2, 10000 + Y + 28 + 30 * i, BlockText[i], EasyGUI_Color.Min_Bri(180).Max_Bri(220), EasyGUI_Font, EasyGUI_FontSize + 2, 600);
                else Render_String(EasyGUI_RenderTarget, 10000 + X + Width / 2, 10000 + Y + 28 + 30 * i, BlockText[i], EasyGUI_Color.Min_Bri(180).Max_Bri(220) / 2, EasyGUI_Font, EasyGUI_FontSize + 2, 600);
            }
        }
        inline int GUI_Text(EasyGUI_Block& Block, const string& Text) noexcept//行文字
        {
            //Render_Rect(Block.Target, 0, Block.Line, 9999, 1, { 255,0,0 });//Debug
            const auto ReturnValue = Render_String(Block.Target, 45 + Block.Offset, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize); Block.Line += 25; return ReturnValue.x;
        }
        inline void GUI_Line(EasyGUI_Block& Block, int Y_Offset = 0) noexcept//分割线
        {
            Render_Rect(Block.Target, 25, Block.Line + Y_Offset, Block.Size.x - 50, 1, { 60,60,60 }); Block.Line += 20;
        }
        inline void GUI_Checkbox(EasyGUI_Block& Block, const string& Text, bool& CheckboxValue) noexcept//单选框
        {
            const Vector2 CheckBoxPos = { 25 + Block.Offset, Block.Line - 6 }, CheckBoxSize = { 12,12 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + CheckBoxPos.x, Block.Pos.y - Block.Start + CheckBoxPos.y, Render_String(Block.Target, 0, 0, Text, {}, EasyGUI_Font, EasyGUI_FontSize).x + CheckBoxSize.x + 15, CheckBoxSize.y);//窗口检测
            if (InputState_IsWindShow && Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true))CheckboxValue = !CheckboxValue;//当最前端窗口为GUI窗口接收按钮事件
            Render_Rect(Block.Target, CheckBoxPos.x, CheckBoxPos.y, CheckBoxSize.x, CheckBoxSize.y, { 0,0,0 });
            Render_GradientRect(Block.Target, CheckBoxPos.x + 1, CheckBoxPos.y + 1, CheckBoxSize.x - 2, CheckBoxSize.y - 2, EasyGUI_Color / Animation<class EasyGUI_Checkbox_DetMouAni>(DetectMousePos ? 3 : 4, EasyGUI_AnimationSmooth, Block.ID + Block.Line), { 25,25,25 }, true);
            const auto SelectAlpha = Animation<class EasyGUI_Checkbox_SelectAni>(CheckboxValue ? 255 : 0, EasyGUI_AnimationSmooth, Block.ID + Block.Line);
            Render_GradientRect(Block.Target, CheckBoxPos.x + 1, CheckBoxPos.y + 1, CheckBoxSize.x - 2, CheckBoxSize.y - 2, EasyGUI_Color.Alpha(SelectAlpha), (EasyGUI_Color / 5).Alpha(SelectAlpha), true);
            Render_String(Block.Target, CheckBoxPos.x + 20, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
            Block.Line += 25;
        }
        inline bool GUI_Button(EasyGUI_Block& Block, const string& Text) noexcept//单击按钮
        {
            Block.Line += 3;
            const Vector2 ButtonPos = { 45 + Block.Offset,Block.Line - 15 }, ButtonSize = { (int)(Block.Size.x / 1.5), 28 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            const auto IsPressed = InputState_IsWindShow && Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true);//是否按下按钮
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / Animation<class EasyGUI_Button_DetMouAni>(DetectMousePos ? 6 : 8, EasyGUI_AnimationSmooth, Block.ID + Block.Line), { 20,20,20 }, true);
            Render_Rect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color.Alpha(Animation<class EasyGUI_Button_PressEffAni>(IsPressed ? 40 : 0, IsPressed ? 0 : EasyGUI_AnimationSmooth * 1.5f, Block.ID + Block.Line)));//按下动画
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, Text, { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            Block.Line += 26;
            return IsPressed;
        }
        inline bool GUI_LongPressButton(EasyGUI_Block& Block, const string& Text) noexcept//长按按钮
        {
            Block.Line += 3;
            const Vector2 ButtonPos = { 45 + Block.Offset,Block.Line - 15 }, ButtonSize = { (int)(Block.Size.x / 1.5), 28 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            static unordered_map<long, float> PressTime{}; bool IsPressed = false;//防止多函数冲突
            if (InputState_IsWindShow && Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON))
            {
                PressTime[Block.ID + Block.Line] += 1.f / EasyGUI_DrawFPS * 1.4f;//计时器增加速度
                if (PressTime[Block.ID + Block.Line] >= 1) { PressTime[Block.ID + Block.Line] = 1; KeyEvent(VK_LBUTTON, true); IsPressed = true; }
            }
            else PressTime[Block.ID + Block.Line] = 0;//重置计时器
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / Animation<class EasyGUI_LongPressButton_DetMouAni>(DetectMousePos ? 6 : 8, EasyGUI_AnimationSmooth, Block.ID + Block.Line), { 20,20,20 }, true);
            Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, (ButtonSize.x - 4) * PressTime[Block.ID + Block.Line], ButtonSize.y - 4, { 0,0,0,0 }, EasyGUI_Color / 1.5, false);//触发进度条
            Render_Rect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color.Alpha(Animation<class EasyGUI_LongPressButton_PressEffAni>(IsPressed ? 40 : 0, IsPressed ? 0 : EasyGUI_AnimationSmooth * 1.5f, Block.ID + Block.Line)));//按下动画
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, "*" + Text + "*", { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            Block.Line += 26;
            return IsPressed;
        }
        inline bool GUI_MiniButton(EasyGUI_Block& Block, const string& Text = "...") noexcept//单击按钮(小号)
        {
            const Vector2 ButtonPos = { 5 + Block.Offset,Block.Line - 10 }, ButtonSize = { 15, 20 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            const auto IsPressed = InputState_IsWindShow && Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true);//是否按下按钮
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / Animation<class EasyGUI_MiniButton_DetMouAni>(DetectMousePos ? 6 : 8, EasyGUI_AnimationSmooth, Block.ID + Block.Line), { 20,20,20 }, true);
            Render_Rect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color.Alpha(Animation<class EasyGUI_MiniButton_PressEffAni>(IsPressed ? 40 : 0, IsPressed ? 0 : EasyGUI_AnimationSmooth * 1.5f, Block.ID + Block.Line)));//按下动画
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2 + 1, 10000 + Block.Line, Text, { 180,180,180 }, EasyGUI_Font, EasyGUI_FontSize - 3);
            return IsPressed;
        }
        template<class ValueClass> inline void GUI_Slider(EasyGUI_Block& Block, const string& Text, const ValueClass& StartValue, const ValueClass& EndValue, ValueClass& SliderValue, string Unit = "") noexcept//滑条
        {
            const Vector2 NormalSliderPos = { 45 + Block.Offset,Block.Line + 2 }, NormalSliderSize = { (int)(Block.Size.x / 1.5),9 };//滑条坐标,滑条大小
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + NormalSliderPos.x, Block.Pos.y - Block.Start + NormalSliderPos.y, NormalSliderSize.x, NormalSliderSize.y);//窗口检测
            static unordered_map<long, bool> OutSide{};//防止指针脱落时失去控制力
            if (InputState_IsWindShow)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (DetectMousePos && Block.IsInBlock)//当鼠标移动到滑条上方 按键反馈事件
                {
                    if (KeyEvent(VK_LEFT, true) || KeyEvent(VK_UP, true)) { if ((ValueClass)0.1 == 0)SliderValue--; else SliderValue -= 0.05; }//检测是否是浮点值
                    else if (KeyEvent(VK_RIGHT, true) || KeyEvent(VK_DOWN, true)) { if ((ValueClass)0.1 == 0)SliderValue++; else SliderValue += 0.05; }
                    if (KeyEvent(VK_LBUTTON) && !OutSide[Block.ID + Block.Line])OutSide[Block.ID + Block.Line] = true;
                    Block.IsInScrollArea = true;//禁止区块滑动
                }
                if (OutSide[Block.ID + Block.Line] && KeyEvent(VK_LBUTTON)) { SliderValue = ((EasyGUI_MousePos.x - Block.Pos.x - EasyGUI_WindowPos.left - NormalSliderPos.x) * (EndValue - StartValue) / NormalSliderSize.x) + StartValue; InputState_IsSlider = true; }
                else if (!KeyEvent(VK_LBUTTON)) { OutSide[Block.ID + Block.Line] = false; InputState_IsSlider = false; }
                if (SliderValue < StartValue)SliderValue = StartValue; else if (SliderValue > EndValue)SliderValue = EndValue;//值范围限制
            }
            int SliderSize = (float)(SliderValue - StartValue) / (float)(EndValue - StartValue) * NormalSliderSize.x; if (SliderSize < 0)SliderSize = 0; else if (SliderSize > NormalSliderSize.x - 2)SliderSize = NormalSliderSize.x - 2;//滑条长度计算
            const int SliderAni = Animation<class EasyGUI_Slider_SizeAni>(SliderSize, EasyGUI_AnimationSmooth * 0.7, Block.ID + Block.Line);//滑条动画
            std::stringstream FloatPre{}; FloatPre << std::fixed << std::setprecision(3) << SliderValue;//保留小数点后数
            if (Unit != "")//数值单位
            {
                if (Unit.find("%delete") != string::npos)Unit.erase(Unit.find("%delete"), ((string)"%delete").length());//删除掉全部字符串
                else if (Unit.find("%string") != string::npos)Unit.replace(Unit.find("%string"), ((string)"%string").length(), FloatPre.str());//替换掉原本字符串
                else Unit = FloatPre.str() + Unit;//不存在特殊字符串时
            }
            else Unit = FloatPre.str();
            Render_String(Block.Target, NormalSliderPos.x, 10000 + NormalSliderPos.y - 8, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
            Render_Rect(Block.Target, NormalSliderPos.x, NormalSliderPos.y, NormalSliderSize.x, NormalSliderSize.y, { 0,0,0 });//黑色外边框
            Render_GradientRect(Block.Target, NormalSliderPos.x + 1, NormalSliderPos.y + 1, NormalSliderSize.x - 2, NormalSliderSize.y - 2, { 25,25,25 }, EasyGUI_Color / Animation<class EasyGUI_Slider_DetMouAni>((DetectMousePos || OutSide[Block.ID + Block.Line]) ? 5 : 6, EasyGUI_AnimationSmooth, Block.ID + Block.Line), true);//滑条背景
            Render_GradientRect(Block.Target, NormalSliderPos.x + 1, NormalSliderPos.y + 1, SliderAni, NormalSliderSize.y - 2, EasyGUI_Color, EasyGUI_Color / 4, true);//滑条
            Render_MiniString(Block.Target, 10000 + NormalSliderPos.x + SliderAni, NormalSliderPos.y + 1, Unit + "<DIM>", { 200,200,200 });//居中返回值绘制
            Block.Line += 30;
        }
        inline void GUI_KeySelector(EasyGUI_Block& Block, int& KeySelectValue, int Offset = 0, const string& DefaultText = "-") noexcept//按键选取按钮
        {
            if (KeySelectValue >= 0xCCCCCCCC)KeySelectValue = 0;//修复过量
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + Block.Size.x - Offset - 50, Block.Pos.y - Block.Start + Block.Line - 6, 30, 12);//鼠标坐标检测
            static unordered_map<long, bool> BoxMea{};//只声明一次初始开关设定变量
            if (InputState_IsWindShow)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (DetectMousePos && Block.IsInBlock)EasyGUI_MouseIcon = IDC_HAND;//手型鼠标图标
                if (!BoxMea[Block.ID + Block.Line + Offset * 10000] && DetectMousePos && Block.IsInBlock && KeyEvent(VK_LBUTTON, true))BoxMea[Block.ID + Block.Line + Offset * 10000] = true;
                else if (BoxMea[Block.ID + Block.Line + Offset * 10000])
                {
                    if (KeyEvent(VK_ESCAPE, true)) { KeySelectValue = 0; BoxMea[Block.ID + Block.Line + Offset * 10000] = false; }//默认无值
                    for (int i = 0x0; i < 0xFE; ++i)if (KeyEvent(i, true)) { KeySelectValue = i; BoxMea[Block.ID + Block.Line + Offset * 10000] = false; }//当按下任意键
                    Block.IsInScrollArea = true;//禁止区块滑动
                }
            }
            if (!BoxMea[Block.ID + Block.Line + Offset * 10000])
            {
                string DrawString_VK = "";
                switch (KeySelectValue)
                {
                case 0x00: DrawString_VK = DefaultText; break;
                case 0x01: DrawString_VK = "M1"; break;
                case 0x02: DrawString_VK = "M2"; break;
                case 0x03: DrawString_VK = "CAN"; break;
                case 0x04: DrawString_VK = "M3"; break;
                case 0x05: DrawString_VK = "M4"; break;
                case 0x06: DrawString_VK = "M5"; break;
                case 0x07: DrawString_VK = "NON"; break;
                case 0x08: DrawString_VK = "BAK"; break;
                case 0x09: DrawString_VK = "TAB"; break;
                case 0x0C: DrawString_VK = "CLE"; break;
                case 0x0D: DrawString_VK = "ENT"; break;
                case 0x10: DrawString_VK = "SHF"; break;
                case 0x11: DrawString_VK = "CLR"; break;
                case 0x12: DrawString_VK = "ALT"; break;
                case 0x13: DrawString_VK = "PAU"; break;
                case 0x14: DrawString_VK = "CAP"; break;
                case 0x15: DrawString_VK = "KAN"; break;
                case 0x16: DrawString_VK = "KAN"; break;
                case 0x17: DrawString_VK = "JUN"; break;
                case 0x18: DrawString_VK = "FIN"; break;
                case 0x19: DrawString_VK = "HAN"; break;
                case 0x1B: DrawString_VK = "ESC"; break;
                case 0x1C: DrawString_VK = "CON"; break;
                case 0x1D: DrawString_VK = "NON"; break;
                case 0x1E: DrawString_VK = "ACC"; break;
                case 0x1F: DrawString_VK = "MOD"; break;
                case 0x20: DrawString_VK = "SPA"; break;
                case 0x21: DrawString_VK = "PRI"; break;
                case 0x22: DrawString_VK = "NEX"; break;
                case 0x23: DrawString_VK = "END"; break;
                case 0x24: DrawString_VK = "HOM"; break;
                case 0x25: DrawString_VK = "LEF"; break;
                case 0x26: DrawString_VK = "UP"; break;
                case 0x27: DrawString_VK = "RIG"; break;
                case 0x28: DrawString_VK = "DN"; break;
                case 0x29: DrawString_VK = "SEL"; break;
                case 0x2A: DrawString_VK = "PRI"; break;
                case 0x2B: DrawString_VK = "EXE"; break;
                case 0x2C: DrawString_VK = "SNA"; break;
                case 0x2D: DrawString_VK = "INS"; break;
                case 0x2E: DrawString_VK = "DEL"; break;
                case 0x2F: DrawString_VK = "HEL"; break;
                case 0x30: DrawString_VK = "0"; break;
                case 0x31: DrawString_VK = "1"; break;
                case 0x32: DrawString_VK = "2"; break;
                case 0x33: DrawString_VK = "3"; break;
                case 0x34: DrawString_VK = "4"; break;
                case 0x35: DrawString_VK = "5"; break;
                case 0x36: DrawString_VK = "6"; break;
                case 0x37: DrawString_VK = "7"; break;
                case 0x38: DrawString_VK = "8"; break;
                case 0x39: DrawString_VK = "9"; break;
                case 0x41: DrawString_VK = "A"; break;
                case 0x42: DrawString_VK = "B"; break;
                case 0x43: DrawString_VK = "C"; break;
                case 0x44: DrawString_VK = "D"; break;
                case 0x45: DrawString_VK = "E"; break;
                case 0x46: DrawString_VK = "F"; break;
                case 0x47: DrawString_VK = "G"; break;
                case 0x48: DrawString_VK = "H"; break;
                case 0x49: DrawString_VK = "I"; break;
                case 0x4A: DrawString_VK = "J"; break;
                case 0x4B: DrawString_VK = "K"; break;
                case 0x4C: DrawString_VK = "L"; break;
                case 0x4D: DrawString_VK = "M"; break;
                case 0x4E: DrawString_VK = "N"; break;
                case 0x4F: DrawString_VK = "O"; break;
                case 0x50: DrawString_VK = "P"; break;
                case 0x51: DrawString_VK = "Q"; break;
                case 0x52: DrawString_VK = "R"; break;
                case 0x53: DrawString_VK = "S"; break;
                case 0x54: DrawString_VK = "T"; break;
                case 0x55: DrawString_VK = "U"; break;
                case 0x56: DrawString_VK = "V"; break;
                case 0x57: DrawString_VK = "W"; break;
                case 0x58: DrawString_VK = "X"; break;
                case 0x59: DrawString_VK = "Y"; break;
                case 0x5A: DrawString_VK = "Z"; break;
                case 0x5B: DrawString_VK = "WIN"; break;
                case 0x5C: DrawString_VK = "WIN"; break;
                case 0x5D: DrawString_VK = "APP"; break;
                case 0x5F: DrawString_VK = "SLP"; break;
                case 0x60: DrawString_VK = "0"; break;
                case 0x61: DrawString_VK = "1"; break;
                case 0x62: DrawString_VK = "2"; break;
                case 0x63: DrawString_VK = "3"; break;
                case 0x64: DrawString_VK = "4"; break;
                case 0x65: DrawString_VK = "5"; break;
                case 0x66: DrawString_VK = "6"; break;
                case 0x67: DrawString_VK = "7"; break;
                case 0x68: DrawString_VK = "8"; break;
                case 0x69: DrawString_VK = "9"; break;
                case 0x6A: DrawString_VK = "*"; break;
                case 0x6B: DrawString_VK = "+"; break;
                case 0x6C: DrawString_VK = "SEP"; break;
                case 0x6D: DrawString_VK = "-"; break;
                case 0x6E: DrawString_VK = "."; break;
                case 0x6F: DrawString_VK = "/"; break;
                case 0x70: DrawString_VK = "F1"; break;
                case 0x71: DrawString_VK = "F2"; break;
                case 0x72: DrawString_VK = "F3"; break;
                case 0x73: DrawString_VK = "F4"; break;
                case 0x74: DrawString_VK = "F5"; break;
                case 0x75: DrawString_VK = "F6"; break;
                case 0x76: DrawString_VK = "F7"; break;
                case 0x77: DrawString_VK = "F8"; break;
                case 0x78: DrawString_VK = "F9"; break;
                case 0x79: DrawString_VK = "F10"; break;
                case 0x7A: DrawString_VK = "F11"; break;
                case 0x7B: DrawString_VK = "F12"; break;
                case 0x7C: DrawString_VK = "F13"; break;
                case 0x7D: DrawString_VK = "F14"; break;
                case 0x7E: DrawString_VK = "F15"; break;
                case 0x7F: DrawString_VK = "F16"; break;
                case 0x80: DrawString_VK = "F17"; break;
                case 0x81: DrawString_VK = "F18"; break;
                case 0x82: DrawString_VK = "F19"; break;
                case 0x83: DrawString_VK = "F20"; break;
                case 0x84: DrawString_VK = "F21"; break;
                case 0x85: DrawString_VK = "F22"; break;
                case 0x86: DrawString_VK = "F23"; break;
                case 0x87: DrawString_VK = "F24"; break;
                case 0x90: DrawString_VK = "NUM"; break;
                case 0x91: DrawString_VK = "SCR"; break;
                case 0xA0: DrawString_VK = "SHF"; break;
                case 0xA1: DrawString_VK = "SHF"; break;
                case 0xA2: DrawString_VK = "CLR"; break;
                case 0xA3: DrawString_VK = "CLR"; break;
                case 0xA4: DrawString_VK = "ALT"; break;
                case 0xA5: DrawString_VK = "ALT"; break;
                case 0xC0: DrawString_VK = "~"; break;
                case 0xBB: DrawString_VK = "="; break;
                case 0xBC: DrawString_VK = ","; break;
                case 0xBD: DrawString_VK = "-"; break;
                case 0xBE: DrawString_VK = "."; break;
                case 0xBF: DrawString_VK = "/"; break;
                case 0xBA: DrawString_VK = ";"; break;
                case 0xDE: DrawString_VK = "'"; break;
                case 0xDB: DrawString_VK = "["; break;
                case 0xDD: DrawString_VK = "]"; break;
                case 0xDC: DrawString_VK = "|"; break;
                default: DrawString_VK = std::to_string(KeySelectValue); break;//如果什么都不是直接返回编码
                }
                Render_MiniString(Block.Target, 10000 + Block.Size.x - Offset - 33, 10000 + Block.Line, "(" + DrawString_VK + ")", EasyGUI_Color.Min_Bri(190) / Animation<class EasyGUI_KeySelector_DetMouAni>(DetectMousePos ? 2 : 2.5f, EasyGUI_AnimationSmooth, Block.ID + Block.Line + Offset * 10000), 8);
            }
            else Render_MiniString(Block.Target, 10000 + Block.Size.x - Offset - 33, 10000 + Block.Line, "(-)", EasyGUI_Color / 1.5, 8);//激活读取
        }
        inline void GUI_InputText(EasyGUI_Block& Block, string& InputValue, const string& DefaultText = "") noexcept//字符串输入框 (仅英文数字符号)
        {
            const Vector2 ButtonPos = { 45 + Block.Offset, Block.Line - 12 }, ButtonSize = { (int)(Block.Size.x / 1.5), 26 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y - 1);//窗口检测机制
            static unordered_map<long, bool> IsInput{};//判断是否在输入变量
            auto DrawString = InputValue;//绘制字符串
            if (InputState_IsWindShow)//当最前端窗口为GUI窗口接收输入框事件
            {
                if (Block.IsInBlock)//鼠标在区块内部
                {
                    if (!InputValue.empty() && MouseJudgment(Block.Pos.x + ButtonPos.x + ButtonSize.x - 25, Block.Pos.y - Block.Start + ButtonPos.y + 3, 20, ButtonSize.y - 6))//鼠标坐标在X上方
                    {
                        EasyGUI_MouseIcon = IDC_HAND;//清除文字鼠标图标
                        if (InputValue != "" && KeyEvent(VK_LBUTTON, true))InputValue = "";//清除全部内容
                    }
                    else if (DetectMousePos)EasyGUI_MouseIcon = IDC_IBEAM;//输入框鼠标图标
                    if (!IsInput[Block.ID + Block.Line] && DetectMousePos && KeyEvent(VK_LBUTTON, true))IsInput[Block.ID + Block.Line] = true;//进入输入状态
                }
                if (IsInput[Block.ID + Block.Line])//在输入状态时
                {
                    if (KeyEvent(VK_CONTROL))//Ctrl键脚本
                    {
                        OpenClipboard(0);//打开剪切板
                        if (KeyEvent('C', true))//Ctrl + C 复制
                        {
                            EmptyClipboard();//清空剪切板
                            const auto hHandle = GlobalAlloc(GMEM_MOVEABLE, InputValue.size() + 1);//分配内存
                            strcpy_s((char*)GlobalLock(hHandle), InputValue.size() + 1, InputValue.c_str());
                            SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
                            GlobalUnlock(hHandle);//解除锁定
                        }
                        if (KeyEvent('V', true))//Ctrl + V 粘贴
                        {
                            if (IsClipboardFormatAvailable(CF_TEXT))
                            {
                                const auto c_data = GetClipboardData(CF_TEXT);//获取剪切板数据
                                InputValue += ((char*)GlobalLock(c_data));//在字符串尾部粘贴字符串内容
                                GlobalUnlock(c_data);//解除锁定
                            }
                        }
                        CloseClipboard();//关闭剪切板
                    }
                    else {//不阻止Ctrl脚本事件
                        const auto Is_Toupper = KeyEvent(VK_SHIFT) || KeyEvent(VK_LSHIFT) || KeyEvent(VK_RSHIFT) || GetKeyState(VK_CAPITAL);//大写按键脚本
                        for (int i = 0x8; i < 0xFE; ++i)//VK键码遍历 (检测按下了什么键)
                        {
                            if (i != VK_SHIFT && i != VK_LSHIFT && i != VK_RSHIFT && KeyEvent(i, true))
                            {
                                string PressedKey = "";//按键记录变量
                                switch (i)//相比if函数执行更快
                                {
                                case 0x20:PressedKey = " "; break;
                                case 0x30:PressedKey = Is_Toupper ? ")" : "0"; break;
                                case 0x31:PressedKey = Is_Toupper ? "!" : "1"; break;
                                case 0x32:PressedKey = Is_Toupper ? "@" : "2"; break;
                                case 0x33:PressedKey = Is_Toupper ? "#" : "3"; break;
                                case 0x34:PressedKey = Is_Toupper ? "$" : "4"; break;
                                case 0x35:PressedKey = Is_Toupper ? "%" : "5"; break;
                                case 0x36:PressedKey = Is_Toupper ? "^" : "6"; break;
                                case 0x37:PressedKey = Is_Toupper ? "&" : "7"; break;
                                case 0x38:PressedKey = Is_Toupper ? "*" : "8"; break;
                                case 0x39:PressedKey = Is_Toupper ? "(" : "9"; break;
                                case 0x41:PressedKey = Is_Toupper ? "A" : "a"; break;
                                case 0x42:PressedKey = Is_Toupper ? "B" : "b"; break;
                                case 0x43:PressedKey = Is_Toupper ? "C" : "c"; break;
                                case 0x44:PressedKey = Is_Toupper ? "D" : "d"; break;
                                case 0x45:PressedKey = Is_Toupper ? "E" : "e"; break;
                                case 0x46:PressedKey = Is_Toupper ? "F" : "f"; break;
                                case 0x47:PressedKey = Is_Toupper ? "G" : "g"; break;
                                case 0x48:PressedKey = Is_Toupper ? "H" : "h"; break;
                                case 0x49:PressedKey = Is_Toupper ? "I" : "i"; break;
                                case 0x4A:PressedKey = Is_Toupper ? "J" : "j"; break;
                                case 0x4B:PressedKey = Is_Toupper ? "K" : "k"; break;
                                case 0x4C:PressedKey = Is_Toupper ? "L" : "l"; break;
                                case 0x4D:PressedKey = Is_Toupper ? "M" : "m"; break;
                                case 0x4E:PressedKey = Is_Toupper ? "N" : "n"; break;
                                case 0x4F:PressedKey = Is_Toupper ? "O" : "o"; break;
                                case 0x50:PressedKey = Is_Toupper ? "P" : "p"; break;
                                case 0x51:PressedKey = Is_Toupper ? "Q" : "q"; break;
                                case 0x52:PressedKey = Is_Toupper ? "R" : "r"; break;
                                case 0x53:PressedKey = Is_Toupper ? "S" : "s"; break;
                                case 0x54:PressedKey = Is_Toupper ? "T" : "t"; break;
                                case 0x55:PressedKey = Is_Toupper ? "U" : "u"; break;
                                case 0x56:PressedKey = Is_Toupper ? "V" : "v"; break;
                                case 0x57:PressedKey = Is_Toupper ? "W" : "w"; break;
                                case 0x58:PressedKey = Is_Toupper ? "X" : "x"; break;
                                case 0x59:PressedKey = Is_Toupper ? "Y" : "y"; break;
                                case 0x5A:PressedKey = Is_Toupper ? "Z" : "z"; break;
                                case 0xBA:PressedKey = Is_Toupper ? ":" : ";"; break;
                                case 0xBB:PressedKey = Is_Toupper ? "+" : "="; break;
                                case 0xBC:PressedKey = Is_Toupper ? "<" : ","; break;
                                case 0xBD:PressedKey = Is_Toupper ? "_" : "-"; break;
                                case 0xBE:PressedKey = Is_Toupper ? ">" : "."; break;
                                case 0xBF:PressedKey = Is_Toupper ? "?" : "/"; break;
                                case 0xC0:PressedKey = Is_Toupper ? "~" : "`"; break;
                                case 0xDB:PressedKey = Is_Toupper ? "{" : "["; break;
                                case 0xDC:PressedKey = Is_Toupper ? "|" : "\\"; break;
                                case 0xDD:PressedKey = Is_Toupper ? "}" : "]"; break;
                                case 0xDE:PressedKey = Is_Toupper ? "\"" : "'"; break;
                                case 0x60:PressedKey = "0"; break;//小键盘按键 (0x6开头)
                                case 0x61:PressedKey = "1"; break;
                                case 0x62:PressedKey = "2"; break;
                                case 0x63:PressedKey = "3"; break;
                                case 0x64:PressedKey = "4"; break;
                                case 0x65:PressedKey = "5"; break;
                                case 0x66:PressedKey = "6"; break;
                                case 0x67:PressedKey = "7"; break;
                                case 0x68:PressedKey = "8"; break;
                                case 0x69:PressedKey = "9"; break;
                                case 0x6A:PressedKey = "*"; break;
                                case 0x6B:PressedKey = "+"; break;
                                case 0x6D:PressedKey = "-"; break;
                                case 0x6E:PressedKey = "."; break;
                                case 0x6F:PressedKey = "/"; break;
                                case VK_BACK:if (!InputValue.empty())InputValue.pop_back(); break;//擦除最后一个字符
                                case VK_DELETE:InputValue = ""; break;//清除全部字符
                                case VK_ESCAPE:case VK_RETURN:IsInput[Block.ID + Block.Line] = false; break;//按键解除输入状态
                                }
                                if (InputValue.size() < 50)InputValue += PressedKey;//返回按下
                            }
                        }
                    }
                    if (((long)EasyGUI_Tick / 250) % 2 == 0)DrawString += "_";//输入中绘制标识
                    if (!DetectMousePos && (KeyEvent(VK_LBUTTON) || KeyEvent(VK_RBUTTON)))IsInput[Block.ID + Block.Line] = false;//鼠标解除输入状态
                }
            }
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { 15,15,15 }, EasyGUI_Color / Animation<class EasyGUI_InputText_DetMouAni>((DetectMousePos || IsInput[Block.ID + Block.Line]) ? 7 : 8, EasyGUI_AnimationSmooth, Block.ID + Block.Line), true);
            if (!IsInput[Block.ID + Block.Line] && InputValue.empty())Render_String(Block.Target, ButtonPos.x + 10, 10000 + ButtonPos.y + 13, DefaultText + "<NOSHADOW>", EasyGUI_Color.Min_Bri(170) / 4, EasyGUI_Font, EasyGUI_FontSize, 400, { ButtonSize.x - 40 });//默认显示文字
            else {
                Render_String(Block.Target, ButtonPos.x + 10, 10000 + ButtonPos.y + 13, DrawString, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ButtonSize.x - 40 });//已输入的文字
                if (InputValue != "")Render_MiniString(Block.Target, ButtonPos.x + 10 + ButtonSize.x - 28, 10000 + ButtonPos.y + 14, "X", { 60,60,60 }, 15, 400);//删除全部字符叉叉
            }
            Block.Line += 27;
        }
        inline void GUI_Tip(EasyGUI_Block& Block, string Text, const string& DefaultText = "(?)") noexcept//鼠标指针提示
        {
            if (!Text.empty() && Text.back() == '\n')Text.pop_back();//移除最后的自动换行
            const auto DetectMousePos = Block.IsInBlock && InputState_IsWindShow && !KeyEvent(VK_LBUTTON) && MouseJudgment(Block.Pos.x + 5 + Block.Offset, Block.Pos.y - Block.Start + Block.Line - 6, 16, 11);//当鼠标移动到问号 且GUI窗口为最顶层
            if (DetectMousePos)EasyGUI_MouseIcon = IDC_HELP;//帮助鼠标图标
            const auto TipBoxAni = Animation<class EasyGUI_Tip_BoxAni>(DetectMousePos, EasyGUI_AnimationSmooth, Block.ID + Block.Line);//提示框透明度动画
            Render_MiniString(Block.Target, 5 + Block.Offset, 10000 + Block.Line, DefaultText, EasyGUI_Color.Min_Bri(170) * (TipBoxAni * 0.5f + 0.4f));//提示符绘制
            if (TipBoxAni > 0.01f)
            {
                const auto StringSize = Render_MiniString(EasyGUI_RenderTarget, 0, 0, Text, {}, EasyGUI_FontSize - 1, 600, { Block.Size.x - 55,0 }) + Vector2{ 12, 11 };//提示框大小
                const auto TipRectPos = Vector2{ Block.Pos.x + 35 + Block.Offset, Block.Pos.y + Block.Line - Block.Start };//提示框位置
                Render_Rect(EasyGUI_RenderTarget, TipRectPos.x, TipRectPos.y, StringSize.x, StringSize.y, { 0,0,0,int(TipBoxAni * 255) });
                Render_Rect(EasyGUI_RenderTarget, TipRectPos.x + 1, TipRectPos.y + 1, StringSize.x - 2, StringSize.y - 2, { 60,60,60,int(TipBoxAni * 255) });
                Render_GradientRect(EasyGUI_RenderTarget, TipRectPos.x + 2, TipRectPos.y + 2, StringSize.x - 4, StringSize.y - 4, EasyGUI_Color.Alpha(TipBoxAni * 255) / 15, EasyGUI_Color.Alpha(TipBoxAni * 255) / 10, true);
                Render_MiniString(EasyGUI_RenderTarget, TipRectPos.x + 5, TipRectPos.y + 5, Text, { 200,200,200,int(TipBoxAni * 255) }, EasyGUI_FontSize - 1, 600, { Block.Size.x - 55,0 });
            }
        }
        inline void GUI_ColorSelector(EasyGUI_Block& Block, Vector4& ColorValue, int Offset = 0) noexcept//颜色选择器
        {
            auto DrawCheckerboard = [&](ID2D1RenderTarget* Target, int X, int Y, int Width, int Height) {//绘制棋盘格背景
                for (int i = 0; i < Height; i += 2)for (int j = 0; j < Width; j += 2)
                    Render_Rect(Target, j + X, i + Y, 2, 2, ((i / 2) + (j / 2)) % 2 ? Vector4{ 150, 150, 150 } : Vector4{ 200, 200, 200 }, true, 0);
                };
            const Vector2 ColorRectPos = { Block.Size.x - 43 - Offset,Block.Line - 6 }, ColorPickerSize = { 200, 100 };//颜色预览框位置,颜色选择器大小
            static unordered_map<long, bool> OpenColorPicker{};//颜色选择器开关
            static unordered_map<long, Vector4> BaseColor{};//基础颜色值备份
            if (Block.IsInBlock && InputState_IsWindShow && !InputState_ControlWindowShow && MouseJudgment(Block.Pos.x + ColorRectPos.x, Block.Pos.y - Block.Start + ColorRectPos.y, 20, 12))
            {
                EasyGUI_MouseIcon = IDC_HAND;//手型鼠标图标
                if (!OpenColorPicker[Block.ID + Block.Line + Offset * 10000] && KeyEvent(VK_LBUTTON, true))//打开颜色选择器
                {
                    BaseColor[Block.ID + Block.Line + Offset * 10000] = ColorValue;
                    OpenColorPicker[Block.ID + Block.Line + Offset * 10000] = true;
                    InputState_ControlWindowShow = true;
                    MoveControlWindow(EasyGUI_MousePos.x + 20, EasyGUI_MousePos.y + 20, ColorPickerSize.x, ColorPickerSize.y, 255);
                }
            }
            if (OpenColorPicker[Block.ID + Block.Line + Offset * 10000])//颜色选择器打开时
            {
                if (!InputState_ControlWindowShow)OpenColorPicker[Block.ID + Block.Line + Offset * 10000] = false;//当控制窗口关闭时关闭颜色选择器
                const bool SelectBar_1 = EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 5 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < 5 + ColorPickerSize.x - 10 - 1 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > 5 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < 5 + 18,
                    SelectBar_2 = EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 5 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < 5 + ColorPickerSize.x - 10 - 1 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > 5 + 25 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < 5 + 25 + 18,
                    SelectBar_3 = EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 5 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < 5 + ColorPickerSize.x - 10 - 1 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > 5 + 50 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < 5 + 50 + 18;
                if (InputState_ControlWindowShow && KeyEvent(VK_LBUTTON))
                {
                    InputState_IsSlider = true;
                    static const auto Window_HDC = GetDC(0); const auto Pixel = GetPixel(Window_HDC, EasyGUI_MousePos.x, EasyGUI_MousePos.y);
                    const Vector4 MouseColor = { GetRValue(Pixel),GetGValue(Pixel),GetBValue(Pixel),ColorValue.a };
                    if (MouseColor.Alpha(255) != Vector4{ 0, 0, 1 })
                    {
                        if (SelectBar_1) { BaseColor[Block.ID + Block.Line + Offset * 10000] = MouseColor; ColorValue = MouseColor; }
                        else if (SelectBar_2)ColorValue = MouseColor;
                        else if (SelectBar_3)ColorValue.a = (1.f - (EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left) / (ColorPickerSize.x - 10.f)) * 255.f;
                        if (ColorValue.a >= 245)ColorValue.a = 255; else if (ColorValue.a <= 5)ColorValue.a = 0;
                    }
                }
                else InputState_IsSlider = false;
                Render_Rect(EasyGUI_ControlRenderTarget, 0, 0, ColorPickerSize.x, ColorPickerSize.y, { 0,0,0 });
                Render_Rect(EasyGUI_ControlRenderTarget, 1, 1, ColorPickerSize.x - 2, ColorPickerSize.y - 2, { 60,60,60 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 2, 2, ColorPickerSize.x - 4, ColorPickerSize.y - 4, EasyGUI_Color / 15, EasyGUI_Color / 10, true);
                Render_Rect(EasyGUI_ControlRenderTarget, 8, 5, ColorPickerSize.x - 16, 20, { 0,0,0 }, true, 0);//彩虹颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 32 * 0, 6, 32, 18, { 255,0,0 }, { 255,255,0 }, false, false, 0);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 32 * 1, 6, 32, 18, { 255,255,0 }, { 0,255,0 }, false, false, 0);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 32 * 2, 6, 32, 18, { 0,255,0 }, { 0,255,255 }, false, false, 0);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 32 * 3, 6, 32, 18, { 0,255,255 }, { 0,0,255 }, false, false, 0);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 32 * 4, 6, 32, 18, { 0,0,255 }, { 255,0,255 }, false, false, 0);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 32 * 5, 6, 32 - 4, 18, { 255,0,255 }, { 255,0,0 }, false, false, 0);
                Render_Rect(EasyGUI_ControlRenderTarget, 5, 5 + 25, ColorPickerSize.x - 10, 20, { 0,0,0 }, true, 0);//明暗颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6, 6 + 25, (ColorPickerSize.x - 10) / 2, 18, { 0,0,0 }, BaseColor[Block.ID + Block.Line + Offset * 10000].Alpha(255), false, false, 0);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + (ColorPickerSize.x - 10) / 2, 6 + 25, (ColorPickerSize.x - 10) / 2 - 2, 18, BaseColor[Block.ID + Block.Line + Offset * 10000].Alpha(255), { 255,255,255 }, false, false, 0);
                Render_Rect(EasyGUI_ControlRenderTarget, 5, 5 + 50, ColorPickerSize.x - 10, 20, { 0,0,0 }, true, 0);//透明颜色条
                DrawCheckerboard(EasyGUI_ControlRenderTarget, 6, 6 + 50, ColorPickerSize.x - 12, 18);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6, 6 + 50, ColorPickerSize.x - 12, 18, ColorValue.Alpha(255), ColorValue.Alpha(0), false, false, 0);
                Render_String(EasyGUI_ControlRenderTarget, 10000 + ColorPickerSize.x / 2, 10000 + 6 + 75 + 5, "(R:" + std::to_string(ColorValue.r) + ")(G:" + std::to_string(ColorValue.g) + ")(B:" + std::to_string(ColorValue.b) + ")(A:" + std::to_string(ColorValue.a) + ")", ColorValue.Min_Bri(100).Max_Bri(220).Alpha(255), EasyGUI_Font, EasyGUI_FontSize, 500);//颜色字符串
                if (KeyEvent(VK_LBUTTON))//绘制选择标识
                {
                    if (SelectBar_1)Render_Rect(EasyGUI_ControlRenderTarget, EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left + 1, 6, 1, 18, { 0,0,1 }, false);
                    else if (SelectBar_2)Render_Rect(EasyGUI_ControlRenderTarget, EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left + 1, 6 + 25, 1, 18, { 0,0,1 }, false);
                    else if (SelectBar_3)Render_Rect(EasyGUI_ControlRenderTarget, EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left + 1, 6 + 50, 1, 18, { 0,0,1 }, false);
                }
            }
            Render_Rect(Block.Target, ColorRectPos.x, ColorRectPos.y, 20, 12, { 0,0,0 });//黑色边框
            DrawCheckerboard(Block.Target, ColorRectPos.x + 2, ColorRectPos.y + 2, 16, 8);//透明格子绘制
            Render_GradientRect(Block.Target, ColorRectPos.x + 1, ColorRectPos.y + 1, 18, 10, ColorValue, ColorValue / 3, true, false);//颜色预览框
        }
        inline void GUI_PosSelector(EasyGUI_Block& Block, Vector3& PosValue) noexcept//坐标选择器
        {
            const Vector2 ButtonSize = { 65,18 }, ButtonPos = { Block.Size.x - ButtonSize.x * 3 - 15,Block.Line - ButtonSize.y / 2 };//按钮位置,按钮大小
            for (int Pos_Bl = 0; Pos_Bl <= 2; ++Pos_Bl)
            {
                vector<float> UsedPos = { PosValue.x,PosValue.y,PosValue.z };
                const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x + ButtonSize.x * Pos_Bl, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x - 2, ButtonSize.y);//窗口检测机制
                if (InputState_IsWindShow && DetectMousePos && Block.IsInBlock)//当最前端窗口为GUI窗口接收按钮事件
                {
                    if (KeyEvent(VK_LBUTTON, true))UsedPos[Pos_Bl] += 0.1; else if (KeyEvent(VK_RBUTTON, true))UsedPos[Pos_Bl] -= 0.1;
                    if (KeyEvent(VK_LEFT, true))UsedPos[Pos_Bl] += 1; else if (KeyEvent(VK_RIGHT, true))UsedPos[Pos_Bl] -= 1;
                    if (KeyEvent(VK_UP, true))UsedPos[Pos_Bl] -= 10; else if (KeyEvent(VK_DOWN, true))UsedPos[Pos_Bl] += 10;
                    if (KeyEvent(VK_DELETE, true))UsedPos[Pos_Bl] = 0;
                    PosValue = { UsedPos[0],UsedPos[1],UsedPos[2] };
                    Block.IsInScrollArea = true;//禁止区块滑动
                }
                Render_Rect(Block.Target, ButtonPos.x + ButtonSize.x * Pos_Bl, ButtonPos.y, ButtonSize.x - 2, ButtonSize.y, { 0,0,0 });
                Render_GradientRect(Block.Target, ButtonPos.x + ButtonSize.x * Pos_Bl + 1, ButtonPos.y + 1, ButtonSize.x - 2 - 2, ButtonSize.y - 2, EasyGUI_Color / Animation<class EasyGUI_PosSelector_DetMouAni>(DetectMousePos ? 5 : 6, EasyGUI_AnimationSmooth, Block.ID + Block.Line + Pos_Bl * 100), { 20,20,20 }, true);
            }
            std::stringstream Pos_X{}, Pos_Y{}, Pos_Z{}; Pos_X << std::fixed << std::setprecision(1) << PosValue.x; Pos_Y << std::fixed << std::setprecision(1) << PosValue.y; Pos_Z << std::fixed << std::setprecision(1) << PosValue.z;//只保留特定小数点后数
            Render_MiniString(Block.Target, ButtonPos.x + 5 + ButtonSize.x * 0, 10000 + Block.Line + 1, "X: " + Pos_X.str(), { 150,150,150 });
            Render_MiniString(Block.Target, ButtonPos.x + 5 + ButtonSize.x * 1, 10000 + Block.Line + 1, "Y: " + Pos_Y.str(), { 150,150,150 });
            Render_MiniString(Block.Target, ButtonPos.x + 5 + ButtonSize.x * 2, 10000 + Block.Line + 1, "Z: " + Pos_Z.str(), { 150,150,150 });
        }
        inline void GUI_Combobox(EasyGUI_Block& Block, const vector<string>& ComboText, int& SelectValue) noexcept//单选组合框
        {
            const Vector2 ComboboxPos = { 45 + Block.Offset,Block.Line - 12 }, ComboboxSize = { (int)(Block.Size.x / 1.5),24 }, ComboboxWindowSize = { (int)(Block.Size.x / 1.5), (int)(ComboText.size() * 24) };//颜色选择器大小
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ComboboxPos.x, Block.Pos.y - Block.Start + ComboboxPos.y, ComboboxSize.x, ComboboxSize.y);//窗口检测机制
            static unordered_map<long, bool> IsOpen{};//判断是否打开选择变量
            if (InputState_IsWindShow && !IsOpen[Block.ID + Block.Line] && !InputState_ControlWindowShow && Block.IsInBlock && DetectMousePos)//当最前端窗口为GUI窗口接收事件
            {
                if (KeyEvent(VK_LBUTTON, true))//打开选择器
                {
                    IsOpen[Block.ID + Block.Line] = true; InputState_ControlWindowShow = true;
                    MoveControlWindow(EasyGUI_WindowPos.left + Block.Pos.x + ComboboxPos.x, EasyGUI_WindowPos.top + Block.Pos.y - Block.Start + ComboboxPos.y + 27, ComboboxWindowSize.x, ComboboxWindowSize.y);
                }
                if (KeyEvent(VK_UP, true))--SelectValue; else if (KeyEvent(VK_DOWN, true))++SelectValue;
                if (SelectValue < 0)SelectValue = 0; else if (SelectValue >= ComboText.size())SelectValue = ComboText.size() - 1;//限制值防止崩溃
                Block.IsInScrollArea = true;//禁止区块滑动
            }
            if (IsOpen[Block.ID + Block.Line])
            {
                if (!InputState_ControlWindowShow)IsOpen[Block.ID + Block.Line] = false;//当控制窗口关闭时关闭颜色选择器
                Render_Rect(EasyGUI_ControlRenderTarget, 0, 0, ComboboxWindowSize.x, ComboboxWindowSize.y, { 0,0,0 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 1, 1, ComboboxWindowSize.x - 2, ComboboxWindowSize.y - 2, EasyGUI_Color / 10, { 10,10,10 }, true);
                for (int i = 0; i < ComboText.size(); ++i)//遍历选项绘制
                {
                    const auto Pos_Y = i * 24 + 1, PosHeight = 22; int SelectAlpha = 0;
                    if (EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 2 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < ComboboxWindowSize.x - 2 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > Pos_Y && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < Pos_Y + PosHeight)//鼠标悬停高亮
                    {
                        if (KeyEvent(VK_LBUTTON, true)) { SelectValue = i; InputState_ControlWindowShow = false; } SelectAlpha = 255;
                    }
                    const auto SelectAniAlpha = Animation<class EasyGUI_Combobox_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth, i);
                    Render_GradientRect(EasyGUI_ControlRenderTarget, 1, Pos_Y, ComboboxWindowSize.x - 2, PosHeight, EasyGUI_Color.Alpha(SelectAniAlpha) / 6, Vector4{ 20,20,20 }.Alpha(SelectAniAlpha), true);
                    if (SelectValue == i)Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2, ComboText[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600, { ComboboxSize.x - 20 });
                    else Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2, ComboText[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 20 });
                }
            }
            Render_Rect(Block.Target, ComboboxPos.x, ComboboxPos.y, ComboboxSize.x, ComboboxSize.y, { 0,0,0 });
            Render_GradientRect(Block.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, { 20,20,20 }, EasyGUI_Color / Animation<class EasyGUI_Combobox_DetMouAni>((DetectMousePos || IsOpen[Block.ID + Block.Line]) ? 6 : 7, EasyGUI_AnimationSmooth, Block.ID + Block.Line), true);
            Render_String(Block.Target, ComboboxPos.x + 10, 10000 + ComboboxPos.y + 13, ComboText[SelectValue], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 35 });
            if (IsOpen[Block.ID + Block.Line])Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▲", { 200,200,200 }, 9, 400);
            else Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▼", { 200,200,200 }, 9, 400);
            Block.Line += 25;
        }
        inline void GUI_MultiCombobox(EasyGUI_Block& Block, const vector<string>& ComboText, vector<bool>& SelectValue) noexcept//多选组合框
        {
            const Vector2 ComboboxPos = { 45 + Block.Offset,Block.Line - 12 }, ComboboxSize = { (int)(Block.Size.x / 1.5),24 }, ComboboxWindowSize = { (int)(Block.Size.x / 1.5), (int)(ComboText.size() * 24) };//颜色选择器大小
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ComboboxPos.x, Block.Pos.y - Block.Start + ComboboxPos.y, ComboboxSize.x, ComboboxSize.y);//窗口检测机制
            static unordered_map<long, bool> IsOpen{};//判断是否打开选择变量
            if (InputState_IsWindShow && !IsOpen[Block.ID + Block.Line] && !InputState_ControlWindowShow && Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true))//当最前端窗口为GUI窗口接收事件
            {
                IsOpen[Block.ID + Block.Line] = true; InputState_ControlWindowShow = true;
                MoveControlWindow(EasyGUI_WindowPos.left + Block.Pos.x + ComboboxPos.x, EasyGUI_WindowPos.top + Block.Pos.y - Block.Start + ComboboxPos.y + 27, ComboboxWindowSize.x, ComboboxWindowSize.y);
            }
            if (IsOpen[Block.ID + Block.Line])
            {
                if (!InputState_ControlWindowShow)IsOpen[Block.ID + Block.Line] = false;//当控制窗口关闭时关闭颜色选择器
                Render_Rect(EasyGUI_ControlRenderTarget, 0, 0, ComboboxWindowSize.x, ComboboxWindowSize.y, { 0,0,0 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 1, 1, ComboboxWindowSize.x - 2, ComboboxWindowSize.y - 2, EasyGUI_Color / 10, { 10,10,10 }, true);
                for (int i = 0; i < ComboText.size(); ++i)//遍历选项绘制
                {
                    const auto Pos_Y = i * 24 + 1, PosHeight = 22; int SelectAlpha = 0;
                    if (EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 2 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < ComboboxWindowSize.x - 2 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > Pos_Y && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < Pos_Y + PosHeight)//鼠标悬停高亮
                    {
                        if (KeyEvent(VK_LBUTTON, true))SelectValue[i] = !SelectValue[i]; SelectAlpha = 255;
                    }
                    const auto SelectAniAlpha = Animation<class EasyGUI_MultiCombobox_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth, i);
                    Render_GradientRect(EasyGUI_ControlRenderTarget, 1, Pos_Y, ComboboxWindowSize.x - 2, PosHeight, EasyGUI_Color.Alpha(SelectAniAlpha) / 6, Vector4{ 20,20,20 }.Alpha(SelectAniAlpha), true);
                    if (SelectValue[i])Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2, ComboText[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600, { ComboboxSize.x - 20 });
                    else Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2, ComboText[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 20 });
                }
            }
            string SelectString = "-"; for (int i = 0; i < ComboText.size(); ++i)if (SelectValue[i]) { if (SelectString == "-")SelectString = ""; if (!SelectString.empty()) SelectString += ", "; SelectString += ComboText[i]; }//字符串计算
            Render_Rect(Block.Target, ComboboxPos.x, ComboboxPos.y, ComboboxSize.x, ComboboxSize.y, { 0,0,0 });
            Render_GradientRect(Block.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, { 20,20,20 }, EasyGUI_Color / Animation<class EasyGUI_Combobox_DetMouAni>((DetectMousePos || IsOpen[Block.ID + Block.Line]) ? 6 : 7, EasyGUI_AnimationSmooth, Block.ID + Block.Line), true);
            Render_String(Block.Target, ComboboxPos.x + 10, 10000 + ComboboxPos.y + 13, SelectString, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 35 });
            if (IsOpen[Block.ID + Block.Line])Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▲", { 200,200,200 }, 9, 400);
            else Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▼", { 200,200,200 }, 9, 400);
            Block.Line += 25;
        }
        inline void GUI_List(EasyGUI_Block& Block, const vector<string>& LineString, int& m_InLine, int LimitLine = 0) noexcept//单选列表
        {
            Block.Line += 3;
            const auto LineStringSize = LineString.size();//获取行列数
            if (m_InLine < 0)m_InLine = 0; else if (m_InLine >= LineStringSize)m_InLine = LineStringSize - 1;//赋值范围限制
            static unordered_map<long, int> StartLinePos{}; if (!LimitLine)LimitLine = LineStringSize; if (!LineStringSize)m_InLine = -1;//防止过量访问崩溃
            const Vector2 ListPos = { 45 + Block.Offset,Block.Line - 15 }, ListSize = { (int)(Block.Size.x / 1.5),(int)(LimitLine * 25 + 5) };//列表位置,列表大小
            const auto IsInList = MouseJudgment(Block.Pos.x + ListPos.x, Block.Pos.y - Block.Start + ListPos.y, ListSize.x, ListSize.y);
            if (IsInList && InputState_IsWindShow && Block.IsInBlock && LineStringSize > LimitLine) { if (KeyEvent(VK_UP, true))StartLinePos[Block.ID + Block.Line] -= 2; else if (KeyEvent(VK_DOWN, true))StartLinePos[Block.ID + Block.Line] += 2; Block.IsInScrollArea = true; }//鼠标滚轮调整绘制起始位置
            if (StartLinePos[Block.ID + Block.Line] + LimitLine > LineStringSize)StartLinePos[Block.ID + Block.Line] = LineStringSize - LimitLine; if (StartLinePos[Block.ID + Block.Line] < 0)StartLinePos[Block.ID + Block.Line] = 0;//开始行列位置范围限制
            Render_Rect(Block.Target, ListPos.x, ListPos.y, ListSize.x, ListSize.y, { 0,0,0 });//黑色外边框
            Render_GradientRect(Block.Target, ListPos.x + 1, ListPos.y + 1, ListSize.x - 2, ListSize.y - 2, EasyGUI_Color / 10, { 10,10,10 }, true);//主题色渐变背景
            for (int i = StartLinePos[Block.ID + Block.Line]; i < LineStringSize; ++i)//行列内容遍历
            {
                if (i - StartLinePos[Block.ID + Block.Line] >= LimitLine)continue;//限制行数
                const auto LineY = ListPos.y + (i - StartLinePos[Block.ID + Block.Line]) * 25 + 5; int SelectAlpha = 0;//当前行的Y坐标 统一坐标体系
                if (m_InLine == i)SelectAlpha = 255;
                else if (Block.IsInBlock && MouseJudgment(Block.Pos.x + ListPos.x, Block.Pos.y - Block.Start + LineY, ListSize.x, 20))//鼠标赋值选择
                {
                    if (InputState_IsWindShow && m_InLine != i && KeyEvent(VK_LBUTTON, true))m_InLine = i; SelectAlpha = 150;
                }
                const auto SelectAniAlpha = Animation<class EasyGUI_Combobox_SelectAni>(SelectAlpha, EasyGUI_AnimationSmooth, Block.ID + Block.Line + i);
                Render_GradientRect(Block.Target, ListPos.x + 1, LineY, ListSize.x - 2, 20, EasyGUI_Color.Alpha(SelectAniAlpha) / 5, Vector4{ 20,20,20 }.Alpha(SelectAniAlpha), true);
                if (m_InLine == i)Render_String(Block.Target, ListPos.x + 12, 10000 + LineY + 10, LineString[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600);
                else Render_String(Block.Target, ListPos.x + 12, 10000 + LineY + 10, LineString[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
            }
            if (LineStringSize > LimitLine)//只有在内容超出可视区域时才会绘制滚动条
            {
                const auto ListHeight = LimitLine * 25 + 1, ScrollBarHeight = max(int(ListHeight * float(LimitLine) / LineStringSize), 10);
                Render_GradientRect(Block.Target, ListPos.x + ListSize.x - 3, ListPos.y + 2, 1, ListHeight, { 10,10,10 }, EasyGUI_Color / 10, true);//滚动槽背景
                Render_GradientRect(Block.Target, ListPos.x + ListSize.x - 3, ListPos.y + 2 + ((LineStringSize - LimitLine) > 0 ? float(StartLinePos[Block.ID + Block.Line]) / (LineStringSize - LimitLine) * (ListHeight - ScrollBarHeight) : 0.f), 1, ScrollBarHeight, EasyGUI_Color / 2, EasyGUI_Color / 4, true);//滚动条
            }
            Block.Line += LimitLine * 25 + 5;
        }
    };
}