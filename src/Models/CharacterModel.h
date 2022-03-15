#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include "Object.h"
#include <string>

class CharacterModel: public Object
{

    public:
        CharacterModel(Properties *prop): Object(prop) {}

        virtual void DrawObject()= 0;
        virtual void UpdateObject(float dt)=0;
        virtual void CleanObject()= 0;

    protected:
        std::string m_Name;
};

#endif // CHARACTERMODEL_H
