#include "TileManager.h"

TileManager::TileManager(int tileSize, int rowCount, int colCount, tileMap tilemap, tileList tileSet)
{
    m_TileSize = tileSize;
    m_NRows = rowCount;
    m_ColCount = colCount;
    m_TileMap = tilemap;
    m_TileSet = tileSet;
}

void TileManager::RenderLayer()
{

}

void TileManager::UpdateLayer()
{

}
