//#include <SFML/Graphics.hpp>

#include "adessiner.h"

// constantes à changer en parametres
const sf::Color couleurCercleNourriture = sf::Color(20,255,20);

ADessiner::ADessiner()
{

    for(int i = 0 ; i < 1000 ; ++i)
    {
        sf::CircleShape rondNourrirure;

        nourritures.push_back(rondNourrirure);
    }

}

// ADessiner::~ADessiner()
// {
//
// }

void ADessiner::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
