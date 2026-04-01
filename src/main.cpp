#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "KMeans.hpp"
#include <string>

int main() {
    // Phase 1: 800x600 window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "K-Means Visualizer");
    window.setFramerateLimit(60);

    KMeans kmeans(3); // Default to k=3

    sf::Font font;
    bool fontLoaded = font.openFromFile("/System/Library/Fonts/Monaco.ttf") ||
                      font.openFromFile("/System/Library/Fonts/Helvetica.ttc");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    window.close();
                } else if (keyPressed->code == sf::Keyboard::Key::Space) {
                    kmeans.step();
                }
            } else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    kmeans.addPoint(static_cast<float>(mousePressed->position.x), static_cast<float>(mousePressed->position.y));
                }
            }
        }

        window.clear(sf::Color(30, 30, 30)); // Dark grey background
        
        kmeans.draw(window);

        if (fontLoaded) {
            sf::Text text(font);
            text.setString("Inertia: " + std::to_string(kmeans.getInertia()) + "\nPoints: " + std::to_string(kmeans.points.size()));
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::White);
            text.setPosition({10.f, 10.f});
            window.draw(text);
        }

        window.display();
    }

    return 0;
}
