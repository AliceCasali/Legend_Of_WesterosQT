#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QDialog>
#include <string>

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

private slots:
    void on_back_clicked();

    void on_targaryen_clicked();

    void on_stark_clicked();

    void on_greyjoy_clicked();

    void on_lannister_clicked();

    void on_whitewalkers_clicked();

    void on_baratheon_clicked();

private:
    Ui::ChooseWindow *ui;
    void startGame(string nameHouse);
};

#endif // CHOOSEWINDOW_H
