#include "texture.h"
#include "win.h"
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
using namespace std;

//global window g
extern LWindow g;

//global font
extern TTF_Font* font;

LTexture::LTexture():mTexture{NULL}, mWidth(0), mHeight(0), mPosX(0), mPosY(0){}

LTexture::~LTexture(){destroy();}

void LTexture::destroy(){
    SDL_DestroyTexture(mTexture);
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

//loads texture from file path s
bool LTexture::loadFromFile(string s){
    SDL_Surface* ls = IMG_Load(s.c_str());
    if(ls == nullptr) return false;

    if(SDL_SetSurfaceColorKey(ls, true, SDL_MapSurfaceRGB(ls, 0x00, 0xFF, 0xFF)) == false) return false;
    mTexture = SDL_CreateTextureFromSurface(g.r, ls);
    if(mTexture == nullptr) return false;
    mWidth = ls->w;
    mHeight = ls->h;
    SDL_DestroySurface(ls);
    return mTexture != nullptr;
}

bool LTexture::loadFromRenderedText(string s, SDL_Color c){
    destroy();
    SDL_Surface* ls = TTF_RenderText_Blended(font, s.c_str(), 0, c);
    if(ls == nullptr) return false;
    mTexture = SDL_CreateTextureFromSurface(g.r, ls);
    if(mTexture == nullptr) return false;
    mWidth = ls->w;
    mHeight = ls->h;
    SDL_DestroySurface(ls);
    return mTexture != nullptr;
}

void LTexture::render(){
    SDL_FRect rect = {(float)mPosX, (float)mPosY, (float)mWidth, (float)mHeight};
    SDL_RenderTexture(g.r, mTexture, nullptr, &rect);
}

int LTexture::getWidth(){return mWidth;}
int LTexture::getHeight(){return mHeight;}
bool LTexture::isLoaded(){return mTexture != nullptr;}
