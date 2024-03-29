#ifndef OBJECT_H
#define OBJECT_H

#include "IObject.h"
#include "Transformation.h"
#include "SDL.h"
#include "Target.h"

struct Properties{

    public:
        Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
        {
            X = x;
            Y = y;
            Flip = flip;
            Width = width;
            Height = height;
            TextureID = textureID;
        }
    public:
        std::string TextureID;
        int Width, Height;
        float X, Y;
        SDL_RendererFlip Flip;

};

class Object : public IObject
{
    public:
        Object(Properties* props):  m_TextureID(props->TextureID),
        m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip) {
            m_Transformation = new Transformation(props->X, props->Y);

            float tx = props->X + props->Width / 2;
            float ty = props->Y + props->Height / 2;
            m_Target = new Target(tx, ty);
        }

        virtual void DrawObject() = 0;
        virtual void UpdateObject(float dt) = 0;
        virtual void CleanObject() = 0;
        inline Target *GetTarget()
        {
            return m_Target;
        }
    protected:
        Target *m_Target;
        Transformation *m_Transformation;
        int m_Width , m_Height;
        std::string m_TextureID;
        SDL_RendererFlip m_Flip;

};
#endif // OBJECT_H
