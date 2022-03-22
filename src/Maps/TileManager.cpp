#include "TileManager.h"
#include "Textures/TextureController.h"

TileManager::TileManager(int tilesize, int colcount, int rowcount, TileMap tilemap, TilesetsList tilesets):
m_TileSize(tilesize)
{
    m_RowCount = rowcount;
    m_ColCount = colcount;
    m_Tilemap = tilemap;
    m_Tilesets = tilesets;

    for(unsigned int i=0; i < m_Tilesets.size(); i++)
        TextureController::GetInstance()->LoadTexture(m_Tilesets[i].Name, "assets/mapas/" + m_Tilesets[i].Source);
}

void TileManager::Render(){
    for(unsigned int i = 0; i < m_RowCount; i++){
        for(unsigned int j = 0; j < m_ColCount; j++){

            int tileID = m_Tilemap[i][j];
            int temp = tileID;

            if(tileID == 0)
                continue;

            else{
                int index = 0;
                if(m_Tilesets.size() > 1){
                    for(unsigned int k = 1; k < m_Tilesets.size(); k++){
                        if(tileID > m_Tilesets[k].FirstID && tileID < m_Tilesets[k].LastID){
                            tileID = tileID + m_Tilesets[k].TileCount - m_Tilesets[k].LastID;
                            index = k;
                            break;
                        }
                    }
                }

                Tileset ts = m_Tilesets[index];
                int tileRow = tileID/ts.ColCount;
                int tileCol = tileID - tileRow*ts.ColCount-1;

                // if this tile is on the las column
                if(tileID % ts.ColCount == 0){
                    tileRow--;
                    tileCol = ts.ColCount - 1;
                }

                TextureController::GetInstance()->DrawTile(ts.Name, ts.TileSize, j * ts.TileSize, i * ts.TileSize, tileRow, tileCol);
            }
        }
    }
}

void TileManager::Update(){

}

