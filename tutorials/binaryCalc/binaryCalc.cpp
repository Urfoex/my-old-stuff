#include "binaryCalc.h"
#include "ui_binaryCalc.h"

binaryCalc::binaryCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::binaryCalc)
{
    ui->setupUi(this);
}

binaryCalc::~binaryCalc()
{
    delete ui;
}

void binaryCalc::on_b0_clicked()
{
    ui->lcdNumber->display( ui->lcdNumber->value()*2);
}

void binaryCalc::on_b1_clicked()
{
    ui->lcdNumber->display( ui->lcdNumber->value()*2+1);
}

void binaryCalc::on_bAND_clicked()
{
    if( AndOr == 1)
        last =  (int)ui->lcdNumber->value() & (int)last;
    else if(AndOr == 2)
        last = (int)ui->lcdNumber->value() | (int)last;
    else
        last = ui->lcdNumber->value();
    AndOr = 1;
    ui->lcdNumber->display( 0);
}

void binaryCalc::on_bOR_clicked()
{
    if( AndOr == 1)
        last = (int)ui->lcdNumber->value() & (int)last;
    else if(AndOr == 2)
        last = (int)ui->lcdNumber->value() | (int)last;
    else
        last = ui->lcdNumber->value();
    AndOr = 2;
    ui->lcdNumber->display( 0);
}

void binaryCalc::on_bCLR_clicked()
{
    AndOr = 0;
    last = 0;
    ui->lcdNumber->display( 0);
    ui->b0->setDisabled(false);
    ui->b1->setDisabled(false);
    ui->bAND->setDisabled(false);
    ui->bOR->setDisabled(false);
    ui->bIS->setEnabled(true);
}

void binaryCalc::on_bIS_clicked()
{
    if( AndOr == 1)
        ui->lcdNumber->display( (int)ui->lcdNumber->value() & (int)last);
    else if(AndOr == 2)
        ui->lcdNumber->display( (int)ui->lcdNumber->value() | (int)last);
    AndOr = 0;
    last = ui->lcdNumber->value();
    ui->b0->setDisabled(true);
    ui->b1->setDisabled(true);
    ui->bAND->setDisabled(true);
    ui->bOR->setDisabled(true);
    ui->bIS->setEnabled(false);
}
