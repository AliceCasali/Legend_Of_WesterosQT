#include "PlayWindow.h"
#include "ui_playwindow.h"
#include "iostream"
#include "math.h"

#include <QString>
#include <QMouseEvent>
//#include Q_OBJECT
#include <string>


/*QPixmap bg("://home/pcalice/Immagini/a.jpg");
QPalette p(palette());
p.setBrush(QPalette::Background, bg);
*/

//using namespace std;

PlayWindow::PlayWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::PlayWindow), bkgnd("img/westeros.jpg"), westeros("img/westeros.jpg"), baratheon("img/baratheon.png"),
    greyjoy("img/greyjoy.png"), lannister("img/lannister.png"), stark("img/stark.png"),
    targaryen("img/targaryen.png"), whitewalkers("img/whitewalkers.png"),
    invaderRow(-1), invaderColumn(-1), defenderRow(-1), defenderColumn(-1)
{
    ui->setupUi(this);

    srand(time(NULL)); //da chiamare una volta quando tirerò a caso i numeri con la rand
                           //serve con la rand, la chiamo una volta sola nel main
    //assegno una strategy casuale ad ogni casata
    Baratheon::strategy = Army::randomStrategy();
    Greyjoy::strategy = Army::randomStrategy();
    Lannister::strategy = Army::randomStrategy();
    Stark::strategy = Army::randomStrategy();
    Targaryen::strategy = Army::randomStrategy();
    WhiteWalkers::strategy = Army::randomStrategy();

    vectHouses[0] = 'B';
    vectHouses[1] = 'G';
    vectHouses[2] = 'L';
    vectHouses[3] = 'S';
    vectHouses[4] = 'T';
    vectHouses[5] = 'W';
}



PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::paintEvent(QPaintEvent *)
{
    bkgnd = bkgnd.scaled(this->ui->vistaMappa->size());
    // andrà modificato per togliere l'errore
    QPainter painter(&bkgnd);
    painter.drawPixmap(0, 0, ui->vistaMappa->width(), ui->vistaMappa->height(), westeros);

    QPixmap *stemma;
    int w, h;
    w = ui->vistaMappa->width()/mappa.getNumColumns();
    h = ui->vistaMappa->height()/mappa.getNumRows();
    for(int i = 0; i<mappa.getNumRows(); i++){
        for(int j = 0; j<mappa.getNumColumns(); j++){
            Territory territory = mappa.readTerritory(i, j);
            if(!territory.isEarth())
                continue;
            int x = j * w;
            int y = i * h;
            switch (territory.getArmy()->getName()[0]) {
                case 'L':
                    stemma = &lannister;
                    break;
                case 'S':
                    stemma = &stark;
                    break;
                case 'G':
                    stemma = &greyjoy;
                    break;
                case 'T':
                    stemma = &targaryen;
                    break;
                case 'W':
                    stemma = &whitewalkers;
                    break;
                case 'B':
                    stemma = &baratheon;
                    break;
            }
            painter.drawPixmap(x, y, w, h, *stemma);
        }
    }

    /*QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->ui->vistaMappa->setPalette(palette);*/

    ui->vistaMappa->setPixmap(bkgnd);

    /*ui->vistaMappa->render(&painter);
    ui->vistaMappa->show();*/

    //delete stemma;
}

void PlayWindow::mousePressEvent(QMouseEvent *eventPress)
{
    QPoint p = eventPress->pos();
    QPoint topleft = ui->vistaMappa->pos();
    p = p - topleft;
    cout << "Mouse pressed: x = " << p.x() << ", y = " << p.y() << endl;
    if(p.x() < 0 || p.x() >= ui->vistaMappa->width() || p.y() < 0 || p.y() >= ui->vistaMappa->height())
        return;
    int w, h;
    w = ui->vistaMappa->width()/mappa.getNumColumns();
    h = ui->vistaMappa->height()/mappa.getNumRows();
    int i = p.y()/h;
    int j = p.x()/w;
    Territory territory = mappa.readTerritory(i, j);

    switch(eventPress->button()){
    case Qt::LeftButton:
        cout << "Premuto clic sx" << endl;
        if(invaderRow == -1){
            if(territory.isEarth()){
                if(vectHouses[0] == territory.getArmy()->getName()[0]){
                    invaderRow = i;
                    invaderColumn = j;
                    // eventualmente mostro qualcosa graficamente
                    cout << "Riga invasore: " << invaderRow << ", Colonna invasore: " << invaderColumn << endl;
                }
            }
            return;
        }

        if(defenderRow == -1){  //controllo che sia dentro la mappa
            if(territory.isEarth()){  //controllo acqua
                if(vectHouses[0] != territory.getArmy()->getName()[0]){  //controllo che non sia territorio invader
                    if(abs(i-invaderRow) <= 1 && abs(j-invaderColumn) <= 1) //controllo confinanti
                    {
                        defenderRow = i;
                        defenderColumn = j;
                        // eventualmente mostro qualcosa graficamente
                        cout << "Riga difensore: " << defenderRow << ", Colonna difensore: " << defenderColumn << endl;
                    }
                }
            }
            return;
        }



        break;
    case Qt::RightButton:
        cout << "Premuto clic dx" << endl;
    }
}

void PlayWindow::setHouse(string nameHouse)
{
    for(int i = 0; i<numCasate; i++){
        if(vectHouses[i] == nameHouse[0]){
            vectHouses[i] = vectHouses[0];
            vectHouses[0] = nameHouse[0];
            break;
        }
    }
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
