#include "../include/KeyboardKey.h"

KeyboardKey::KeyboardKey():
PRESSED( false)
{
    KEY = SDLK_WORLD_95;
}

KeyboardKey::~KeyboardKey()
{
    //dtor
}
/*
KeyboardKey::KeyboardKey(const KeyboardKey& other)
{
    // TODO copy ctor
}

KeyboardKey& KeyboardKey::operator=(const KeyboardKey& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    // TODO assignment operator
    return *this;
}
*/
