#pragma once
#include <SFML/Graphics.hpp>

class Point {
public:
    float x;
    float y;
    sf::Color color;
    int clusterID;

    Point(float x, float y);
    
    void draw(sf::RenderTarget& target) const;
};
