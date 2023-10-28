//
// Created by Tello on 27/10/2023.
//

#ifndef JOINS_REF_H
#define JOINS_REF_H

#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

using namespace std;

const float M2P = 20.0f; //Metros a pixeles
const float P2M = 1.0f/20.0f; //Pixeles a metros

void Dist();
void Gear();
void Revolute();

class Cube{
public:
    Cube(b2World &world, float sizeX, float sizeY, float posX, float posY, float density, float friction, b2BodyType type, sf::Color color = sf::Color::Blue){
        //Variables
        b2BodyDef bodyDef;
        b2FixtureDef fixtureDef;
        b2PolygonShape shape;

        //Creacion figura SFML
        rectangleShape.setSize(sf::Vector2f (sizeX, sizeY));
        rectangleShape.setOrigin(sizeX/2, sizeY/2);
        rectangleShape.setFillColor(color);

        //Creacion cuerpo box2D
        bodyDef.type = type;
        bodyDef.position.Set(posX * P2M, posY * P2M);
        body = world.CreateBody(&bodyDef);

        shape.SetAsBox((sizeX/2) * P2M, (sizeY/2) * P2M);

        fixtureDef.shape = &shape;
        fixtureDef.friction = friction;
        fixtureDef.density = density;

        body->CreateFixture(&fixtureDef);
    }

    //Actualizamos la posicion y rotacion del cubo
    void Update(){
        sf::Vector2f position(body->GetPosition().x * M2P, body->GetPosition().y * M2P);
        float rotation = body->GetAngle() * 180 / b2_pi; //Constante incluida de box2D
        rectangleShape.setPosition(position);
        rectangleShape.setRotation(rotation);
    }

    void Draw(sf::RenderWindow &win) const {
        win.draw(rectangleShape);
    }

    b2Body *getBody(){
        return body;
    }

    //Movimiento personalizado
    void MoveTo(b2Vec2 pos, sf::Keyboard::Key key){
        if(sf::Keyboard::isKeyPressed(key)){
            body->ApplyForceToCenter(pos,true);
        }
    }
private:
    //SFML
    sf::RectangleShape rectangleShape;
    b2Body* body;
};

#endif //JOINS_REF_H
