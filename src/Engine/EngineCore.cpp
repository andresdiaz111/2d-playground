#include "EngineCore.h"
#include "../Textures/TextureController.h"
#include "Transformation.h"

EngineCore *EngineCore::s_Instance = nullptr;

bool EngineCore::Init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        SDL_Log("Fail to init SDL error: %s", SDL_GetError());
        return false;
    }

    m_Window = SDL_CreateWindow("2D-Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(!m_Window)
    {
        SDL_Log("Fail to create window SDL error: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!m_Renderer)
    {
        SDL_Log("Fail to create renderer SDL error: %s", SDL_GetError());
        return false;
    }
    TextureController::GetInstance()->LoadTexture("tree", "assets/tree.png");
    Transformation tf;
    tf.Log();
    return m_IsRunning = true;
}

bool EngineCore::Clean()
{
    TextureController::GetInstance()->CleanTextureController();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void EngineCore::Quit()
{
    m_IsRunning = false;
}

void EngineCore::Update()
{

}

void EngineCore::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 219, 254, 255);
    SDL_RenderClear(m_Renderer);

    TextureController::GetInstance()->DrawTexture("tree", 100, 100, 64, 128);
    SDL_RenderPresent(m_Renderer);
}

void EngineCore::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            Quit();
            break;
    }
}
