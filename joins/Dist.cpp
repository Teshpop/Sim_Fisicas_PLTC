//
// Created by Tello on 27/10/2023.
//

#include "ref.h"

void Dist(){
    sf::RenderWindow window;
    window.create(sf::VideoMode(1270, 720), "Join/Distance");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    //Limites Temp
    Cube wallTop(world, 1270.0f, 0.1f, 635.0f, 1.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);
    Cube wall2(world, 1270.0f, 0.1f, 635.0f, 715.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);
    Cube wall3(world, 0.1f, 720.0f, 1.0f, 360.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);
    Cube wall4(world, 0.1f, 720.0f, 1270.0f, 360.0f, 0.0, 0.0, b2_staticBody, sf::Color::Transparent);

    //Figuras
    Cube box_A(world, 20.0f, 20.0f, 635.0f, 300.0f, 1.0f, 1.0f, b2_dynamicBody, sf::Color::Red);
    Cube box_B(world, 20.0f, 20.0f, 635.0f, 400.0f, 1.0f, 1.0f, b2_dynamicBody, sf::Color::Yellow);

    b2DistanceJointDef jointDef;
    //Obtenemos los cuerpos y ponemos los ganchos en cada uno
    jointDef.Initialize(box_A.getBody(), box_B.getBody(), box_A.getBody()->GetWorldCenter(), box_B.getBody()->GetWorldCenter());
    float frequencyHz = 30.0f; //Se utiliza la mitad de lo que vale timeStep
    float dampingRatio = 0.0f;
    b2LinearStiffness(jointDef.stiffness, jointDef.damping, frequencyHz, dampingRatio, jointDef.bodyA, jointDef.bodyB);

    world.CreateJoint(&jointDef);

    while(window.isOpen()){
        sf::Event even;
        while(window.pollEvent(even)){
            if(even.type == sf::Event::Closed) window.close();
        }
        box_A.MoveTo(b2Vec2(0.0f, -0.05f), sf::Keyboard::W);
        box_A.MoveTo(b2Vec2(0.0f, 0.05f), sf::Keyboard::S);
        box_A.MoveTo(b2Vec2(0.05f, 0.0f), sf::Keyboard::D);
        box_A.MoveTo(b2Vec2(-0.05f, 0.0f), sf::Keyboard::A);


        world.Step(1/60.0f, 8, 3);

        window.clear(sf::Color::Black);

        box_A.Update();
        box_A.Draw(window);
        box_B.Update();
        box_B.Draw(window);

        window.display();
    }
}