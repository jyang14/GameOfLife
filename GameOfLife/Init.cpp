#include <Gui.h>
#include <cstdlib>

int main()
{
    Gui::Builder builder;

    builder.setDimensions(30, 30, 30);

    builder.setLiveRule(2, 3);
    builder.setBirthRule(4, 5);

    builder.setModularBoard(0);

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

    builder.setTexture("mams.jpeg");

    builder.setDrawDelay(100);

    builder.initGui();


#if _DEBUG
    system("pause");
#endif

}