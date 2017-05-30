#include <QString>
#include <QMouseEvent>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <math.h>

#include "PlayWindow.h"
#include "ui_playwindow.h"
#include "ChooseWindow.h"
#include "ui_choosewindow.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::PlayWindow), bkgnd("img/westeros.jpg"), westeros("img/westeros.jpg"), baratheon("img/baratheon.png"),
    greyjoy("img/greyjoy.png"), lannister("img/lannister.png"), stark("img/stark.png"),
    targaryen("img/targaryen.png"), whitewalkers("img/whitewalkers.png"), crown("img/crown.png"), cross("img/cross.png"), tic("img/tic.png"),
    invaderRow(-1), invaderColumn(-1), defenderRow(-1), defenderColumn(-1)
{
    ui->setupUi(this);
    ui->labelStark_2->setPixmap(stark.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labelStark_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labelBaratheon_2->setPixmap(baratheon.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labelBaratheon_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labelGreyjoy_2->setPixmap(greyjoy.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labelGreyjoy_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labelLannister_2->setPixmap(lannister.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labelLannister_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labelTargaryen_2->setPixmap(targaryen.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labelTargaryen_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labelWhiteWalkers_2->setPixmap(whitewalkers.scaled(100, 100, Qt::KeepAspectRatio));
    ui->labelWhiteWalkers_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->labelLegend->setText("<html><head/><body><p><b>Legend:<b></p><body></html>");

    ui->labelCrown->setPixmap(crown.scaled(30, 30, Qt::KeepAspectRatio));
    ui->labelCrown_2->setText("your house");

    ui->labelTic->setPixmap(tic.scaled(25, 25, Qt::KeepAspectRatio));
    ui->labelTic_2->setText("enemies you can attack");

    ui->labelCross->setPixmap(cross.scaled(25, 25, Qt::KeepAspectRatio));
    ui->labelCross_2->setText("enemies you can't attack");


    srand(time(NULL)); //da chiamare una volta quando tirerò a caso i numeri con la rand
                           //serve con la rand, la chiamo una volta sola nel main
    //assegno una strategy casuale ad ogni casata
    Baratheon::strategy = Army::randomStrategy();
    Greyjoy::strategy = Army::randomStrategy();
    Lannister::strategy = Army::randomStrategy();
    Stark::strategy = Army::randomStrategy();
    Targaryen::strategy = Army::randomStrategy();
    WhiteWalkers::strategy = Army::randomStrategy();

    vectHouses.push_back('B');
    vectHouses.push_back('G');
    vectHouses.push_back('L');
    vectHouses.push_back('S');
    vectHouses.push_back('T');
    vectHouses.push_back('W');

    refreshLabels();

    ui->attacca->setEnabled(false);

    //ui->bac
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

    if(invaderRow != -1){
        if(vectHouses[0] == mappa.readTerritory(invaderRow, invaderColumn).getArmy()->getName()[0]){
            painter.drawPixmap(invaderColumn * w + w*107/500, invaderRow * h, w*286/500, h*176/500, crown);
            for(int i = invaderRow - 1; i < invaderRow + 2; i++){
                for(int j = invaderColumn - 1; j < invaderColumn + 2; j++){
                    if(i >= 0 && i < mappa.getNumRows() && j >= 0 && j < mappa.getNumColumns() &&
                            mappa.readTerritory(i, j).isEarth() && vectHouses[0] != mappa.readTerritory(i, j).getArmy()->getName()[0])
                        painter.drawPixmap(j * w, i * h, w * 2/5, h * 2/5, tic);
                }
            }
        } else {
            painter.drawPixmap(invaderColumn * w, invaderRow * h, w * 2/5, h * 2/5, cross);

        }
    }

    ui->vistaMappa->setPixmap(bkgnd);
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

    if(!territory.isEarth())
        return;
    if(invaderRow == -1 || vectHouses[0] == territory.getArmy()->getName()[0] ||
        abs(i - invaderRow) > 1 || abs(j - invaderColumn) > 1 ||
        vectHouses[0] != mappa.readTerritory(invaderRow, invaderColumn).getArmy()->getName()[0] ){
        invaderRow = i;
        invaderColumn = j;
        defenderRow = -1;
        defenderColumn = -1;
        ui->attacca->setEnabled(false);
        // eventualmente mostro qualcosa graficamente
        cout << "Riga invasore: " << invaderRow << ", Colonna invasore: " << invaderColumn << endl;
    }

    else {
        defenderRow = i;
        defenderColumn = j;
        ui->attacca->setEnabled(true);
        // eventualmente mostro qualcosa graficamente
        cout << "Riga difensore: " << defenderRow << ", Colonna difensore: " << defenderColumn << endl;
    }

    ui->labelName->setText("<html><head/><body><b>" + QString::fromStdString(territory.getArmy()->getName()) + "</b></body></html>");
    ui->labelSimple->setText("<html><head/><body><p>Simple Troops: " + QString::number(territory.getArmy()->getNumSimpleTroops()) + "</p></body></html> ");
    ui->labelMagic->setText("<html><head/><body><p>Magic Troops: " + QString::number(territory.getArmy()->getNumMagicTroops()) + "</p></body></html> ");

    float strength;
    if(territory.getArmy()->getName()[0] == vectHouses[0])
        strength = mappa.calculateStrength(i, j, true);
    else
        strength = mappa.calculateStrength(i, j, false);

    ui->labelPower->setText("<html><head/><body><p>Army Power: " + QString::number(strength) + "</p></body></html> ");
}

void PlayWindow::setHouse(string nameHouse)
{
    for(int i = 0; i<vectHouses.size(); i++){
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
    ui->attacca->setEnabled(false);
    mappa.show();
    bool esito;
    QString opponentName = QString::fromStdString(mappa.readTerritory(defenderRow, defenderColumn).getArmy()->getName());
    mappa.conquer(invaderRow, invaderColumn, defenderRow, defenderColumn, esito);
    QString resoconto("You ");
    if(esito)
        resoconto += "won ";
    else
        resoconto += "lost ";
    resoconto += QString("against the troops " + opponentName + ".");

    //inserisco in un vettore gli eserciti ancora presenti tra i nemici
    for(int k = 1; k < vectHouses.size(); k++){
        vector<QPoint> invaderEnemyArmies;
        for(int i = 0; i < mappa.getNumRows(); i++){
            for(int j = 0; j < mappa.getNumColumns(); j++){
                if(mappa.readTerritory(i, j).isEarth() && vectHouses[k] == mappa.readTerritory(i, j).getArmy()->getName()[0] && mappa.hasEnemies(i, j)){
                    invaderEnemyArmies.push_back(QPoint(j, i));
                }
            }
        }

        //se il vettore delle armate dello stesso tipo è vuoto allora casata k ha perso e non può attaccare, si continua il ciclo
        if(invaderEnemyArmies.size() == 0){
            continue;
        }

        //inizializzo i turni random dei nemici
        int randomInvader;
        randomInvader = rand() % invaderEnemyArmies.size();
        QPoint pi = invaderEnemyArmies[randomInvader];

        //funzione che raccoglie in un vettore le truppe confinanti dell'invader (pc)
        vector<QPoint> defenderEnemyArmies;
        for(int i = pi.y() - 1; i <= pi.y() + 1; i++){
            for(int j = pi.x() - 1; j <= pi.x() + 1; j++){
                if(i >= 0 && i < mappa.getNumRows() && j >= 0 && j < mappa.getNumColumns() &&
                        mappa.readTerritory(i, j).isEarth() && vectHouses[k] != mappa.readTerritory(i, j).getArmy()->getName()[0]){
                    defenderEnemyArmies.push_back(QPoint(j, i));
                }
            }
        }

        //controllo fine turni
        int randomDefender;
        randomDefender = rand() % defenderEnemyArmies.size();
        QPoint pd = defenderEnemyArmies[randomDefender];
        opponentName = QString::fromStdString(mappa.readTerritory(pi.y(), pi.x()).getArmy()->getName());
        mappa.conquer(pi.y(), pi.x(), pd.y(), pd.x(), esito);
        if(mappa.readTerritory(pd.y(), pd.x()).getArmy()->getName()[0] == vectHouses[0]){
            resoconto += QString("\nYou have been attacked from the troops of " + opponentName + " and you ");
            if(!esito)
                resoconto += "won.";
            else
                resoconto += "lost.";
        }

    }
    refreshLabels();
    invaderRow = -1;
    invaderColumn = -1;
    defenderRow = -1;
    defenderColumn = -1;

    // qui controllo sconfitta giocatore
    bool isAlive = false;
    bool enemyAlive = false;
    for(int i = 0; i < mappa.getNumRows(); i++){
        for(int j = 0; j < mappa.getNumColumns(); j++){
            if(mappa.readTerritory(i, j).isEarth()){
                if(mappa.readTerritory(i, j).getArmy()->getName()[0] == vectHouses[0]){
                    // non ho perso
                    isAlive = true;
                } else {
                    //non ho vinto
                    enemyAlive = true;
                }
            }
        }
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle("Game is Over");

    if(!enemyAlive){
        //Il giocatore ha vinto
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setText("You win! Do you want to restart a new battle?");
        if(msgBox.exec() == QMessageBox::Yes){
            ChooseWindow addView;
            close();
            addView.exec();

        } else{
            close();
        } return;
    } else if(!isAlive){
        //Il giocatore ha perso
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setText("You lost! Do you want to restart a new battle?");
        if(msgBox.exec() == QMessageBox::Yes){
            ChooseWindow addView;
            close();
            addView.exec();

        } else{
            close();
        }return;
    }

    //resoconto attacchi
    msgBox.setWindowTitle("Turns report");
    msgBox.addButton(QMessageBox::Ok);
    msgBox.setText(resoconto);
    msgBox.exec();
}

void PlayWindow::refreshLabels()
{
    int numMagic;
    int numSimple;

    mappa.countTroops("Baratheon", numMagic, numSimple);
    ui->labelBaratheon->setText("<html><head/><body><p><b>Baratheon:<b></p><p>Simple " +
                                QString::number(numSimple) + ", Magic " + QString::number(numMagic) + "</p></body></html> ");

    mappa.countTroops("Greyjoy", numMagic, numSimple);
    ui->labelGreyjoy->setText("<html><head/><body><p><b>Greyjoy:<b></p><p>Simple " +
                                QString::number(numSimple) + ", Magic " + QString::number(numMagic) + "</p></body></html> ");

    mappa.countTroops("Lannister", numMagic, numSimple);
    ui->labelLannister->setText("<html><head/><body><p><b>Lannister:<b></p><p>Simple " +
                                QString::number(numSimple) + ", Magic " + QString::number(numMagic) + "</p></body></html> ");

    mappa.countTroops("Stark", numMagic, numSimple);
    ui->labelStark->setText("<html><head/><body><p><b>Stark:<b></p><p>Simple " +
                                QString::number(numSimple) + ", Magic " + QString::number(numMagic) + "</p></body></html> ");

    mappa.countTroops("Targaryen", numMagic, numSimple);
    ui->labelTargaryen->setText("<html><head/><body><p><b>Targaryen:<b></p><p>Simple " +
                                QString::number(numSimple) + ", Magic " + QString::number(numMagic) + "</p></body></html> ");

    mappa.countTroops("WhiteWalkers", numMagic, numSimple);
    ui->labelWhiteWalkers->setText("<html><head/><body><p><b>WhiteWalkers:<b></p><p>Simple " +
                                QString::number(numSimple) + ", Magic " + QString::number(numMagic) + "</p></body></html> ");



}
