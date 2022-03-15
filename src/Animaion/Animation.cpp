#include "Animation.h"
#include "../Textures/TextureController.h"
void Animation::Update()
{
    m_SpriteFrame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
    TextureController::GetInstance()->DrawFrame(m_TextureID, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProperties(std::string textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip)
{
    m_TextureID = textureID;
    m_SpriteRow = spriteRow;
    m_FrameCount = frameCount;
    m_AnimationSpeed = animationSpeed;
    m_Flip = flip;
}
