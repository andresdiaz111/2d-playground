#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include "LayerManager.h"
#include <string>
#include <vector>

struct TileSet
{
    int firstID, lastID;
    int rowsCount, colCount;
    int nTile, tileSize;
    std::string name, source;
};

using tileList = std::vector<TileSet>;
using tileMap = std::vector<std::vector<int>>;

class TileManager : public LayerManager
{
    public:
        TileManager(int tileSize, int rowCount, int colCount, tileMap tilemap, tileList tileSet);
        virtual void RenderLayer();
        virtual void UpdateLayer();
        inline tileMap GetTileMap() { return m_TileMap;}
    private:
        int m_TileSize;
        int m_NRows, m_ColCount;
        tileMap m_TileMap;
        tileList m_TileSet;
};

#endif // TILEMANAGER_H
