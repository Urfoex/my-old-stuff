/****************************************************************************
** Form interface generated from reading ui file 'wormhole.ui'
**
** Created: Mo Okt 16 19:00:29 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef WORMHOLE_H
#define WORMHOLE_H

#include <qvariant.h>
#include <qmainwindow.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class QGroupBox;
class QComboBox;
class QPushButton;
class QProgressBar;
class QLabel;

class WormHole : public QMainWindow
{
    Q_OBJECT

public:
    WormHole( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~WormHole();

    QGroupBox* Wahlbox;
    QComboBox* comboBox8;
    QComboBox* comboBox1;
    QComboBox* comboBox2;
    QComboBox* comboBox3;
    QComboBox* comboBox4;
    QComboBox* comboBox5;
    QComboBox* comboBox6;
    QComboBox* comboBox7;
    QComboBox* comboBox9;
    QPushButton* Anwahl_Abbrechen;
    QPushButton* Verbindung_schliessen;
    QProgressBar* progressBar1;
    QPushButton* Anwaehlen;
    QPushButton* Schutzschliessen;
    QProgressBar* progressBar3;
    QLabel* textLabel1;

public slots:
    virtual void Schutzschild_aktivieren( bool Schutz );

protected:

protected slots:
    virtual void languageChange();

};

#endif // WORMHOLE_H
