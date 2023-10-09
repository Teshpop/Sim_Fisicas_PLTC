#include <iostream>
#include <box2d/box2d.h>

using namespace std;
int main() {
    /*b2Vec2 gravity(0.0f, -9.8f);
    b2World world(gravity);

    b2BodyDef bodyDef;
    bodyDef.position.Set(0.0f, 0.0f);
    b2Body* body = world.CreateBody(&bodyDef);*/

    //Triangulo
    b2FixtureDef fixtureDef;
    b2PolygonShape triangle;
    b2Vec2 vertices[3];
    int32 count = 3;

    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(1.0f, 0.0f);
    vertices[2].Set(0.0f, 1.0f);
    triangle.Set(vertices, count);
    fixtureDef.shape = &triangle;

    //Rectangulo
    b2FixtureDef fixtureDefRec;
    b2PolygonShape Rectangle;
    b2Vec2 verticesRec[4];
    int32 countRec = 4;

    verticesRec[0].Set(0.0f, 0.0f);
    verticesRec[1].Set(1.0f, 0.0f);
    verticesRec[2].Set(1.0f, 3.0f);
    verticesRec[3].Set(0.0f, 3.0f);
    Rectangle.Set(verticesRec, countRec);
    fixtureDefRec.shape = &Rectangle;

    //Cuadrado
    b2FixtureDef fixtureDefSquare;
    b2PolygonShape Square;
    b2Vec2 verticesSquare[4];
    int32 countSqu = 4;

    verticesSquare[0].Set(0.0f, 0.0f);
    verticesSquare[1].Set(1.0f, 0.0f);
    verticesSquare[2].Set(1.0f, 1.0f);
    verticesSquare[3].Set(0.0f, 1.0f);
    Square.Set(verticesSquare, countSqu);
    fixtureDefSquare.shape = &Square;

    //Pentagono
    b2FixtureDef fixtureDefPentagon;
    b2PolygonShape Pentagon;
    b2Vec2 verticesPent[5];
    int32 countPen = 5;

    verticesPent[0].Set(0.0f, 0.0f);
    verticesPent[1].Set(-0.5f, 1.0f);
    verticesPent[2].Set(0.5f, 1.5f);
    verticesPent[3].Set(1.5f, 1.0f);
    verticesPent[4].Set(1.0f, 0.0f);
    Pentagon.Set(verticesPent, countPen);
    fixtureDefPentagon.shape = &Pentagon;

    //Hexagonos
    b2FixtureDef fixtureDefHex;
    b2PolygonShape Hexagon;
    b2Vec2 verticesHexagon[6];
    int32 countHex = 6;

    verticesHexagon[0].Set(0.0f, 0.0f);
    verticesHexagon[1].Set(1.0f,  0.5f);
    verticesHexagon[2].Set(1.0f, 1.5f);
    verticesHexagon[3].Set(0.0f, 2.0f);
    verticesHexagon[4].Set(-1.0f, 1.5f);
    verticesHexagon[5].Set(-1.0f, 0.5f);
    Hexagon.Set(verticesHexagon, countHex);
    fixtureDefHex.shape = &Hexagon;

    //Octagono
    b2FixtureDef fixtureDefOct;
    b2PolygonShape Octagon;
    b2Vec2 verticesOctagon[8];
    int32 countOct = 8;

    verticesOctagon[0].Set(0.0f, 0.0f);
    verticesOctagon[1].Set(1.0f, 0.0f);
    verticesOctagon[2].Set(2.0f, 1.0f);
    verticesOctagon[3].Set(2.0f, 2.0f);
    verticesOctagon[4].Set(1.0f, 3.0f);
    verticesOctagon[5].Set(0.0f, 3.0f);
    verticesOctagon[6].Set(-1.0f, 2.0f);
    verticesOctagon[7].Set(-1.0f, 1.0f);
    Octagon.Set(verticesOctagon, countOct);
    fixtureDefOct.shape = &Octagon;

    return 0;
}
