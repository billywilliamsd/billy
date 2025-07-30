#include "win.h"
#include "texture.h"
#include <vector>
#include <iostream>
using namespace std;

extern vector<LTexture> v;

//name of window s, width and height of window in pixels
LWindow::LWindow(string s, int width, int height):mWidth(width), mHeight(height){
    w = SDL_CreateWindow(s.c_str(), width, height, 0);
    if(w == nullptr) return;
    r = SDL_CreateRenderer(w, nullptr);
    if(r == nullptr){
        SDL_DestroyWindow(w);
        w = nullptr;
        return;
    }
    SDL_SetRenderDrawColor(r, 0, 0, 0, 0); //black
}

void LWindow::render(){
    SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(r);

    for(auto iter = v.begin(); iter != v.end(); ++iter)
        iter->render();

    SDL_RenderPresent(r);
}