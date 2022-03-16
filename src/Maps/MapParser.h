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
        void CleanMapParsers();

        inline Map *GetMaps();
        inline static MapParser *GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser();
        }

    private:
        bool Parse(std::string id,  std::string path);
        TileSet ParseTileList(TiXmlElement *xmlTileSet);
        TileManager *ParseTileLayer(TiXmlElement *xmlLayer);
    private:
        MapParser();
        static MapParser *s_Instance;
        std::map<std::string, Map*> m_Maps;
};

#endif // MAPPARSER_H
