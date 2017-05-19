#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void paintEvent(QPaintEvent *) override;

private slots:
    void on_play_clicked();

    void on_quit_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap mainbkgnd;
};

#endif // MAINWINDOW_H
