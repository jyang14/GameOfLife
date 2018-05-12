#include <gui.h>
#include <cstdlib>

int main()
{
    gui::builder builder;

    builder.set_dimensions(100, 100, 100);

    builder.set_live_rule(2, 3);
    builder.set_birth_rule(4, 5);

    builder.set_modular_board(0);

    // builder.setInitalState("ox\toox\txxx\nox\toox\txxx"); // glider 5766
    // builder.setInitalState("xx\txx\txx"); //oscilator 5766
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

    builder.set_texture("mams.jpeg");

    builder.set_draw_delay(100);

    builder.init_gui();


#if _DEBUG
    system("pause");
#endif

}