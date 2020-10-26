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
    void show_win_pcent(int i_player, float num_pcent);
    void show_tied_pcent(int i_player, int num_pcent);
    void create_game(int num_players);
    ~MainWindow();

private slots:
    void calculate_ranges();
    void put_card_on_board(QString act_card);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
