#include <qapplication.h>
#include "wormhole.h"

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    WormHole w;
    w.show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}
