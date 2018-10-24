#include <iostream>

#include "../outils/alea.h"

#include "adessiner.h"

// constantes à changer en parametres
const sf::Color couleurCercleNourriture = sf::Color(20,255,20);
const float rayonDeNourriture = 5.f;
const int nbreDeNourritures = 1000;
const int minimumX = 0.f, minimumY = 1000.f;

ADessiner::ADessiner()
{

    generateurAleaF alea(minimumX, minimumY);

    for(int i = 0 ; i < nbreDeNourritures ; ++i)
    {
        sf::Vector2f position(alea.alea(), alea.alea());
        std::cout << "x : " << position.x << " ; y : " << position.y << "\n";
        sf::CircleShape rondNourrirure(rayonDeNourriture);
        rondNourrirure.setFillColor(couleurCercleNourriture);
        rondNourrirure.setPosition(position);
        nourritures.push_back(rondNourrirure);
    }

}

void ADessiner::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i = 0 ; i < nourritures.size() ; ++i)
    {
        target.draw(nourritures[i], states);
    }
}
