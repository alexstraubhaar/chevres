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

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void petitTour();

private:
    std::vector<sf::CircleShape> nourritures;
    std::vector<sf::Vector2f> vitesses;

};

#endif /* adessiner_h */