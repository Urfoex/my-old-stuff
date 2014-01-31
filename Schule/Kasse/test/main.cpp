#include <qapplication.h>
#include "Test.h"

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    Test *dialog = new Test;
    a.setMainWidget(dialog);
    dialog->show();
    return a.exec();
}
