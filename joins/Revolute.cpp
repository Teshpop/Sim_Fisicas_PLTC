//
// Created by Tello on 27/10/2023.
//

#include "ref.h"

void Revolute(){
    sf::RenderWindow window;
    window.create(sf::VideoMode(1270, 720), "Join/Revolute");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    //Figuras
    Cube box_dynamic(world, 30.0f, 30.0f, 700.0f, 360.0f, 0.3f, 1.0f, b2_dynamicBody, sf::Color::Red);
    Cube box_Static(world, 30.0f, 30.0f, 635.0f, 360.0f, 0.0f, 0.0f, b2_staticBody, sf::Color::Yellow);

    b2RevoluteJointDef jointDef;
    jointDef.Initialize(box_Static.getBody(), box_dynamic.getBody(), box_Static.getBody()->GetWorldCenter());
    jointDef.enableLimit = false;
    jointDef.lowerAngle = -0.25f * b2_pi;
    jointDef.upperAngle = 0.25 * b2_pi;
    jointDef.maxMotorTorque = 0.0f;
    jointDef.motorSpeed = 0.0f;
    jointDef.enableMotor = true;

    world.CreateJoint(&jointDef);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }

        box_dynamic.MoveTo(b2Vec2(0.0f, -0.2f), sf::Keyboard::W);
        box_dynamic.MoveTo(b2Vec2(0.0f, 0.2f), sf::Keyboard::S);
        box_dynamic.MoveTo(b2Vec2(0.2f, 0.0f), sf::Keyboard::D);
        box_dynamic.MoveTo(b2Vec2(-0.2f, 0.0f), sf::Keyboard::A);

        world.Step(1.0f/60.0f, 8, 3);
        window.clear(sf::Color::Black);

        box_dynamic.Update();
        box_dynamic.Draw(window);
        box_Static.Update();
        box_Static.Draw(window);

        window.display();
    }
}