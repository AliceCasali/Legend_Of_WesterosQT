#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QDialog>
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

    void setHouseBaratheon();
    void setHouseGreyjoy();
    void setHouseLannister();
    void setHouseStark();
    void setHouseTargaryen();
    void setHouseWhiteWalkers();


private slots:
    void on_pushButton_clicked();

    void on_attacca_clicked();

private:
    Ui::PlayWindow *ui;
    Map mappa;

};


#endif // PLAYWINDOW_H