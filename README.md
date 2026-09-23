# 🤖EasyGUI

<a href="https://en.wikipedia.org/wiki/C%2B%2B"><img src="https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white"></a>
<a href="https://visualstudio.microsoft.com/"><img src="https://img.shields.io/badge/Visual%20Studio-2022-5C2D91?style=flat&logo=visualstudio&logoColor=white"></a>
<a href = "https://en.wikipedia.org/wiki/Direct2D"><img src = "https://img.shields.io/badge/Direct2D-purple?style=flat&label=Render"></a>
<a href = "https://github.com/Coslly/EasyGUI.git"><img src = "https://img.shields.io/badge/Proto-orange?style=flat&label=Version"></a>
<a href = "https://github.com/Coslly/EasyGUI/blob/main/EasyGUI/EasyGUI/EasyGUI_Direct2D.h"><img src = "https://img.shields.io/badge/EasyGUI.h-white?logo=github&label=Core"></a>

A lightweight and high-performance GUI library based on Direct2D

Empower C++ beginners to build their own menus in no time.

一个基于 Direct2D 的轻量级高性能 GUI 库

让 C++ 初学者能够快速构建自己的菜单。
## 😀Features
- For C++ worker
- Fast - Simple - Safety - Light
- Style can be easily modified
## 👾Technical highlights
Some technical problems I encountered and their solutions during the development of EasyGUI

*I believe there are always better ways to optimize this. If you have any ideas, inspirations, or improvements, feel free to open an Issue or start a discussion in the EasyGUI repository! - Coslly*
| Skill | Explanation / Description | Complexity |
| --- | --- | --- |
| [Block refresh delay](https://github.com/Coslly/EasyGUI/blob/main/Docs/TechnicalSkill1.md) | Introduce a throttled/debounced redraw delay for each block to improve rendering performance without compromising user experience. | ★★★☆☆ |
| [Memory resource management](https://github.com/Coslly/EasyGUI/blob/main/Docs/TechnicalSkill2.md) | Optimize memory usage and performance through hash-based data structures and periodic garbage collection/resource release. | ★★★★☆ |
## 🥰Showcase (Example)
![image](https://github.com/Coslly/EasyGUI/blob/main/Docs/Image/ShowCase.png?raw=true)
![image](https://github.com/Coslly/EasyGUI/blob/main/Docs/Image/ShowCase.gif?raw=true)
## 😧How to use it?
### - Constitute
EasyGUI is a fast and lightweight GUI library written in C++. The core drawing library is used for original Direct2D (fast and lightweight) and is composed of the most basic key judgment system. Therefore the performance loss is negligible. Lightweight enough that a single header file is all you need to build a GUI.

Core file: `EasyGUI_Direct2D.h`

Example file: `Main.cpp`
### - Initialization
```cpp
//Initialize EasyGUI
EasyGUI_Direct2D::EasyGUI GUI_Variable("EasyGUI Test Windows", {590, 360});
```
### - Add controls
You need to add a control block.
Then add controls inside the block.
```cpp
//Variable
static bool UI_Checkbox = false;
static bool UI_Button = false;
while (true)
{
    GUI_Variable.Draw(0);//Begin Draw GUI

    GUI_Variable.GUI_BackGround();//BackGround

    static EasyGUI_Direct2D::EasyGUI_Block Block{};
    if (GUI_Variable.GUI_Block(Block, "Test Block", 30, 30, 400, 200))//Block
    {
        GUI_Variable.GUI_Checkbox(Block, "Checkbox", UI_Checkbox);
        UI_Button = GUI_Variable.GUI_Button(Block, "Button");
    }
    GUI_Variable.Draw(1);//End Draw GUI

    Sleep(1);
}
```
### - Overall Code (Example Code)
```cpp
int main()
{
    EasyGUI_Direct2D::EasyGUI GUI_Variable("EasyGUI Test Windows", {500, 300});

    //Variable
    static bool UI_Checkbox = false;
    static bool UI_Button = false;
    while (true)
    {
        GUI_Variable.Draw(0);//Begin Draw GUI

        GUI_Variable.GUI_BackGround();//BackGround

        static EasyGUI_Direct2D::EasyGUI_Block Block{};
        if (GUI_Variable.GUI_Block(Block, "Test Block", 30, 30, 400, 200))//Block
        {
            GUI_Variable.GUI_Checkbox(Block, "Checkbox", UI_Checkbox);
            UI_Button = GUI_Variable.GUI_Button(Block, "Button");
        }
        GUI_Variable.Draw(1);//End Draw GUI
        //Sleep(1);//Do not need this
    }
}
```
### - Finished Product

![image](https://github.com/Coslly/EasyGUI/blob/main/Docs/Image/OverallCode.png?raw=true)
