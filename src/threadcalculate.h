#ifndef THREADCALCULATE_H
#define THREADCALCULATE_H

#include <QThread>

//include from header.h
//extern board
//extern range_pkr;
//extern long_hex_pos
//extern calculate_EQ
//extern calculate_all
//extern tot_win_pcent;
//extern range_pkr


extern int board[10];
extern char range_pkr[6][3700];
extern int long_hex_pos[6];
extern void calculate_EQ(int i_player);
extern void create_preflop(int num_hands);
extern void create_board();
extern void conv_range_pkr_to_hex(char tmp_range[],int i_player);
extern void calculate_all(int num_players,int restart_vars);
extern float tot_win_pcent[6];


class ThreadCalculate : public QThread
{
    Q_OBJECT
public:
    explicit ThreadCalculate(QObject *parent = nullptr);
    int num_players=0;
    void setStopProcess(bool flag);

signals:
    void show_win_pcent(int i_player, float num_pcent);
protected:
    void run();
private:
    bool flag_stop_process;
};

#endif // THREADCALCULATE_H
