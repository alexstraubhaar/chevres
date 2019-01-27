#include <iostream>

#include "../tools/randomTools.h"
#include "toDraw.h"

// constantes à changer en parametres
const sf::Color foodCircleColor = sf::Color(20,255,20); //Vert moche
const float foodRadius = 5.f;
const int foodNumber = 10;
const float minimum = 0.f, maximum = 1000.f;
const float minAcceleration = -500.f, maxAcceleration = 500.f;

ToDraw::ToDraw()
{
    RandomGenerator_float randomf(minimum, maximum);

    for(int i = 0 ; i < foodNumber ; ++i)
    {
        sf::Vector2f position(randomf.rnd(), randomf.rnd());
        std::cout << "x : " << position.x << " ; y : " << position.y << "\n"; // Debug ; à supprimer
        sf::CircleShape foodCircle(foodRadius);

        foodCircle.setFillColor(foodCircleColor);
        foodCircle.setPosition(position);
        food.push_back(foodCircle);
        speed.push_back(sf::Vector2f(0, 0));
    }

}

void ToDraw::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i = 0 ; i < food.size() ; ++i)
    {
        target.draw(food[i], states);
    }
}
void ToDraw::update()
{
    RandomGenerator_float randomf(minAcceleration, maxAcceleration);

    for(int i = 0 ; i < food.size() ; ++i)
    {
        sf::Vector2f acceleration(randomf.rnd()/100000, (randomf.rnd()/100000));
        speed[i] += acceleration;
        if(speed[i].x > 1){
            speed[i].x = 1;
        }
        if(speed[i].y > 1){
            speed[i].y = 1;
        }
        if(speed[i].x < -1){
            speed[i].x = -1;
        }
        if(speed[i].y < -1){
            speed[i].y = -1;
        }
        food[i].setPosition(food[i].getPosition() + speed[i]);
        if(food[i].getPosition().x < 0 || food[i].getPosition().x > 1000)
        {
            speed[i].x *= -1;
        }
        if(food[i].getPosition().y < 0 || food[i].getPosition().y > 1000)
        {
            speed[i].y *= -1;
        }
    }
}
