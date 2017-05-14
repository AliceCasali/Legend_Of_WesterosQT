#include "ChooseWindow.h"
#include "ui_choosewindow.h"
#include "PlayWindow.h"
#include "ui_playwindow.h"
#include "Targaryen.h"
#include "Territory.h"
#include "ConcreteArmyFactory.h"
#include <iostream>

ChooseWindow::ChooseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}

void ChooseWindow::on_back_clicked()
{
    close();
}

void ChooseWindow::on_targaryen_clicked()
{
    PlayWindow addView;
    addView.setHouseTargaryen();
    close();
    addView.exec();

}



   // Army* army = new army(this);
    //così creiamo un nuovo esercito, andrà bene? meglio un setArmy? va fatto perchè non c'è in Territory
    /*ConcreteArmyFactory f(army->getName());
    army = Territory(f.createArmy());
    addView.getArmy(Targaryen);
    */
// per ognuno ci fai una nuova finestra e gli passi il nome del tizio scelto.
    //nella finestra che apri (addview) devi creare una funzione pubblica di setHouse.
    // quando crei addview, prima di exec() scrivi addview.setHOuse(roba)

//void MainWindow::on_pushButton_clicked()
//{
//    circle* circleObj = new circle(this); // instance created
//    circleObj->myFunct(); // the necessary  actions are done in this function
//    // connect the signals from the circle class if any to the required slots in MainWindow
//    connect(circle, SIGNAL(mySignal()), this, SLOT(mySlot());
//}


void ChooseWindow::on_stark_clicked()
{
    PlayWindow addView;
    addView.setHouseStark();
    close();
    addView.exec();
}

void ChooseWindow::on_greyjoy_clicked()
{
    PlayWindow addView;
    addView.setHouseGreyjoy();
    close();
    addView.exec();
}

void ChooseWindow::on_lannister_clicked()
{
    PlayWindow addView;
    addView.setHouseLannister();
    close();
    addView.exec();
}

void ChooseWindow::on_whitewalkers_clicked()
{
    PlayWindow addView;
    addView.setHouseWhiteWalkers();
    close();
    addView.exec();
}

void ChooseWindow::on_baratheon_clicked()
{
    PlayWindow addView;
    addView.setHouseBaratheon();
    close();
    addView.exec();
}
