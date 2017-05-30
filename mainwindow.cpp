#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ChooseWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), mainbkgnd("img/main.jpg")
{
    ui->setupUi(this);
    //aggiunta musica nella mainwindow e choosewindow
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/gotmusic.mp3"));
    music->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//bottone play
void MainWindow::on_play_clicked() //per passare da schermatamain a schermatachoose
{
    ChooseWindow addView;
    addView.setMusic(music);
    close();
    addView.exec();
}

//bottone quit
void MainWindow::on_quit_clicked()
{
   close();
}

void MainWindow::paintEvent(QPaintEvent *)
{

}
