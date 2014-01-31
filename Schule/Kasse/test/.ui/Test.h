/****************************************************************************
** Form interface generated from reading ui file 'Test.ui'
**
** Created: Di Okt 10 19:35:10 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TEST_H
#define TEST_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QGroupBox;
class QLabel;
class QLineEdit;

class Test : public QDialog
{
    Q_OBJECT

public:
    Test( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Test();

    QPushButton* buttonOk;
    QPushButton* buttonAbbrechen;
    QPushButton* buttonErweitern;
    QGroupBox* gruppe1;
    QLabel* textName;
    QLineEdit* lineEdit19;
    QLineEdit* lineEdit20;
    QLabel* textVorname;
    QGroupBox* gruppe2;
    QLineEdit* lineEdit19_2;
    QLabel* textName2;
    QLabel* textVorname2;
    QLineEdit* lineEdit20_2;
    QGroupBox* gruppe3;
    QLineEdit* lineEdit20_3;
    QLabel* textVorname3;
    QLabel* textName3;
    QLineEdit* lineEdit19_3;

protected:
    QGridLayout* TestLayout;
    QSpacerItem* spacer18;
    QVBoxLayout* layout5;
    QSpacerItem* spacer17;
    QGridLayout* layout8;
    QGridLayout* layout9;
    QGridLayout* layout10;

protected slots:
    virtual void languageChange();

private:
    void init();

};

#endif // TEST_H
