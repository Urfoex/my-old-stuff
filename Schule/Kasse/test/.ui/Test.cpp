/****************************************************************************
** Form implementation generated from reading ui file 'Test.ui'
**
** Created: Di Okt 10 19:35:14 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Test.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "../Test.ui.h"
/*
 *  Constructs a Test as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Test::Test( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Test" );
    TestLayout = new QGridLayout( this, 1, 1, 11, 6, "TestLayout"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    buttonOk = new QPushButton( this, "buttonOk" );
    layout5->addWidget( buttonOk );

    buttonAbbrechen = new QPushButton( this, "buttonAbbrechen" );
    layout5->addWidget( buttonAbbrechen );
    spacer17 = new QSpacerItem( 20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout5->addItem( spacer17 );

    buttonErweitern = new QPushButton( this, "buttonErweitern" );
    buttonErweitern->setToggleButton( TRUE );
    layout5->addWidget( buttonErweitern );

    TestLayout->addMultiCellLayout( layout5, 0, 1, 1, 1 );
    spacer18 = new QSpacerItem( 20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding );
    TestLayout->addItem( spacer18, 1, 0 );

    gruppe1 = new QGroupBox( this, "gruppe1" );

    QWidget* privateLayoutWidget = new QWidget( gruppe1, "layout8" );
    privateLayoutWidget->setGeometry( QRect( 11, 20, 166, 60 ) );
    layout8 = new QGridLayout( privateLayoutWidget, 1, 1, 11, 6, "layout8"); 

    textName = new QLabel( privateLayoutWidget, "textName" );

    layout8->addWidget( textName, 0, 0 );

    lineEdit19 = new QLineEdit( privateLayoutWidget, "lineEdit19" );

    layout8->addWidget( lineEdit19, 1, 1 );

    lineEdit20 = new QLineEdit( privateLayoutWidget, "lineEdit20" );

    layout8->addWidget( lineEdit20, 0, 1 );

    textVorname = new QLabel( privateLayoutWidget, "textVorname" );

    layout8->addWidget( textVorname, 1, 0 );

    TestLayout->addWidget( gruppe1, 0, 0 );

    gruppe2 = new QGroupBox( this, "gruppe2" );

    QWidget* privateLayoutWidget_2 = new QWidget( gruppe2, "layout9" );
    privateLayoutWidget_2->setGeometry( QRect( 11, 20, 166, 60 ) );
    layout9 = new QGridLayout( privateLayoutWidget_2, 1, 1, 11, 6, "layout9"); 

    lineEdit19_2 = new QLineEdit( privateLayoutWidget_2, "lineEdit19_2" );

    layout9->addWidget( lineEdit19_2, 1, 1 );

    textName2 = new QLabel( privateLayoutWidget_2, "textName2" );

    layout9->addWidget( textName2, 0, 0 );

    textVorname2 = new QLabel( privateLayoutWidget_2, "textVorname2" );

    layout9->addWidget( textVorname2, 1, 0 );

    lineEdit20_2 = new QLineEdit( privateLayoutWidget_2, "lineEdit20_2" );

    layout9->addWidget( lineEdit20_2, 0, 1 );

    TestLayout->addWidget( gruppe2, 2, 0 );

    gruppe3 = new QGroupBox( this, "gruppe3" );

    QWidget* privateLayoutWidget_3 = new QWidget( gruppe3, "layout10" );
    privateLayoutWidget_3->setGeometry( QRect( 11, 20, 166, 60 ) );
    layout10 = new QGridLayout( privateLayoutWidget_3, 1, 1, 11, 6, "layout10"); 

    lineEdit20_3 = new QLineEdit( privateLayoutWidget_3, "lineEdit20_3" );

    layout10->addWidget( lineEdit20_3, 0, 1 );

    textVorname3 = new QLabel( privateLayoutWidget_3, "textVorname3" );

    layout10->addWidget( textVorname3, 1, 0 );

    textName3 = new QLabel( privateLayoutWidget_3, "textName3" );

    layout10->addWidget( textName3, 0, 0 );

    lineEdit19_3 = new QLineEdit( privateLayoutWidget_3, "lineEdit19_3" );

    layout10->addWidget( lineEdit19_3, 1, 1 );

    TestLayout->addWidget( gruppe3, 3, 0 );
    languageChange();
    resize( QSize(332, 323).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( buttonAbbrechen, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( buttonErweitern, SIGNAL( toggled(bool) ), gruppe2, SLOT( setShown(bool) ) );
    connect( buttonErweitern, SIGNAL( toggled(bool) ), gruppe3, SLOT( setShown(bool) ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
Test::~Test()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Test::languageChange()
{
    setCaption( tr( "Test" ) );
    buttonOk->setText( tr( "&Ok" ) );
    buttonOk->setAccel( QKeySequence( tr( "Alt+O" ) ) );
    buttonAbbrechen->setText( tr( "&Abbrechen" ) );
    buttonAbbrechen->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    buttonErweitern->setText( tr( "&Erweitern" ) );
    buttonErweitern->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    gruppe1->setTitle( tr( "Gruppe 1" ) );
    textName->setText( tr( "Name" ) );
    textVorname->setText( tr( "Vorname" ) );
    gruppe2->setTitle( tr( "Gruppe 2" ) );
    textName2->setText( tr( "Name" ) );
    textVorname2->setText( tr( "Vorname" ) );
    gruppe3->setTitle( tr( "Gruppe 3" ) );
    textVorname3->setText( tr( "Vorname" ) );
    textName3->setText( tr( "Name" ) );
}

