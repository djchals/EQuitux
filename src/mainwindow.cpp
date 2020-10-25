#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boards.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    srand (time(NULL));
    init_vars();
    ui->setupUi(this);
    connect(ui->button_calculate,SIGNAL(clicked(bool)),this,SLOT(calculate_ranges()));
    connect(ui->button_clear_0, &QPushButton::clicked,[&](){
        ui->board_0->clear();
        ui->board_1->clear();
        ui->board_2->clear();
        ui->board_3->clear();
        ui->board_4->clear();
    });
    connect(ui->button_clear_1, &QPushButton::clicked,[&](){ ui->range_1->clear(); });
    connect(ui->button_clear_2, &QPushButton::clicked,[&](){ ui->range_2->clear(); });
    connect(ui->button_clear_3, &QPushButton::clicked,[&](){ ui->range_3->clear(); });
    connect(ui->button_clear_4, &QPushButton::clicked,[&](){ ui->range_4->clear(); });
    connect(ui->button_clear_5, &QPushButton::clicked,[&](){ ui->range_5->clear(); });
    connect(ui->button_clear_6, &QPushButton::clicked,[&](){ ui->range_6->clear(); });

//  connect(ui->button_clear_6,SIGNAL(clicked(bool)),this,SLOT(clear_range(ui->button_clear_0)));

}
MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::calculate_ranges(){
    tot_combos=0;
    memset(tot_win_pos,0,sizeof(long double)*6);
    memset(tot_tied_pos,0,sizeof(long double)*6);
    tie=0;
    tot_tie=0;

    qDebug() << "dentro calculate ranges";
    int i=0;
    if(!ui->range_1->text().isEmpty()){
        strcpy(range_pkr[i],ui->range_1->text().toStdString().c_str());
        arr_pos_pcent[i]=1;
        ++i;
    }
    if(!ui->range_2->text().isEmpty()){
        strcpy(range_pkr[i],ui->range_2->text().toStdString().c_str());
        arr_pos_pcent[i]=2;
        ++i;
    }
    if(!ui->range_3->text().isEmpty()){
        strcpy(range_pkr[i],ui->range_3->text().toStdString().c_str());
        arr_pos_pcent[i]=3;
        ++i;
    }
    if(!ui->range_4->text().isEmpty()){
        strcpy(range_pkr[i],ui->range_4->text().toStdString().c_str());
        arr_pos_pcent[i]=4;
        ++i;
    }
    if(!ui->range_5->text().isEmpty()){
        strcpy(range_pkr[i],ui->range_5->text().toStdString().c_str());
        arr_pos_pcent[i]=5;
        ++i;
    }
    if(!ui->range_6->text().isEmpty()){
        strcpy(range_pkr[i],ui->range_6->text().toStdString().c_str());
        arr_pos_pcent[i]=6;
        ++i;
    }
    if(i>=2 && (!ui->board_0->text().isEmpty() && !ui->board_1->text().isEmpty() && !ui->board_2->text().isEmpty())){
        //have flop
        board[0]=arr_suit_to_int[ui->board_0->text().toStdString().at(1)];
        board[1]=arr_let_to_int[ui->board_0->text().toStdString().at(0)];
        board[2]=arr_suit_to_int[ui->board_1->text().toStdString().at(1)];
        board[3]=arr_let_to_int[ui->board_1->text().toStdString().at(0)];
        board[4]=arr_suit_to_int[ui->board_2->text().toStdString().at(1)];
        board[5]=arr_let_to_int[ui->board_2->text().toStdString().at(0)];

        if(!ui->board_3->text().isEmpty()){
            board[6]=arr_suit_to_int[ui->board_3->text().toStdString().at(1)];
            board[7]=arr_let_to_int[ui->board_3->text().toStdString().at(0)];
        }
        if(!ui->board_4->text().isEmpty()){
            board[8]=arr_suit_to_int[ui->board_4->text().toStdString().at(1)];
            board[9]=arr_let_to_int[ui->board_4->text().toStdString().at(0)];
        }
        this->create_game(i);
    }else if(i>=2 && (ui->board_0->text().isEmpty() && ui->board_1->text().isEmpty() && ui->board_2->text().isEmpty() && ui->board_3->text().isEmpty() && ui->board_4->text().isEmpty())){
        this->create_game(i);
    }
}
void MainWindow::create_game(int num_players){
    int i=0,i_player=0;
    int j,k;

    if(board[1]!=0){
        for(i_player=0;i_player<num_players;++i_player){
            if(range_pkr[i_player]){
                //the result of this function will be saved in arr_hex_return
                conv_range_pkr_to_hex(range_pkr[i_player],i_player);
                if(long_hex_pos[i_player]>0){
                    calculate_EQ(i_player);
                }
            }
        }
        calculate_all(num_players,1);
        for(j=0;j<num_players;j++){
           this->show_win_pcent(j,tot_win_pcent[j]);
        }
        for(j=0;j<num_players;j++){
           this->show_tied_pcent(j,tot_tied_pcent[j]);
        }
    }else{
        for(i=0;i<10000;i++){
            create_preflop(NUM_HANDS_PREFLOP);
            for(i_player=0;i_player<num_players;++i_player){
                if(range_pkr[i_player]){
                    //the result of this function will be saved in arr_hex_return
                    conv_range_pkr_to_hex(range_pkr[i_player],i_player);
                    if(long_hex_pos[i_player]>0){
                        calculate_EQ(i_player);
                    }
                }
            }
            calculate_all(num_players,0);
            for(j=0;j<num_players;j++){
                this->show_win_pcent(j,tot_win_pcent[j]);
            }
            for(j=0;j<num_players;j++){
                this->show_tied_pcent(j,tot_tied_pcent[j]);
            }
        }
    }
}

void MainWindow::show_win_pcent(int i_player, float num_pcent){
    int act_i_player=arr_pos_pcent[i_player];
    qDebug() << "dentro win" << act_i_player;
    switch(act_i_player){
        case 1:ui->win_1->display(num_pcent);break;
        case 2:ui->win_2->display(num_pcent);break;
        case 3:ui->win_3->display(num_pcent);break;
        case 4:ui->win_4->display(num_pcent);break;
        case 5:ui->win_5->display(num_pcent);break;
        case 6:ui->win_6->display(num_pcent);break;
    }
}
void MainWindow::show_tied_pcent(int i_player, int num_pcent){
    int act_i_player=arr_pos_pcent[i_player];
    qDebug() << "dentro pcent"<< act_i_player;
    switch(act_i_player){
//        case 1:ui->tie_1->display(num_pcent);break;
//        case 2:ui->tie_2->display(num_pcent);break;
//        case 3:ui->tie_3->display(num_pcent);break;
//        case 4:ui->tie_4->display(num_pcent);break;
//        case 5:ui->tie_5->display(num_pcent);break;
//        case 6:ui->tie_6->display(num_pcent);break;
    }
}

void MainWindow::clear_range(int i_player){
    qDebug() << "dentro clear";
    qDebug() << "enviador";
//    switch(i_range){
//        case 0:
//            ui->board_0->text().clear();
//            ui->board_1->text().clear();
//            ui->board_2->text().clear();
//            ui->board_3->text().clear();
//            ui->board_4->text().clear();
//        break;
//        case 1:ui->range_1->text().clear();break;
//        case 2:ui->range_2->text().clear();break;
//        case 3:ui->range_3->text().clear();break;
//        case 4:ui->range_4->text().clear();break;
//        case 5:ui->range_5->text().clear();break;
//        case 6:ui->range_6->text().clear();break;
//    }
}
