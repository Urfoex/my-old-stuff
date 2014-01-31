#include "../include/Bacchikoi.h"

Bacchikoi::Bacchikoi():
FOREGROUND( NULL)
{
    if( SDL_Init( SDL_INIT_VIDEO) == -1){
        printSDLError();
    }
}

Bacchikoi::~Bacchikoi()
{
    SDL_Quit();
}
/*
Bacchikoi::Bacchikoi(const Bacchikoi& other)
{
    // TODO copy ctor
}

Bacchikoi& Bacchikoi::operator=(const Bacchikoi& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    // TODO assignment operator
    return *this;
}
*/
inline void Bacchikoi::printSDLError(){
    printf("ERROR: %s \n", SDL_GetError() );
}

const bool Bacchikoi::Initiate(){
    SDL_WM_SetCaption( "Bacchikoi\0",'\0');
    if( !InitiateVideo())
        return false;
        InitiateInput();
    return true;
}

const bool Bacchikoi::InitiateVideo(){
    // TODO variable VideoModeEinstellung
    // TODO ueberpruefung, welche Einstellung da sind
    FOREGROUND = SDL_SetVideoMode( 800, 480, 32, SDL_HWSURFACE | SDL_NOFRAME | SDL_DOUBLEBUF);
    if( !FOREGROUND){
        printSDLError();
        return false;
    }

    return true;
}

void Bacchikoi::ShowScreen(){
    if( !FOREGROUND)
        return;

    while( true){
        SDL_Flip( FOREGROUND);
        if( !watchEvents())
            break;
    }

}

const bool Bacchikoi::InitiateInput(){
    // TODO setzten von Standardtasten und Gamepad
    // TODO auslagern von Input in Extraklasse SPIELER
    // TODO anlegen von SPIELER Klasse
    KEYS[0].setKey( SDLK_w);
    KEYS[1].setKey( SDLK_a);
    KEYS[2].setKey( SDLK_s);
    KEYS[3].setKey( SDLK_d);
    KEYS[4].setKey( SDLK_LCTRL);
    KEYS[5].setKey( SDLK_SPACE);
    KEYS[6].setKey( SDLK_KP8);
    KEYS[7].setKey( SDLK_KP4);
    KEYS[8].setKey( SDLK_KP5);
    KEYS[9].setKey( SDLK_KP6);
    KEYS[10].setKey( SDLK_KP0);
    KEYS[11].setKey( SDLK_KP_ENTER);
    return true;
}

const bool Bacchikoi::watchEvents(){
    while( SDL_PollEvent( &EVENT)){
        switch( EVENT.type){
            case SDL_KEYDOWN:
            case SDL_KEYUP: if( handleInputEvents() == false) return false;
                            break;
            default:
                break;
        }
    }
    return true;
}

const bool Bacchikoi::handleInputEvents(){
    if( EVENT.key.state == SDL_RELEASED && EVENT.key.keysym.sym == SDLK_ESCAPE)
        return false;
    for( unsigned short int i = 0; i < 12; ++i){
        if( EVENT.key.keysym.sym == KEYS[i].getKey()){
            KEYS[i].gotPressed();
            break;
        }
    }

    return true;
}
