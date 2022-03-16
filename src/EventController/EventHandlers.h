#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

#include "SDL.h"

class EventHandlers
{

    public:
        static EventHandlers *GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new EventHandlers();
        }

        void ListenEvent();
        bool GetKeyDown(SDL_Scancode key);
    private:
        EventHandlers();
        void KeyUp();
        void KeyDown();
        const Uint8 *m_KeyState;
        static EventHandlers *s_Instance;
};

#endif // EVENTHANDLERS_H
