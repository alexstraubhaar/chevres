#include <iostream>

#include "interface/gui.h"
#include "simulation/toDraw.h"

enum state
{
    RUN,
    PAUSE,
    STOP,
    QUIT
};

int main()
{

    state programState = STOP;
    Gui gui;
    ToDraw toDraw;

    while(programState != QUIT){

        toDraw.update();
        if(!gui.round(toDraw))
        {
            programState = QUIT;
        }

    }

    return 0;
}
