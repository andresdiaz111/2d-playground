#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
class Vector
{
    public:
        int X,Y;
    public:
        Vector(float x=0, float y=0): X(x), Y(y) {}
    public:
        inline Vector operator+(const Vector &v2) const
        {
            return Vector(X + v2.X, Y + v2.Y);
        }

        inline Vector operator-(const Vector &v2) const
        {
            return Vector(X - v2.X, Y - v2.Y);
        }

        inline Vector operator*(const float sc) const
        {
            return Vector(X*sc, Y*sc);
        }
        void Log(std::string msg = "")
        {
            std::cout << msg << "(X Y) = (" << X << " " << Y << ")"<< std::endl;
        }

};

#endif // VECTOR_H
