#include <SDL3/SDL.h>
#include "texture.h"
#include "win.h"
#define PLAYERWIDTH 64
#define PLAYERHEIGHT 64

class Player{
    int mPosX, mPosY;
    int mVelX, mVelY;
    SDL_Texture* sheet;
    SDL_FRect currentClip;
    SDL_FRect clips[16];
public:
    Player();
    void handleEvent(SDL_Event& e);
    void move();
    void render();
};