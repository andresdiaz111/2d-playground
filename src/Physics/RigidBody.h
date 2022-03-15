#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector.h"


#define UNIT_MASS 1.0f
#define GRAVITY 9.8f
class RigidBody
{
    public:
        RigidBody()
        {
            m_Mass = UNIT_MASS;
            m_Gravity = GRAVITY;
        }

        inline void SetMass(float mass){ m_Mass = mass;}
        inline void SetGravity(float gravity) {m_Gravity = gravity;}

        inline float GetMass(){return m_Mass;}
        inline Vector GetPosition(){return m_Position;}
        inline Vector GetVelocity() {return m_Velocity;}
        inline Vector GetAcceleration() {return m_Acceleration;}

        inline void AppForce(Vector F) {m_Force = F;}
        inline void AppForceX(float Fx) {m_Force.X = Fx;}
        inline void AppForceY(float Fy) {m_Force.Y = Fy;}
        inline void CleanForce(){m_Force = Vector(0, 0);}

        inline void AppFriction(Vector Fr) {m_Friction = Fr;}
        inline void CleanFriction() {m_Friction = Vector(0, 0);}

        void Update(float dt)
        {
            m_Acceleration.X = (m_Force.X + m_Friction.X) / m_Mass;
            m_Acceleration.Y = m_Gravity + m_Force.Y / m_Mass;
            m_Velocity = m_Acceleration * dt;
            m_Position = m_Velocity * dt;
        }

    private:
        float m_Mass;
        float m_Gravity;

        Vector m_Force;
        Vector m_Friction;

        Vector m_Position;
        Vector m_Velocity;
        Vector m_Acceleration;
};

#endif // RIGIDBODY_H
