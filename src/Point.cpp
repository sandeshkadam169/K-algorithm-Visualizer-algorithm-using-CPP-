#include "Point.hpp"

Point::Point(float x, float y) : x(x), y(y), color(sf::Color::White), clusterID(-1) {}

void Point::draw(sf::RenderTarget& target) const {
    sf::CircleShape shape(3.0f);
    shape.setPosition({x - 3.0f, y - 3.0f});
    shape.setFillColor(color);
    target.draw(shape);
}
