#pragma once
#include <Vector>
#include <String>
#include <Chrono>
#include <Unordered_map>
#include <Dwmapi.h>
#include <Dwrite.h>
#include <D2D1.h>
#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "Dwrite.lib")
#pragma comment(lib, "Dwmapi.lib")
using namespace std; using namespace chrono;
namespace EasyGUI_Direct2D
{
    namespace EasyGUI_Vector
    {
        struct Vector2//用来储存坐标数据 XY
        {
            Vector2(const int x = 0, const int y = 0) noexcept :x(x), y(y) {} int x, y;
            bool operator==(Vector2 other) const noexcept { return x == other.x && y == other.y; }
            bool operator!=(Vector2 other) const noexcept { return x != other.x || y != other.y; }
            Vector2 operator+(Vector2 other) const noexcept { return Vector2{ x + other.x, y + other.y }; }
            Vector2 operator-(Vector2 other) const noexcept { return Vector2{ x - other.x, y - other.y }; }
            Vector2 operator+=(Vector2 other) noexcept { x += other.x, y += other.y; return *this; }
            Vector2 operator-=(Vector2 other) noexcept { x -= other.x, y -= other.y; return *this; }
            Vector2 operator*(int other) const noexcept { return Vector2{ x * other, y * other }; }
            Vector2 operator/(int other) const noexcept { return Vector2{ x / other, y / other }; }
            Vector2 operator*(float other) const noexcept { return Vector2{ (int)(x * other), (int)(y * other) }; }
            Vector2 operator/(float other) const noexcept { return Vector2{ (int)(x / other), (int)(y / other) }; }
            Vector2 operator*(double other) const noexcept { return Vector2{ (int)(x * other), (int)(y * other) }; }
            Vector2 operator/(double other) const noexcept { return Vector2{ (int)(x / other), (int)(y / other) }; }
            bool IsZero() const noexcept { return x == 0 && y == 0; }//判断是否为0
            template<class CreateClassName> inline Vector2 Animation(float speed = 10, long key = 0) const noexcept//Vector2坐标动画
            {
                static unordered_map<long, Vector2> ReturnValue; if (!ReturnValue.count(key))ReturnValue[key] = *this;
                if (speed == 1) { ReturnValue[key] = *this; return ReturnValue[key]; }
                if (x > ReturnValue[key].x)ReturnValue[key].x += (x - ReturnValue[key].x) / speed; else if (x < ReturnValue[key].x)ReturnValue[key].x -= (ReturnValue[key].x - x) / speed;
                if (y > ReturnValue[key].y)ReturnValue[key].y += (y - ReturnValue[key].y) / speed; else if (y < ReturnValue[key].y)ReturnValue[key].y -= (ReturnValue[key].y - y) / speed;
                return ReturnValue[key];
            }
        };
        struct Vector3//用来储存坐标数据 XYZ
        {
            Vector3(const float x = 0, const float y = 0, const float z = 0) noexcept :x(x), y(y), z(z) {} float x, y, z;
            bool operator==(Vector3 other) const noexcept { return x == other.x && y == other.y && z == other.z; }
            bool operator!=(Vector3 other) const noexcept { return x != other.x || y != other.y || z != other.z; }
            Vector3 operator+(Vector3 other) const noexcept { return Vector3{ x + other.x, y + other.y, z + other.z }; }
            Vector3 operator-(Vector3 other) const noexcept { return Vector3{ x - other.x, y - other.y, z - other.z }; }
            Vector3 operator+=(Vector3 other) noexcept { x += other.x, y += other.y, z += other.z; return *this; }
            Vector3 operator-=(Vector3 other) noexcept { x -= other.x, y -= other.y, z -= other.z; return *this; }
            Vector3 operator*(int other) const noexcept { return Vector3{ x * other, y * other, z * other }; }
            Vector3 operator/(int other) const noexcept { return Vector3{ x / other, y / other, z / other }; }
            Vector3 operator*(float other) const noexcept { return Vector3{ x * other, y * other, z * other }; }
            Vector3 operator/(float other) const noexcept { return Vector3{ x / other, y / other, z / other }; }
            Vector3 operator*(double other) const noexcept { return Vector3{ (float)(x * other), (float)(y * other), (float)(z * other) }; }
            Vector3 operator/(double other) const noexcept { return Vector3{ (float)(x / other), (float)(y / other), (float)(z / other) }; }
            bool IsZero() const noexcept { return x == 0 && y == 0 && z == 0; }//判断是否为0
            template<class CreateClassName> inline Vector3 Animation(float speed = 10, long key = 0) const noexcept//Vector3坐标动画
            {
                static unordered_map<long, Vector3> ReturnValue; if (!ReturnValue.count(key))ReturnValue[key] = *this;
                if (speed == 1) { ReturnValue[key] = *this; return ReturnValue[key]; }
                if (x > ReturnValue[key].x)ReturnValue[key].x += (x - ReturnValue[key].x) / speed; else if (x < ReturnValue[key].x)ReturnValue[key].x -= (ReturnValue[key].x - x) / speed;
                if (y > ReturnValue[key].y)ReturnValue[key].y += (y - ReturnValue[key].y) / speed; else if (y < ReturnValue[key].y)ReturnValue[key].y -= (ReturnValue[key].y - y) / speed;
                if (z > ReturnValue[key].z)ReturnValue[key].z += (z - ReturnValue[key].z) / speed; else if (z < ReturnValue[key].z)ReturnValue[key].z -= (ReturnValue[key].z - z) / speed;
                return ReturnValue[key];
            }
        };
        struct Vector4//用来储存颜色数据 RGBA
        {
            Vector4(const int r = 0, const int g = 0, const int b = 0, const int a = 255) noexcept :r(r), g(g), b(b), a(a) {} int r, g, b, a = 255;
            bool operator==(Vector4 other) const noexcept { return r == other.r && g == other.g && b == other.b && a == other.a; }
            bool operator!=(Vector4 other) const noexcept { return r != other.r || g != other.g || b != other.b || a != other.a; }
            Vector4 operator+(Vector4 other) const noexcept { return Vector4{ r + other.r, g + other.g, b + other.b, a }; }
            Vector4 operator-(Vector4 other) const noexcept { return Vector4{ r - other.r, g - other.g, b - other.b, a }; }
            Vector4 operator*(int other) const noexcept { return Vector4{ r * other, g * other, b * other, a }; }
            Vector4 operator/(int other) const noexcept { return Vector4{ r / other, g / other, b / other, a }; }
            Vector4 operator*(float other) const noexcept { return Vector4{ (int)(r * other), (int)(g * other), (int)(b * other), a }; }
            Vector4 operator/(float other) const noexcept { return Vector4{ (int)(r / other), (int)(g / other), (int)(b / other), a }; }
            Vector4 operator*(double other) const noexcept { return Vector4{ (int)(r * other), (int)(g * other), (int)(b * other), a }; }
            Vector4 operator/(double other) const noexcept { return Vector4{ (int)(r / other), (int)(g / other), (int)(b / other), a }; }
            bool IsZero() const noexcept { return r == 0 && g == 0 && b == 0; }//判断是否为0
            Vector4 D_Alpha(int alpha, int limit = 0) const noexcept { if (alpha <= limit)return { r,g,b,limit }; else return { r,g,b,alpha }; }//原有基础上设置特定透明度
            template<class CreateClassName> inline Vector4 Animation(float speed = 10, long key = 0) const noexcept//Vector4颜色动画
            {
                static unordered_map<long, Vector4> ReturnValue; if (!ReturnValue.count(key))ReturnValue[key] = *this;
                if (speed == 1) { ReturnValue[key] = *this; return ReturnValue[key]; }
                if (r > ReturnValue[key].r)ReturnValue[key].r += (r - ReturnValue[key].r) / speed; else if (r < ReturnValue[key].r)ReturnValue[key].r -= (ReturnValue[key].r - r) / speed;
                if (g > ReturnValue[key].g)ReturnValue[key].g += (g - ReturnValue[key].g) / speed; else if (g < ReturnValue[key].g)ReturnValue[key].g -= (ReturnValue[key].g - g) / speed;
                if (b > ReturnValue[key].b)ReturnValue[key].b += (b - ReturnValue[key].b) / speed; else if (b < ReturnValue[key].b)ReturnValue[key].b -= (ReturnValue[key].b - b) / speed;
                if (a > ReturnValue[key].a)ReturnValue[key].a += (a - ReturnValue[key].a) / speed; else if (a < ReturnValue[key].a)ReturnValue[key].a -= (ReturnValue[key].a - a) / speed;
                return ReturnValue[key];
            }
            Vector4 Re_Col() const noexcept//限制颜色值过量 (0~255)
            {
                auto Color_Var = *this;
                if (Color_Var.r < 0)Color_Var.r = 0; else if (Color_Var.r > 255)Color_Var.r = 255;
                if (Color_Var.g < 0)Color_Var.g = 0; else if (Color_Var.g > 255)Color_Var.g = 255;
                if (Color_Var.b < 0)Color_Var.b = 0; else if (Color_Var.b > 255)Color_Var.b = 255;
                if (Color_Var.a < 0)Color_Var.a = 0; else if (Color_Var.a > 255)Color_Var.a = 255;
                return Color_Var;
            }
            Vector4 Min_Bri(int bright = 0) const noexcept//最小亮度
            {
                auto Color_Var = *this;
                if (Color_Var.r < bright)Color_Var.r = bright;
                if (Color_Var.g < bright)Color_Var.g = bright;
                if (Color_Var.b < bright)Color_Var.b = bright;
                return Color_Var;
            }
            Vector4 Max_Bri(int bright = 0) const noexcept//最大亮度
            {
                auto Color_Var = *this;
                if (Color_Var.r > bright)Color_Var.r = bright;
                if (Color_Var.g > bright)Color_Var.g = bright;
                if (Color_Var.b > bright)Color_Var.b = bright;
                return Color_Var;
            }
            Vector4 Sat(float saturation = 1, float grey = 0, float brightness = 1) const noexcept//色调设置
            {
                float rNorm = r / 255.f, gNorm = g / 255.f, bNorm = b / 255.f, max_val = max(rNorm, max(gNorm, bNorm)), min_val = min(rNorm, min(gNorm, bNorm)), delta = max_val - min_val, h = 0, s = 0, v = max_val + grey; if (v > 1)v = 1;
                if (delta == 0)h = 0; else if (max_val == rNorm) h = 60 * (((gNorm - bNorm) / delta) + (gNorm < bNorm ? 6 : 0));
                else if (max_val == gNorm)h = 60 * (((bNorm - rNorm) / delta) + 2); else h = 60 * (((rNorm - gNorm) / delta) + 4);
                s = (max_val == 0) ? 0 : (delta / max_val); s *= saturation / 1; if (s < 0)s = 0; else if (s > 1)s = 1;
                int i = static_cast<int>(h / 60) % 6;
                float f = h / 60 - i, p = v * (1 - s), q = v * (1 - f * s), t = v * (1 - (1 - f) * s), newR = 0, newG = 0, newB = 0;
                switch (i)
                {
                case 0: newR = v; newG = t; newB = p; break;
                case 1: newR = q; newG = v; newB = p; break;
                case 2: newR = p; newG = v; newB = t; break;
                case 3: newR = p; newG = q; newB = v; break;
                case 4: newR = t; newG = p; newB = v; break;
                case 5: newR = v; newG = p; newB = q; break;
                }
                return Vector4{ (int)(newR * 255 * brightness) ,(int)(newG * 255 * brightness) ,(int)(newB * 255 * brightness) };
            }
        };
    }
    using namespace EasyGUI_Vector;
    auto EasyGUI_MouseIcon = IDC_ARROW;//鼠标图标变量 (修改图标时更改该变量即可)
    LRESULT CALLBACK EasyGUI_WindowProcess(HWND Hwnd, UINT Message, WPARAM wParam, LPARAM lParam) noexcept//窗口消息循环(用于解决窗口未响应问题 接收窗口消息)
    {
        if (Message == WM_CLOSE)exit(0);//接收到关闭窗口事件时返回全部线程
        else if (Message == WM_SETCURSOR) { SetCursor(LoadCursor(0, EasyGUI_MouseIcon)); EasyGUI_MouseIcon = IDC_ARROW; }//鼠标图标事件
        else if (Message == WM_MOUSEWHEEL)//鼠标滚轮事件
        {
            const auto Delta = GET_WHEEL_DELTA_WPARAM(wParam);
            if (Delta > 0)keybd_event(VK_UP, 0, 0, 0); else if (Delta < 0)keybd_event(VK_DOWN, 0, 0, 0);
        }
        return DefWindowProc(Hwnd, Message, wParam, lParam);//定义回调函数的返回值
    }
    struct EasyGUI_Block { string Title; Vector2 Pos, Size; int ID, Line, Start; bool IsInBlock, IsInScrollArea; ID2D1BitmapRenderTarget* Target; };
    class EasyGUI
    {
    private:
        HWND EasyGUI_WindowHWND, EasyGUI_ControlWindowHWND;//窗口句柄
        ID2D1HwndRenderTarget* EasyGUI_RenderTarget; ID2D1HwndRenderTarget* EasyGUI_ControlRenderTarget;//Direct2D绘制目标
        ID2D1SolidColorBrush* CacheSolBrush; ID2D1LinearGradientBrush* CacheLGraBrush; ID2D1RadialGradientBrush* CacheRGraBrush;//Direct2D画笔缓存
        POINT EasyGUI_MousePos; RECT EasyGUI_WindowPos, EasyGUI_ControlWindowPos;//窗口鼠标坐标
        string EasyGUI_Font = "Verdana";//字体名称
        float EasyGUI_FontSize = 12;//字体大小
        Vector4 EasyGUI_Color = { 255,255,255 };//主题颜色
        int EasyGUI_Alpha = 250;//窗口透明度
        double EasyGUI_DrawFPS, EasyGUI_DrawFrame;//绘制帧数
        bool InputState_IsWindShow, InputState_InBlock, InputState_IsSlider, InputState_IsMove, InputState_ControlWindowShow;//防止控件函数之间冲突的判断变量
        inline void MoveControlWindow(int X, int Y, int Width, int Height) noexcept//移动控件窗口位置
        {
            SetLayeredWindowAttributes(EasyGUI_ControlWindowHWND, RGB(0, 0, 0), 255, 2);
            MoveWindow(EasyGUI_ControlWindowHWND, X, Y, Width, Height, true);
            EasyGUI_ControlRenderTarget->EndDraw(); EasyGUI_ControlRenderTarget->Resize(D2D1::SizeU(Width, Height));
            ShowWindow(EasyGUI_ControlWindowHWND, SW_SHOW);
        }
        inline ID2D1HwndRenderTarget* CreateHWNDRenderTarget(HWND WindowHWND, Vector2 PaintSize, long CreateID) noexcept//创建单独渲染目标
        {
            static unordered_map<long, ID2D1HwndRenderTarget*> RenderTarget;
            if (!RenderTarget[CreateID])
            {
                ID2D1Factory* EasyGUI_RenderFactory{}; D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &EasyGUI_RenderFactory);
                EasyGUI_RenderFactory->CreateHwndRenderTarget(
                    D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_HARDWARE, D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)),
                    D2D1::HwndRenderTargetProperties(WindowHWND, D2D1::SizeU(PaintSize.x, PaintSize.y), D2D1_PRESENT_OPTIONS_IMMEDIATELY), &RenderTarget[CreateID]);
                EasyGUI_RenderFactory->Release();
                RenderTarget[CreateID]->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED); RenderTarget[CreateID]->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_DEFAULT);//抗锯齿设置
            }
            return RenderTarget[CreateID];
        }
        inline ID2D1BitmapRenderTarget* CreateBitmapRenderTarget(ID2D1RenderTarget* MainTarget, Vector2 PaintSize, long CreateID) noexcept//创建控件渲染目标
        {
            static unordered_map<long, ID2D1BitmapRenderTarget*> RenderBitMap;
            if (!RenderBitMap[CreateID])
            {
                MainTarget->CreateCompatibleRenderTarget(D2D1::SizeF(PaintSize.x, PaintSize.y), &RenderBitMap[CreateID]);
                RenderBitMap[CreateID]->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED); RenderBitMap[CreateID]->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_DEFAULT);//抗锯齿设置
            }
            else {
                const auto OldSize = RenderBitMap[CreateID]->GetSize();
                if (OldSize.width != PaintSize.x || OldSize.height != PaintSize.y)
                {
                    RenderBitMap[CreateID]->Release();
                    MainTarget->CreateCompatibleRenderTarget(D2D1::SizeF(PaintSize.x, PaintSize.y), &RenderBitMap[CreateID]);
                }
            }
            return RenderBitMap[CreateID];
        }
        inline D2D1::ColorF D2DCol(Vector4 Color = { 0,0,0,0 }) noexcept { return D2D1::ColorF((float)Color.r / 255, (float)Color.g / 255, (float)Color.b / 255, (float)Color.a / 255); };//颜色转换
        inline bool KeyEvent(int VK_CODE, bool Release = false) noexcept//检测按键是否被按下 (后者参数为按下后是否立马释放)
        {
            const bool Key_State = GetAsyncKeyState(VK_CODE) & 0x8000;
            if (Release && Key_State)//释放按键
            {
                if (VK_CODE == VK_LBUTTON)mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//鼠标键盘判断
                else if (VK_CODE == VK_RBUTTON)mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                else if (VK_CODE == VK_MBUTTON)mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
                else keybd_event(VK_CODE, 0, KEYEVENTF_KEYUP, 0);
            }
            return Key_State;
        }
        inline float SystemTick() noexcept { return duration<double, milli>(steady_clock::now().time_since_epoch()).count(); }//获取程序毫秒单位运行时间
        inline bool MouseJudgment(int X, int Y, int Width, int Height) noexcept//检测鼠标坐标是否在窗口矩形坐标内
        {
            Y += 2;
            return EasyGUI_MousePos.x - EasyGUI_WindowPos.left >= X && EasyGUI_MousePos.x - EasyGUI_WindowPos.left <= X + Width && EasyGUI_MousePos.y - EasyGUI_WindowPos.top >= Y && EasyGUI_MousePos.y - EasyGUI_WindowPos.top <= Y + Height;
        }
        template<class CreateClassName> inline float Animation(float Value, float Speed = 5, long Key = 0) noexcept//快到慢动画
        {
            static unordered_map<long, float> ReturnValue; if (!ReturnValue.count(Key)) ReturnValue[Key] = Value;
            if (Speed == 1) { ReturnValue[Key] = Value; return ReturnValue[Key]; }
            if (Value > ReturnValue[Key])ReturnValue[Key] += (Value - ReturnValue[Key]) / Speed;
            else if (Value < ReturnValue[Key])ReturnValue[Key] -= (ReturnValue[Key] - Value) / Speed;
            return ReturnValue[Key];
        }
    public:
        inline void Render_Rect(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, Vector4 Color) noexcept//绘制实心矩形
        {
            Target->CreateSolidColorBrush(D2DCol(Color), &CacheSolBrush);
            Target->FillRectangle(D2D1::RectF(X, Y, X + Width, Y + Height), CacheSolBrush);
            CacheSolBrush->Release();
        }
        inline void Render_GradientRect(ID2D1RenderTarget* Target, int X, int Y, int Width, int Height, Vector4 Color_1, Vector4 Color_2, bool Direction = 0) noexcept//绘制渐变矩形
        {
            static D2D1_GRADIENT_STOP GradStop[2]; GradStop[0].position = 0; GradStop[1].position = 1; GradStop[0].color = D2DCol(Color_1); GradStop[1].color = D2DCol(Color_2);
            ID2D1GradientStopCollection* pGradStop; Target->CreateGradientStopCollection(GradStop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &pGradStop);
            if (Direction)Target->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(X, Y), D2D1::Point2F(X, Y + Height)), pGradStop, &CacheLGraBrush);
            else Target->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(X, Y), D2D1::Point2F(X + Width, Y)), pGradStop, &CacheLGraBrush);
            Target->FillRectangle(D2D1::RectF(X, Y, X + Width, Y + Height), CacheLGraBrush);
            CacheLGraBrush->Release(); pGradStop->Release();
        }
        inline Vector2 Render_String(ID2D1RenderTarget* Target, int X, int Y, string String, Vector4 Color, string FontName = "Verdana", float FontSize = 15, int FontWeight = 400, Vector2 StringLimit = { 0,0 }) noexcept//绘制文字
        {
            IDWriteFactory* WriteFactory; IDWriteTextFormat* TextFormat; IDWriteTextLayout* Layout;
            DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(WriteFactory), reinterpret_cast<IUnknown**>(&WriteFactory));
            WriteFactory->CreateTextFormat(wstring(FontName.begin(), FontName.end()).c_str(), 0, (DWRITE_FONT_WEIGHT)FontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, FontSize, L"", &TextFormat);
            TextFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            const auto TextSize = MultiByteToWideChar(0, 0, String.c_str(), -1, 0, 0);//转码UTF-8 (为了显示中文)
            wchar_t* TextCache = new wchar_t[TextSize]; MultiByteToWideChar(0, 0, String.c_str(), -1, TextCache, TextSize);
            if (!StringLimit.x)StringLimit.x = 9999; if (!StringLimit.y)StringLimit.y = 9999;
            WriteFactory->CreateTextLayout(TextCache, TextSize, TextFormat, StringLimit.x, StringLimit.y, &Layout); delete[] TextCache;
            static DWRITE_TEXT_METRICS Metrics{}; Layout->GetMetrics(&Metrics); if (X >= 10000)X -= 10000 + Metrics.width / 2; if (Y >= 10000)Y -= 10000 + Metrics.height / 2;
            if (X || Y)
            {
                if (Color.D_Alpha(0) != Vector4{ 50,50,50,0 })
                {
                    Target->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, Color.a), &CacheSolBrush);
                    Target->DrawTextLayout(D2D1::Point2F(X + 1, Y + 1), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                    CacheSolBrush->Release();
                }
                Target->CreateSolidColorBrush(D2DCol(Color), &CacheSolBrush);
                Target->DrawTextLayout(D2D1::Point2F(X, Y), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                CacheSolBrush->Release();
            }
            WriteFactory->Release(); TextFormat->Release(); Layout->Release();
            return { (int)Metrics.width,(int)Metrics.height };
        }
        inline Vector2 Render_MiniString(ID2D1RenderTarget* Target, int X, int Y, string String, Vector4 Color, float FontSize = 10, int FontWeight = 600) noexcept//绘制简单文字
        {
            IDWriteFactory* WriteFactory; IDWriteTextFormat* TextFormat; IDWriteTextLayout* Layout;
            DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(WriteFactory), reinterpret_cast<IUnknown**>(&WriteFactory));
            WriteFactory->CreateTextFormat(L"Verdana", 0, (DWRITE_FONT_WEIGHT)FontWeight, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, FontSize, L"", &TextFormat);
            TextFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            const auto TextSize = MultiByteToWideChar(0, 0, String.c_str(), -1, 0, 0);//转码UTF-8 (为了显示中文)
            wchar_t* TextCache = new wchar_t[TextSize]; MultiByteToWideChar(0, 0, String.c_str(), -1, TextCache, TextSize);
            WriteFactory->CreateTextLayout(TextCache, TextSize, TextFormat, 9999, 9999, &Layout); delete[] TextCache;
            static DWRITE_TEXT_METRICS Metrics{}; Layout->GetMetrics(&Metrics); if (X >= 10000)X -= 10000 + Metrics.width / 2; if (Y >= 10000)Y -= 10000 + Metrics.height / 2;
            if (X || Y)
            {
                Target->CreateSolidColorBrush(D2DCol({ 0,0,0 }), &CacheSolBrush);
                Target->DrawTextLayout(D2D1::Point2F(X + 1, Y + 1), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X - 1, Y - 1), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X + 1, Y - 1), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X - 1, Y + 1), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X + 1, Y), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X, Y + 1), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X - 1, Y), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                Target->DrawTextLayout(D2D1::Point2F(X, Y - 1), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                CacheSolBrush->Release();
                Target->CreateSolidColorBrush(D2DCol(Color), &CacheSolBrush);
                Target->DrawTextLayout(D2D1::Point2F(X, Y), Layout, CacheSolBrush, D2D1_DRAW_TEXT_OPTIONS_CLIP);
                CacheSolBrush->Release();
            }
            WriteFactory->Release(); TextFormat->Release(); Layout->Release();
            return { (int)Metrics.width,(int)Metrics.height };
        }
        //------------------------------------------------------------------------------------------------------------------------------
        EasyGUI(Vector2 WindowSize, string WindowTitle) noexcept//初始化EasyGUI
        {
            const auto WindowName = wstring(WindowTitle.begin(), WindowTitle.end());//窗口类名
            WNDCLASS WindowClass{}; WindowClass.lpfnWndProc = EasyGUI_WindowProcess; WindowClass.hInstance = GetModuleHandle(0); WindowClass.lpszClassName = WindowName.c_str(); RegisterClass(&WindowClass);//窗口注册类
            while (true)//防止创建失败
            {
                EasyGUI_WindowHWND = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW, WindowName.c_str(), WindowName.c_str(), WS_POPUP, GetSystemMetrics(0) / 2 - WindowSize.x / 2, GetSystemMetrics(1) / 2 - WindowSize.y / 2, WindowSize.x, WindowSize.y, 0, 0, 0, 0); if (!EasyGUI_WindowHWND)continue;
                EasyGUI_ControlWindowHWND = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW, WindowName.c_str(), WindowName.c_str(), WS_POPUP, 0, 0, 0, 0, EasyGUI_WindowHWND, 0, 0, 0);
                //---------------------------------------------------------------------------------------------------
                ShowWindow(EasyGUI_WindowHWND, SW_SHOW); SetForegroundWindow(EasyGUI_WindowHWND); UpdateWindow(EasyGUI_WindowHWND);//显示窗口
                SetLayeredWindowAttributes(EasyGUI_WindowHWND, RGB(0, 0, 0), EasyGUI_Alpha, 2);//设置窗口透明度
                MARGINS Margin{ -1 }; DwmExtendFrameIntoClientArea(EasyGUI_WindowHWND, &Margin);//设置窗口模糊化
                //---------------------------------------------------------------------------------------------------Direct2D初始化
                EasyGUI_RenderTarget = CreateHWNDRenderTarget(EasyGUI_WindowHWND, WindowSize, -1);
                EasyGUI_ControlRenderTarget = CreateHWNDRenderTarget(EasyGUI_ControlWindowHWND, WindowSize, -2);
                return;
            }
        }
        inline void Draw(bool State = false) noexcept//绘制全部内容 0:开始绘制 1:结束绘制
        {
            if (!State)
            {
                MSG MSG{}; while (PeekMessage(&MSG, 0, 0, 0, 1)) { TranslateMessage(&MSG); DispatchMessage(&MSG); }//窗口消息循环
                InputState_IsWindShow = GetForegroundWindow() == EasyGUI_WindowHWND, InputState_InBlock = false;//重置控件冲突判断变量
                GetCursorPos(&EasyGUI_MousePos); GetWindowRect(EasyGUI_WindowHWND, &EasyGUI_WindowPos); GetWindowRect(EasyGUI_ControlWindowHWND, &EasyGUI_ControlWindowPos);//刷新鼠标窗口坐标
                if (InputState_ControlWindowShow && !(EasyGUI_MousePos.x > EasyGUI_ControlWindowPos.left && EasyGUI_MousePos.x < EasyGUI_ControlWindowPos.right && EasyGUI_MousePos.y > EasyGUI_ControlWindowPos.top && EasyGUI_MousePos.y < EasyGUI_ControlWindowPos.bottom) && (KeyEvent(VK_LBUTTON, true) || KeyEvent(VK_RBUTTON, true)))InputState_ControlWindowShow = false; if (!InputState_ControlWindowShow)ShowWindow(EasyGUI_ControlWindowHWND, 0);//保持控件窗口最前端
                EasyGUI_RenderTarget->Resize(D2D1::SizeU(EasyGUI_WindowPos.right - EasyGUI_WindowPos.left, EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top));//刷新画布大小
                EasyGUI_RenderTarget->BeginDraw(); EasyGUI_ControlRenderTarget->BeginDraw();//开始绘制
                EasyGUI_RenderTarget->Clear(D2DCol()); EasyGUI_ControlRenderTarget->Clear(D2DCol());//清空绘制内容
            }
            else {
                EasyGUI_RenderTarget->EndDraw(); EasyGUI_ControlRenderTarget->EndDraw();//结束绘制
                const auto Tick = SystemTick(); EasyGUI_DrawFrame = Tick - EasyGUI_DrawFrame; if (EasyGUI_DrawFrame > 0)EasyGUI_DrawFPS = 1000.f / EasyGUI_DrawFrame; EasyGUI_DrawFrame = Tick;//计算绘制帧率
                KeyEvent(VK_UP, true); KeyEvent(VK_DOWN, true);//释放按键消息
            }
        }
        //------------------------------------------------------------------------------------------------------------------------------
        inline string Style_GetFont() noexcept { return EasyGUI_Font; }//获取全局字体
        inline void Style_SetFont(string FontName) noexcept { if (FontName == "")EasyGUI_Font = "Verdana"; else EasyGUI_Font = FontName; }//设置全局字体
        inline float Style_GetFontSize() noexcept { return EasyGUI_FontSize; }//获取全局字体大小
        inline void Style_SetFontSize(float FontSize) noexcept { if (!FontSize)EasyGUI_FontSize = 12; else EasyGUI_FontSize = FontSize; }//设置全局字体大小
        inline Vector4 Style_GetColor() noexcept { return EasyGUI_Color; }//获取全局主题颜色
        inline void Style_SetColor(Vector4 MainColor) noexcept { EasyGUI_Color = MainColor.D_Alpha(255); }//设置全局主题颜色
        //------------------------------------------------------------------------------------------------------------------------------
        inline HWND Window_HWND() noexcept { return EasyGUI_WindowHWND; }//获取窗口HWND
        inline Vector2 Window_GetPos() noexcept { return { EasyGUI_WindowPos.left ,EasyGUI_WindowPos.top }; }//获取窗口坐标
        inline void Window_SetPos(Vector2 WindowPos) noexcept//修改窗口坐标
        {
            MoveWindow(EasyGUI_WindowHWND, WindowPos.x, WindowPos.y, EasyGUI_WindowPos.right - EasyGUI_WindowPos.left, EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top, true);
        }
        inline Vector2 Window_GetSize() noexcept { return { EasyGUI_WindowPos.right - EasyGUI_WindowPos.left ,EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top }; }//获取窗口大小
        inline void Window_SetSize(Vector2 WindowSize) noexcept//修改窗口大小
        {
            MoveWindow(EasyGUI_WindowHWND, EasyGUI_WindowPos.left, EasyGUI_WindowPos.top, WindowSize.x, WindowSize.y, true);
        }
        inline int Window_GetAlpha() noexcept { return EasyGUI_Alpha; }//获取窗口透明度
        inline void Window_SetAlpha(int WindowAlpha) noexcept//修改窗口透明度
        {
            if (WindowAlpha == EasyGUI_Alpha)return; if (WindowAlpha < 10)WindowAlpha = 10;
            SetLayeredWindowAttributes(EasyGUI_WindowHWND, RGB(0, 0, 0), WindowAlpha, 2);
            EasyGUI_Alpha = WindowAlpha;
        }
        inline void Window_Show() noexcept//修改窗口为最前端
        {
            SetForegroundWindow(EasyGUI_WindowHWND);
            ShowWindow(EasyGUI_WindowHWND, true);
        }
        inline void Window_Hide() noexcept//隐藏窗口
        {
            ShowWindow(EasyGUI_WindowHWND, false);
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
        inline bool Window_AllowMove(int DrawDelay = 3) noexcept//允许拖动窗口 (在GUI循环线程内加入此函数不需要添加延时函数来降低占用)
        {
            static bool AntiOff, SaveMousePos; static Vector2 OldPos;//按下时坐标
            if (GetForegroundWindow() == EasyGUI_WindowHWND || InputState_ControlWindowShow)//检测窗口是否在最前端
            {
                GetCursorPos(&EasyGUI_MousePos); GetWindowRect(EasyGUI_WindowHWND, &EasyGUI_WindowPos);//刷新鼠标窗口坐标
                if (!AntiOff && !InputState_InBlock && !InputState_IsSlider && !InputState_ControlWindowShow && KeyEvent(VK_LBUTTON))//触发移动窗口机制
                {
                    if (SaveMousePos) { OldPos = { EasyGUI_MousePos.x - EasyGUI_WindowPos.left ,EasyGUI_MousePos.y - EasyGUI_WindowPos.top }; SaveMousePos = false; }
                    AntiOff = true;//触发移动窗口事件变量
                }
                else if (AntiOff && !OldPos.IsZero() && KeyEvent(VK_LBUTTON))//移动窗口时
                {
                    InputState_IsMove = true;
                    MoveWindow(EasyGUI_WindowHWND, EasyGUI_MousePos.x - OldPos.x, EasyGUI_MousePos.y - OldPos.y, EasyGUI_WindowPos.right - EasyGUI_WindowPos.left, EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top, true);//移动窗口到鼠标坐标
                    const auto Tick = SystemTick(); static auto OldTick = Tick; if (Tick - OldTick >= 50) { OldTick = Tick; return false; }return true;//定时返回false (用来刷新面板)
                }
                else {//闲置时
                    AntiOff = false; SaveMousePos = true; InputState_IsMove = false;
                    if (!InputState_IsSlider)Sleep(DrawDelay);//降低硬件占用
                }
            }
            else Sleep(20); return false;
        }
        //------------------------------------------------------------------------------------------------------------------------------
        inline void GUI_BackGround(int StyleCode = 2) noexcept//背景
        {
            const auto Tick = SystemTick();
            const Vector2 Window_Size = { EasyGUI_WindowPos.right - EasyGUI_WindowPos.left ,EasyGUI_WindowPos.bottom - EasyGUI_WindowPos.top };
            vector<int> LineColor = { 0,255,255,255,0,255,255,255,0 }, StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,5,5,5,30,30,30 };
            if (StyleCode == 0)//毛都没有
            {
                LineColor = { 16,16,16,16,16,16,16,16,16 };
                StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,15,15,15,EasyGUI_Color.r / 10,EasyGUI_Color.g / 10,EasyGUI_Color.b / 10 };
            }
            else if (StyleCode == 1)//彩色变色渐变条
            {
                const auto AnimaSpeed = 3000.f;//渐变条变化速度
                LineColor = {
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 3) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 5) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 7) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 2) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 4) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 6) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 1) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 3) * 127 + 128),
                    (int)floor(sin(Tick / AnimaSpeed * 2 + 5) * 127 + 128),
                };
                StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,3,3,3,EasyGUI_Color.r / 10,EasyGUI_Color.g / 10,EasyGUI_Color.b / 10 };
                EasyGUI_Color = { LineColor[3],LineColor[4], LineColor[5] };
            }
            else if (StyleCode == 2)//主题色渐变条
            {
                const auto AnimaSpeed = 600.f;//渐变条变化速度
                const Vector3 Sins = { sin(Tick / AnimaSpeed), sin(Tick / AnimaSpeed + 1),sin(Tick / AnimaSpeed + 2) };
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
                for (size_t i = 0; i <= 8; ++i)if (LineColor[i] < 50)LineColor[i] = 50;//颜色最小值
                StyleColor = { 0,0,0,60,60,60,30,30,30,15,15,15,0,0,0,EasyGUI_Color.r / 10,EasyGUI_Color.g / 10,EasyGUI_Color.b / 10 };
            }
            Render_Rect(EasyGUI_RenderTarget, 0, 0, Window_Size.x, Window_Size.y, { StyleColor[0], StyleColor[1], StyleColor[2] });
            Render_Rect(EasyGUI_RenderTarget, 1, 1, Window_Size.x - 2, Window_Size.y - 2, { StyleColor[3], StyleColor[4], StyleColor[5] });
            Render_Rect(EasyGUI_RenderTarget, 2, 2, Window_Size.x - 4, Window_Size.y - 4, { StyleColor[6], StyleColor[7], StyleColor[8] });
            Render_Rect(EasyGUI_RenderTarget, 5, 5, Window_Size.x - 10, Window_Size.y - 10, { StyleColor[3], StyleColor[4], StyleColor[5] });
            Render_GradientRect(EasyGUI_RenderTarget, 6, 6, Window_Size.x - 12, Window_Size.y - 12, { StyleColor[12], StyleColor[13], StyleColor[14] }, { StyleColor[15], StyleColor[16], StyleColor[17] }, true);
            if (StyleCode)//彩虹条
            {
                Render_GradientRect(EasyGUI_RenderTarget, 7, 7, (Window_Size.x - 14) / 2, 2, { LineColor[0] / 2, LineColor[1] / 2, LineColor[2] / 2 }, { LineColor[3] / 2, LineColor[4] / 2, LineColor[5] / 2 }, false);
                Render_GradientRect(EasyGUI_RenderTarget, 7 + (Window_Size.x - 14) / 2, 7, (Window_Size.x - 14) / 2, 2, { LineColor[3] / 2, LineColor[4] / 2, LineColor[5] / 2 }, { LineColor[6] / 2, LineColor[7] / 2, LineColor[8] / 2 }, false);
                Render_GradientRect(EasyGUI_RenderTarget, 7, 7, (Window_Size.x - 14) / 2, 1, { LineColor[0], LineColor[1], LineColor[2] }, { LineColor[3], LineColor[4], LineColor[5] }, false);
                Render_GradientRect(EasyGUI_RenderTarget, 7 + (Window_Size.x - 14) / 2, 7, (Window_Size.x - 14) / 2, 1, { LineColor[3], LineColor[4], LineColor[5] }, { LineColor[6], LineColor[7], LineColor[8] }, false);
            }
        }
        inline void GUI_Block(EasyGUI_Block& Block, int X, int Y, int Width, int Height, string BlockTitle) noexcept//区块
        {
            if (Width < 300)Width = 300; else if (Width > 800)Width = 800;//宽度限制
            static int BlockID = 0; if (!Block.ID) { BlockID++; Block.ID = BlockID; }//分配唯一BlockID
            if (Block.Target)Block.Target->EndDraw();//结束绘制
            Block.Title = BlockTitle; Block.Pos = { X,Y }; Block.Size = { Width,Height }; Block.IsInBlock = MouseJudgment(X, Y, Width, Height); if (Block.IsInBlock)InputState_InBlock = true;
            if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && Block.IsInBlock && !InputState_ControlWindowShow && !Block.IsInScrollArea && Block.Line > Height)//滚轮滚动
            {
                if (KeyEvent(VK_UP, true))Block.Start -= 50; else if (KeyEvent(VK_DOWN, true))Block.Start += 50;//滚轮按键判定与滚动幅度
                if (Block.Start < 0)Block.Start = 0; else if (Block.Start > Block.Line - Height)Block.Start = Block.Line - Height;//限制滚动区域
            }
            Block.IsInScrollArea = false; Block.Line = 30; Block.Target = CreateBitmapRenderTarget(EasyGUI_RenderTarget, { Width,Height * 5 }, Block.ID);//创建区块渲染目标
            Render_Rect(EasyGUI_RenderTarget, X, Y, Width, Height, { 0,0,0 });//黑色外边框
            Render_Rect(EasyGUI_RenderTarget, X + 1, Y + 1, Width - 2, Height - 2, { 60,60,60 });//白色外边框
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 2, Width - 4, Height - 4, { 10,10,10 }, EasyGUI_Color / 10, true);//渐变背景
            if (BlockTitle != "")
            {
                const auto TextSize = Render_String(EasyGUI_RenderTarget, 0, 0, BlockTitle, { 0,0,0 }, "Verdana", 13, 600).x + 1;//获取文字大小
                Render_GradientRect(EasyGUI_RenderTarget, X + TextSize + 15, Y + 1, Width - TextSize - 16, 1, { 20,20,20 }, { 60,60,60 });//渐变头条
                Render_Rect(EasyGUI_RenderTarget, X + 15, Y, TextSize + 10, 3, { 10,10,10 });//文字后遮挡边框
            }
            Y += 2; Height -= 4;
            const auto PaintStartPos = Animation<class EasyGUI_Block_ScroolAnimation>(Block.Start, 3, Block.ID);//滑动动画
            ID2D1Bitmap* BitMap; Block.Target->GetBitmap(&BitMap); EasyGUI_RenderTarget->DrawBitmap(BitMap,
                D2D1::RectF(X, Y, X + Width, Y + Height), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
                D2D1::RectF(0, PaintStartPos, Width, PaintStartPos + Height)); BitMap->Release();
            Block.Target->BeginDraw(); Block.Target->Clear(D2DCol());
            Y -= 2; Height += 4;
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 2, Width - 4, 30, { 10,10,10,255 }, { 10,10,10,0 }, true);//顶部遮罩
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + Height - 25 - 2, Width - 4, 25, EasyGUI_Color.D_Alpha(0) / 10, EasyGUI_Color.D_Alpha(255) / 10, true);//底部遮罩
            Render_String(EasyGUI_RenderTarget, X + 20, Y - 9, BlockTitle, { 200,200,200 }, "Verdana", 13, 600);
        }
        inline void GUI_RadioBlock(int X, int Y, int Width, int Height, string BlockTitle, vector<string>BlockText, int& BlockPage) noexcept//区块_大区块选择器
        {
            if (BlockPage < 0)BlockPage = 0; else if (BlockPage >= BlockText.size())BlockPage = BlockText.size() - 1;//范围限制
            if (MouseJudgment(X, Y, Width, Height))InputState_InBlock = true;//鼠标在区块内
            Render_Rect(EasyGUI_RenderTarget, X, Y, Width, Height, { 0,0,0 });//黑色外边框
            Render_Rect(EasyGUI_RenderTarget, X + 1, Y + 1, Width - 2, Height - 2, { 60,60,60 });//白色外边框
            Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 2, Width - 4, Height - 4, EasyGUI_Color / 10, { 10,10,10 }, true);//主题色渐变背景
            if (BlockTitle != "")
            {
                const auto TextSize = Render_String(EasyGUI_RenderTarget, 0, 0, BlockTitle, { 0,0,0 }, "Verdana", 13, 600).x + 1;//获取文字大小
                Render_GradientRect(EasyGUI_RenderTarget, X + TextSize + 10, Y + 1, Width - TextSize - 16, 1, { 20,20,20 }, { 60,60,60 });//渐变头条
                Render_Rect(EasyGUI_RenderTarget, X + 10, Y, TextSize + 10, 3, EasyGUI_Color / 10);//文字后遮挡边框
            }
            Render_String(EasyGUI_RenderTarget, X + 15, Y - 8, BlockTitle, { 200,200,200 }, "Verdana", 13, 600);
            for (int i = 0; i < BlockText.size(); ++i)//遍历坐标
            {
                if (MouseJudgment(X, Y + 14 + 30 * i, Width, 23))
                {
                    Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 16 + 30 * i, Width - 4, 23, EasyGUI_Color / 6, { 20,20,20 });
                    if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && BlockPage != i && KeyEvent(VK_LBUTTON, true))BlockPage = i;//鼠标赋值选择
                }
                if (BlockPage == i)
                {
                    Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 16 + 30 * BlockPage, Width - 4, 25, EasyGUI_Color.D_Alpha(0) / 4, EasyGUI_Color / 4);
                    Render_GradientRect(EasyGUI_RenderTarget, X + 2, Y + 16 + 30 * BlockPage + 1, Width - 4, 23, EasyGUI_Color / 4, { 20,20,20 });
                }
                int StrWidth = 400; if (BlockPage == i)StrWidth = 600;//文字宽度
                Render_String(EasyGUI_RenderTarget, 10000 + X + Width / 2, 10000 + Y + 28 + 30 * i, BlockText[i], EasyGUI_Color.Min_Bri(180).Max_Bri(200), EasyGUI_Font, EasyGUI_FontSize + 1, StrWidth);
            }
        }
        inline void GUI_Text(EasyGUI_Block& Block, string Text, Vector4 TextColor = { 200,200,200 }) noexcept//行文字
        {
            //Render_Rect(Block.Target, 0, Block.Line, 9999, 1, { 255,0,0,100 });//Debug
            Render_String(Block.Target, 45, 10000 + Block.Line, Text, TextColor, EasyGUI_Font, EasyGUI_FontSize); Block.Line += 25;
        }
        template<typename VarType> inline void GUI_Variable(EasyGUI_Block& Block, string VarName, VarType Variable, Vector4 TextColor = { 200,200,200 }) noexcept//变量行文字
        {
            Render_String(Block.Target, 45, 10000 + Block.Line, VarName + " = " + to_string(Variable), TextColor, EasyGUI_Font, EasyGUI_FontSize); Block.Line += 25;
        }
        inline void GUI_Checkbox(EasyGUI_Block& Block, string Text, bool& CheckboxValue, Vector4 TextColor = { 200,200,200 }) noexcept//单选框
        {
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + 25, Block.Pos.y - Block.Start + Block.Line - 5, Render_String(Block.Target, 0, 0, Text, {}, EasyGUI_Font, EasyGUI_FontSize).x + 25, 10);//窗口检测
            if (InputState_IsWindShow && Block.IsInBlock && !InputState_IsSlider && !InputState_IsMove && DetectMousePos && KeyEvent(VK_LBUTTON, true))CheckboxValue = !CheckboxValue;//当最前端窗口为GUI窗口接收按钮事件
            Render_Rect(Block.Target, 25, Block.Line - 5, 10, 10, { 0,0,0 });
            if (DetectMousePos)Render_GradientRect(Block.Target, 25 + 1, Block.Line - 5 + 1, 8, 8, EasyGUI_Color / 3, { 25,25,25 }, true);
            else Render_GradientRect(Block.Target, 25 + 1, Block.Line - 5 + 1, 8, 8, EasyGUI_Color / 4, { 25,25,25 }, true);
            if (CheckboxValue)Render_GradientRect(Block.Target, 25 + 1, Block.Line - 5 + 1, 8, 8, EasyGUI_Color, EasyGUI_Color / 5, true);
            Render_String(Block.Target, 45, 10000 + Block.Line, Text, TextColor, EasyGUI_Font, EasyGUI_FontSize);
            Block.Line += 25;
        }
        inline void GUI_Button(EasyGUI_Block& Block, string Text, bool& ButtonValue) noexcept//单击按钮
        {
            if (ButtonValue)Sleep(30);//更好地让其他循环线程接收
            Block.Line += 3;
            const Vector2 ButtonPos = { 45,Block.Line - 15 }, ButtonSize = { (int)(Block.Size.x / 1.5), 28 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            if (DetectMousePos)Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 6, { 20,20,20 }, true);
            else Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 7, { 20,20,20 }, true);
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            ButtonValue = InputState_IsWindShow && Block.IsInBlock && !InputState_IsSlider && !InputState_IsMove && DetectMousePos && KeyEvent(VK_LBUTTON, true);//按钮赋值
            Block.Line += 26;
        }
        inline bool GUI_Button(EasyGUI_Block& Block, string Text) noexcept//单击按钮
        {
            Block.Line += 3;
            const Vector2 ButtonPos = { 45,Block.Line - 15 }, ButtonSize = { (int)(Block.Size.x / 1.5), 28 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            if (DetectMousePos)Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 6, { 20,20,20 }, true);
            else Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 7, { 20,20,20 }, true);
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            Block.Line += 26;
            return InputState_IsWindShow && Block.IsInBlock && !InputState_IsSlider && !InputState_IsMove && DetectMousePos && KeyEvent(VK_LBUTTON, true);
        }
        inline void GUI_LongPressButton(EasyGUI_Block& Block, string Text, bool& ButtonValue) noexcept//单击长按按钮
        {
            if (ButtonValue)Sleep(30);//更好地让其他循环线程接收
            Block.Line += 3;
            const Vector2 ButtonPos = { 45,Block.Line - 15 }, ButtonSize = { (int)(Block.Size.x / 1.5), 28 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            static unordered_map<long, float> PressTime;//防止多函数冲突
            if (InputState_IsWindShow && Block.IsInBlock && !InputState_IsSlider && !InputState_IsMove && DetectMousePos && KeyEvent(VK_LBUTTON))
            {
                PressTime[Block.ID + Block.Line] += 0.03f;//计时器增加速度
                if (PressTime[Block.ID + Block.Line] >= 1) { PressTime[Block.ID + Block.Line] = 1; ButtonValue = true; KeyEvent(VK_LBUTTON, true); }
            }
            else { PressTime[Block.ID + Block.Line] = 0; ButtonValue = false; }//重置计时器
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            if (DetectMousePos)Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 6, { 20,20,20 }, true);
            else Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 7, { 20,20,20 }, true);
            Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, (ButtonSize.x - 4) * PressTime[Block.ID + Block.Line], ButtonSize.y - 4, EasyGUI_Color / 3, { 20,20,20 }, true);
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 600);
            Block.Line += 26;
        }
        inline void GUI_MiniButton(EasyGUI_Block& Block, bool& ButtonValue, int Offset = 0, string Text = "...") noexcept//单击按钮(小号)
        {
            if (ButtonValue)Sleep(30);//更好地让其他循环线程接收
            const Vector2 ButtonPos = { 5 + Offset,Block.Line - 10 }, ButtonSize = { 15, 20 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            if (DetectMousePos)Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 6, { 20,20,20 }, true);
            else Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 7, { 20,20,20 }, true);
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2 + 1, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize - 3);
            ButtonValue = InputState_IsWindShow && Block.IsInBlock && !InputState_IsSlider && !InputState_IsMove && DetectMousePos && KeyEvent(VK_LBUTTON, true);//按钮赋值
        }
        inline bool GUI_MiniButton(EasyGUI_Block& Block, int Offset = 0, string Text = "...") noexcept//单击按钮(小号)
        {
            const Vector2 ButtonPos = { 5 + Offset,Block.Line - 10 }, ButtonSize = { 15, 20 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y);//窗口检测机制
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            if (DetectMousePos)Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 6, { 20,20,20 }, true);
            else Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, EasyGUI_Color / 7, { 20,20,20 }, true);
            Render_String(Block.Target, 10000 + ButtonPos.x + ButtonSize.x / 2 + 1, 10000 + Block.Line, Text, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize - 3);
            return InputState_IsWindShow && Block.IsInBlock && !InputState_IsSlider && !InputState_IsMove && DetectMousePos && KeyEvent(VK_LBUTTON, true);
        }
        template<class ValueClass> inline void GUI_Slider(EasyGUI_Block& Block, string Text, ValueClass StartValue, ValueClass EndValue, ValueClass& SliderValue, string Unit = "", Vector4 TextColor = { 200,200,200 }) noexcept//滑条
        {
            const Vector2 NormalSliderPos = { 45 ,Block.Line + 4 }, NormalSliderSize = { (int)(Block.Size.x / 1.5) ,8 };//滑条坐标,滑条大小
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + NormalSliderPos.x, Block.Pos.y - Block.Start + NormalSliderPos.y, NormalSliderSize.x, NormalSliderSize.y);//窗口检测
            static unordered_map<long, bool> OutSide;//防止指针脱落时失去控制力
            if (InputState_IsWindShow && !InputState_IsMove)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (DetectMousePos && Block.IsInBlock)//当鼠标移动到滑条上方 按键反馈事件
                {
                    if (KeyEvent(VK_LEFT, true) || KeyEvent(VK_UP, true)) { if ((ValueClass)0.1 == 0)SliderValue--; else SliderValue -= 0.05; }//检测是否是浮点值
                    else if (KeyEvent(VK_RIGHT, true) || KeyEvent(VK_DOWN, true)) { if ((ValueClass)0.1 == 0)SliderValue++; else SliderValue += 0.05; }
                    if (KeyEvent(VK_LBUTTON) && !OutSide[Block.ID + Block.Line])OutSide[Block.ID + Block.Line] = true;
                    Block.IsInScrollArea = true;//禁止区块滑动
                }
                if (OutSide[Block.ID + Block.Line] && KeyEvent(VK_LBUTTON)) { SliderValue = ((EasyGUI_MousePos.x - Block.Pos.x - EasyGUI_WindowPos.left - 45) * (EndValue - StartValue) / NormalSliderSize.x) + StartValue; InputState_IsSlider = true; }
                else if (!KeyEvent(VK_LBUTTON)) { OutSide[Block.ID + Block.Line] = false; InputState_IsSlider = false; }
            }
            int SliderSize = (float)(SliderValue - StartValue) / (float)(EndValue - StartValue) * NormalSliderSize.x; if (SliderSize < 0)SliderSize = 0; else if (SliderSize > NormalSliderSize.x - 2)SliderSize = NormalSliderSize.x - 2;//滑条长度计算
            if (SliderValue <= StartValue)SliderValue = StartValue; else if (SliderValue >= EndValue)SliderValue = EndValue;//范围限制
            stringstream FloatPre; FloatPre << fixed << setprecision(3) << SliderValue;//保留小数点后数
            if (Unit != "")//数值单位
            {
                if (Unit.find("%delete") != string::npos)Unit.erase(Unit.find("%delete"), ((string)"%delete").length());//删除掉全部字符串
                else if (Unit.find("%string") != string::npos)Unit.replace(Unit.find("%string"), ((string)"%string").length(), FloatPre.str());//替换掉原本字符串
                else Unit = FloatPre.str() + Unit;//不存在特殊字符串时
            }
            else Unit = FloatPre.str();
            Render_String(Block.Target, NormalSliderPos.x, 10000 + NormalSliderPos.y - 8, Text, TextColor, EasyGUI_Font, EasyGUI_FontSize);
            Render_Rect(Block.Target, NormalSliderPos.x, NormalSliderPos.y, NormalSliderSize.x, NormalSliderSize.y, { 0,0,0 });//黑色外边框
            if (DetectMousePos || OutSide[Block.ID + Block.Line])Render_GradientRect(Block.Target, NormalSliderPos.x + 1, NormalSliderPos.y + 1, NormalSliderSize.x - 2, NormalSliderSize.y - 2, { 25,25,25 }, EasyGUI_Color / 5, true);//滑条背景
            else Render_GradientRect(Block.Target, NormalSliderPos.x + 1, NormalSliderPos.y + 1, NormalSliderSize.x - 2, NormalSliderSize.y - 2, { 25,25,25 }, EasyGUI_Color / 6, true);
            Render_GradientRect(Block.Target, NormalSliderPos.x + 1, NormalSliderPos.y + 1, SliderSize, NormalSliderSize.y - 2, EasyGUI_Color, EasyGUI_Color / 4, true);//滑条
            Render_MiniString(Block.Target, 10000 + NormalSliderPos.x + SliderSize, NormalSliderPos.y + 1, Unit, TextColor * 0.75);//居中返回值绘制
            Block.Line += 30;
        }
        inline void GUI_KeySelector(EasyGUI_Block& Block, int& KeySelectValue, int Offset = 0) noexcept//按键选取按钮
        {
            if (KeySelectValue >= 0xCCCCCCCC)KeySelectValue = 0;//修复过量
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + Block.Size.x - Offset - 50, Block.Pos.y - Block.Start + Block.Line - 6, 30, 12);//鼠标坐标检测
            static unordered_map<long, bool> BoxMea;//只声明一次初始开关设定变量
            if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && Block.IsInBlock)//当最前端窗口为GUI窗口接收按钮事件
            {
                if (DetectMousePos)EasyGUI_MouseIcon = IDC_HAND;//手型鼠标图标
                if (!BoxMea[Block.ID + Block.Line] && DetectMousePos && Block.IsInBlock && KeyEvent(VK_LBUTTON, true))BoxMea[Block.ID + Block.Line] = true;
                else if (BoxMea[Block.ID + Block.Line])
                {
                    if (KeyEvent(VK_ESCAPE, true)) { KeySelectValue = 0; BoxMea[Block.ID + Block.Line] = false; }//默认无值
                    for (int i = 0x0; i < 0xFE; ++i)if (KeyEvent(i, true)) { KeySelectValue = i; BoxMea[Block.ID + Block.Line] = false; }//当按下任意键
                    Block.IsInScrollArea = true;//禁止区块滑动
                }
            }
            if (!BoxMea[Block.ID + Block.Line])
            {
                string DrawString_VK = "";
                switch (KeySelectValue)
                {
                case 0x00: DrawString_VK = "[-]"; break;
                case 0x01: DrawString_VK = "[M1]"; break;
                case 0x02: DrawString_VK = "[M2]"; break;
                case 0x03: DrawString_VK = "[CAN]"; break;
                case 0x04: DrawString_VK = "[M3]"; break;
                case 0x05: DrawString_VK = "[M4]"; break;
                case 0x06: DrawString_VK = "[M5]"; break;
                case 0x07: DrawString_VK = "[NON]"; break;
                case 0x08: DrawString_VK = "[BAK]"; break;
                case 0x09: DrawString_VK = "[TAB]"; break;
                case 0x0C: DrawString_VK = "[CLE]"; break;
                case 0x0D: DrawString_VK = "[ENT]"; break;
                case 0x10: DrawString_VK = "[SHF]"; break;
                case 0x11: DrawString_VK = "[CLR]"; break;
                case 0x12: DrawString_VK = "[ALT]"; break;
                case 0x13: DrawString_VK = "[PAU]"; break;
                case 0x14: DrawString_VK = "[CAP]"; break;
                case 0x15: DrawString_VK = "[KAN]"; break;
                case 0x16: DrawString_VK = "[KAN]"; break;
                case 0x17: DrawString_VK = "[JUN]"; break;
                case 0x18: DrawString_VK = "[FIN]"; break;
                case 0x19: DrawString_VK = "[HAN]"; break;
                case 0x1B: DrawString_VK = "[ESC]"; break;
                case 0x1C: DrawString_VK = "[CON]"; break;
                case 0x1D: DrawString_VK = "[NON]"; break;
                case 0x1E: DrawString_VK = "[ACC]"; break;
                case 0x1F: DrawString_VK = "[MOD]"; break;
                case 0x20: DrawString_VK = "[SPA]"; break;
                case 0x21: DrawString_VK = "[PRI]"; break;
                case 0x22: DrawString_VK = "[NEX]"; break;
                case 0x23: DrawString_VK = "[END]"; break;
                case 0x24: DrawString_VK = "[HOM]"; break;
                case 0x25: DrawString_VK = "[LEF]"; break;
                case 0x26: DrawString_VK = "[UP]"; break;
                case 0x27: DrawString_VK = "[RIG]"; break;
                case 0x28: DrawString_VK = "[DN]"; break;
                case 0x29: DrawString_VK = "[SEL]"; break;
                case 0x2A: DrawString_VK = "[PRI]"; break;
                case 0x2B: DrawString_VK = "[EXE]"; break;
                case 0x2C: DrawString_VK = "[SNA]"; break;
                case 0x2D: DrawString_VK = "[INS]"; break;
                case 0x2E: DrawString_VK = "[DEL]"; break;
                case 0x2F: DrawString_VK = "[HEL]"; break;
                case 0x30: DrawString_VK = "[0]"; break;
                case 0x31: DrawString_VK = "[1]"; break;
                case 0x32: DrawString_VK = "[2]"; break;
                case 0x33: DrawString_VK = "[3]"; break;
                case 0x34: DrawString_VK = "[4]"; break;
                case 0x35: DrawString_VK = "[5]"; break;
                case 0x36: DrawString_VK = "[6]"; break;
                case 0x37: DrawString_VK = "[7]"; break;
                case 0x38: DrawString_VK = "[8]"; break;
                case 0x39: DrawString_VK = "[9]"; break;
                case 0x41: DrawString_VK = "[A]"; break;
                case 0x42: DrawString_VK = "[B]"; break;
                case 0x43: DrawString_VK = "[C]"; break;
                case 0x44: DrawString_VK = "[D]"; break;
                case 0x45: DrawString_VK = "[E]"; break;
                case 0x46: DrawString_VK = "[F]"; break;
                case 0x47: DrawString_VK = "[G]"; break;
                case 0x48: DrawString_VK = "[H]"; break;
                case 0x49: DrawString_VK = "[I]"; break;
                case 0x4A: DrawString_VK = "[J]"; break;
                case 0x4B: DrawString_VK = "[K]"; break;
                case 0x4C: DrawString_VK = "[L]"; break;
                case 0x4D: DrawString_VK = "[M]"; break;
                case 0x4E: DrawString_VK = "[N]"; break;
                case 0x4F: DrawString_VK = "[O]"; break;
                case 0x50: DrawString_VK = "[P]"; break;
                case 0x51: DrawString_VK = "[Q]"; break;
                case 0x52: DrawString_VK = "[R]"; break;
                case 0x53: DrawString_VK = "[S]"; break;
                case 0x54: DrawString_VK = "[T]"; break;
                case 0x55: DrawString_VK = "[U]"; break;
                case 0x56: DrawString_VK = "[V]"; break;
                case 0x57: DrawString_VK = "[W]"; break;
                case 0x58: DrawString_VK = "[X]"; break;
                case 0x59: DrawString_VK = "[Y]"; break;
                case 0x5A: DrawString_VK = "[Z]"; break;
                case 0x5B: DrawString_VK = "[WIN]"; break;
                case 0x5C: DrawString_VK = "[WIN]"; break;
                case 0x5D: DrawString_VK = "[APP]"; break;
                case 0x5F: DrawString_VK = "[SLP]"; break;
                case 0x60: DrawString_VK = "[0]"; break;
                case 0x61: DrawString_VK = "[1]"; break;
                case 0x62: DrawString_VK = "[2]"; break;
                case 0x63: DrawString_VK = "[3]"; break;
                case 0x64: DrawString_VK = "[4]"; break;
                case 0x65: DrawString_VK = "[5]"; break;
                case 0x66: DrawString_VK = "[6]"; break;
                case 0x67: DrawString_VK = "[7]"; break;
                case 0x68: DrawString_VK = "[8]"; break;
                case 0x69: DrawString_VK = "[9]"; break;
                case 0x6A: DrawString_VK = "[*]"; break;
                case 0x6B: DrawString_VK = "[+]"; break;
                case 0x6C: DrawString_VK = "[SEP]"; break;
                case 0x6D: DrawString_VK = "[-]"; break;
                case 0x6E: DrawString_VK = "[.]"; break;
                case 0x6F: DrawString_VK = "[/]"; break;
                case 0x70: DrawString_VK = "[F1]"; break;
                case 0x71: DrawString_VK = "[F2]"; break;
                case 0x72: DrawString_VK = "[F3]"; break;
                case 0x73: DrawString_VK = "[F4]"; break;
                case 0x74: DrawString_VK = "[F5]"; break;
                case 0x75: DrawString_VK = "[F6]"; break;
                case 0x76: DrawString_VK = "[F7]"; break;
                case 0x77: DrawString_VK = "[F8]"; break;
                case 0x78: DrawString_VK = "[F9]"; break;
                case 0x79: DrawString_VK = "[F10]"; break;
                case 0x7A: DrawString_VK = "[F11]"; break;
                case 0x7B: DrawString_VK = "[F12]"; break;
                case 0x7C: DrawString_VK = "[F13]"; break;
                case 0x7D: DrawString_VK = "[F14]"; break;
                case 0x7E: DrawString_VK = "[F15]"; break;
                case 0x7F: DrawString_VK = "[F16]"; break;
                case 0x80: DrawString_VK = "[F17]"; break;
                case 0x81: DrawString_VK = "[F18]"; break;
                case 0x82: DrawString_VK = "[F19]"; break;
                case 0x83: DrawString_VK = "[F20]"; break;
                case 0x84: DrawString_VK = "[F21]"; break;
                case 0x85: DrawString_VK = "[F22]"; break;
                case 0x86: DrawString_VK = "[F23]"; break;
                case 0x87: DrawString_VK = "[F24]"; break;
                case 0x90: DrawString_VK = "[NUM]"; break;
                case 0x91: DrawString_VK = "[SCR]"; break;
                case 0xA0: DrawString_VK = "[SHF]"; break;//L
                case 0xA1: DrawString_VK = "[SHF]"; break;//R
                case 0xA2: DrawString_VK = "[CLR]"; break;//L
                case 0xA3: DrawString_VK = "[CLR]"; break;//R
                case 0xA4: DrawString_VK = "[ALT]"; break;//L
                case 0xA5: DrawString_VK = "[ALT]"; break;//R
                case 0xC0: DrawString_VK = "[~]"; break;
                case 0xBC: DrawString_VK = "[,]"; break;
                case 0xBE: DrawString_VK = "[.]"; break;
                case 0xBF: DrawString_VK = "[/]"; break;
                case 0xBA: DrawString_VK = "[;]"; break;
                case 0xDE: DrawString_VK = "[']"; break;
                case 0xDB: DrawString_VK = "[[]"; break;
                case 0xDD: DrawString_VK = "[]]"; break;
                case 0xDC: DrawString_VK = "[\]"; break;
                default: DrawString_VK = "[" + to_string(KeySelectValue) + "]"; break;//如果什么都不是直接返回编码
                }
                if (DetectMousePos)Render_MiniString(Block.Target, 10000 + Block.Size.x - Offset - 33, 10000 + Block.Line, DrawString_VK, { 130,130,130 }, 8);
                else Render_MiniString(Block.Target, 10000 + Block.Size.x - Offset - 33, 10000 + Block.Line, DrawString_VK, { 100,100,100 }, 8);
            }
            else Render_MiniString(Block.Target, 10000 + Block.Size.x - Offset - 33, 10000 + Block.Line, "[-]", EasyGUI_Color / 1.5, 8);//激活读取
        }
        inline void GUI_InputText(EasyGUI_Block& Block, string& InputValue, string NormalText = "") noexcept//字符串输入框 (仅英文数字)
        {
            const Vector2 ButtonPos = { 45, Block.Line - 13 }, ButtonSize = { (int)(Block.Size.x / 1.5), 26 };
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x, ButtonSize.y - 1);//窗口检测机制
            static unordered_map<long, bool> IsInput;//判断是否在输入变量
            auto DrawString = InputValue;//绘制字符串
            if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove)//当最前端窗口为GUI窗口接收输入框事件
            {
                if (Block.IsInBlock)//鼠标在区块内部
                {
                    if (MouseJudgment(Block.Pos.x + ButtonPos.x + ButtonSize.x - 25, Block.Pos.y - Block.Start + ButtonPos.y + 3, 20, ButtonSize.y - 6))//鼠标坐标在X上方
                    {
                        EasyGUI_MouseIcon = IDC_HAND;//清除文字鼠标图标
                        if (InputValue != "" && KeyEvent(VK_LBUTTON, true))InputValue = "";//清除全部内容
                    }
                    else if (DetectMousePos)EasyGUI_MouseIcon = IDC_IBEAM;//输入框鼠标图标
                    if (!IsInput[Block.ID + Block.Line] && DetectMousePos && KeyEvent(VK_LBUTTON, true))IsInput[Block.ID + Block.Line] = true;//进入输入状态
                }
                if (IsInput[Block.ID + Block.Line])//在输入状态时
                {
                    string PressedKey = "";//按键记录变量
                    if (KeyEvent(VK_LCONTROL) || KeyEvent(VK_RCONTROL))//Ctrl键脚本
                    {
                        if (KeyEvent('C', true) && OpenClipboard(0))//Ctrl + C 复制
                        {
                            EmptyClipboard();//清空剪切板
                            const auto hHandle = GlobalAlloc(GMEM_MOVEABLE, strlen(InputValue.c_str()) + 1);//分配内存
                            strcpy_s((char*)GlobalLock(hHandle), strlen(InputValue.c_str()) + 1, InputValue.c_str());
                            SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
                            GlobalUnlock(hHandle);//解除锁定
                            CloseClipboard();//关闭剪切板
                        }
                        if (KeyEvent('V', true) && OpenClipboard(0))//Ctrl + V 粘贴
                        {
                            if (IsClipboardFormatAvailable(CF_TEXT))
                            {
                                const auto c_data = GetClipboardData(CF_TEXT);//获取剪切板数据
                                InputValue += ((char*)GlobalLock(c_data));//在字符串尾部粘贴字符串内容
                                GlobalUnlock(c_data);//解除锁定
                            }
                            CloseClipboard();//关闭剪切板
                        }
                    }
                    else {//不阻止Ctrl脚本事件
                        const auto Is_Shift = KeyEvent(VK_SHIFT) || KeyEvent(VK_LSHIFT) || KeyEvent(VK_RSHIFT);//Shift键脚本
                        for (int i = 0x8; i < 0xFE; ++i)//VK键码遍历 (检测按下了什么键)
                        {
                            if (i != VK_SHIFT && i != VK_LSHIFT && i != VK_RSHIFT && KeyEvent(i, true))
                            {
                                switch (i)//相比if函数执行更快
                                {
                                case 0x20:PressedKey = " "; break;
                                case 0x30:PressedKey = Is_Shift ? ")" : "0"; break;
                                case 0x31:PressedKey = Is_Shift ? "!" : "1"; break;
                                case 0x32:PressedKey = Is_Shift ? "@" : "2"; break;
                                case 0x33:PressedKey = Is_Shift ? "#" : "3"; break;
                                case 0x34:PressedKey = Is_Shift ? "$" : "4"; break;
                                case 0x35:PressedKey = Is_Shift ? "%" : "5"; break;
                                case 0x36:PressedKey = Is_Shift ? "^" : "6"; break;
                                case 0x37:PressedKey = Is_Shift ? "&" : "7"; break;
                                case 0x38:PressedKey = Is_Shift ? "*" : "8"; break;
                                case 0x39:PressedKey = Is_Shift ? "(" : "9"; break;
                                case 0x41:PressedKey = Is_Shift ? "A" : "a"; break;
                                case 0x42:PressedKey = Is_Shift ? "B" : "b"; break;
                                case 0x43:PressedKey = Is_Shift ? "C" : "c"; break;
                                case 0x44:PressedKey = Is_Shift ? "D" : "d"; break;
                                case 0x45:PressedKey = Is_Shift ? "E" : "e"; break;
                                case 0x46:PressedKey = Is_Shift ? "F" : "f"; break;
                                case 0x47:PressedKey = Is_Shift ? "G" : "g"; break;
                                case 0x48:PressedKey = Is_Shift ? "H" : "h"; break;
                                case 0x49:PressedKey = Is_Shift ? "I" : "i"; break;
                                case 0x4A:PressedKey = Is_Shift ? "J" : "j"; break;
                                case 0x4B:PressedKey = Is_Shift ? "K" : "k"; break;
                                case 0x4C:PressedKey = Is_Shift ? "L" : "l"; break;
                                case 0x4D:PressedKey = Is_Shift ? "M" : "m"; break;
                                case 0x4E:PressedKey = Is_Shift ? "N" : "n"; break;
                                case 0x4F:PressedKey = Is_Shift ? "O" : "o"; break;
                                case 0x50:PressedKey = Is_Shift ? "P" : "p"; break;
                                case 0x51:PressedKey = Is_Shift ? "Q" : "q"; break;
                                case 0x52:PressedKey = Is_Shift ? "R" : "r"; break;
                                case 0x53:PressedKey = Is_Shift ? "S" : "s"; break;
                                case 0x54:PressedKey = Is_Shift ? "T" : "t"; break;
                                case 0x55:PressedKey = Is_Shift ? "U" : "u"; break;
                                case 0x56:PressedKey = Is_Shift ? "V" : "v"; break;
                                case 0x57:PressedKey = Is_Shift ? "W" : "w"; break;
                                case 0x58:PressedKey = Is_Shift ? "X" : "x"; break;
                                case 0x59:PressedKey = Is_Shift ? "Y" : "y"; break;
                                case 0x5A:PressedKey = Is_Shift ? "Z" : "z"; break;
                                case 0xBA:PressedKey = Is_Shift ? ":" : ";"; break;
                                case 0xBB:PressedKey = Is_Shift ? "+" : "="; break;
                                case 0xBC:PressedKey = Is_Shift ? "<" : ","; break;
                                case 0xBD:PressedKey = Is_Shift ? "_" : "-"; break;
                                case 0xBE:PressedKey = Is_Shift ? ">" : "."; break;
                                case 0xBF:PressedKey = Is_Shift ? "?" : "/"; break;
                                case 0xC0:PressedKey = Is_Shift ? "~" : "`"; break;
                                case 0xDB:PressedKey = Is_Shift ? "{" : "["; break;
                                case 0xDC:PressedKey = Is_Shift ? "|" : "\\"; break;
                                case 0xDD:PressedKey = Is_Shift ? "}" : "]"; break;
                                case 0xDE:PressedKey = Is_Shift ? "\"" : "'"; break;
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
                                case VK_BACK:if (InputValue.size() > 0)InputValue.erase(InputValue.end() - 1); break;//擦除最后一个字符
                                case VK_DELETE:InputValue = ""; break;//清除全部字符
                                case VK_ESCAPE:case VK_RETURN:IsInput[Block.ID + Block.Line] = false; break;//按键解除输入状态
                                }
                                if (GetKeyState(0x14))for (auto& Str : PressedKey)Str = toupper(static_cast<unsigned char>(Str));//CapsLock大写转换
                                InputValue += PressedKey;//返回按下
                            }
                        }
                    }
                    if (((long)SystemTick() / 250) % 2 == 0)DrawString += "_";//输入中绘制标识
                    if (!DetectMousePos && (KeyEvent(VK_LBUTTON) || KeyEvent(VK_RBUTTON)))IsInput[Block.ID + Block.Line] = false;//鼠标解除输入状态
                }
            }
            Render_Rect(Block.Target, ButtonPos.x, ButtonPos.y, ButtonSize.x, ButtonSize.y, { 0,0,0 });
            Render_Rect(Block.Target, ButtonPos.x + 1, ButtonPos.y + 1, ButtonSize.x - 2, ButtonSize.y - 2, { 60,60,60 });
            if (DetectMousePos || IsInput[Block.ID + Block.Line])Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { 15,15,15 }, EasyGUI_Color / 7, true);
            else Render_GradientRect(Block.Target, ButtonPos.x + 2, ButtonPos.y + 2, ButtonSize.x - 4, ButtonSize.y - 4, { 15,15,15 }, EasyGUI_Color / 8, true);
            if (!IsInput[Block.ID + Block.Line] && InputValue == "")Render_String(Block.Target, ButtonPos.x + 10, 10000 + Block.Line + 1, NormalText, { 50,50,50 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ButtonSize.x - 40 });//默认显示文字
            else {
                Render_String(Block.Target, ButtonPos.x + 10, 10000 + Block.Line + 1, DrawString, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ButtonSize.x - 40 });//已输入的文字
                if (InputValue != "")Render_MiniString(Block.Target, ButtonPos.x + 10 + ButtonSize.x - 30, 10000 + Block.Line + 1, "X", { 60,60,60 }, 15, 400);//删除全部字符叉叉
            }
            Block.Line += 27;
        }
        inline void GUI_Tip(EasyGUI_Block& Block, string Text, Vector4 TextColor = { 200,200,200 }) noexcept//鼠标指针提示 (只支持单行字符,代码写在最后为了不被覆盖绘制)
        {
            Render_MiniString(Block.Target, 5, 10000 + Block.Line, "[?]", { 100,100,100 });//提示符绘制
            if (Block.IsInBlock && InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && MouseJudgment(Block.Pos.x + 5, Block.Pos.y - Block.Start + Block.Line - 6, 15, 10))//当鼠标移动到问号 且GUI窗口为最顶层
            {
                EasyGUI_MouseIcon = IDC_HELP;//帮助鼠标图标
                const auto StringSize = Render_MiniString(EasyGUI_RenderTarget, 0, 0, Text, {}) + Vector2{ 10, 10 };//提示框长度
                const auto TipRectPos = Vector2{ Block.Pos.x + 35, Block.Pos.y + Block.Line - Block.Start };//提示框位置
                Render_Rect(EasyGUI_RenderTarget, TipRectPos.x, TipRectPos.y, StringSize.x, StringSize.y, { 0,0,0 });
                Render_Rect(EasyGUI_RenderTarget, TipRectPos.x + 1, TipRectPos.y + 1, StringSize.x - 2, StringSize.y - 2, { 60,60,60 });
                Render_GradientRect(EasyGUI_RenderTarget, TipRectPos.x + 2, TipRectPos.y + 2, StringSize.x - 4, StringSize.y - 4, EasyGUI_Color / 15, EasyGUI_Color / 10, true);
                Render_MiniString(EasyGUI_RenderTarget, TipRectPos.x + 5, TipRectPos.y + 5, Text, TextColor);
            }
        }
        inline void GUI_ColorSelector(EasyGUI_Block& Block, Vector4& ColorValue, int Offset = 0) noexcept//颜色选择器
        {
            auto DrawCheckerboard = [&](ID2D1RenderTarget* Target, int X, int Y, int Width, int Height) {//绘制棋盘格背景
                for (int i = 0; i < Height; i += 2)for (int j = 0; j < Width; j += 2)
                    Render_Rect(Target, j + X, i + Y, 2, 2, ((i / 2) + (j / 2)) % 2 ? Vector4{ 150, 150, 150 } : Vector4{ 200, 200, 200 });
                };
            const Vector2 ColorRectPos = { Block.Size.x - 43 - Offset,Block.Line - 6 }, ColorPickerSize = { 190, 80 };//颜色预览框位置,颜色选择器大小
            static unordered_map<long, bool> OpenColorPicker;//颜色选择器开关
            static unordered_map<long, Vector4> BaseColor;//基础颜色值备份
            if (Block.IsInBlock && InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && !InputState_ControlWindowShow && MouseJudgment(Block.Pos.x + ColorRectPos.x, Block.Pos.y - Block.Start + ColorRectPos.y, 20, 12))
            {
                EasyGUI_MouseIcon = IDC_HAND;//手型鼠标图标
                if (!OpenColorPicker[Block.ID + Block.Line] && KeyEvent(VK_LBUTTON, true))//打开颜色选择器
                {
                    BaseColor[Block.ID + Block.Line] = ColorValue;
                    OpenColorPicker[Block.ID + Block.Line] = true;
                    InputState_ControlWindowShow = true;
                    MoveControlWindow(EasyGUI_MousePos.x + 20, EasyGUI_MousePos.y + 20, ColorPickerSize.x, ColorPickerSize.y);
                }
            }
            if (OpenColorPicker[Block.ID + Block.Line])//颜色选择器打开时
            {
                if (!InputState_ControlWindowShow)OpenColorPicker[Block.ID + Block.Line] = false;//当控制窗口关闭时关闭颜色选择器
                const bool SelectBar_1 = EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 5 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < 5 + ColorPickerSize.x - 10 - 1 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > 5 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < 5 + 18,
                    SelectBar_2 = EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 5 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < 5 + ColorPickerSize.x - 10 - 1 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > 5 + 25 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < 5 + 25 + 18,
                    SelectBar_3 = EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 5 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < 5 + ColorPickerSize.x - 10 - 1 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > 5 + 50 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < 5 + 50 + 18;
                if (InputState_ControlWindowShow && KeyEvent(VK_LBUTTON))
                {
                    InputState_IsSlider = true;
                    static const auto Window_HDC = GetDC(0); const auto Pixel = GetPixel(Window_HDC, EasyGUI_MousePos.x, EasyGUI_MousePos.y);
                    const Vector4 MouseColor = { GetRValue(Pixel), GetGValue(Pixel), GetBValue(Pixel),ColorValue.a };
                    if (MouseColor.D_Alpha(255) != Vector4{ 0, 0, 1 })
                    {
                        if (SelectBar_1) { BaseColor[Block.ID + Block.Line] = MouseColor; ColorValue = MouseColor; }
                        else if (SelectBar_2)ColorValue = MouseColor;
                        else if (SelectBar_3)ColorValue.a = (1.f - (EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left) / (ColorPickerSize.x - 10.f)) * 255.f;
                        //else KeyEvent(VK_LBUTTON, true);
                        if (ColorValue.a >= 245)ColorValue.a = 255; else if (ColorValue.a <= 10)ColorValue.a = 0;
                    }
                }
                else InputState_IsSlider = false;
                Render_Rect(EasyGUI_ControlRenderTarget, 0, 0, ColorPickerSize.x, ColorPickerSize.y, { 0,0,0 });
                Render_Rect(EasyGUI_ControlRenderTarget, 1, 1, ColorPickerSize.x - 2, ColorPickerSize.y - 2, { 60,60,60 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 2, 2, ColorPickerSize.x - 4, ColorPickerSize.y - 4, EasyGUI_Color / 15, EasyGUI_Color / 10, true);
                Render_Rect(EasyGUI_ControlRenderTarget, 5, 5, ColorPickerSize.x - 10, 20, { 0,0,0 });//彩虹颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 30 * 0, 6, 30, 18, { 255,0,0 }, { 255,255,0 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 30 * 1, 6, 30, 18, { 255,255,0 }, { 0,255,0 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 30 * 2, 6, 30, 18, { 0,255,0 }, { 0,255,255 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 30 * 3, 6, 30, 18, { 0,255,255 }, { 0,0,255 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 30 * 4, 6, 30, 18, { 0,0,255 }, { 255,0,255 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 30 * 5, 6, 30 - 2, 18, { 255,0,255 }, { 255,0,0 });
                Render_Rect(EasyGUI_ControlRenderTarget, 5, 5 + 25, ColorPickerSize.x - 10, 20, { 0,0,0 });//明暗颜色条
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6, 6 + 25, 90, 18, { 0,0,0 }, BaseColor[Block.ID + Block.Line].D_Alpha(255));
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6 + 90, 6 + 25, 90 - 2, 18, BaseColor[Block.ID + Block.Line].D_Alpha(255), { 255,255,255 });
                Render_Rect(EasyGUI_ControlRenderTarget, 5, 5 + 50, ColorPickerSize.x - 10, 20, { 0,0,0 });//透明颜色条
                DrawCheckerboard(EasyGUI_ControlRenderTarget, 6, 6 + 50, ColorPickerSize.x - 12, 18);
                Render_GradientRect(EasyGUI_ControlRenderTarget, 6, 6 + 50, ColorPickerSize.x - 12, 18, ColorValue.D_Alpha(255), ColorValue.D_Alpha(0));
                if (KeyEvent(VK_LBUTTON))//绘制选择标识
                {
                    if (SelectBar_1)Render_Rect(EasyGUI_ControlRenderTarget, EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left + 1, 6, 1, 18, { 0,0,1 });
                    else if (SelectBar_2)Render_Rect(EasyGUI_ControlRenderTarget, EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left + 1, 6 + 25, 1, 18, { 0,0,1 });
                    else if (SelectBar_3)Render_Rect(EasyGUI_ControlRenderTarget, EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left + 1, 6 + 50, 1, 18, { 0,0,1 });
                }
            }
            Render_Rect(Block.Target, ColorRectPos.x, ColorRectPos.y, 20, 12, { 0,0,0 });//黑色边框
            DrawCheckerboard(Block.Target, ColorRectPos.x + 1, ColorRectPos.y + 1, 18, 10);//透明格子绘制
            Render_GradientRect(Block.Target, ColorRectPos.x + 1, ColorRectPos.y + 1, 18, 10, ColorValue, ColorValue / 3, true);//颜色预览框
        }
        inline void GUI_PosSelector(EasyGUI_Block& Block, Vector3& PosValue) noexcept//坐标选择器
        {
            const Vector2 ButtonSize = { 65,18 }, ButtonPos = { Block.Size.x - ButtonSize.x * 3 - 15,Block.Line - ButtonSize.y / 2 };//按钮位置,按钮大小
            for (int Pos_Bl = 0; Pos_Bl <= 2; ++Pos_Bl)
            {
                vector<float> UsedPos = { PosValue.x,PosValue.y,PosValue.z };
                const auto DetectMousePos = MouseJudgment(Block.Pos.x + ButtonPos.x + ButtonSize.x * Pos_Bl, Block.Pos.y - Block.Start + ButtonPos.y, ButtonSize.x - 2, ButtonSize.y);//窗口检测机制
                if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && DetectMousePos && Block.IsInBlock)//当最前端窗口为GUI窗口接收按钮事件
                {
                    if (KeyEvent(VK_LBUTTON, true))UsedPos[Pos_Bl] += 0.1; else if (KeyEvent(VK_RBUTTON, true))UsedPos[Pos_Bl] -= 0.1;
                    if (KeyEvent(VK_LEFT, true))UsedPos[Pos_Bl] += 1; else if (KeyEvent(VK_RIGHT, true))UsedPos[Pos_Bl] -= 1;
                    if (KeyEvent(VK_UP, true))UsedPos[Pos_Bl] -= 10; else if (KeyEvent(VK_DOWN, true))UsedPos[Pos_Bl] += 10;
                    if (KeyEvent(VK_DELETE, true))UsedPos[Pos_Bl] = 0;
                    PosValue = { UsedPos[0],UsedPos[1],UsedPos[2] };
                    Block.IsInScrollArea = true;//禁止区块滑动
                }
                Render_Rect(Block.Target, ButtonPos.x + ButtonSize.x * Pos_Bl, ButtonPos.y, ButtonSize.x - 2, ButtonSize.y, { 0,0,0 });
                if (DetectMousePos)Render_GradientRect(Block.Target, ButtonPos.x + ButtonSize.x * Pos_Bl + 1, ButtonPos.y + 1, ButtonSize.x - 2 - 2, ButtonSize.y - 2, EasyGUI_Color / 5, { 20,20,20 }, true);
                else Render_GradientRect(Block.Target, ButtonPos.x + ButtonSize.x * Pos_Bl + 1, ButtonPos.y + 1, ButtonSize.x - 2 - 2, ButtonSize.y - 2, EasyGUI_Color / 6, { 20,20,20 }, true);
            }
            stringstream Pos_X, Pos_Y, Pos_Z; Pos_X << fixed << setprecision(1) << PosValue.x; Pos_Y << fixed << setprecision(1) << PosValue.y; Pos_Z << fixed << setprecision(1) << PosValue.z;//只保留特定小数点后数
            Render_MiniString(Block.Target, ButtonPos.x + 5 + ButtonSize.x * 0, 10000 + Block.Line + 1, "X: " + Pos_X.str(), { 150,150,150 });
            Render_MiniString(Block.Target, ButtonPos.x + 5 + ButtonSize.x * 1, 10000 + Block.Line + 1, "Y: " + Pos_Y.str(), { 150,150,150 });
            Render_MiniString(Block.Target, ButtonPos.x + 5 + ButtonSize.x * 2, 10000 + Block.Line + 1, "Z: " + Pos_Z.str(), { 150,150,150 });
        }
        inline void GUI_Combobox(EasyGUI_Block& Block, vector<string> ComboText, int& SelectValue) noexcept//单选组合框
        {
            const Vector2 ComboboxPos = { 45,Block.Line - 12 }, ComboboxSize = { (int)(Block.Size.x / 1.5),24 }, ComboboxWindowSize = { (int)(Block.Size.x / 1.5), (int)(ComboText.size() * 24) };//颜色选择器大小
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ComboboxPos.x, Block.Pos.y - Block.Start + ComboboxPos.y, ComboboxSize.x, ComboboxSize.y);//窗口检测机制
            static unordered_map<long, bool> IsOpen;//判断是否打开选择变量
            if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && !IsOpen[Block.ID + Block.Line] && !InputState_ControlWindowShow && Block.IsInBlock && DetectMousePos)//当最前端窗口为GUI窗口接收事件
            {
                if (KeyEvent(VK_LBUTTON, true))//打开选择器
                {
                    IsOpen[Block.ID + Block.Line] = true; InputState_ControlWindowShow = true;
                    MoveControlWindow(EasyGUI_WindowPos.left + Block.Pos.x + 45, EasyGUI_WindowPos.top + Block.Pos.y - Block.Start + Block.Line + 15, ComboboxWindowSize.x, ComboboxWindowSize.y);
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
                    const auto Pos_Y = i * 24 + 1, PosHeight = 22;
                    if (EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 2 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < ComboboxWindowSize.x - 2 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > Pos_Y && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < Pos_Y + PosHeight)//鼠标悬停高亮
                    {
                        Render_GradientRect(EasyGUI_ControlRenderTarget, 1, Pos_Y, ComboboxWindowSize.x - 2, PosHeight, EasyGUI_Color / 7, { 15,15,15 });
                        if (KeyEvent(VK_LBUTTON, true)) { SelectValue = i; InputState_ControlWindowShow = false; }
                    }
                    if (SelectValue == i)Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2 + 1, ComboText[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600);
                    else Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2 + 1, ComboText[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
                }
            }
            Render_Rect(Block.Target, ComboboxPos.x, ComboboxPos.y, ComboboxSize.x, ComboboxSize.y, { 0,0,0 });
            if (DetectMousePos || IsOpen[Block.ID + Block.Line])Render_GradientRect(Block.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, { 20,20,20 }, EasyGUI_Color / 6, true);
            else Render_GradientRect(Block.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, { 20,20,20 }, EasyGUI_Color / 7, true);
            Render_String(Block.Target, ComboboxPos.x + 10, 10000 + ComboboxPos.y + 13, ComboText[SelectValue], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
            if (IsOpen[Block.ID + Block.Line])Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▲", { 200,200,200 }, 9, 400);
            else Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▼", { 200,200,200 }, 9, 400);
            Block.Line += 25;
        }
        inline void GUI_MultiCombobox(EasyGUI_Block& Block, vector<string> ComboText, vector<bool>& SelectValue) noexcept//多选组合框
        {
            const Vector2 ComboboxPos = { 45,Block.Line - 12 }, ComboboxSize = { (int)(Block.Size.x / 1.5),24 }, ComboboxWindowSize = { (int)(Block.Size.x / 1.5), (int)(ComboText.size() * 24) };//颜色选择器大小
            const auto DetectMousePos = MouseJudgment(Block.Pos.x + ComboboxPos.x, Block.Pos.y - Block.Start + ComboboxPos.y, ComboboxSize.x, ComboboxSize.y);//窗口检测机制
            static unordered_map<long, bool> IsOpen;//判断是否打开选择变量
            if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && !IsOpen[Block.ID + Block.Line] && !InputState_ControlWindowShow && Block.IsInBlock && DetectMousePos && KeyEvent(VK_LBUTTON, true))//当最前端窗口为GUI窗口接收事件
            {
                IsOpen[Block.ID + Block.Line] = true; InputState_ControlWindowShow = true;
                MoveControlWindow(EasyGUI_WindowPos.left + Block.Pos.x + 45, EasyGUI_WindowPos.top + Block.Pos.y - Block.Start + Block.Line + 15, ComboboxWindowSize.x, ComboboxWindowSize.y);
            }
            if (IsOpen[Block.ID + Block.Line])
            {
                if (!InputState_ControlWindowShow)IsOpen[Block.ID + Block.Line] = false;//当控制窗口关闭时关闭颜色选择器
                Render_Rect(EasyGUI_ControlRenderTarget, 0, 0, ComboboxWindowSize.x, ComboboxWindowSize.y, { 0,0,0 });
                Render_GradientRect(EasyGUI_ControlRenderTarget, 1, 1, ComboboxWindowSize.x - 2, ComboboxWindowSize.y - 2, EasyGUI_Color / 10, { 10,10,10 }, true);
                for (int i = 0; i < ComboText.size(); ++i)//遍历选项绘制
                {
                    const auto Pos_Y = i * 24 + 1, PosHeight = 22;
                    if (EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left > 2 && EasyGUI_MousePos.x - EasyGUI_ControlWindowPos.left < ComboboxWindowSize.x - 2 && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top > Pos_Y && EasyGUI_MousePos.y - EasyGUI_ControlWindowPos.top < Pos_Y + PosHeight)//鼠标悬停高亮
                    {
                        Render_GradientRect(EasyGUI_ControlRenderTarget, 1, Pos_Y, ComboboxWindowSize.x - 2, PosHeight, EasyGUI_Color / 7, { 15,15,15 });
                        if (KeyEvent(VK_LBUTTON, true))SelectValue[i] = !SelectValue[i];
                    }
                    if (SelectValue[i])Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2 + 1, ComboText[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600);
                    else Render_String(EasyGUI_ControlRenderTarget, 10, 10000 + Pos_Y + PosHeight / 2 + 1, ComboText[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
                }
            }
            string SelectString = "-"; for (int i = 0; i < ComboText.size(); ++i)if (SelectValue[i]) { if (SelectString == "-")SelectString = ""; if (!SelectString.empty()) SelectString += ", "; SelectString += ComboText[i]; }//字符串计算
            Render_Rect(Block.Target, ComboboxPos.x, ComboboxPos.y, ComboboxSize.x, ComboboxSize.y, { 0,0,0 });
            if (DetectMousePos || IsOpen[Block.ID + Block.Line])Render_GradientRect(Block.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, { 20,20,20 }, EasyGUI_Color / 6, true);
            else Render_GradientRect(Block.Target, ComboboxPos.x + 1, ComboboxPos.y + 1, ComboboxSize.x - 2, ComboboxSize.y - 2, { 20,20,20 }, EasyGUI_Color / 7, true);
            Render_String(Block.Target, ComboboxPos.x + 10, 10000 + ComboboxPos.y + 13, SelectString, { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize, 400, { ComboboxSize.x - 35 });
            if (IsOpen[Block.ID + Block.Line])Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▲", { 200,200,200 }, 9, 400);
            else Render_MiniString(Block.Target, ComboboxPos.x + 10 + ComboboxSize.x - 25, 10000 + Block.Line + 1, "▼", { 200,200,200 }, 9, 400);
            Block.Line += 25;
        }
        inline void GUI_List(EasyGUI_Block& Block, vector<string>LineString, int& m_InLine, int LimitLine = 0) noexcept//单选列表
        {
            Block.Line += 3;
            const auto LineStringSize = LineString.size();//获取行列数
            if (m_InLine < 0)m_InLine = 0; else if (m_InLine >= LineStringSize)m_InLine = LineStringSize - 1;//赋值范围限制
            static unordered_map<long, int> StartLinePos; if (!LimitLine)LimitLine = LineStringSize; if (!LineStringSize)m_InLine = -1;//防止过量访问崩溃
            const Vector2 ListPos = { 45,Block.Line - 15 }, ListSize = { (int)(Block.Size.x / 1.5),(int)(LimitLine * 25 + 5) };//列表位置,列表大小
            const auto IsInList = MouseJudgment(Block.Pos.x + ListPos.x, Block.Pos.y - Block.Start + ListPos.y, ListSize.x, ListSize.y);
            if (IsInList && InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && Block.IsInBlock && LineStringSize > LimitLine) { if (KeyEvent(VK_UP, true))--StartLinePos[Block.ID + Block.Line]; else if (KeyEvent(VK_DOWN, true))++StartLinePos[Block.ID + Block.Line]; Block.IsInScrollArea = true; }//鼠标滚轮调整绘制起始位置
            if (StartLinePos[Block.ID + Block.Line] + LimitLine > LineStringSize)StartLinePos[Block.ID + Block.Line] = LineStringSize - LimitLine; if (StartLinePos[Block.ID + Block.Line] < 0)StartLinePos[Block.ID + Block.Line] = 0;//开始行列位置范围限制
            Render_Rect(Block.Target, ListPos.x, ListPos.y, ListSize.x, ListSize.y, { 0,0,0 });//黑色外边框
            Render_GradientRect(Block.Target, ListPos.x + 1, ListPos.y + 1, ListSize.x - 2, ListSize.y - 2, EasyGUI_Color / 10, { 10,10,10 }, true);//主题色渐变背景
            for (int i = StartLinePos[Block.ID + Block.Line]; i < LineStringSize; ++i)//行列内容遍历
            {
                if (i - StartLinePos[Block.ID + Block.Line] >= LimitLine)continue;//限制行数
                const auto LineY = ListPos.y + (i - StartLinePos[Block.ID + Block.Line]) * 25 + 5;//当前行的Y坐标 统一坐标体系
                if (Block.IsInBlock && MouseJudgment(Block.Pos.x + ListPos.x, Block.Pos.y - Block.Start + LineY, ListSize.x, 20))//鼠标赋值选择
                {
                    if (InputState_IsWindShow && !InputState_IsSlider && !InputState_IsMove && m_InLine != i && KeyEvent(VK_LBUTTON, true))m_InLine = i;
                    Render_GradientRect(Block.Target, ListPos.x + 1, LineY, ListSize.x - 2, 20, EasyGUI_Color / 8, { 15,15,15 });
                }
                if (m_InLine == i)
                {
                    Render_GradientRect(Block.Target, ListPos.x + 1, LineY, ListSize.x - 2, 20, EasyGUI_Color / 7, { 15,15,15 });
                    Render_String(Block.Target, ListPos.x + 12, 10000 + LineY + 1 + 10, LineString[i], EasyGUI_Color, EasyGUI_Font, EasyGUI_FontSize, 600);
                }
                else Render_String(Block.Target, ListPos.x + 12, 10000 + LineY + 1 + 10, LineString[i], { 200,200,200 }, EasyGUI_Font, EasyGUI_FontSize);
            }
            if (LineStringSize > LimitLine)//只有在内容超出可视区域时才会绘制滚动条
            {
                const auto ListHeight = LimitLine * 25 + 1, ScrollBarHeight = max(int(ListHeight * float(LimitLine) / LineStringSize), 10);
                Render_GradientRect(Block.Target, ListPos.x + ListSize.x - 4, ListPos.y + 2, 2, ListHeight, { 10,10,10 }, EasyGUI_Color / 10, true);//滚动槽背景
                Render_GradientRect(Block.Target, ListPos.x + ListSize.x - 4, ListPos.y + 2 + ((LineStringSize - LimitLine) > 0 ? float(StartLinePos[Block.ID + Block.Line]) / (LineStringSize - LimitLine) * (ListHeight - ScrollBarHeight) : 0.f), 2, ScrollBarHeight, EasyGUI_Color / 2, EasyGUI_Color / 3, true);//滚动条
            }
            Block.Line += LimitLine * 25 + 5;
        }
    };
}