#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Entidad.h"
#include <string>
#include <vector>



class Personaje : public Entidad, public sf::Drawable {
private:
    std::vector<sf::Texture> texturasFramesDerecha;
    std::vector<sf::Texture> texturasFramesIzquierda;
    std::vector<sf::Texture> texturasFramesSalto;
    std::vector<sf::Texture> texturasFramesEstatico;
    std::vector<sf::Texture> texturasFramesAtaqueaderecha;
    std::vector<sf::Texture> texturasFramesAtaqueaizquierda;
    std::vector<sf::Texture> texturasFramesAtaquebderecha;
    std::vector<sf::Texture> texturasFramesAtaquebizquierda;



    sf::Sprite _spritePersonaje;

    sf::Vector2f _velocity = { 0.5, 0.2 };
    sf::Vector2f _gravity = { 0, 0.005 }; // Aceleración de la gravedad
    sf::Vector2f _currentVelocity = { 0, 0 };
    bool _isJumping = false;
    bool _onGround = false;
    int vida;
    int danio;
    sf::Clock animClock;
    int currentFrameDerecha = 0;
    int currentFrameIzquierda = 0;
    int currentFrameAtaqueaderecha = 0;
    int currentFrameAtaqueaizquierda = 0;
    int currentFrameAtaquebderecha = 0;
    int currentFrameAtaquebizquierda = 0;

public:
    Personaje(int vida = 100, int danio = 10) {
        _spritePersonaje.setOrigin(_spritePersonaje.getGlobalBounds().width / 2, _spritePersonaje.getGlobalBounds().height);
        Entidad::carga_sprites("./sprites/derecha", texturasFramesDerecha, 8);
        Entidad::carga_sprites("./sprites/izquierda", texturasFramesIzquierda, 8);
        Entidad::carga_sprites("./sprites/salto", texturasFramesSalto, 1);
        Entidad::carga_sprites("./sprites/estaticoderecha", texturasFramesEstatico, 1);
        Entidad::carga_sprites("./sprites/ataqueaderecha", texturasFramesAtaqueaderecha, 7);
        Entidad::carga_sprites("./sprites/ataqueaizquierda", texturasFramesAtaqueaizquierda, 7);
        Entidad::carga_sprites("./sprites/ataquebderecha", texturasFramesAtaquebderecha, 6);
        Entidad::carga_sprites("./sprites/ataquebizquierda", texturasFramesAtaquebizquierda, 6);
        _spritePersonaje.setPosition(0, 1000);
    }

    void update() {
        sf::Vector2f velocity = { 0, 0 };
        float animSpeed = 0.1f;

        // Aplicar la gravedad
        if (!_onGround) {
            _currentVelocity += _gravity;
        }
        else {
            _currentVelocity.y = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _onGround) {
            _currentVelocity.y = -_velocity.y * 7; // Impulso de salto
            _isJumping = true;
            _onGround = false;
            _spritePersonaje.setTexture(texturasFramesSalto[0]);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocity.x = -_velocity.x;
            if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                currentFrameIzquierda = (currentFrameIzquierda + 1) % texturasFramesIzquierda.size();
                _spritePersonaje.setTexture(texturasFramesIzquierda[currentFrameIzquierda]);
                animClock.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x = _velocity.x;
            if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                currentFrameDerecha = (currentFrameDerecha + 1) % texturasFramesDerecha.size();
                _spritePersonaje.setTexture(texturasFramesDerecha[currentFrameDerecha]);
                animClock.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                currentFrameAtaqueaderecha = (currentFrameAtaqueaderecha + 1) % texturasFramesAtaqueaderecha.size();
                _spritePersonaje.setTexture(texturasFramesAtaqueaderecha[currentFrameAtaqueaderecha]);
                animClock.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                currentFrameAtaquebderecha = (currentFrameAtaquebderecha + 1) % texturasFramesAtaquebderecha.size();
                _spritePersonaje.setTexture(texturasFramesAtaquebderecha[currentFrameAtaquebderecha]);
                animClock.restart();
            }
        }


        _spritePersonaje.move(velocity);
        _spritePersonaje.move(0, _currentVelocity.y);

        // Colisiones con los bordes de la ventana
        if (_spritePersonaje.getPosition().x < 0) {
            _spritePersonaje.setPosition(0, _spritePersonaje.getPosition().y);
        }
        if (_spritePersonaje.getPosition().y < 0) {
            _spritePersonaje.setPosition(_spritePersonaje.getPosition().x, 0);
            _currentVelocity.y = 0;
        }
        if (_spritePersonaje.getPosition().y + _spritePersonaje.getGlobalBounds().height > 1000) {
            _spritePersonaje.setPosition(_spritePersonaje.getPosition().x, 1000 - _spritePersonaje.getGlobalBounds().height);
            _currentVelocity.y = 0;
            _onGround = true;
            _isJumping = false;
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_spritePersonaje, states);
    }

    sf::Sprite getSprite() const {
        return _spritePersonaje;
    }
};