# 🤖EasyGUI

<a href="https://en.wikipedia.org/wiki/C%2B%2B"><img src="https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white"></a>
<a href="https://visualstudio.microsoft.com/"><img src="https://img.shields.io/badge/Visual%20Studio-2022-5C2D91?style=flat&logo=visualstudio&logoColor=white"></a>
<a href = "https://en.wikipedia.org/wiki/Direct2D"><img src = "https://img.shields.io/badge/Direct2D-purple?style=flat&label=Render"></a>
<a href = "https://github.com/Coslly/EasyGUI.git"><img src = "https://img.shields.io/badge/Proto-orange?style=flat&label=Version"></a>
<a href = "https://github.com/Coslly/EasyGUI/blob/main/EasyGUI/EasyGUI/EasyGUI_Direct2D.h"><img src = "https://img.shields.io/badge/EasyGUI.h-white?logo=github&label=Core"></a>

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
![image](https://github.com/Coslly/EasyGUI/blob/main/Show/ShowCase.gif?raw=true)
## 😧How to use it?
### - Constitute
EasyGUI is a fast and lightweight GUI library written in C++. The core drawing library is used for original Direct2D (fast and lightweight) and is composed of the most basic key judgment system. Therefore the performance loss is negligible. Lightweight enough that a single header file is all you need to build a GUI.

Core file: `EasyGUI_Direct2D.h`

Example file: `Main.cpp`
### - Initialization
```cpp
//Initialize EasyGUI
EasyGUI_Direct2D::EasyGUI GUI_Variable = { "EasyGUI Test Windows", {590, 360} };
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
    UI_Button = GUI_Variable.GUI_Button(Block, "Button");

    GUI_Variable.Draw(1);//End Draw GUI

    Sleep(1);
}
```
### - Overall Code (Example Code)
```cpp
int main()
{
    EasyGUI_Direct2D::EasyGUI GUI_Variable = { "EasyGUI Test Windows", {500, 300} };

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
        UI_Button = GUI_Variable.GUI_Button(Block, "Button");

        GUI_Variable.Draw(1);//End Draw GUI
        //Sleep(1);//Do not need this
    }
}
```
### - Finished Product

![image](https://github.com/Coslly/EasyGUI/blob/main/Show/OverallCode.png?raw=true)
