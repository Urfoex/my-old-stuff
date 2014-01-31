#ifndef BINARYCALC_H
#define BINARYCALC_H

#include <QMainWindow>

namespace Ui {
    class binaryCalc;
}

class binaryCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit binaryCalc(QWidget *parent = 0);
    ~binaryCalc();

private:
    Ui::binaryCalc *ui;
    double last;
    int AndOr;

private slots:
    void on_b0_clicked();
    void on_b1_clicked();
    void on_bAND_clicked();
    void on_bOR_clicked();
    void on_bCLR_clicked();
    void on_bIS_clicked();
};

#endif // BINARYCALC_H
