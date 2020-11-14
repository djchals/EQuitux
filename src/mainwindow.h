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
    ~MainWindow();
    void calculate_beginning();
    void calculate_ranges();
    void calculate_stop();
    void setAllEnabled(bool flag_enable);


private slots:
    void put_card_on_board(QString act_card);
    void remove_card_from_board(QString act_text);

private:
    void clearAll();
    void clearVars();
    Ui::MainWindow *ui;
    ThreadCalculate *mThread;
};

#endif // MAINWINDOW_H
