
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Enemigo.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Personaje Example");

    // Cargar la imagen de fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./sprites/background.png")) {
        std::cout << "Error al cargar la imagen de fondo" << std::endl;
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // Escalar la imagen de fondo para que se ajuste a la ventana
    float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
    backgroundSprite.setScale(scaleX, scaleY);

    Personaje personaje;
    Enemy enemy;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        personaje.update();
        enemy.update(personaje.getSprite().getPosition());
        window.clear();
        window.draw(backgroundSprite);
        window.draw(personaje);
        window.draw(enemy);
        window.display();
    }

    return 0;
}