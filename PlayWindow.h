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

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();

    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *eventPress) override;

    void setHouse(string nameHouse);

private slots:
    void on_attacca_clicked();

private:
    void refreshLabels();

    Ui::PlayWindow *ui;
    QPixmap bkgnd;
    QPixmap westeros;
    QPixmap baratheon;
    QPixmap greyjoy;
    QPixmap lannister;
    QPixmap stark;
    QPixmap targaryen;
    QPixmap whitewalkers;
    QPixmap crown;
    QPixmap cross;
    QPixmap tic;

    Map mappa;
    vector<char> vectHouses;
    int invaderRow;
    int invaderColumn;
    int defenderRow;
    int defenderColumn;
};


#endif // PLAYWINDOW_H
