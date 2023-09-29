#include <iostream>
#include <cmath>
#include <box2d/box2d.h>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(){
    //Definimos la gravedad
    b2Vec2 gravity(0.0f, -1.62f);
    b2World world(gravity);

    //Creando el cuerpo dinamico para la bala
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    //Definir una forma para la bala
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.2f, 0.05f);

    //Definir Las propiedades de la bala
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body ->CreateFixture(&fixtureDef);

    //Valores iniciales de la bala
    float angle = 45.0f;
    float speed = 854.0f;
    float vx = speed * cos(angle * M_PI / 180.0f);
    float vy = speed * sin(angle * M_PI / 180.0f);

    body ->SetLinearVelocity(b2Vec2(vx, vy));

    //Simulacion del mundo
    float timeStep = 1.0f / 60.0f;
    int velocityIterations = 6;
    int positionIterations = 2;

    for(int i = 0; i < 60; ++i){
        world.Step(timeStep, velocityIterations, positionIterations);
        cout << body ->GetPosition().x << " " << body->GetPosition().y << endl;
    }

    world.DestroyBody(body);

    return 0;
}