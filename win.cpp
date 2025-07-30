#include "win.h"
#include "texture.h"
#include <vector>
#include <iostream>
using namespace std;
#define BILLION 1000000000

//global texture vector
extern vector<LTexture*> v;

//frametime
extern Uint64 frametime;

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

    /*for(auto iter = v.begin(); iter != v.end(); ++iter)
        iter->render();
    */


    v.at(5)->loadFromRenderedText(to_string(frametime), {0x00, 0xFF, 0x41, 0xFF});
    if(frametime > 0){
        double frames = 1000000000.0 / frametime;
        v.at(7)->loadFromRenderedText(to_string(frames), {0x00, 0xFF, 0x41, 0xFF});
    }
    for(int i = 0; i < v.size(); i++)
        v.at(i)->render();

    /*SDL_FRect rect = {75.f, 150.f, 22, 22};
    SDL_RenderTexture(g.r, , nullptr, &rect);*/

    SDL_RenderPresent(r);
}