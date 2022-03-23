#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H

#include "SDL.h"
#include "TileManager.h"

class CollisionController
{
    public:
        inline static CollisionController *GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new CollisionController();
        }

        bool CollisionMap(SDL_Rect mp);
        bool CheckCol(SDL_Rect mp, SDL_Rect mb);
    private:
        CollisionController();
        static CollisionController *s_Instance;
        TileManager *m_ColLayer;
        TileMap m_ColMap;

};

#endif // COLLISIONCONTROLLER_H
