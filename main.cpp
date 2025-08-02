#include <SDL3_ttf/SDL_ttf.h>
#include "win.h"
#include "texture.h"
#include <iostream>
#include "player.h"
using namespace std;

//global window g
LWindow g = {"GLOBAL", 900, 600};

//global vector v to hold textures 
vector<LTexture*> v;

//global font
TTF_Font* font = nullptr;

//global green
constexpr SDL_Color GREEN = {0x00, 0xFF, 0x41, 0xFF};

//global nanoseconds to render frame
Uint64 frametime;
//global framerate
double fps = 60.0;

extern Player player;

bool init(); //SDL init
bool loadMedia(); //textures
void addTexture(string s, int x, int y); //loadMedia helper
void addTexture(string s, SDL_Color c, int x, int y); //loadMedia helper
void close(); //SDL clean up

int main(int argc, char** argv){
    if(init() == false) return 1;
    if(loadMedia() == false) return 2;
    int frame = -1;
    bool quit = false;
    SDL_Event e;
    SDL_zero(e);
    while(quit == false){
        Uint64 t = SDL_GetTicksNS();
        while(SDL_PollEvent(&e) == true){
            if(e.type == SDL_EVENT_QUIT) quit = true;
        }
        g.render();
        frametime = SDL_GetTicksNS() - t;
        double total = 1000000000.0 / fps;
        SDL_DelayNS(total - frametime);
        frametime = SDL_GetTicksNS() - t;

        frame++;
        constexpr int AnimFrames = 4; //4 total sprites
        constexpr int FramesPerSprite = 6; //6 frames per sprite
        if(frame/FramesPerSprite >= AnimFrames) frame = 0;
        cout << "frame = " << frame << endl;
        cout << "\tFramesPerSprite = " << FramesPerSprite << endl;
        cout << "\tframe/FramesPerSprite = " << frame << "/" << FramesPerSprite << " == " << frame/FramesPerSprite << endl;
        player.setClip(frame/FramesPerSprite);
    }
    close();
    return 0;
}

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO) == false) return false;
    if(TTF_Init() == false) return false;
    return true;
}

bool loadMedia(){
    string path = "../Ubuntu-L.ttf";
    font = TTF_OpenFont(path.c_str(), 22);
    if(font == nullptr) return false;
    
    addTexture("C:/PROJ/texturebin/pokecenter.png", 200, 300);
    addTexture("C:/PROJ/texturebin/tree.png", 0, 0);
    addTexture("C:/PROJ/texturebin/tree.png", 100, 0);
    addTexture("C:/PROJ/texturebin/tree.png", 200, 0);
    addTexture("frametime: ", GREEN, 0, 150);
    addTexture("", GREEN, 125, 150);
    addTexture("frames per second: ", GREEN, 0, 175);
    addTexture("", GREEN, 200, 175);
    return true;
}

void close(){
    TTF_CloseFont(font);
    font = nullptr;
    SDL_DestroyRenderer(g.r);
    g.r = nullptr;
    SDL_DestroyWindow(g.w);
    g.w = nullptr;
    TTF_Quit();
    SDL_Quit();
}

void addTexture(string s, int x, int y){
    LTexture* t = new LTexture;
    t->file = s;
    t->mPosX = x;
    t->mPosY = y;
    v.push_back(t);
    if(v[v.size() - 1]->loadFromFile(s) == true) cout << "loadFromFile " << s << " true\n";
}

void addTexture(string s, SDL_Color c, int x, int y){
    LTexture* t = new LTexture;
    t->mPosX = x;
    t->mPosY = y;
    v.push_back(t);
    if(v[v.size() - 1]->loadFromRenderedText(s, c) == true) cout << "loadFromRenderedText = " << s << endl;
}