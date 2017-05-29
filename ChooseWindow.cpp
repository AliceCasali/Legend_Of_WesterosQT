#include "ChooseWindow.h"
#include "ui_choosewindow.h"
#include "PlayWindow.h"
#include "ui_playwindow.h"
#include "Targaryen.h"
#include "Territory.h"
#include "ConcreteArmyFactory.h"

ChooseWindow::ChooseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseWindow), barriera("img/barriera.jpg"), baratheon("img/baratheon.png"),
    greyjoy("img/greyjoy.png"), lannister("img/lannister.png"), stark("img/stark.png"),
    targaryen("img/targaryen.png"), whitewalkers("img/whitewalkers.png")
{
    ui->setupUi(this);

    ui->labBaratheon->setPixmap(baratheon.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labBaratheon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labGreyjoy->setPixmap(greyjoy.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labGreyjoy->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labLannister->setPixmap(lannister.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labLannister->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labStark->setPixmap(stark.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labStark->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labTargaryen->setPixmap(targaryen.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labTargaryen->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labWhiteWalkers->setPixmap(whitewalkers.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labWhiteWalkers->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

}

ChooseWindow::~ChooseWindow()
{

}

void ChooseWindow::on_back_clicked()
{
    close();
}

void ChooseWindow::on_btnTargaryen_clicked()
{
    startGame("Targaryen");
}

void ChooseWindow::on_btnStark_clicked()
{
    startGame("Stark");
}


void ChooseWindow::on_btnGreyjoy_clicked()
{
    startGame("Greyjoy");
}

void ChooseWindow::on_btnLannister_clicked()
{
    startGame("Lannister");
}

void ChooseWindow::on_btnWhiteWalkers_clicked()
{ui->labBaratheon->setPixmap(baratheon.scaled(100, 100, Qt::KeepAspectRatio));
    startGame("WhiteWalkers");
}

void ChooseWindow::on_btnBaratheon_clicked()
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


void ChooseWindow::paintEvent(QPaintEvent *)
{

}
