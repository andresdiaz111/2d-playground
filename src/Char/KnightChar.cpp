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
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_A) && !EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
    {
        m_RigidBody->AppForceX(10 * LEFT);
        m_Animation->SetProperties("Knight_run", 0, 10, 50, SDL_FLIP_HORIZONTAL);
    }
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_D) && !EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
    {
        m_RigidBody->AppForceX(10 * RIGHT);
        m_Animation->SetProperties("Knight_run", 0, 10, 50);
    }
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
    {
        m_Animation->SetProperties("Knight_noat", 0, 6, 80);
    }
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE) && EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
    {
        m_Animation->SetProperties("Knight_noat", 0, 6, 80, SDL_FLIP_HORIZONTAL);
    }
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_E) && !EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
    {
        m_RigidBody->AppForceX(2 * RIGHT);
        m_Animation->SetProperties("Knight_cat", 0, 10, 50);
    }
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_LSHIFT) && !EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
    {
        m_Animation->SetProperties("Knight_crou", 0, 3, 300);
    }
    if(EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_LSHIFT) && EventHandlers::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE))
    {
        m_Animation->SetProperties("Knight_crouat", 0, 3, 80);
    }
    m_RigidBody->Update(0.5);
    m_Transformation->TranslateX(m_RigidBody->GetPosition().X);
    //m_Transformation->TranslateY(m_RigidBody->GetPosition().Y);

    m_Target->X = m_Transformation->X + m_Width / 2;
    m_Target->Y = m_Transformation->Y + m_Height / 2;
    m_Animation->Update();
}

void KnightChar::CleanObject()
{
    TextureController::GetInstance()->CleanTextureController();
}
