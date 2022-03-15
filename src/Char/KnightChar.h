#ifndef KNIGHTCHAR_H
#define KNIGHTCHAR_H

#include "Animation.h"
#include "CharacterModel.h"

class KnightChar: public CharacterModel
{
    public:
        KnightChar(Properties *prop);

        virtual void DrawObject();
        virtual void UpdateObject(float dt);
        virtual void CleanObject();

    private:
        //int m_Row, m_Frame, m_FrameCount;
        //int m_AnimationSpeed;

        Animation *m_Animation;
};

#endif // KNIGHTCHAR_H
