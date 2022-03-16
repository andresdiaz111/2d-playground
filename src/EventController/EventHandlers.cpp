#include "EventHandlers.h"
#include "Engine/EngineCore.h"

EventHandlers *EventHandlers::s_Instance = nullptr;

EventHandlers::EventHandlers()
{
    m_KeyState = SDL_GetKeyboardState(nullptr);
}

void EventHandlers::ListenEvent()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                EngineCore::GetInstance()->Quit();
                break;

            case SDL_KEYDOWN:
                KeyDown();
                break;

            case SDL_KEYUP:
                KeyUp();
                break;
        }
    }
}

bool EventHandlers::GetKeyDown(SDL_Scancode key)
{
    if(m_KeyState[key] == 1)
        return true;

    return false;
}

void EventHandlers::KeyUp()
{
    m_KeyState = SDL_GetKeyboardState(nullptr);
}

void EventHandlers::KeyDown()
{
    m_KeyState = SDL_GetKeyboardState(nullptr);
}
