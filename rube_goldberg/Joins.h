//
// Created by Tello on 06/11/2023.
//

#ifndef RUBE_GOLDBERG_JOINS_H
#define RUBE_GOLDBERG_JOINS_H

class Distance{
public:
    Distance(b2World &world, b2Body* &body1, b2Body* &body2){
        jointDef.Initialize(body1, body2, body1->GetWorldCenter(), body2->GetWorldCenter());
        float frequency = 30.0f;
        float dampingRatio = 0.0f;
        b2LinearStiffness(jointDef.stiffness, jointDef.damping, frequency, dampingRatio, jointDef.bodyA, jointDef.bodyB);

        world.CreateJoint(&jointDef);
    }
private:
    b2DistanceJointDef jointDef;
};

class Revolute{
public:
    /// \brief pivotBody = cuerpo estatico, body = cuerpo dinamico.
    Revolute(b2World &world,b2Body* &pivotBody, b2Body* &body){
        jointDef.Initialize(pivotBody, body, pivotBody->GetPosition());
        jointDef.enableLimit = false;
        jointDef.lowerAngle = -0.25f * b2_pi;
        jointDef.upperAngle = 0.25 * b2_pi;
        jointDef.enableMotor = true;
        jointDef.motorSpeed = 1.0f;
        jointDef.maxMotorTorque = 10.0f;

        world.CreateJoint(&jointDef);
    }

    b2RevoluteJoint* GetJoint(){
        return joint;
    }

private:
    b2RevoluteJointDef jointDef;
    b2RevoluteJoint* joint;
};

class Gear {
public:
    Gear(b2World &world, b2RevoluteJoint* jointA, b2RevoluteJoint* jointB, b2Body* bodyA, b2Body* bodyB) {
        jointDef.joint1 = jointA;
        jointDef.joint2 = jointB;
        jointDef.bodyA = bodyA;
        jointDef.bodyB = bodyB;
        jointDef.ratio = 1.0f;

        world.CreateJoint(&jointDef);
    }
private:
    b2GearJointDef jointDef;
};

#endif //RUBE_GOLDBERG_JOINS_H
