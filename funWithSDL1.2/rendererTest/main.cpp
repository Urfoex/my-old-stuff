#include <iostream>
#include <SDL/SDL.h>

void cutOf( short int &i, short int j, short int &k);

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        std::cerr << "init: " << SDL_GetError();
        exit(-1);
    }

    SDL_Event events;

    SDL_WindowID window = SDL_CreateWindow(
            "SDL_Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1020, 1020,
            SDL_WINDOW_SHOWN);

    SDL_RendererInfo reninf;


    for( int i = 0; i < SDL_GetNumRenderDrivers() ; ++i){
        SDL_GetRenderDriverInfo( i, &reninf);
        std::cout << i << " " << reninf.name << std::endl;
    }
    int num;
    std::cout  << "which: ";
    std::cin >> num;


    if( SDL_CreateRenderer( window, num, SDL_RENDERER_SINGLEBUFFER | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED) == -1){
        std::cerr << "renderer: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    SDL_RenderFill( 0);
    SDL_RenderPresent();

    bool DONE = false;

    while( SDL_PollEvent( &events));

    SDL_SetRenderDrawColor( 0, 0, 0, 255);
    short int i=0, j=0, r=0, g=0, b=0;
    while( !DONE){
        if( SDL_PollEvent( &events)){
            switch( events.key.keysym.sym){
            case SDLK_q:    DONE = true;
                            break;
            default:
                break;
            }
        }
        SDL_RenderPoint( i,j);
        ++i;
        ++++r;
        if( i >= 1020){
            ++j;
            i = 0;
        }
        if( j >= 1020) j = 0;
        if( r >= 255){
            r = 0;
            ++++g;
        }
        if( g >= 255){
            g = 0;
            ++++b;
        }
        if( b >= 255) b = 0;
            
        SDL_SetRenderDrawColor( r, g, b, 255);
        if( r == 254) SDL_RenderPresent();
    }

    SDL_DestroyRenderer( window);
    SDL_DestroyWindow( window);

    return (EXIT_SUCCESS);
}

void cutOf( short int &i, short int j, short int &k){
    if( i > j){
        i = j%i;
        if( &i != &k) ++k;
        
    }
}
