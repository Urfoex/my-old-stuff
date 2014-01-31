// bacchikoi - Bring it!

//#include <iostream>
#include "include/Bacchikoi.h"



int main()
{
    Bacchikoi* test = new Bacchikoi;
    if( test->Initiate())
        test->ShowScreen();
    //test->Initial();
    //test->Show( 2500);
    delete test;

    return 0;
}
