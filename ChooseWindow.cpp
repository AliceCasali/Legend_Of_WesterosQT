#include "ChooseWindow.h"
#include "ui_choosewindow.h"
#include "PlayWindow.h"
#include "ui_playwindow.h"
#include "Targaryen.h"
#include "Territory.h"
#include "ConcreteArmyFactory.h"

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
    startGame("Targaryen");
}

void ChooseWindow::on_stark_clicked()
{
    startGame("Stark");
}

void ChooseWindow::on_greyjoy_clicked()
{
    startGame("Greyjoy");
}

void ChooseWindow::on_lannister_clicked()
{
    startGame("Lannister");
}

void ChooseWindow::on_whitewalkers_clicked()
{
    startGame("WhiteWalkers");
}

void ChooseWindow::on_baratheon_clicked()
{
    startGame("Baratheon");
}


void ChooseWindow::startGame(string nameHouse)
{
    PlayWindow addView;
    addView.setHouse(nameHouse);
    close();
    addView.exec();
}
