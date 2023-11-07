#include "ref.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1270, 720), "Prueba");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    dynamicCube box(world,sf::Vector2f(635.0f, 360.0f), sf::Vector2f(30.0f, 30.0f));
    dynamicCube box2(world, sf::Vector2f(550.0f, 360.0f), sf::Vector2f(30.0f, 30.0f));
    staticCube box3(world, sf::Vector2f(700.0f, 360.0f), sf::Vector2f(30.0f, 30.0f), sf::Color::Yellow);

    b2Body* bodyA = box.GetBody();
    b2Body* bodyB = box2.GetBody();
    b2Body* bodyC = box3.GetBody();

    Revolute joint1(world, bodyC, bodyA);
    Revolute joint2(world, bodyC, bodyB);

    b2RevoluteJoint* jointA = joint1.GetJoint();
    b2RevoluteJoint* jointB = joint2.GetJoint();

    Gear(world, jointA, jointB, bodyA, bodyB);

    //Distance(world, body1, body2);
    //Revolute(world, pivotBody, body);
    //body->ApplyLinearImpulse(b2Vec2(1.0f, 0.0f), body->GetWorldCenter(), true);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color::Black);

        world.Step(1.0f / 60.0f, 8, 3);

        //Draw
        box.Draw(window);
        box2.Draw(window);
        box3.Draw(window);

        //Update
        box.Update();
        box2.Update();
        box3.Update();

        window.display();
    }

    return 0;
}