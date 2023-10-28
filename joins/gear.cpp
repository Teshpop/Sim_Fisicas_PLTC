//
// Created by Tello on 27/10/2023.
//

#include "ref.h"

void Gear(){
    sf::RenderWindow window;
    window.create(sf::VideoMode(1270,  720), "Join/Gear");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    //Creacion de las cajas
    Cube box_A(world, 50.0f, 50.0f, 600.0f, 360.0f, 1.0f, 1.0f, b2_dynamicBody, sf::Color::Red);
    Cube box_B(world, 50.0f, 50.0f, 600.0f, 430.0f, 1.0f, 1.0f, b2_dynamicBody, sf::Color::Yellow);
    Cube box_Static(world, 40.0f, 300.0f, 700.0f, 360.0f, 0.0f, 0.0f, b2_staticBody, sf::Color::Blue);

    b2RevoluteJointDef jointDefA;
    jointDefA.Initialize(box_Static.getBody(), box_A.getBody(), box_A.getBody()->GetPosition());
    b2RevoluteJoint* JoinA = (b2RevoluteJoint*)world.CreateJoint(&jointDefA);

    b2RevoluteJointDef jointDefB;
    jointDefB.Initialize(box_Static.getBody(), box_B.getBody(), box_B.getBody()->GetPosition());
    b2RevoluteJoint* JoinB = (b2RevoluteJoint*)world.CreateJoint(&jointDefB);

    b2GearJointDef gearJointDef;
    gearJointDef.joint1 = JoinA;
    gearJointDef.joint2 = JoinB;
    gearJointDef.ratio = JoinB->GetJointAngle() / JoinA->GetJointAngle();
    world.CreateJoint(&gearJointDef);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }
        world.Step(1.0f / 60.0f, 8, 3);
        window.clear(sf::Color::Black);

        box_A.Draw(window);
        box_A.Update();
        box_Static.Draw(window);
        box_Static.Update();
        box_B.Draw(window);
        box_B.Update();

        window.display();
    }
}