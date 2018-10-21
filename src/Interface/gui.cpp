#include <iostream>

#include "gui.h"

void hello(){
    std::cout << "test du makefile depuis le fichier inclu...\n";
}

Gui::Gui()
{
    fenetrePrincipale.create(sf::VideoMode(1000, 1000), "Chevres");
}

Gui::~Gui()
{

}

bool Gui::tour()
{
    gestionDeEvenements();
    dessine();
    return fenetrePrincipale.isOpen();
}

void Gui::gestionDeEvenements()
{
    sf::Event evenements;
    while (fenetrePrincipale.pollEvent(evenements))
    {
        if(evenements.type == sf::Event::Closed)
        {
            fenetrePrincipale.close();
        }

    }
}

void Gui::dessine()
{
    fenetrePrincipale.clear(sf::Color(5, 37, 1));
    fenetrePrincipale.display();
}
