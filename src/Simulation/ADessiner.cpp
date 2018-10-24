#include <iostream>

#include "../outils/alea.h"

#include "adessiner.h"

// constantes à changer en parametres
const sf::Color couleurCercleNourriture = sf::Color(20,255,20); //Vert moche
const float rayonDeNourriture = 5.f;
const int nbreDeNourritures = 1000;
const float minimum = 0.f, maximum = 1000.f;
const float minAcceleration = -500.f, maxAcceleration = 500.f;

ADessiner::ADessiner()
{
    generateurAleaF alea0_1000f(minimum, maximum);

    for(int i = 0 ; i < nbreDeNourritures ; ++i)
    {
        sf::Vector2f position(alea0_1000f.alea(), alea0_1000f.alea());
        std::cout << "x : " << position.x << " ; y : " << position.y << "\n"; // Debug ; à supprimer
        sf::CircleShape rondNourrirure(rayonDeNourriture);

        rondNourrirure.setFillColor(couleurCercleNourriture);
        rondNourrirure.setPosition(position);
        nourritures.push_back(rondNourrirure);
        vitesses.push_back(sf::Vector2f(0, 0));
    }

}

void ADessiner::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    for(int i = 0 ; i < nourritures.size() ; ++i)
    {
        target.draw(nourritures[i], states);
    }
}
void ADessiner::petitTour()
{
    generateurAleaF alea0_1000f(minAcceleration, maxAcceleration);

    for(int i = 0 ; i < nourritures.size() ; ++i)
    {
        sf::Vector2f acceleration(alea0_1000f.alea()/10000, (alea0_1000f.alea()/10000));
        vitesses[i].x += acceleration.x;
        vitesses[i].y += acceleration.y;

        nourritures[i].setPosition(
            nourritures[i].getPosition().x + vitesses[i].x,
            nourritures[i].getPosition().y + vitesses[i].y);
    }
}
