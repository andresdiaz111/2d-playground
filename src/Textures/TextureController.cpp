#include "TextureController.h"
#include "../Engine/EngineCore.h"
#include "Vector.h"
#include "View.h"

TextureController *TextureController::s_Instance = nullptr;

bool TextureController::LoadTexture(std::string id, std::string filepath)
{
    SDL_Surface *surface = IMG_Load(filepath.c_str());
    if(!surface)
    {
        SDL_Log("Fail to load texture: %s, %s", filepath.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(EngineCore::GetInstance()->GetRenderer(), surface);
    if(!texture)
    {
        SDL_Log("Fail to create the texture error: %s", SDL_GetError());
        return false;
    }

    m_TextureMap[id] = texture;
    return true;
}

void TextureController::RemoveTexture(std::string id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void TextureController::CleanTextureController()
{
    std::map<std::string, SDL_Texture*>::iterator it;
    for(it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
        SDL_DestroyTexture(it->second);

    m_TextureMap.clear();
    SDL_Log("Texture clean");
}
void TextureController::DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {tileSize* frame, tileSize* row, tileSize, tileSize};

    Vector view = View::GetInstance()->GetPos();
    SDL_Rect dstRect = {x - view.X, y - view.Y, tileSize, tileSize};
    SDL_RenderCopyEx(EngineCore::GetInstance()->GetRenderer(), m_TextureMap[tilesetID], &srcRect, &dstRect, 0, 0, flip);
}


void TextureController::DrawTexture(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect src = {0, 0, width, height};
    SDL_Rect destination = {x, y, width, height};
    SDL_RenderCopyEx(EngineCore::GetInstance()->GetRenderer(), m_TextureMap[id], &src, &destination, 0, nullptr, flip);
}

void TextureController::DrawFrame(std::string id, int x, int y, int width, int height,int row, int frame ,SDL_RendererFlip flip)
{
    SDL_Rect src = {width*frame, height*row, width, height};
    SDL_Rect destination = {x, y, width, height};
    SDL_RenderCopyEx(EngineCore::GetInstance()->GetRenderer(), m_TextureMap[id], &src, &destination, 0, nullptr, flip);
}
