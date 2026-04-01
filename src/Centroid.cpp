#include "Centroid.hpp"

Centroid::Centroid(float x, float y, int id, sf::Color c) : Point(x, y) {
    this->clusterID = id;
    this->color = c;
    resetAccumulators();
}

void Centroid::resetAccumulators() {
    sumX = 0;
    sumY = 0;
    pointCount = 0;
}

void Centroid::addPoint(float px, float py) {
    sumX += px;
    sumY += py;
    pointCount++;
}

void Centroid::updatePosition() {
    if (pointCount > 0) {
        x = sumX / pointCount;
        y = sumY / pointCount;
    }
}

void Centroid::draw(sf::RenderTarget& target) const {
    sf::CircleShape shape(8.0f); // Larger radius
    shape.setPosition({x - 8.0f, y - 8.0f});
    shape.setFillColor(color);
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::White); // Thicker outline
    target.draw(shape);
}
