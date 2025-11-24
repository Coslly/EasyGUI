# 🤖EasyGUI for C++

<a href = "https://en.wikipedia.org/wiki/C%2B%2B"><img src = "https://img.shields.io/badge/build-C++-blue?style=flat&label=Language"></a>
<a href = "https://github.com/Coslly/EasyGUI.git"><img src = "https://img.shields.io/badge/build-Proto-orange?style=flat&label=Version"></a>

A lightweight and high-performance GUI library based on Direct2D
## 😀Features
- For people(beginner,student)
- C++ worker
- Fast
- Simple
- Safety
- Style can be easily modified
## 🥰Showcase (Example)
![image](https://github.com/Coslly/EasyGUI/blob/main/Show/ShowCase.png?raw=true)
## 😧How to use it?
### - Constitute
EasyGUI is a fast and lightweight GUI library written in C++. The core drawing library is used for original Direct2D (fast and lightweight) and is composed of the most basic key judgment system. Therefore the performance loss is negligible. Lightweight enough that a single header file is all you need to build a GUI.

Core file: `EasyGUI_Direct2D.h`

Example file: `Main.cpp`
### - Initialization
```cpp
//Initialize EasyGUI
EasyGUI_Direct2D::EasyGUI GUI_Variable = { {590, 360}, "EasyGUI Test Windows" };
```
### - Add controls
You need to add a control block.

If you add the Window_Move() function inside the loop then you don't need to add the Sleep() function
```cpp
//Variable
static bool UI_Checkbox = false;
static bool UI_Button = false;
while (true)
{
    GUI_Variable.Draw(0);//Begin Draw GUI

    GUI_Variable.GUI_BackGround();//BackGround

    static EasyGUI_Direct2D::EasyGUI_Block Block;
    GUI_Variable.GUI_Block(Block, 30, 30, 400, 200, "Test Block");//Block

    GUI_Variable.GUI_Checkbox(Block, "Checkbox", UI_Checkbox);
    GUI_Variable.GUI_Button(Block, "Button", UI_Button);

    GUI_Variable.Draw(1);//End Draw GUI

    Sleep(1);
}
```
Window_Move() function
```cpp
//Variable
static bool UI_Checkbox = false;
static bool UI_Button = false;
while (true)
{
    if (!GUI_Variable.Window_Move())
    {
        GUI_Variable.Draw(0);//Begin Draw GUI

        GUI_Variable.GUI_BackGround();//BackGround

        static EasyGUI_Direct2D::EasyGUI_Block Block;
        GUI_Variable.GUI_Block(Block, 30, 30, 400, 200, "Test Block");//Block

        GUI_Variable.GUI_Checkbox(Block, "Checkbox", UI_Checkbox);
        GUI_Variable.GUI_Button(Block, "Button", UI_Button);

        GUI_Variable.Draw(1);//End Draw GUI
    }
    //Sleep(1);//Do not need this
}
```
### - Overall Code (Example Code)
```cpp
int main()
{
    EasyGUI_Direct2D::EasyGUI GUI_Variable = { {500, 300}, "EasyGUI Test Windows" };//Initialize GUI variables

    //Variable
    static bool UI_Checkbox = false;
    static bool UI_Button = false;
    while (true)
    {
        if (!GUI_Variable.Window_Move())
        {
            GUI_Variable.Draw(0);//Begin Draw GUI

            GUI_Variable.GUI_BackGround();//BackGround

            static EasyGUI_Direct2D::EasyGUI_Block Block;
            GUI_Variable.GUI_Block(Block, 30, 30, 400, 200, "Test Block");//Block

            GUI_Variable.GUI_Checkbox(Block, "Checkbox", UI_Checkbox);
            GUI_Variable.GUI_Button(Block, "Button", UI_Button);

            GUI_Variable.Draw(1);//End Draw GUI
        }
        //Sleep(1);//Do not need this
    }
}
```
### - Finished Product

![image](https://github.com/Coslly/EasyGUI/blob/main/Show/OverallCode.png?raw=true)
