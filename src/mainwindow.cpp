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
    connect(ui->button_clear_1, &QPushButton::clicked,[&](){
        ui->range_1->clear();
        ui->win_1->display(0);
    });
    connect(ui->button_clear_2, &QPushButton::clicked,[&](){
        ui->range_2->clear();
        ui->win_2->display(0);
    });
    connect(ui->button_clear_3, &QPushButton::clicked,[&](){
        ui->range_3->clear();
        ui->win_3->display(0);
    });
    connect(ui->button_clear_4, &QPushButton::clicked,[&](){
        ui->range_4->clear();
        ui->win_4->display(0);
    });
    connect(ui->button_clear_5, &QPushButton::clicked,[&](){
        ui->range_5->clear();
        ui->win_5->display(0);
    });
    connect(ui->button_clear_6, &QPushButton::clicked,[&](){
        ui->range_6->clear();
        ui->win_6->display(0);
    });
    connect(ui->card_02, &QPushButton::clicked,[&](){put_card_on_board("2h");});
    connect(ui->card_03, &QPushButton::clicked,[&](){put_card_on_board("3h");});
    connect(ui->card_04, &QPushButton::clicked,[&](){put_card_on_board("4h");});
    connect(ui->card_05, &QPushButton::clicked,[&](){put_card_on_board("5h");});
    connect(ui->card_06, &QPushButton::clicked,[&](){put_card_on_board("6h");});
    connect(ui->card_07, &QPushButton::clicked,[&](){put_card_on_board("7h");});
    connect(ui->card_08, &QPushButton::clicked,[&](){put_card_on_board("8h");});
    connect(ui->card_09, &QPushButton::clicked,[&](){put_card_on_board("9h");});
    connect(ui->card_0a, &QPushButton::clicked,[&](){put_card_on_board("Th");});
    connect(ui->card_0b, &QPushButton::clicked,[&](){put_card_on_board("Jh");});
    connect(ui->card_0c, &QPushButton::clicked,[&](){put_card_on_board("Qh");});
    connect(ui->card_0d, &QPushButton::clicked,[&](){put_card_on_board("Kh");});
    connect(ui->card_0e, &QPushButton::clicked,[&](){put_card_on_board("Ah");});

    connect(ui->card_12, &QPushButton::clicked,[&](){put_card_on_board("2d");});
    connect(ui->card_13, &QPushButton::clicked,[&](){put_card_on_board("3d");});
    connect(ui->card_14, &QPushButton::clicked,[&](){put_card_on_board("4d");});
    connect(ui->card_15, &QPushButton::clicked,[&](){put_card_on_board("5d");});
    connect(ui->card_16, &QPushButton::clicked,[&](){put_card_on_board("6d");});
    connect(ui->card_17, &QPushButton::clicked,[&](){put_card_on_board("7d");});
    connect(ui->card_18, &QPushButton::clicked,[&](){put_card_on_board("8d");});
    connect(ui->card_19, &QPushButton::clicked,[&](){put_card_on_board("9d");});
    connect(ui->card_1a, &QPushButton::clicked,[&](){put_card_on_board("Td");});
    connect(ui->card_1b, &QPushButton::clicked,[&](){put_card_on_board("Jd");});
    connect(ui->card_1c, &QPushButton::clicked,[&](){put_card_on_board("Qd");});
    connect(ui->card_1d, &QPushButton::clicked,[&](){put_card_on_board("Kd");});
    connect(ui->card_1e, &QPushButton::clicked,[&](){put_card_on_board("Ad");});

    connect(ui->card_22, &QPushButton::clicked,[&](){put_card_on_board("2s");});
    connect(ui->card_23, &QPushButton::clicked,[&](){put_card_on_board("3s");});
    connect(ui->card_24, &QPushButton::clicked,[&](){put_card_on_board("4s");});
    connect(ui->card_25, &QPushButton::clicked,[&](){put_card_on_board("5s");});
    connect(ui->card_26, &QPushButton::clicked,[&](){put_card_on_board("6s");});
    connect(ui->card_27, &QPushButton::clicked,[&](){put_card_on_board("7s");});
    connect(ui->card_28, &QPushButton::clicked,[&](){put_card_on_board("8s");});
    connect(ui->card_29, &QPushButton::clicked,[&](){put_card_on_board("9s");});
    connect(ui->card_2a, &QPushButton::clicked,[&](){put_card_on_board("Ts");});
    connect(ui->card_2b, &QPushButton::clicked,[&](){put_card_on_board("Js");});
    connect(ui->card_2c, &QPushButton::clicked,[&](){put_card_on_board("Qs");});
    connect(ui->card_2d, &QPushButton::clicked,[&](){put_card_on_board("Ks");});
    connect(ui->card_2e, &QPushButton::clicked,[&](){put_card_on_board("As");});

    connect(ui->card_32, &QPushButton::clicked,[&](){put_card_on_board("2c");});
    connect(ui->card_33, &QPushButton::clicked,[&](){put_card_on_board("3c");});
    connect(ui->card_34, &QPushButton::clicked,[&](){put_card_on_board("4c");});
    connect(ui->card_35, &QPushButton::clicked,[&](){put_card_on_board("5c");});
    connect(ui->card_36, &QPushButton::clicked,[&](){put_card_on_board("6c");});
    connect(ui->card_37, &QPushButton::clicked,[&](){put_card_on_board("7c");});
    connect(ui->card_38, &QPushButton::clicked,[&](){put_card_on_board("8c");});
    connect(ui->card_39, &QPushButton::clicked,[&](){put_card_on_board("9c");});
    connect(ui->card_3a, &QPushButton::clicked,[&](){put_card_on_board("Tc");});
    connect(ui->card_3b, &QPushButton::clicked,[&](){put_card_on_board("Jc");});
    connect(ui->card_3c, &QPushButton::clicked,[&](){put_card_on_board("Qc");});
    connect(ui->card_3d, &QPushButton::clicked,[&](){put_card_on_board("Kc");});
    connect(ui->card_3e, &QPushButton::clicked,[&](){put_card_on_board("Ac");});

}

MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::put_card_on_board(QString act_card){
    if(act_card==ui->board_0->text() || act_card==ui->board_1->text() || act_card==ui->board_2->text() || act_card==ui->board_3->text() || act_card==ui->board_4->text()){
        return;//exit here because we cannot repeat the card
    }

    if(ui->board_0->text().isEmpty()){
        ui->board_0->setText(act_card);
        return;
    }
    if(ui->board_1->text().isEmpty()){
        ui->board_1->setText(act_card);
        return;
    }
    if(ui->board_2->text().isEmpty()){
        ui->board_2->setText(act_card);
        return;
    }
    if(ui->board_3->text().isEmpty()){
       ui->board_3->setText(act_card);
       return;
    }
    if(ui->board_4->text().isEmpty()){
       ui->board_4->setText(act_card);
       return;
    }
    qDebug()<<act_card;
}
void MainWindow::calculate_ranges(){
    tot_combos=0;
    memset(tot_win_pos,0,sizeof(long double)*6);
    memset(tot_tied_pos,0,sizeof(long double)*6);
    tie=0;
    tot_tie=0;

    ui->win_1->display(0);
    ui->win_2->display(0);
    ui->win_3->display(0);
    ui->win_4->display(0);
    ui->win_5->display(0);
    ui->win_6->display(0);

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
        //in the future put a button for stop and put i higher, maybe i=10000
        for(i=0;i<100;i++){
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
//    qDebug() << "dentro pcent"<< act_i_player;
    switch(act_i_player){
//        case 1:ui->tie_1->display(num_pcent);break;
//        case 2:ui->tie_2->display(num_pcent);break;
//        case 3:ui->tie_3->display(num_pcent);break;
//        case 4:ui->tie_4->display(num_pcent);break;
//        case 5:ui->tie_5->display(num_pcent);break;
//        case 6:ui->tie_6->display(num_pcent);break;
    }
}

