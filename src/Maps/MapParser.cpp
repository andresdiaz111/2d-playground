#include "MapParser.h"
#include  <iostream>
#include <string>
#include <bits/stdc++.h>

MapParser *MapParser::s_Instance = nullptr;

bool MapParser::LoadMapParser()
{
    if(!Parse("map", "assets/mapas/basicmap.tmx"))
        return false;
    return true;
}

void MapParser::CleanMapParsers()
{
    std::map<std::string, Map*>::iterator it;
    for(it = m_Maps.begin(); it != m_Maps.end(); it++)
    {
        it->second = nullptr;
    }

    m_Maps.clear();
}

bool MapParser::Parse(std::string id, std::string path)
{
    TiXmlDocument xml;
    xml.LoadFile(path);
    TiXmlElement *root = xml.RootElement();
    int col, row, sizetile = 0;

    if(xml.Error())
    {
        std::cerr << "Failed to load" << std::endl;
        return false;
    }

    root->Attribute("height", &row);
    root->Attribute("width", &col);
    root->Attribute("tilewidth", &sizetile);

    tileList tilesets;
    for(TiXmlElement *i = root->FirstChildElement(); i != nullptr ; i = i->NextSiblingElement())
    {
        if(i->Value() == std::string("tileset"))
        {
            tilesets.push_back(ParseTileList(i));
        }
    }

    Map *map = new Map();
    for(TiXmlElement *i = root->FirstChildElement(); i != nullptr ; i = i->NextSiblingElement())
    {
        if(i->Value() == std::string("layer"))
        {
            TileManager *tilemanager = ParseTileLayer(i, tilesets, sizetile, row, col);
            map->m_MapLayers.push_back(tilemanager);
        }
    }

    m_Maps[id] = map;
    return true;
}

TileSet MapParser::ParseTileList(TiXmlElement* xmlTileSet)
{
    TileSet tileset;
    tileset.name = xmlTileSet->Attribute("name");
    xmlTileSet->Attribute("firstgid", &tileset.firstID);
    xmlTileSet->Attribute("tilecount", &tileset.nTile);
    tileset.lastID = (tileset.firstID + tileset.nTile) - 1;
    xmlTileSet->Attribute("columns", &tileset.colCount);
    tileset.rowsCount = tileset.nTile / tileset.colCount;
    xmlTileSet->Attribute("tilewidth", &tileset.tileSize);

    TiXmlElement *image = xmlTileSet->FirstChildElement();
    tileset.source = image->Attribute("source");
    return tileset;
}

TileManager* MapParser::ParseTileLayer(TiXmlElement *xmlLayer, tileList tileset, int tilesize, int rowcount, int colcount)
{
    TiXmlElement *field;

    for(TiXmlElement *i = xmlLayer->FirstChildElement() ; i != nullptr ; i = i->NextSiblingElement())
    {
        if(i->Value() == std::string("data"))
        {
            field = i;
            break;
        }
    }

    std::string id;
    std::string tileMatrix(field->GetText());
    std::istringstream streams(tileMatrix);

    tileMap tilemap(rowcount, std::vector<int>(colcount, 0));

    for(int j = 0; j < rowcount; j++)
    {
        for(int k = 0; k < colcount; k++)
        {
            getline(streams, id, ',');
            std::stringstream con(id);
            con >> tilemap[j][k];

            if(!streams.good())
                break;
        }
    }

    return (new TileManager(tilesize, rowcount, colcount, tilemap, tileset));
}


