#ifndef toDraw_h
#define toDraw_h
#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

class ToDraw : public sf::Drawable, public sf::Transformable
{
public:
    // constructeurs/destructeurs
    ToDraw();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

private:
    std::vector<sf::CircleShape> food;
    std::vector<sf::Vector2f> speed;

};

#endif /* to_draw_h */
