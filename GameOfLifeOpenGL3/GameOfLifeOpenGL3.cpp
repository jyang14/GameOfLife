// GameOfLifeOpenGL3.cpp : Defines the entry point for the console application.
//

#include "gui3.h"
#include <iostream>

#if _DEBUG
#include <cstdlib>
#endif

int main()
{
#if _DEBUG
    system("cd");
#endif

    gui3 gui;

    gui.set_dimensions(100, 100, 100);

    gui.set_live_rule(2, 3);
    gui.set_birth_rule(4, 5);

    gui.set_modular_board(0);

    // builder.setInitalState("ox\toox\txxx\nox\toox\txxx"); // glider 5766
    // gui.set_inital_state("xx\txx\txx"); //oscilator 5766
    // builder.setInitalState("\tox\nox\txxx\tox\n\tox"); // blinker 5545

    // builder.setInitalState("xx\noxx\nox");

    //builder.setInitalState(
    //    "ooxxoooooxx\n"
    //    "oooxxoooxx\n"
    //    "xooxoxoxoxoox\n"
    //    "xxxoxxoxxoxxx\n"
    //    "oxoxoxoxoxox\n"
    //    "ooxxxoooxxx\n"
    //    "\n"
    //    "ooxxxoooxxx\n"
    //    "oxoxoxoxoxox\n"
    //    "xxxoxxoxxoxxx\n"
    //    "xooxoxoxoxoox\n"
    //    "oooxxoooxx\n"
    //    "ooxxoooooxx\n"
    //); // blinker 2333 2d

    gui.set_texture("mams.png");

    gui.set_draw_delay(100);

    std::cout << gui.show_gui() << std::endl;


#if _DEBUG
    system("pause");
#endif

}
