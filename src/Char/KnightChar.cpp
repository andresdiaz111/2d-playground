#include "KnightChar.h"
#include "../Textures/TextureController.h"
#include "SDL.h"

KnightChar::KnightChar(Properties *prop): CharacterModel(prop)
{
    m_Animation = new Animation();
    m_Animation->SetProperties(m_TextureID, 0, 6, 80, SDL_FLIP_HORIZONTAL);
}

void KnightChar::DrawObject()
{
    m_Animation->Draw(m_Transformation->X, m_Transformation->Y, m_Width, m_Height);
}

void KnightChar::UpdateObject(float dt)
{
    m_Animation->Update();
}

void KnightChar::CleanObject()
{
    TextureController::GetInstance()->CleanTextureController();
}
