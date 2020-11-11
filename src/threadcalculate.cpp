#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "threadcalculate.h"
#include <QDebug>
ThreadCalculate::ThreadCalculate(QObject *parent) : QThread(parent)
{
}

void ThreadCalculate::run(){
    this->setStopProcess(false);
    int i=0,i_player=0;
    int j,k;
    if( //Flop filled, turn empty, river empty
        (board[1]!=0 && board[3]!=0 && board[5]!=0 && board[7]==0 && board[9]==0) ||
         //Flop filled, turn filled, river empty
        (board[1]!=0 && board[3]!=0 && board[5]!=0 && board[7]!=0 && board[9]==0) ||
         //Flop filled, turn filled, river filled
        (board[1]!=0 && board[3]!=0 && board[5]!=0 && board[7]!=0 && board[9]!=0)
    ){
        for(i_player=0;i_player<this->num_players;++i_player){
            if(range_pkr[i_player]){
                //the result of this function will be saved in arr_hex_return
                conv_range_pkr_to_hex(range_pkr[i_player],i_player);
                if(long_hex_pos[i_player]>0){
                    calculate_EQ(i_player);
                }
            }
        }
        calculate_all(this->num_players,1);
        for(j=0;j<this->num_players;j++){
           emit show_win_pcent(j,tot_win_pcent[j]);
        }

//        for(j=0;j<num_players;j++){
//           this->show_tied_pcent(j,tot_tied_pcent[j]);
//        }
    }else if(//Flop empty, turn empty, river empty
        (board[1]==0 && board[3]==0 && board[5]==0 && board[7]==0 && board[9]==0)
    ){
        //preflop
        //in the future put a button for stop and put i higher, maybe i=10000
        for(i=0;i<100000;i++){
            //here put the same number defined in NUM_HANDS_PREFLOP
            create_preflop(100);

            for(i_player=0;i_player<this->num_players;++i_player){
                if(range_pkr[i_player]){
                    //the result of this function will be saved in arr_hex_return
                    conv_range_pkr_to_hex(range_pkr[i_player],i_player);
                    if(long_hex_pos[i_player]>0){
                        calculate_EQ(i_player);
                    }
                }
                if(this->flag_stop_process){
                qDebug() <<"parado 1";
                    break;
                }
            }

            calculate_all(this->num_players,0);
            for(j=0;j<this->num_players;j++){
                emit show_win_pcent(j,tot_win_pcent[j]);
            }
            if(this->flag_stop_process){
                qDebug() <<"parado 2";
                break;
            }
//            for(j=0;j<num_players;j++){
//                emit show_tied_pcent(j,tot_tied_pcent[j]);
//            }
        }
    }
}

void ThreadCalculate::setStopProcess(bool flag){
    this->flag_stop_process=flag;
}
