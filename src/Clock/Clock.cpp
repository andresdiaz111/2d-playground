#include "Clock.h"
#include "SDL.h"

Clock *Clock::s_Instance = nullptr;

void Clock::GetTick()
{
    m_DeltaTime = (SDL_GetTicks() - m_LastTick) * (LIMIT_FPS / 1000.0f);

    if (m_DeltaTime > LIMIT_DELTA)
        m_DeltaTime = LIMIT_DELTA;

    m_LastTick = SDL_GetTicks();
}
