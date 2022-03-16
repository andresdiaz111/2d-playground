#include "KnightChar.h"
#include "../Textures/TextureController.h"
#include "SDL.h"
#include "EventHandlers.h"
KnightChar::KnightChar(Properties *prop): CharacterModel(prop)
{
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProperties(m_TextureID, 0, 10, 80);
}

void KnightChar::DrawObject()
{
    m_Animation->Draw(m_Transformation->X, m_Transformation->Y, m_Width, m_Height);
}

void KnightChar::UpdateObject(float dt)
{
    m_Animation->SetProperties("Knight", 0, 10, 80);
    m_RigidBody->CleanForce();
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
    {
        m_RigidBody->AppForceX(5 * LEFT);
        m_Animation->SetProperties("Knight_run", 0, 10, 80, SDL_FLIP_HORIZONTAL);
    }
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
    {
        m_RigidBody->AppForceX(5 * RIGHT);
        m_Animation->SetProperties("Knight_run", 0, 10, 80);
    }
    m_RigidBody->Update(0.5);
    m_Transformation->TranslateX(m_RigidBody->GetPosition().X);
    //m_Transformation->TranslateY(m_RigidBody->GetPosition().Y);
    m_Animation->Update();
}

void KnightChar::CleanObject()
{
    TextureController::GetInstance()->CleanTextureController();
}
