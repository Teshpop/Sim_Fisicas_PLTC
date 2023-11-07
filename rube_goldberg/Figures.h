//
// Created by Tello on 05/11/2023.
//

#ifndef RUBE_GOLDBERG_FIGURES_H
#define RUBE_GOLDBERG_FIGURES_H

const float M2P = 20.0f;
const float P2M = 1/20.0f;

class Figure{
public:
    Figure(b2World &world, sf::Vector2f pos, sf::Color color){}

    virtual void Draw(sf::RenderWindow &win){}
    virtual void Update(){}

    b2Body* GetBody() {return body;}

protected:
    b2Body* body{};
    sf::RectangleShape rectangleShape;
    sf::CircleShape circleShape;

    void DefBody(b2World &world, sf::Vector2f pos, b2BodyType type){
        b2BodyDef bodyDef;
        bodyDef.type = type;
        bodyDef.position.Set(pos.x * P2M, pos.y * P2M);
        body = world.CreateBody(&bodyDef);
    }

    void Rectangle(sf::Vector2f size, float density, float friction, sf::Color color){
        rectangleShape.setSize(size);
        rectangleShape.setOrigin(size.x/2, size.y/2);
        rectangleShape.setFillColor(color);

        b2PolygonShape shape;
        shape.SetAsBox((size.x / 2) * P2M, (size.y / 2) * P2M);

        Fixture(density, friction, shape);
    }

    void Circle(float radius, float density, float friction, sf::Color color){
        circleShape.setRadius(radius);
        circleShape.setFillColor(color);
        circleShape.setPosition(radius, radius);

        b2CircleShape shape;
        shape.m_radius = circleShape.getRadius() * P2M;

        Fixture(density, friction, shape);
    }

    void Fixture(float density, float friction, b2Shape &shape){
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        body->CreateFixture(&fixtureDef);
    }
};

//Cubos

class dynamicCube : public Figure {
public:
    dynamicCube(b2World &world, sf::Vector2f pos, sf::Vector2f size, sf::Color color = sf::Color::Blue) : Figure(world, pos, color){
        DefBody(world, pos, b2_dynamicBody);
        Rectangle(size, 1.0f, 0.3f, color);
    }

    void Draw(sf::RenderWindow &win) override{
        win.draw(rectangleShape);
    }

    void Update() override{
        sf::Vector2f position(body->GetPosition().x * M2P, body->GetPosition().y * M2P);
        float rotation = body->GetAngle() * 180 / b2_pi;
        rectangleShape.setPosition(position);
        rectangleShape.setRotation(rotation);
    }
};

class staticCube : public Figure{
public:
    staticCube(b2World &world, sf::Vector2f pos, sf::Vector2f size, sf::Color color = sf::Color::Red) : Figure(world, pos, color){
        DefBody(world, pos, b2_staticBody);
        Rectangle(size, 0.0f, 0.3f, color);
    }

    void Draw(sf::RenderWindow &win) override{
        win.draw(rectangleShape);
    }

    void Update() override{
        sf::Vector2f position(body->GetPosition().x * M2P, body->GetPosition().y * M2P);
        float rotation = body->GetAngle() * 180 / b2_pi;
        rectangleShape.setPosition(position);
        rectangleShape.setRotation(rotation);
    }
};

//Circulos

class dynamicCircle : public Figure{
public:
    dynamicCircle(b2World &world, sf::Vector2f pos, float radius, sf::Color color = sf::Color::Blue) : Figure(world, pos, color){
        DefBody(world, pos, b2_dynamicBody);
        Circle(radius, 1.0f, 0.3f, color);
    }

    void Draw(sf::RenderWindow &win) override{
        win.draw(circleShape);
    }

    void Update() override{
        sf::Vector2f position(body->GetPosition().x * M2P, body->GetPosition().y * M2P);
        float rotation = body->GetAngle() * 180 / b2_pi;
        circleShape.setPosition(position);
        circleShape.setRotation(rotation);
    }
};

class staticCircle : public Figure{
public:
    staticCircle(b2World &world, sf::Vector2f pos, float radius, sf::Color color = sf::Color::Blue) : Figure(world, pos, color){
        DefBody(world, pos, b2_staticBody);
        Circle(radius, 0.0f, 0.3f, color);
    }

    void Draw(sf::RenderWindow &win) override{
        win.draw(circleShape);
    }

    void Update() override{
        sf::Vector2f position(body->GetPosition().x * M2P, body->GetPosition().y * M2P);
        float rotation = body->GetAngle() * 180 / b2_pi;
        circleShape.setPosition(position);
        circleShape.setRotation(rotation);
    }
};

#endif //RUBE_GOLDBERG_FIGURES_H
