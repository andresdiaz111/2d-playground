#include "CollisionController.h"
#include "Engine/EngineCore.h"

CollisionController::CollisionController()
{
    m_ColLayer = (TileManager*)EngineCore::GetInstance()->GetMap()->GetLayers().front();
    m_ColMap = m_ColLayer->GetTileMap();
}
bool CollisionController::CollisionMap(SDL_Rect mp)
{
    int tileSize = 32;
    int RowCount = 25;
    int ColCount = 60;

    int left_tile = mp.x/tileSize;
    int right_tile = (mp.x + mp.w)/tileSize;

    int top_tile = mp.y/tileSize;
    int bottom_tile = (mp.y + mp.h)/tileSize;

    if(left_tile < 0) left_tile = 0;
    if(right_tile > ColCount) right_tile = ColCount;

    if(top_tile < 0) top_tile = 0;
    if(bottom_tile > RowCount) bottom_tile = RowCount;

    for(int i = left_tile; i <= right_tile; ++i){
        for(int j = top_tile; j <= bottom_tile; ++j){
            if(m_ColMap[j][i] > 0){
                return true;
            }
        }
    }

    return false;
}

bool CollisionController::CheckCol(SDL_Rect mp, SDL_Rect mb)
{
    bool xcol = (mp.x < mb.x + mb.w) && (mp.x + mp.w > mb.x);
    bool ycol = (mp.y < mb.y + mb.h) && (mp.y + mp.h > mb.y);
    return (xcol && ycol);
}

