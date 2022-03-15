#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Vector.h"
class Transformation
{
    public:
        float X, Y;
    public:
        Transformation(float x=0, float y=0): X(x), Y(y) {}
        void Log(std::string msg = "")
        {
            std::cout << msg << "(X Y) = (" << X << " " << Y << ")"<< std::endl;
        }

    public:
        inline void TranslateX(float x)
        {
            X += x;
        }
        inline void TranslateY(float y)
        {
            Y += y;
        }
        inline void Translate(Vector v)
        {
            X += v.X;
            Y += v.Y;
        }
};

#endif // TRANSFORMATION_H
