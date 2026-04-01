#pragma once
#include "Point.hpp"

class Centroid : public Point {
public:
    float sumX;
    float sumY;
    int pointCount;

    Centroid(float x, float y, int id, sf::Color c);

    void resetAccumulators();
    void addPoint(float px, float py);
    void updatePosition();
    
    // Override draw or provide a specific one
    void draw(sf::RenderTarget& target) const;
};
