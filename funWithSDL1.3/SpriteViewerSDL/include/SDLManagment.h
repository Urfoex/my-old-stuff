#ifndef SDLMANAGMENT_H_INCLUDED
#define SDLMANAGMENT_H_INCLUDED

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class SDLManagment{
public:
    SDLManagment();
    ~SDLManagment();
    SDLManagment( const SDLManagment&);
    SDLManagment operator=( const SDLManagment&);
    const bool wasInit() const;
    void setFullscreen(){ FULLSCREENFLAG = SDL_WINDOW_FULLSCREEN;};

    void Main();
    void loadImage( std::string path);


private:
    std::list<SDL_WindowID> WindowID;
    SDL_Event Events;
    bool STOP;
    SDL_TextureID Picture;
    SDL_Rect FullPicture;
    SDL_Rect PartPicture;
    SDL_Rect zoomPicture;
    SDL_Surface* pic;
    SDL_DisplayMode mainDisplayMode;
    Uint32 FULLSCREENFLAG;

    unsigned short int mouseButtonState;

    const bool setUp();
    const bool createMainWindow( std::string title);
    const bool createWindow( std::string title);

    void clearUp();
    void eraseWindow( SDL_WindowID& window);

    void handleEvents();
    void handleKeyboardEvents();
    void handleMouseEvents();
    void handleWindowEvents();

    void printSDLError() const { std::cerr << SDL_GetError() << std::endl;};
    void printSDLError( std::string msg) const { std::cerr << msg << " : " << SDL_GetError() << std::endl;};

    void refreshWindow( SDL_WindowID& window);

    void movePictureInWindow( SDL_WindowID& window, signed short int x, signed short int y);
    void zoomPictureInWindow( SDL_WindowID& window, signed long int amount);
};

#endif // SDLMANAGMENT_H_INCLUDED
