#ifndef WIN_H
#define WIN_H
#include <SDL3/SDL.h>
#include <string>
using namespace std;

class LWindow{
    int mWidth;
    int mHeight;
public:
    SDL_Renderer* r;
    SDL_Window* w;
    LWindow(string s, int width, int height);
    void render();
};
#endif