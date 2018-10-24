#ifndef adessiner_h
#define adessiner_h
#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

class ADessiner : public sf::Drawable, public sf::Transformable
{
public:
    // constructeurs/destructeurs
    ADessiner();
    //~ADessiner();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<sf::CircleShape> nourritures;

};

#endif /* adessiner_h */
