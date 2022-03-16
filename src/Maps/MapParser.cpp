#include "MapParser.h"

bool MapParser::LoadMapParser()
{
    if(!Parse("level1", "assets/mapas/basicmap.tmx"))
        return false;
    return true;
}

void MapParser::CleanMapParsers()
{

}

Map* MapParser::GetMaps()
{

}

bool MapParser::Parse(std::string id, std::string path)
{

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

TileManager* MapParser::ParseTileLayer(TiXmlElement* xmlLayer)
{

}



MapParser::MapParser()
{
    //ctor
}

