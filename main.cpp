#include "win.h"
#include "texture.h"
#include <iostream>
using namespace std;

LWindow g = {"GLOBAL", 900, 600};
vector<LTexture> texture;

bool init();
bool loadMedia();
void close();
void addTexture(string s, int x, int y);

int main(int argc, char** argv){
    if(init() == false) return 1;
    if(loadMedia() == false) return 2;
    vector<LTexture>::iterator it;
    for(it = texture.begin(); it != texture.end(); ++it)
        cout << it->file << endl;
    bool quit = false;
    SDL_Event e;
    SDL_zero(e);
    while(quit == false){
        while(SDL_PollEvent(&e) == true){
            if(e.type == SDL_EVENT_QUIT) quit = true;
        }
        g.render();
    }
    close();
    return 0;
}

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO) == false) return false;
    return true;
}

bool loadMedia(){
    addTexture("C:/PROJ/texturebin/pokecenter.png", 200, 300);
    addTexture("C:/PROJ/texturebin/tree.png", 0, 0);
    addTexture("C:/PROJ/texturebin/tree.png", 100, 0);
    addTexture("C:/PROJ/texturebin/tree.png", 200, 0);
    return true;
}

void close(){
    SDL_DestroyRenderer(g.r);
    g.r = nullptr;
    SDL_DestroyWindow(g.w);
    g.w = nullptr;
    SDL_Quit();
}

void addTexture(string s, int x, int y){
    LTexture t;
    t.file = s;
    t.mPosX = x;
    t.mPosY = y;
    texture.push_back(t);
    if(texture[texture.size() - 1].loadFromFile(s) == true) cout << "loadFromFile " << s << " true\n";
}