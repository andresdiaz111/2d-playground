#ifndef ENGINECORE_H
#define ENGINECORE_H

#include "SDL.h"
#include "SDL_image.h"
#include "Map.h"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640

class EngineCore
{
    public:
        static EngineCore* GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new EngineCore();
        }

        bool Init();
        bool Clean();
        void Quit();

        void Update();
        void Render();
        void Events();

        inline bool IsRunning()
        {
            return m_IsRunning;
        }

        inline SDL_Renderer *GetRenderer()
        {
            return m_Renderer;
        }

        inline Map *GetMap()
        {
            return m_map;
        }

    private:
        EngineCore(){}
        bool m_IsRunning;

        Map *m_map;
        SDL_Window *m_Window;
        SDL_Renderer *m_Renderer;
        static EngineCore *s_Instance;
};

#endif // ENGINECORE_H
