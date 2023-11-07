//
// Created by Tello on 28/10/2023.
//

#include "ref.h"

void Pris(){
    sf::RenderWindow window;
    window.create(sf::VideoMode(1270, 720), "Join/Prismatic");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    Cube wallTop(world, 1270.0f, 0.1f, 635.0f, 1.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);
    Cube wall2(world, 1270.0f, 0.1f, 635.0f, 715.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);
    Cube wall3(world, 0.1f, 720.0f, 1.0f, 360.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);
    Cube wall4(world, 0.1f, 720.0f, 1270.0f, 360.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);

    Cube box_A(world, 35.0f, 35.0f, 635.0f, 360.0f, 1.0f, 1.0f, b2_dynamicBody, sf::Color::Red);
    Cube box_B(world, 35.0f, 35.0f, 635.0f, 300.0f, 1.0f, 1.0f, b2_dynamicBody, sf::Color::Yellow);

    b2PrismaticJointDef jointDef;
    b2Vec2 worldAxis( 0.0f, 100.0f);
    jointDef.Initialize(box_B.getBody(), box_A.getBody(), box_B.getBody()->GetPosition(), worldAxis);
    jointDef.lowerTranslation = -5.0f;
    jointDef.upperTranslation = 2.5f;
    jointDef.enableLimit = true;
    jointDef.maxMotorForce = 1.0f;
    jointDef.motorSpeed = 0.0f;
    jointDef.enableMotor = true;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }

        box_B.MoveTo(b2Vec2(0.0f, -0.05f), sf::Keyboard::W);
        box_B.MoveTo(b2Vec2(0.0f, 0.05f), sf::Keyboard::S);
        box_B.MoveTo(b2Vec2(0.05f, 0.0f), sf::Keyboard::D);
        box_B.MoveTo(b2Vec2(-0.05f, 0.0f), sf::Keyboard::A);

        world.Step(1.0f/60.0f, 8, 3);

        window.clear(sf::Color::Black);

        box_A.Update();
        box_A.Draw(window);
        box_B.Update();
        box_B.Draw(window);

        window.display();
    }
}
