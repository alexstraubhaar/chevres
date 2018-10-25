#include <iostream>

#include "Interface/gui.h"

enum etat
{
    MARCHE,
    PAUSE,
    ARRET,
    QUITTE
};

int main()
{
    etat etatProgramme = ARRET;
    Gui gui;

    std::cout << "Hello world !\n"; /*!< juste pour un code minimum, pour tester le makefile */
    hello();

    while(etatProgramme != QUITTE){

        if(!gui.tour())
        {
            etatProgramme = QUITTE;
        }

    }

    return 0;
}
