#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H

#include <string>
#include "SDL.h"
#include <map>

class TextureController
{
    public:
        static TextureController *GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureController();
        }
        bool LoadTexture(std::string id, std::string filepath);
        void RemoveTexture(std::string id);
        void CleanTextureController();
        void DrawTexture(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

    private:
        TextureController(){}
        std::map<std::string, SDL_Texture*> m_TextureMap;
        static TextureController *s_Instance;
};

#endif // TEXTURECONTROLLER_H
