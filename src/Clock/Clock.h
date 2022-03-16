#ifndef CLOCK_H
#define CLOCK_H

const int LIMIT_FPS = 60;
const float LIMIT_DELTA = 2.0f;

class Clock
{
    public:
        void GetTick();
        inline float GetDeltaTime(){ return m_DeltaTime;}
        static Clock *GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Clock();
        }

    private:
        Clock(){}
        static Clock *s_Instance;
        float m_DeltaTime;
        float m_LastTick;
};

#endif // CLOCK_H
