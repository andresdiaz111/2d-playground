#include "EngineCore.h"

int main(int argc, char **argv)
{
    EngineCore::GetInstance()->Init();

    while(EngineCore::GetInstance()->IsRunning()){
        EngineCore::GetInstance()->Events();
        EngineCore::GetInstance()->Update();
        EngineCore::GetInstance()->Render();
    }

    EngineCore::GetInstance()->Clean();
    return 0;
}
