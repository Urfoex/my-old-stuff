#include <iostream>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_rotozoom.h>
#include <SDL_thread.h>

using namespace std;

class mySystem{
public:
    mySystem();
    ~mySystem();

private:
    bool Loading();
    bool InitSystem();
    bool InitVideoSystem();
    SDL_Surface* LoadPicture(char* FileName);

    SDL_Thread* TEST;

    void DisplaySplash();
    bool SPLASH;

    fstream LOGFILE;

    SDL_Surface *MAINSURFACE;

protected:
};

mySystem::mySystem(){
    LOGFILE.open( "logfile.log", fstream::out);
    SPLASH = true;

    Loading();
}

mySystem::~mySystem(){

    SDL_FreeSurface( MAINSURFACE);

    SDL_Quit();

    LOGFILE.close();
}

bool mySystem::Loading(){
    if( !InitSystem()){
        LOGFILE << "InitSystem() failed. Aborting ...\n";
        return false;
    }

    if( !InitVideoSystem()){
        LOGFILE << "InitVideoSystem() failed. Aborting ...\n";
        return false;
    }

    //TEST = SDL_CreateThread( DisplaySplash(), NULL);

    SPLASH = false;

    return true;
}

bool mySystem::InitSystem(){
    if( SDL_Init( SDL_INIT_VIDEO) == -1){
        LOGFILE << "SDL_INIT_VIDEO: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

bool mySystem::InitVideoSystem(){
    MAINSURFACE = SDL_SetVideoMode( 640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if( MAINSURFACE == 0){
        LOGFILE << "SDL_SetVideoMode(): " << SDL_GetError() << endl;
        return false;
    }

    return true;
};

SDL_Surface* mySystem::LoadPicture(char* FileName){
    SDL_Surface* TMP_PICTURE_ONE = IMG_Load( FileName);
    if( !TMP_PICTURE_ONE){
        LOGFILE << "Could not load: " << FileName << " with error: " << IMG_GetError() << endl;
        SDL_FreeSurface( TMP_PICTURE_ONE);
        return false;
    }

    SDL_Surface* TMP_PICTURE_TWO = SDL_DisplayFormatAlpha( TMP_PICTURE_ONE);
    if( !TMP_PICTURE_TWO){
        LOGFILE << "Could not convert: " << FileName << " with error: " << SDL_GetError() << endl;
        SDL_FreeSurface( TMP_PICTURE_ONE);
        SDL_FreeSurface( TMP_PICTURE_TWO);
        return false;
    }

    SDL_FreeSurface( TMP_PICTURE_ONE);

    return TMP_PICTURE_TWO;
}

void mySystem::DisplaySplash(){
    SDL_Surface* SPLASH_BW = LoadPicture( "gfx/splash_bw.png");
    if( !SPLASH_BW){
        LOGFILE << "LoadSplash() failed. Aborting ...\n";
        return false;
    }

    SDL_Surface* SPLASH_WB = LoadPicture( "gfx/splash_wb.png");
    if( !SPLASH_WB){
        LOGFILE << "LoadSplash() failed. Aborting ...\n";
        return false;
    }
// Load Picture in HW
    while( SPLASH){
        SDL_BlitSurface( SPLASH_BW, NULL , MAINSURFACE, NULL);
        SDL_Flip( MAINSURFACE);

        SDL_Delay( 250);

        SDL_BlitSurface( SPLASH_WB, NULL , MAINSURFACE, NULL);
        SDL_Flip( MAINSURFACE);

        SDL_Delay( 250);
    }


    SDL_FreeSurface( SPLASH);
}

int main ( int argc, char** argv )
{
    mySystem test;
    return 0;
}
