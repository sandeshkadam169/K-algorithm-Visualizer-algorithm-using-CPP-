#include "KMeans.hpp"
#include <cmath>
#include <cstdlib>
#include <limits>

KMeans::KMeans(int k) : k(k), converged(false) {}

void KMeans::addPoint(float x, float y) {
    points.emplace_back(x, y);
}

float KMeans::distance(const Point& a, const Point& b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

void KMeans::initializeCentroids() {
    centroids.clear();
    converged = false;
    if (points.empty()) return;

    std::vector<sf::Color> colors = {
        sf::Color::Red, sf::Color::Green, sf::Color::Blue, 
        sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan
    };
    
    // 1. Pick first centroid randomly
    int first_idx = std::rand() % points.size();
    centroids.emplace_back(points[first_idx].x, points[first_idx].y, 0, colors[0]);

    // 2. Compute probabilities for the next centroids
    for (int i = 1; i < k; ++i) {
        std::vector<float> dist_sq(points.size(), std::numeric_limits<float>::max());
        float sum_dist_sq = 0;

        for (size_t p_idx = 0; p_idx < points.size(); ++p_idx) {
            for (const auto& c : centroids) {
                float d = distance(points[p_idx], c);
                if (d * d < dist_sq[p_idx]) {
                    dist_sq[p_idx] = d * d;
                }
            }
            sum_dist_sq += dist_sq[p_idx];
        }

        float rand_val = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * sum_dist_sq;
        float cumulative = 0;
        int next_idx = -1;
        for (size_t p_idx = 0; p_idx < points.size(); ++p_idx) {
            cumulative += dist_sq[p_idx];
            if (cumulative >= rand_val) {
                next_idx = p_idx;
                break;
            }
        }
        if (next_idx == -1) next_idx = points.size() - 1;

        centroids.emplace_back(points[next_idx].x, points[next_idx].y, i, colors[i % colors.size()]);
    }
}

void KMeans::assignPoints() {
    for (auto& p : points) {
        float min_dist = -1;
        int best_cluster = -1;
        for (int i = 0; i < centroids.size(); ++i) {
            float d = distance(p, centroids[i]);
            if (min_dist == -1 || d < min_dist) {
                min_dist = d;
                best_cluster = i;
            }
        }
        p.clusterID = best_cluster;
        if (best_cluster != -1) {
            p.color = centroids[best_cluster].color;
        }
    }
}

void KMeans::updateCentroids() {
    for (auto& c : centroids) {
        c.resetAccumulators();
    }
    for (auto& p : points) {
        if (p.clusterID != -1) {
            centroids[p.clusterID].addPoint(p.x, p.y);
        }
    }

    converged = true;
    for (auto& c : centroids) {
        if (c.pointCount > 0) {
            float oldX = c.x;
            float oldY = c.y;
            c.updatePosition();
            if (std::abs(c.x - oldX) > 0.1f || std::abs(c.y - oldY) > 0.1f) {
                converged = false;
            }
        }
    }
}

void KMeans::step() {
    if (centroids.empty() && !points.empty()) {
        initializeCentroids();
    }
    if (!converged && !centroids.empty()) {
        assignPoints();
        updateCentroids();
    }
}

bool KMeans::isConverged() const {
    return converged;
}

void KMeans::draw(sf::RenderTarget& target) const {
    for (const auto& p : points) p.draw(target);
    for (const auto& c : centroids) c.draw(target);
}

float KMeans::getInertia() const {
    float inertia = 0.0f;
    for (const auto& p : points) {
        if (p.clusterID != -1) {
            float d = distance(p, centroids[p.clusterID]);
            inertia += d * d;
        }
    }
    return inertia;
}
