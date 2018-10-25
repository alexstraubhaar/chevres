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
    ADessiner adessiner;

    std::cout << "Hello world !\n"; /*!< juste pour un code minimum, pour tester le makefile */
    hello();

    while(etatProgramme != QUITTE){

        adessiner.petitTour();
        if(!gui.tour(adessiner))
        {
            etatProgramme = QUITTE;
        }

    }

    return 0;
}
