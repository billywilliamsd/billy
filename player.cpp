#include "player.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

extern LWindow g;

Player::Player():mPosX(200), mPosY(200), mVelX(0), mVelY(0){
    string s = {"C:/billywilliamsd/billy/texturebin/sprite.png"};
    SDL_Surface* ls = IMG_Load(s.c_str());
    if(ls == nullptr) cout << "error loading player texture\n";
    if(SDL_SetSurfaceColorKey(ls, true, SDL_MapSurfaceRGB(ls, 0x00, 0xFF, 0xFF)) == false) cout << "error loading player texture\n";
    sheet = SDL_CreateTextureFromSurface(g.r, ls);
    SDL_DestroySurface(ls);

    clips[0] = {0.0, 0.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[1] = {64.0, 0.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[2] = {128.0, 0.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[3] = {192.0, 0.0, PLAYERWIDTH, PLAYERHEIGHT};

    clips[4] = {0.0, 64.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[5] = {64.0, 64.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[6] = {128.0, 64.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[7] = {192.0, 0.0, PLAYERWIDTH, PLAYERHEIGHT};

    clips[8] = {0.0, 128.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[9] = {64.0, 128.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[10] = {128.0, 128.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[11] = {192.0, 128.0, PLAYERWIDTH, PLAYERHEIGHT};

    clips[12] = {0.0, 192.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[13] = {64.0, 192.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[14] = {128.0, 192.0, PLAYERWIDTH, PLAYERHEIGHT};
    clips[15] = {192.0, 192.0, PLAYERWIDTH, PLAYERHEIGHT};

    currentClip = clips[0];
}

void Player::render(){
    SDL_FRect dstRect = {mPosX, mPosY, PLAYERWIDTH, PLAYERHEIGHT};
    SDL_RenderTexture(g.r, sheet, &currentClip, &dstRect);
}
