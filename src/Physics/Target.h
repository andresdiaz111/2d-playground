#ifndef TARGET_H
#define TARGET_H


class Target
{
    public:
        float X, Y;

    public:
        Target(float X = 0, float Y = 0) : X(X), Y(Y){}


        inline Target operator+(const Target &t2) const
        {
            return Target(X + t2.X, Y + t2.Y);
        }

        inline friend Target operator+=(Target &t1, const Target &t2)
        {
            t1.X += t2.X;
            t1.Y += t2.Y;
            return t1;
        }

        inline Target operator-(const Target &t2) const
        {
            return Target(X - t2.X, Y - t2.Y);
        }

        inline friend Target operator-=(Target &t1, const Target &t2)
        {
            t1.X -= t2.X;
            t1.Y -= t2.Y;
            return t1;
        }

        inline Target operator*(const float sc)const
        {
            return Target(X * sc, Y * sc);
        }

        void Log(std::string msg = "")
        {
            std::cout << msg << "(X Y) = (" << X << " " << Y << ")"<< std::endl;
        }

};

#endif // TARGET_H
