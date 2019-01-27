#ifndef gui_h
#define gui_h
#pragma once

#include <SFML/Graphics.hpp>

class Gui
{

public:
    //Constructeurs/destructeurs
    Gui();

    // Méthodes publiques
    bool round(sf::Drawable& toDraw);

private:
    // Méthodes privées
    void eventsManagement();
    void draw(sf::Drawable& toDraw);

public: //Juste pour tester...
    // Membres privés
    sf::RenderWindow mainWinow; /*!< a priori la seule fenêtre du programme */

};

#endif //gui_h
