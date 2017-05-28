#include "ChooseWindow.h"
#include "ui_choosewindow.h"
#include "PlayWindow.h"
#include "ui_playwindow.h"
#include "Targaryen.h"
#include "Territory.h"
#include "ConcreteArmyFactory.h"

ChooseWindow::ChooseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseWindow), barriera("img/barriera.jpg")/*, baratheon("img/baratheon.png"),
    greyjoy("img/greyjoy.png"), lannister("img/lannister.png"), stark("img/stark.png"),
    targaryen("img/targaryen.png"), whitewalkers("img/whitewalkers.png")*/
{
    ui->setupUi(this);

    ui->labBaratheon->setVisible(false);
    ui->labGreyjoy->setVisible(false);
    ui->labLannister->setVisible(false);
    ui->labStark->setVisible(false);
    ui->labTargaryen->setVisible(false);
    ui->labWhiteWalkers->setVisible(false);
}

ChooseWindow::~ChooseWindow()
{
    delete ui;
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
{
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

    /*baratheon = baratheon.scaled(ui->labBaratheon->size());
    QPainter painterBaratheon(&baratheon);
    painterBaratheon.drawPixmap(0, 0, ui->labBaratheon->width(), ui->labBaratheon->height(), baratheon);
    ui->labBaratheon->setPixmap(baratheon);

    greyjoy = greyjoy.scaled(ui->labGreyjoy->size());
    QPainter painterGreyjoy(&greyjoy);
    painterGreyjoy.drawPixmap(0, 0, ui->labGreyjoy->width(), ui->labGreyjoy->height(), greyjoy);
    ui->labGreyjoy->setPixmap(greyjoy);

    lannister = lannister.scaled(ui->labLannister->size());
    QPainter painterLannister(&lannister);
    painterLannister.drawPixmap(0, 0, ui->labLannister->width(), ui->labLannister->height(), lannister);
    ui->labLannister->setPixmap(lannister);

    stark = stark.scaled(ui->labStark->size());
    QPainter painterStark(&stark);
    painterStark.drawPixmap(0, 0, ui->labStark->width(), ui->labStark->height(), stark);
    ui->labStark->setPixmap(stark);

    targaryen = targaryen.scaled(ui->labTargaryen->size());
    QPainter painterTargaryen(&targaryen);
    painterTargaryen.drawPixmap(0, 0, ui->labTargaryen->width(), ui->labTargaryen->height(), targaryen);
    ui->labTargaryen->setPixmap(targaryen);

    whitewalkers = whitewalkers.scaled(ui->labWhiteWalkers->size());
    QPainter painterWhiteWalkers(&whitewalkers);
    painterWhiteWalkers.drawPixmap(0, 0, ui->labWhiteWalkers->width(), ui->labWhiteWalkers->height(), whitewalkers);
    ui->labWhiteWalkers->setPixmap(whitewalkers);*/

}
