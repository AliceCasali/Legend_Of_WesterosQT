#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ChooseWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked() //per passare da schermataplay a schermatachoose
{
    ChooseWindow addView;
    close();
    addView.exec();
}

void MainWindow::on_quit_clicked()
{
   close();
}