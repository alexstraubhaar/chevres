#ifndef gui_h
#define gui_h
#pragma once

#include <SFML/Graphics.hpp>

// fonctions
void hello();

class Gui
{

public:
    //Constructeurs/destructeurs
    Gui();
    ~Gui();

    // Méthodes publiques
    bool tour();

private:
    // Méthodes privées
    void gestionDesEvenements();
    void dessine();

    // Membres privés
    sf::RenderWindow fenetrePrincipale; /*!< a priori la seule fenêtre du programme */

};

#endif //gui_h
