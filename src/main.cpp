#include <iostream>

//#include <SFML/Graphics.hpp>

#include "Interface/gui.h"
#include "Simulation/adessiner.h"

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

    ADessiner adessiner; // il faudra qu'un classe Simulation générale hérite de Adessiner...


    return 0;
}
