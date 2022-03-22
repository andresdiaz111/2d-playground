#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include "LayerManager.h"
#include <string>
#include <vector>

struct Tileset{
    int FirstID, LastID;
    int RowCount, ColCount;
    int TileCount, TileSize;
    std::string Name, Source;
};

using TilesetsList = std::vector<Tileset> ;
using TileMap = std::vector<std::vector<int> >;

class TileManager : public LayerManager{

    public:
        TileManager(int tilesize, int width, int height, TileMap tilemap, TilesetsList tilesets);

        virtual void Render();
        virtual void Update();
        inline TileMap GetTileMap(){return m_Tilemap;}

    private:
        int m_TileSize;
        int m_ColCount, m_RowCount;

        TileMap m_Tilemap;
        TilesetsList m_Tilesets;
};

#endif // TILEMANAGER_H
