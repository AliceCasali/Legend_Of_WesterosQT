#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QDialog>
#include <string>
#include <QMediaPlayer>

using namespace std;

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = 0);
    ~ChooseWindow();
    void paintEvent(QPaintEvent *) override;
    void setMusic(QMediaPlayer *music);

private slots:
    void on_exit_clicked();

    void on_btnTargaryen_clicked();

    void on_btnStark_clicked();

    void on_btnLannister_clicked();

    void on_btnWhiteWalkers_clicked();

    void on_btnBaratheon_clicked();

    void on_btnGreyjoy_clicked();


private:
    void startGame(string nameHouse);

    Ui::ChooseWindow *ui;
    QPixmap barriera;
    QPixmap baratheon;
    QPixmap greyjoy;
    QPixmap lannister;
    QPixmap stark;
    QPixmap targaryen;
    QPixmap whitewalkers;

    QMediaPlayer *music;
};

#endif // CHOOSEWINDOW_H
