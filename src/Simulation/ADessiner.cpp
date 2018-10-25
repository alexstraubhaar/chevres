#include <iostream>

#include "../outils/alea.h"

#include "adessiner.h"

// constantes à changer en parametres
const sf::Color couleurCercleNourriture = sf::Color(20,255,20); //Vert moche
const float rayonDeNourriture = 5.f;
const int nbreDeNourritures = 10;
const float minimum = 0.f, maximum = 1000.f;
const float minAcceleration = -500.f, maxAcceleration = 500.f;

ADessiner::ADessiner()
{
    generateurAleaF aleaf(minimum, maximum);

    for(int i = 0 ; i < nbreDeNourritures ; ++i)
    {
        sf::Vector2f position(aleaf.alea(), aleaf.alea());
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
    generateurAleaF aleaf(minAcceleration, maxAcceleration);

    for(int i = 0 ; i < nourritures.size() ; ++i)
    {
        sf::Vector2f acceleration(aleaf.alea()/100000, (aleaf.alea()/100000));
        vitesses[i] += acceleration;
        if(vitesses[i].x > 1){
            vitesses[i].x = 1;
        }
        if(vitesses[i].y > 1){
            vitesses[i].y = 1;
        }
        if(vitesses[i].x < -1){
            vitesses[i].x = -1;
        }
        if(vitesses[i].y < -1){
            vitesses[i].y = -1;
        }
        nourritures[i].setPosition(nourritures[i].getPosition() + vitesses[i]);
        if(nourritures[i].getPosition().x < 0 || nourritures[i].getPosition().x > 1000)
        {
            vitesses[i].x *= -1;
        }
        if(nourritures[i].getPosition().y < 0 || nourritures[i].getPosition().y > 1000)
        {
            vitesses[i].y *= -1;
        }
    }
}
