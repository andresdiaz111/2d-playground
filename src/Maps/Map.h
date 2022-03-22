#ifndef MAP_H
#define MAP_H

#include <vector>
#include "LayerManager.h"

class Map
{
    public:
        Map(){}

        void Render(){
            for(unsigned int i = 0; i < m_MapLayers.size(); i++)
                m_MapLayers[i]->Render();
        }

        void Update(){
            for(unsigned int i=0; i < m_MapLayers.size(); i++)
                m_MapLayers[i]->Update();
        }

        std::vector<LayerManager*> GetLayers(){
            return m_MapLayers;
        }

    private:
        friend class MapParser;
        std::vector<LayerManager*> m_MapLayers;
};

#endif // MAP_H
