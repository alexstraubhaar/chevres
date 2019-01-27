#include <iostream>

#include "gui.h"

//Constantes à changer en parametres...
int windowSizeX = 1000;
int windowSizeY = 1000;
sf::Color backGround = sf::Color(5,27,1); //très joli vert

Gui::Gui()
{
    mainWinow.create(sf::VideoMode(windowSizeX, windowSizeY), L"Chêêêêêêêêêêvre");
}

bool Gui::round(sf::Drawable& toDraw)
{
    eventsManagement();
    draw(toDraw);
    return mainWinow.isOpen();
}

void Gui::eventsManagement()
{
    sf::Event events;
    while (mainWinow.pollEvent(events))
    {
        if(events.type == sf::Event::Closed)
        {
            mainWinow.close();
        }
    }
}

void Gui::draw(sf::Drawable& toDraw)
{
    mainWinow.clear(backGround);
    mainWinow.draw(toDraw);
    mainWinow.display();
}
