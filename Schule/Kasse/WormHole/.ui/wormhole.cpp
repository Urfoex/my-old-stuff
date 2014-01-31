/****************************************************************************
** Form implementation generated from reading ui file 'wormhole.ui'
**
** Created: Mo Okt 16 19:02:57 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "wormhole.h"

#include <qvariant.h>
#include <qgroupbox.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qprogressbar.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>
#include <qimage.h>
#include <qpixmap.h>

#include "../wormhole.ui.h"
/*
 *  Constructs a WormHole as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
WormHole::WormHole( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "WormHole" );
    setEnabled( TRUE );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 1, 1, sizePolicy().hasHeightForWidth() ) );
    setMinimumSize( QSize( 21, 21 ) );
    setMaximumSize( QSize( 480, 180 ) );
    setCentralWidget( new QWidget( this, "qt_central_widget" ) );

    Wahlbox = new QGroupBox( centralWidget(), "Wahlbox" );
    Wahlbox->setGeometry( QRect( 10, 10, 460, 140 ) );

    comboBox8 = new QComboBox( FALSE, Wahlbox, "comboBox8" );
    comboBox8->setGeometry( QRect( 360, 20, 40, 21 ) );

    comboBox1 = new QComboBox( FALSE, Wahlbox, "comboBox1" );
    comboBox1->setGeometry( QRect( 10, 20, 40, 21 ) );

    comboBox2 = new QComboBox( FALSE, Wahlbox, "comboBox2" );
    comboBox2->setGeometry( QRect( 60, 20, 40, 21 ) );

    comboBox3 = new QComboBox( FALSE, Wahlbox, "comboBox3" );
    comboBox3->setGeometry( QRect( 110, 20, 40, 21 ) );

    comboBox4 = new QComboBox( FALSE, Wahlbox, "comboBox4" );
    comboBox4->setGeometry( QRect( 160, 20, 40, 21 ) );

    comboBox5 = new QComboBox( FALSE, Wahlbox, "comboBox5" );
    comboBox5->setGeometry( QRect( 210, 20, 40, 21 ) );

    comboBox6 = new QComboBox( FALSE, Wahlbox, "comboBox6" );
    comboBox6->setGeometry( QRect( 260, 20, 40, 21 ) );

    comboBox7 = new QComboBox( FALSE, Wahlbox, "comboBox7" );
    comboBox7->setGeometry( QRect( 310, 20, 40, 21 ) );

    comboBox9 = new QComboBox( FALSE, Wahlbox, "comboBox9" );
    comboBox9->setGeometry( QRect( 410, 20, 40, 20 ) );

    Anwahl_Abbrechen = new QPushButton( Wahlbox, "Anwahl_Abbrechen" );
    Anwahl_Abbrechen->setGeometry( QRect( 10, 110, 130, 20 ) );

    Verbindung_schliessen = new QPushButton( Wahlbox, "Verbindung_schliessen" );
    Verbindung_schliessen->setGeometry( QRect( 150, 110, 130, 20 ) );

    progressBar1 = new QProgressBar( Wahlbox, "progressBar1" );
    progressBar1->setGeometry( QRect( 10, 50, 440, 22 ) );
    progressBar1->setProgress( 0 );

    Anwaehlen = new QPushButton( Wahlbox, "Anwaehlen" );
    Anwaehlen->setGeometry( QRect( 10, 80, 90, 20 ) );

    Schutzschliessen = new QPushButton( Wahlbox, "Schutzschliessen" );
    Schutzschliessen->setGeometry( QRect( 350, 113, 100, 20 ) );
    Schutzschliessen->setToggleButton( TRUE );

    progressBar3 = new QProgressBar( Wahlbox, "progressBar3" );
    progressBar3->setGeometry( QRect( 150, 80, 300, 22 ) );
    progressBar3->setTotalSteps( 100 );
    progressBar3->setProgress( 0 );

    textLabel1 = new QLabel( Wahlbox, "textLabel1" );
    textLabel1->setGeometry( QRect( 280, 110, 70, 20 ) );

    // toolbars

    languageChange();
    resize( QSize(480, 180).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( Schutzschliessen, SIGNAL( toggled(bool) ), this, SLOT( Schutzschild_aktivieren(bool) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
WormHole::~WormHole()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void WormHole::languageChange()
{
    setCaption( tr( "WormHole" ) );
    Wahlbox->setTitle( tr( "Ringanwahl" ) );
    comboBox8->clear();
    comboBox8->insertItem( tr( "00" ) );
    comboBox8->insertItem( tr( "76" ) );
    comboBox1->clear();
    comboBox1->insertItem( tr( "00" ) );
    comboBox1->insertItem( tr( "12" ) );
    comboBox1->insertItem( tr( "19" ) );
    comboBox1->setCurrentItem( 0 );
    comboBox2->clear();
    comboBox2->insertItem( tr( "00" ) );
    comboBox2->insertItem( tr( "21" ) );
    comboBox2->insertItem( tr( "70" ) );
    comboBox3->clear();
    comboBox3->insertItem( tr( "00" ) );
    comboBox3->insertItem( tr( "68" ) );
    comboBox4->clear();
    comboBox4->insertItem( tr( "00" ) );
    comboBox5->clear();
    comboBox5->insertItem( tr( "00" ) );
    comboBox6->clear();
    comboBox6->insertItem( tr( "00" ) );
    comboBox6->insertItem( tr( "01" ) );
    comboBox7->clear();
    comboBox7->insertItem( tr( "00" ) );
    comboBox7->insertItem( tr( "32" ) );
    comboBox9->clear();
    comboBox9->insertItem( tr( "00" ) );
    comboBox9->insertItem( tr( "80" ) );
    Anwahl_Abbrechen->setText( tr( "Anwahl A&bbrechen" ) );
    Anwahl_Abbrechen->setAccel( QKeySequence( tr( "Alt+B" ) ) );
    QToolTip::add( Anwahl_Abbrechen, tr( "Bricht die Anwahl ab." ) );
    Verbindung_schliessen->setText( tr( "&Verbindung beenden" ) );
    Verbindung_schliessen->setAccel( QKeySequence( tr( "Alt+V" ) ) );
    QToolTip::add( Verbindung_schliessen, tr( "Beendet die aktive Verbindung." ) );
    Anwaehlen->setText( trUtf8( "\x26\x41\x6e\x77\xc3\xa4\x68\x6c\x65\x6e" ) );
    Anwaehlen->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QToolTip::add( Anwaehlen, trUtf8( "\x57\xc3\xa4\x68\x6c\x74\x20\x64\x69\x65\x20\x65\x69\x6e\x67\x65\x67\x65\x62\x65\x6e"
    "\x65\x20\x41\x64\x72\x65\x73\x73\x65\x20\x61\x6e\x2e" ) );
    Schutzschliessen->setText( tr( "Schutzschild" ) );
    QToolTip::add( Schutzschliessen, tr( "Aktivieren um das Schutzschild zu aktivieren." ) );
    textLabel1->setText( tr( "textLabel1" ) );
}

