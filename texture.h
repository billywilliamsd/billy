#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL3/SDL.h>
#include <string>
#include <vector>
using namespace std;

class LTexture{
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
public:
    int mPosX;
    int mPosY;
    string file;

    LTexture();
    ~LTexture();
    void destroy();
    bool loadFromFile(string s);
    bool loadFromRenderedText(string s, SDL_Color c);
    void render();

    int getWidth();
    int getHeight();
    bool isLoaded();
};
#endif