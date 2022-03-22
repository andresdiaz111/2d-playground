#ifndef MAP_H
#define MAP_H

#include <vector>
#include "LayerManager.h"

class Map
{
    public:
        void Render()
        {
            for(unsigned int i = 0 ; i < m_MapLayers.size() ; i++)
            {
                m_MapLayers[i]->RenderLayer();
            }

        }
        void Update()
        {
            for(unsigned int i = 0 ; i < m_MapLayers.size() ; i++)
            {
                m_MapLayers[i]->UpdateLayer();
            }

        }

        std::vector<LayerManager*> GetMapLayers(){return m_MapLayers;}
    private:
        friend class MapParser;
        std::vector<LayerManager*> m_MapLayers;
};

#endif // MAP_H
