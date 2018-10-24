#include <iostream>

#include "gui.h"

//Constantes à changer en parametres...
int tailleFenetreX = 1000;
int tailleFenetreY = 1000;
sf::Color fondDecran = sf::Color(5,27,1);

void hello(){
    std::cout << "test du makefile depuis le fichier inclu...\n";
}

Gui::Gui()
{
    fenetrePrincipale.create(sf::VideoMode(tailleFenetreX, tailleFenetreY), L"Chêêêêêêêvres");
}

Gui::~Gui()
{

}

bool Gui::tour()
{
    gestionDesEvenements();
    dessine();
    return fenetrePrincipale.isOpen();
}

void Gui::gestionDesEvenements()
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
    fenetrePrincipale.clear(fondDecran);
    fenetrePrincipale.display();
}
