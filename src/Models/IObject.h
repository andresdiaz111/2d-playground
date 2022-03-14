#ifndef IOBJECT_H
#define IOBJECT_H


class IObject
{
    public:
        virtual void DrawObject() = 0;
        virtual void UpdateObject(float dt) = 0;
        virtual void CleanObject() = 0;

};

#endif // IOBJECT_H
