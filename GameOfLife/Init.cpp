#include <Gui.h>
#include <cstdlib>

int main()
{
    Gui::Builder builder;

    builder.setDimensions(40, 40, 40);
    
    builder.setLiveRule(3, 7);
    builder.setBirthRule(6, 6);

    builder.setModularBoard(1);

    //builder.setInitalState("ox\toox\txxx\nox\toox\txxx"); // glider 5766
    // builder.setInitalState("xx\txx\txx"); //oscilator 5766
    //builder.setInitalState("\tox\nox\txxx\tox\n\tox"); // blinker 5545

    //builder.setInitalState("xx\noxx\nox");
    builder.setTexture("C:/Users/jinch/Desktop/Untitled.png");

    builder.setDrawDelay(100);

    builder.initGui();


#if _DEBUG
    system("pause");
#endif

}