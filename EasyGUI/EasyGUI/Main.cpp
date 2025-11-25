#include "EasyGUI_Direct2D.h"
int main()
{
    ShowWindow(GetConsoleWindow(), true);//Show Console Window
    system("cls"); printf("EasyGUI - Direct2D\nA lightweight and high-performance GUI library based on Direct2D\nGithub: https://github.com/Coslly/EasyGUI.git\n");
    EasyGUI_Direct2D::EasyGUI GUI_Variable = { {790, 360}, "EasyGUI Test Windows" };//Initialize GUI variables
    while (true)
    {
        static bool UI_Checkbox = false;
        static int UI_Slider_int = 5;
        static float UI_Slider_float = 5;
        static int UI_Combobox = 0;
        static bool UI_Button = false;
        static bool UI_Button_Small = false;
        static int UI_KeySelector = 4;
        static EasyGUI_Direct2D::Vector4 UI_ColorSelector = { 200,200,255,250 };
        static EasyGUI_Direct2D::Vector3 UI_PosSelector = { 0.23,100,1000 };
        static int UI_PanelSelector = 0;
        static string UI_InputText = "Input text";
        static int UI_List = 0;
        if (!GUI_Variable.Window_AllowMove())//Allow windows to be dragged
        {
            GUI_Variable.Draw(0);//Begin draw
            GUI_Variable.GUI_BackGround();//BackGround
            GUI_Variable.GUI_RadioBlock(30, 30, 100, 300, "Panel", { "Panel 1","Panel 2","Panel 3" }, UI_PanelSelector);
            if (UI_PanelSelector == 0)//Panel 1 Paint
            {
                static EasyGUI_Direct2D::EasyGUI_Block Block;
                GUI_Variable.GUI_Block(Block, 160, 30, 600, 300, "Block");//Block
                GUI_Variable.GUI_Tip(Block, "Some tips");
                GUI_Variable.GUI_KeySelector(Block, UI_KeySelector);
                GUI_Variable.GUI_Checkbox(Block, "This is a Checkbox", UI_Checkbox);
                if (UI_Checkbox)for (int i = 0; i < 10; ++i)GUI_Variable.GUI_Text(Block, "This is Text " + to_string(i));
                GUI_Variable.GUI_Slider<int>(Block, "Slider int", 0, 10, UI_Slider_int);
                GUI_Variable.GUI_Slider<float>(Block, "Slider float", 0, 10, UI_Slider_float);
                GUI_Variable.GUI_Combobox(Block, { "Head","CSGO","Dick","Coke","Shoot","Combo" }, UI_Combobox);
                GUI_Variable.GUI_MiniButton(Block, UI_Button_Small, 10);
                GUI_Variable.GUI_Button(Block, "Button", UI_Button);
                static auto ButtonClick = 0; if (UI_Button || UI_Button_Small)ButtonClick++;
                GUI_Variable.GUI_Text(Block, "Button hit: " + to_string(ButtonClick));
                GUI_Variable.GUI_ColorSelector(Block, UI_ColorSelector);
                GUI_Variable.Style_SetColor(UI_ColorSelector);
                GUI_Variable.Window_SetAlpha(UI_ColorSelector.a);
                GUI_Variable.GUI_Text(Block, "Main color");
                GUI_Variable.GUI_PosSelector(Block, UI_PosSelector);
                GUI_Variable.GUI_Text(Block, "Pos selector");
                GUI_Variable.GUI_Text(Block, "Window FPS: " + to_string(GUI_Variable.Window_DrawFPS()));
            }
            else if (UI_PanelSelector == 1)//Panel 2 Paint
            {
                static EasyGUI_Direct2D::EasyGUI_Block Block;
                GUI_Variable.GUI_Block(Block, 160, 30, 600, 300, "Block");//Block
                GUI_Variable.GUI_InputText(Block, UI_InputText);
                GUI_Variable.GUI_List(Block, { "Hello","C++","Java","CS","Windows","Hello","C++","Java","CS","Windows" }, UI_List, 5);
            }
            GUI_Variable.Draw(1);//End draw
        }
    }
}