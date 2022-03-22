#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <string>
#include "Map.h"
#include "TileManager.h"
#include "tinyxml.h"
class MapParser
{
   public:
        bool LoadMapParser();
        void CleanMapParser();

        inline Map* GetMap(std::string id){return m_MapDict[id];}
        inline static MapParser* GetInstance(){ return s_Instance = (s_Instance != nullptr)? s_Instance : new MapParser();}

    private:
        MapParser(){}

        bool Parse(std::string id, std::string source);
        Tileset ParseTileset(TiXmlElement* xmlTileset);
        TileManager* ParseTileLayer(TiXmlElement* xmlLayer, std::vector<Tileset> tilesets, int tilesize, int rowcount, int colcount);

        static MapParser* s_Instance;
        std::map<std::string, Map*> m_MapDict;
};

#endif // MAPPARSER_H
