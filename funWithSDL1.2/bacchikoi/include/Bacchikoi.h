#ifndef BACCHIKOI_H
#define BACCHIKOI_H

#include <SDL/SDL.h>
#include <iostream>

#include "KeyboardKey.h"

class Bacchikoi
{
    public:
        Bacchikoi();
        ~Bacchikoi();
        /*Bacchikoi(const Bacchikoi& other);
        Bacchikoi& operator=(const Bacchikoi& other);*/
        const bool Initiate();
        // TODO void Play();
        void ShowScreen();
    protected:

    private:
        SDL_Surface* FOREGROUND;
        SDL_Event EVENT;

        KeyboardKey KEYS[12];

        inline void printSDLError();
        const bool InitiateVideo();
        const bool InitiateInput();

        const bool watchEvents();
        const bool handleInputEvents();

};

#endif // BACCHIKOI_H
