//
// Created by Tello on 01/11/2023.
//

#include "ref.h"

void Cont(){
    sf::RenderWindow(sf::VideoMode(1270, 720), "box2d/Contacto");
    b2Vec2 gravity(0.0f, 9.8f);
    b2World world(gravity);
}