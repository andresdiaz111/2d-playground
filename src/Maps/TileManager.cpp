#include "TileManager.h"
#include "Textures/TextureController.h"

TileManager::TileManager(int tileSize, int rowCount, int colCount, tileMap tilemap, tileList tileSet) :
m_TileSet (tileSize)
{
    m_NRows = rowCount;
    m_ColCount = colCount;
    m_TileMap = tilemap;
    m_TileSet = tileSet;

    for(unsigned int i = 0 ; i < m_TileSet.size(); i++)
    {
        TextureController::GetInstance()->LoadTexture(m_TileSet[i].name, "assets/mapas/" + m_TileSet[i].source);
    }
}

void TileManager::RenderLayer()
{
    for(unsigned int i = 0; i < m_NRows; i++)
    {
        for(unsigned int j = 0; j < m_ColCount; j++)
        {
            int tileID = m_TileMap[i][j];

            if(tileID == 0)
                continue;
            else
            {
                int index;
                if(m_TileSet.size() > 1)
                {
                    for(unsigned int k = 1; k < m_TileSet.size(); k++)
                    {
                        if(tileID > m_TileSet[k].firstID && tileID < m_TileSet[k].lastID)
                        {
                            tileID = tileID + m_TileSet[k].nTile - m_TileSet[k].lastID;
                            index = k;
                            break;
                        }
                    }
                }

                TileSet tilesets = m_TileSet[index];
                int tilerow = tileID / tilesets.colCount;
                int tilecol = tileID - tilerow * tilesets.colCount - 1;

                if(tileID % tilesets.colCount == 0)
                {
                    tilerow--;
                    tilecol = tilesets.colCount - 1;
                }

                TextureController::GetInstance()->DrawTile(tilesets.name, tilesets.tileSize, j * tilesets.tileSize,  i * tilesets.tileSize, tilerow, tilecol);
            }
        }
    }
}

void TileManager::UpdateLayer()
{

}
