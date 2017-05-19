#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QDialog>
#include <QPainter>
#include "Targaryen.h"
#include "Baratheon.h"
#include "Greyjoy.h"
#include "Lannister.h"
#include "Stark.h"
#include "WhiteWalkers.h"
#include "Map.h"
#define numCasate 6

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();

    /*void setHouseBaratheon();
    void setHouseGreyjoy();
    void setHouseLannister();
    void setHouseStark();
    void setHouseTargaryen();
    void setHouseWhiteWalkers();*/

    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *eventPress) override;

    void setHouse(string nameHouse);

private slots:
    void on_attacca_clicked();

private:
    Ui::PlayWindow *ui;
    QPixmap bkgnd;
    QPixmap stark;
    QPixmap lannister;
    QPixmap baratheon;
    QPixmap targaryen;
    QPixmap greyjoy;
    QPixmap whitewalkers;

    Map mappa;
    int vectHouses[numCasate];
    int invaderRow;
    int invaderColumn;
    int defenderRow;
    int defenderColumn;
};


#endif // PLAYWINDOW_H
