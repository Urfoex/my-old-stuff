#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "include/SDLManagment.h"

int main( int argc, char* argv[]){
    SDLManagment* Manager = new SDLManagment;

    if( argc == 2){
        Manager->loadImage( argv[1]);
    }else{
        if( argc == 3){
            Manager->loadImage( argv[1]);
            if( strcmp( argv[2], "--fullscreen") == 0 || strcmp( argv[2], "-f") == 0){
                Manager->setFullscreen();
            }else
                std::cout << "Using: SpriteViewerSDL.exe picture -f --fullscreen\n";
        }else
            std::cout << "Using: SpriteViewerSDL.exe picture -f --fullscreen\n";
    }

    std::cout << "Init: " << ((Manager->wasInit())?"true":"false") << std::endl;

    Manager->Main();

    delete Manager;
    SDL_Quit();

    return 0;
}
