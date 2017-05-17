#include "PlayWindow.h"
#include "ui_playwindow.h"
#include "iostream"

#include <QString>
//#include Q_OBJECT
#include <string>


/*QPixmap bg("://home/pcalice/Immagini/a.jpg");
QPalette p(palette());
p.setBrush(QPalette::Background, bg);
*/

using namespace std;

PlayWindow::PlayWindow(QWidget *parent) :
    QDialog(parent), painter(this),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    bkgnd = QPixmap("img/westeros.jpg");

    stark = QPixmap("img/stark.png");

    srand(time(NULL)); //da chiamare una volta quando tirerò a caso i numeri con la rand
                           //serve con la rand, la chiamo una volta sola nel main
    //assegno una strategy casuale ad ogni casata
    Baratheon::strategy = Army::randomStrategy();
    Greyjoy::strategy = Army::randomStrategy();
    Lannister::strategy = Army::randomStrategy();
    Stark::strategy = Army::randomStrategy();
    Targaryen::strategy = Army::randomStrategy();
    WhiteWalkers::strategy = Army::randomStrategy();

    //creo la mappa
    mappa = Map();

}



PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::setHouseBaratheon()
{
    Baratheon* player;
    player=new Baratheon;
    ui->label->setText(QString::fromStdString(std::string(player->getName())));
}

void PlayWindow::setHouseGreyjoy()
{
    Greyjoy* player;
    player=new Greyjoy;
    ui->label->setText(QString::fromStdString(std::string(player->getName())));
}

void PlayWindow::setHouseLannister()
{
    Lannister* player;
    player=new Lannister;
    ui->label->setText(QString::fromStdString(std::string(player->getName())));
}

void PlayWindow::setHouseStark()
{
    Stark* player;
    player=new Stark;
    ui->label->setText(QString::fromStdString(std::string(player->getName())));
}

void PlayWindow::setHouseTargaryen()
{
    Targaryen*player;
    player=new Targaryen;
    ui->label->setText(QString::fromStdString(std::string(player->getName())));
}

void PlayWindow::setHouseWhiteWalkers()
{
    WhiteWalkers* player;
    player=new WhiteWalkers;
    ui->label->setText(QString::fromStdString(std::string(player->getName())));
}

void PlayWindow::paintEvent(QPaintEvent *)
{



    QPainter painter2(&bkgnd);
    painter2.drawPixmap(0, 0, 100, 100, stark);

    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

/*ostream& operator<<(ostream &o, Strategy s) //traduzione da strategy a stringa per fare cout
{
    switch(s)
    {
        case Strategy::onlyMagic:
            return o << "onlyMagic";
        case Strategy::onlySimple:
            return o << "onlySimple";
        case Strategy::lessDefense:
            return o << "lessDefense";
        default:
            return o << "valore non valido";
    }
}*/


void PlayWindow::on_attacca_clicked()
{
    mappa.show();
}
