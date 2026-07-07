#include "EasyGUI_Direct2D.h"
namespace TestVariable
{
    int UI_Page = 0;
    bool UI_CustomMainColor = true;
    EasyGUI_Direct2D::Vector4 UI_ColorSelector = { 255,255,255 };
    float UI_MenuAnimationSmooth = 5;
    int UI_MenuVibrancy = 100;
    int UI_MenuBrightness = 2;
    int UI_MenuFontSize = 0;
    std::string UI_CustomFont = "";
    int UI_LanguageTestList = 0;
}
int main()
{
    ShowWindow(GetConsoleWindow(), true);
    system("cls"); printf("EasyGUI - Direct2D\nA lightweight and high-performance GUI library based on Direct2D\nGithub: https://github.com/Coslly/EasyGUI\n");
    EasyGUI_Direct2D::EasyGUI GUI_Variable("EasyGUI - Direct2D", { 680,440 });
    while (true)
    {
        GUI_Variable.Draw(0);
        GUI_Variable.GUI_BackGround();
        GUI_Variable.GUI_RadioBlock(30, 30, 100, 380, "EasyGUI", { "Page 1","Page 2","Page 3" }, TestVariable::UI_Page);
        if (TestVariable::UI_Page == 0)
        {
            static EasyGUI_Direct2D::EasyGUI_Block Block{};
            if (GUI_Variable.GUI_Block(Block, 150, 30, 500, 380, "Block"))
            {
                GUI_Variable.GUI_Tip(Block, "Customize menu theme colors.");
                GUI_Variable.GUI_ColorSelector3(Block, TestVariable::UI_ColorSelector);
                GUI_Variable.GUI_Checkbox(Block, "Custom main color", TestVariable::UI_CustomMainColor);
                GUI_Variable.Style_SetColor(TestVariable::UI_CustomMainColor ? TestVariable::UI_ColorSelector : EasyGUI_Direct2D::Vector4{ 255,255,255 });
                GUI_Variable.GUI_Slider<float>(Block, "Menu animation smooth", 0, 20, TestVariable::UI_MenuAnimationSmooth);
                GUI_Variable.Style_SetAnimationSmooth(TestVariable::UI_MenuAnimationSmooth);
                GUI_Variable.GUI_Slider<int>(Block, "Menu vibrancy", 0, 200, TestVariable::UI_MenuVibrancy, "%");
                GUI_Variable.GUI_Slider<int>(Block, "Menu brightness", 0, 10, TestVariable::UI_MenuBrightness, "%");
                GUI_Variable.Style_SetColorHue(TestVariable::UI_MenuVibrancy / 100.f, TestVariable::UI_MenuBrightness / 100.f);
                GUI_Variable.GUI_Slider<int>(Block, "Menu font size", 0, 20, TestVariable::UI_MenuFontSize, "px");
                GUI_Variable.Style_SetFontSize(TestVariable::UI_MenuFontSize);
                GUI_Variable.GUI_InputText(Block, TestVariable::UI_CustomFont, "Custom menu font");
                GUI_Variable.Style_SetFont(TestVariable::UI_CustomFont);
                GUI_Variable.GUI_List(Block, { "English", "中文", "한국어", "日本語", "Русский", "Español", "Français", "Deutsch", "Português", "العربية" }, TestVariable::UI_LanguageTestList, 5);
                if (GUI_Variable.GUI_Button(Block, "Close"))exit(0);
            }
        }
        GUI_Variable.Draw(1);
    }
}