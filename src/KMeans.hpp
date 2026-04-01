#pragma once
#include <vector>
#include "Point.hpp"
#include "Centroid.hpp"
#include <SFML/Graphics.hpp>

class KMeans {
public:
    int k;
    std::vector<Point> points;
    std::vector<Centroid> centroids;
    bool converged;

    KMeans(int k);

    void addPoint(float x, float y);
    void initializeCentroids();
    void assignPoints();
    void updateCentroids();
    void step();
    bool isConverged() const;
    static float distance(const Point& a, const Point& b);
    float getInertia() const;

    void draw(sf::RenderTarget& target) const;
};
