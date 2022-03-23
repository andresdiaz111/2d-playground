#include "EngineCore.h"
#include "../Textures/TextureController.h"
#include "Transformation.h"
#include "KnightChar.h"
#include "EventHandlers.h"
#include "Clock.h"
#include "MapParser.h"
#include "View.h"
#include <iostream>

KnightChar *player = nullptr;

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

    if(!MapParser::GetInstance()->LoadMapParser())
    {
        std::cout <<"Fail to load map" << std::endl;
    }

    m_map = MapParser::GetInstance()->GetMap("map");

    TextureController::GetInstance()->LoadTexture("Knight", "assets/knight2idle.png");
    TextureController::GetInstance()->LoadTexture("Knight_run", "assets/knight2run.png");
    TextureController::GetInstance()->LoadTexture("Knight_noat", "assets/knight2na.png");
    TextureController::GetInstance()->LoadTexture("Knight_cat", "assets/knightcombo.png");
    TextureController::GetInstance()->LoadTexture("Knight_crou", "assets/knightcrou.png");
    TextureController::GetInstance()->LoadTexture("Knight_crouat", "assets/knigthcrouattack.png");
    player = new KnightChar(new Properties("Knight", 10, 485, 120, 100));
    View::GetInstance()->SetTarget(player->GetTarget());
    return m_IsRunning = true;
}

bool EngineCore::Clean()
{
    TextureController::GetInstance()->CleanTextureController();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
    return true;
}

void EngineCore::Quit()
{
    m_IsRunning = false;
}

void EngineCore::Update()
{
    float dt = Clock::GetInstance()->GetDeltaTime();
    m_map->Update();
    player->UpdateObject(dt);
    View::GetInstance()->UpdateView(dt);
}

void EngineCore::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_Renderer);

    m_map->Render();
    player->DrawObject();
    SDL_RenderPresent(m_Renderer);
}

void EngineCore::Events()
{
    EventHandlers::GetInstance()->ListenEvent();
}
