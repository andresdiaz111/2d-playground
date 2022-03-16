#include "Engine/EngineCore.h"
#include "RigidBody.h"
#include "Clock.h"
int main(int argc, char **argv)
{
    EngineCore::GetInstance()->Init();

    while(EngineCore::GetInstance()->IsRunning()){
        EngineCore::GetInstance()->Events();
        EngineCore::GetInstance()->Update();
        EngineCore::GetInstance()->Render();
        Clock::GetInstance()->GetTick();

    }

    EngineCore::GetInstance()->Clean();
    return 0;
}
