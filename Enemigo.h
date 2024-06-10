#pragma once
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include <cmath>
#include <random>

class Enemy : public Entidad, public sf::Drawable {
    sf::Vector2f _velocity;
    sf::Vector2f _gravity = { 0, 0.005f };
    sf::Vector2f _currentVelocity = { 0, 0 };
    sf::Clock _animClock;
    bool _onGround = false;
    float _speed;
    float _attackDistance = 100.0f;
    int _currentFrameDerecha = 0;
    int _currentFrameIzquierda = 0;
    int _currentFrameEstatico = 0;
    int _currentFrameSalto = 0;
    int _currentFrameAtaqueA = 0;
    std::vector<sf::Texture> _texturasDerecha;
    std::vector<sf::Texture> _texturasIzquierda;
    std::vector<sf::Texture> _texturasEstatico;
    std::vector<sf::Texture> _texturasSalto;
    std::vector<sf::Texture> _texturasAtaqueA;
    sf::Sprite _sprite;

public:
    Enemy(int vida = 100, int danio = 10) {
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
        Entidad::carga_sprites("./sprites/enemy/derecha", _texturasDerecha, 1);
        Entidad::carga_sprites("./sprites/enemy/izquierda", _texturasIzquierda, 1);
        Entidad::carga_sprites("./sprites/enemy/estatico", _texturasEstatico, 1);
        Entidad::carga_sprites("./sprites/enemy/salto", _texturasSalto, 1);
        Entidad::carga_sprites("./sprites/enemy/ataqueA", _texturasAtaqueA, 5);
        _sprite.setPosition(1920, 1000);
        _speed = 0.3f;
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }

    void update(const sf::Vector2f& targetPosition) {

        if (!_onGround) {
            _currentVelocity += _gravity;
        }
        else {
            _currentVelocity.y = 0;
        }

        sf::Vector2f targetCenter = targetPosition + sf::Vector2f(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
        sf::Vector2f direction = targetCenter - _sprite.getPosition();
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            if (_animClock.getElapsedTime().asSeconds() > 0.1f) {
                _currentFrameAtaqueA = (_currentFrameAtaqueA + 1) % _texturasAtaqueA.size();
                _sprite.setTexture(_texturasAtaqueA[_currentFrameAtaqueA]);
                _animClock.restart();
            }
        }
        else {
            // Perseguir al personaje
            if (length != 0) {
                direction /= length;
            }
            _velocity = direction * _speed;
            _sprite.move(_velocity);
            _sprite.move(0, _currentVelocity.y);

            // Animación de movimiento
            if (_velocity.x > 0) {
                if (_animClock.getElapsedTime().asSeconds() > 0.1f) {
                    _currentFrameDerecha = (_currentFrameDerecha + 1) % _texturasDerecha.size();
                    _sprite.setTexture(_texturasDerecha[_currentFrameDerecha]);
                    _animClock.restart();
                }
            }
            else if (_velocity.x < 0) {
                if (_animClock.getElapsedTime().asSeconds() > 0.1f) {
                    _currentFrameIzquierda = (_currentFrameIzquierda + 1) % _texturasIzquierda.size();
                    _sprite.setTexture(_texturasIzquierda[_currentFrameIzquierda]);
                    _animClock.restart();
                }
            }
            else {
                _sprite.setTexture(_texturasEstatico[0]);
            }
        }

        if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 1000) {
            _sprite.setPosition(_sprite.getPosition().x, 1000 - _sprite.getGlobalBounds().height);
            _currentVelocity.y = 0;
            _onGround = true;
        }
    }

    sf::FloatRect getBounds() const {
        return _sprite.getGlobalBounds();
    }
};
