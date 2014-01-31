#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <SDL/SDL.h>

class KeyboardKey{
    public:
        KeyboardKey();
        ~KeyboardKey();
        /*KeyboardKey(const KeyboardKey& other);
        KeyboardKey& operator=(const KeyboardKey& other);*/
        const bool isPressed(){ return PRESSED;};
        void gotPressed(){ ++PRESSED;};
        const SDLKey getKey(){ return KEY;};
        void setKey( const SDLKey theKey){ KEY = theKey;};
    protected:
    private:
        bool PRESSED;
        SDLKey KEY;

};

#endif // KEYBOARDKEY_H
