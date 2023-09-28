#include <iostream>
#include <Box2d/Box2d.h>

int main(){
    //Creacion de la gravedad como un vector y creacion del mundo
    b2Vec2 gravity(0.0f, -9.81f);
    b2World world(gravity);

    //Caracteristicas de nuestro cuerpo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f); //Configurar su posicion

    b2Body* groundBody = world.CreateBody(&groundBodyDef); //Creacion del cuerpo

    b2PolygonShape groundBox; //Creacion de su forma
    groundBox.SetAsBox(50.0f, 1.0f);

    groundBody ->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody; //Lo cambiamos a dinamico para que se pueda mover
    bodyDef.position.Set(0.0f, 20.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body ->CreateFixture(&fixtureDef);

    float timeStep = 1.0f/60.0f; //Cuanto va a avanzar el mundo

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for(int32 i = 0; i < 60; ++i){
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body ->GetPosition();
        float angle = body ->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
}