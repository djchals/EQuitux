#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//import from header.h
extern char arr_int_to_let[15];
extern int arr_let_to_int[85];
extern int arr_suit_to_int[116];
extern char arr_int_to_suit[4];

namespace Ui {
    class MainWindow;
}

class ThreadCalculate;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//    void show_win_pcent(int i_player, float num_pcent);
//    void show_tied_pcent(int i_player, int num_pcent);
//    void create_game(int num_players);
    ~MainWindow();
    void calculate_beginning();
    void calculate_ranges();
    void calculate_stop();
    void setAllEnabled(bool flag_enable);


private slots:
//    void stop_calculate();
    void put_card_on_board(QString act_card);
    void remove_card_from_board(QString act_text);
//    void on_button_calculate_toggled(bool checked);

private:
    void clearAll();
    void clearVars();
    Ui::MainWindow *ui;
    ThreadCalculate *mThread;
//    bool flag_stop_calculate=true;
};

#endif // MAINWINDOW_H
