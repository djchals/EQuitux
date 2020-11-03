#include "boards.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "winselectrange.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    srand (time(NULL));
    init_vars();
    ui->setupUi(this);
    connect(ui->button_calculate,SIGNAL(clicked(bool)),this,SLOT(calculate_ranges()));
    connect(ui->button_clear_0, &QPushButton::clicked,[&](){
        ui->board_0->setText("");
        ui->board_1->setText("");
        ui->board_2->setText("");
        ui->board_3->setText("");
        ui->board_4->setText("");
    });
    connect(ui->button_clear_1, &QPushButton::clicked,[&](){
        ui->range_1->setText("");
        ui->win_1->display(0);
    });
    connect(ui->button_clear_2, &QPushButton::clicked,[&](){
        ui->range_2->setText("");
        ui->win_2->display(0);
    });
    connect(ui->button_clear_3, &QPushButton::clicked,[&](){
        ui->range_3->setText("");
        ui->win_3->display(0);
    });
    connect(ui->button_clear_4, &QPushButton::clicked,[&](){
        ui->range_4->setText("");
        ui->win_4->display(0);
    });
    connect(ui->button_clear_5, &QPushButton::clicked,[&](){
        ui->range_5->setText("");
        ui->win_5->display(0);
    });
    connect(ui->button_clear_6, &QPushButton::clicked,[&](){
        ui->range_6->setText("");
        ui->win_6->display(0);
    });

    connect(ui->card_02, &QPushButton::clicked,[&](){put_card_on_board(ui->card_02->objectName());});
    connect(ui->card_03, &QPushButton::clicked,[&](){put_card_on_board(ui->card_03->objectName());});
    connect(ui->card_04, &QPushButton::clicked,[&](){put_card_on_board(ui->card_04->objectName());});
    connect(ui->card_05, &QPushButton::clicked,[&](){put_card_on_board(ui->card_05->objectName());});
    connect(ui->card_06, &QPushButton::clicked,[&](){put_card_on_board(ui->card_06->objectName());});
    connect(ui->card_07, &QPushButton::clicked,[&](){put_card_on_board(ui->card_07->objectName());});
    connect(ui->card_08, &QPushButton::clicked,[&](){put_card_on_board(ui->card_08->objectName());});
    connect(ui->card_09, &QPushButton::clicked,[&](){put_card_on_board(ui->card_09->objectName());});
    connect(ui->card_0a, &QPushButton::clicked,[&](){put_card_on_board(ui->card_0a->objectName());});
    connect(ui->card_0b, &QPushButton::clicked,[&](){put_card_on_board(ui->card_0b->objectName());});
    connect(ui->card_0c, &QPushButton::clicked,[&](){put_card_on_board(ui->card_0c->objectName());});
    connect(ui->card_0d, &QPushButton::clicked,[&](){put_card_on_board(ui->card_0d->objectName());});
    connect(ui->card_0e, &QPushButton::clicked,[&](){put_card_on_board(ui->card_0e->objectName());});

    connect(ui->card_12, &QPushButton::clicked,[&](){put_card_on_board(ui->card_12->objectName());});
    connect(ui->card_13, &QPushButton::clicked,[&](){put_card_on_board(ui->card_13->objectName());});
    connect(ui->card_14, &QPushButton::clicked,[&](){put_card_on_board(ui->card_14->objectName());});
    connect(ui->card_15, &QPushButton::clicked,[&](){put_card_on_board(ui->card_15->objectName());});
    connect(ui->card_16, &QPushButton::clicked,[&](){put_card_on_board(ui->card_16->objectName());});
    connect(ui->card_17, &QPushButton::clicked,[&](){put_card_on_board(ui->card_17->objectName());});
    connect(ui->card_18, &QPushButton::clicked,[&](){put_card_on_board(ui->card_18->objectName());});
    connect(ui->card_19, &QPushButton::clicked,[&](){put_card_on_board(ui->card_19->objectName());});
    connect(ui->card_1a, &QPushButton::clicked,[&](){put_card_on_board(ui->card_1a->objectName());});
    connect(ui->card_1b, &QPushButton::clicked,[&](){put_card_on_board(ui->card_1b->objectName());});
    connect(ui->card_1c, &QPushButton::clicked,[&](){put_card_on_board(ui->card_1c->objectName());});
    connect(ui->card_1d, &QPushButton::clicked,[&](){put_card_on_board(ui->card_1d->objectName());});
    connect(ui->card_1e, &QPushButton::clicked,[&](){put_card_on_board(ui->card_1e->objectName());});

    connect(ui->card_22, &QPushButton::clicked,[&](){put_card_on_board(ui->card_22->objectName());});
    connect(ui->card_23, &QPushButton::clicked,[&](){put_card_on_board(ui->card_23->objectName());});
    connect(ui->card_24, &QPushButton::clicked,[&](){put_card_on_board(ui->card_24->objectName());});
    connect(ui->card_25, &QPushButton::clicked,[&](){put_card_on_board(ui->card_25->objectName());});
    connect(ui->card_26, &QPushButton::clicked,[&](){put_card_on_board(ui->card_26->objectName());});
    connect(ui->card_27, &QPushButton::clicked,[&](){put_card_on_board(ui->card_27->objectName());});
    connect(ui->card_28, &QPushButton::clicked,[&](){put_card_on_board(ui->card_28->objectName());});
    connect(ui->card_29, &QPushButton::clicked,[&](){put_card_on_board(ui->card_29->objectName());});
    connect(ui->card_2a, &QPushButton::clicked,[&](){put_card_on_board(ui->card_2a->objectName());});
    connect(ui->card_2b, &QPushButton::clicked,[&](){put_card_on_board(ui->card_2b->objectName());});
    connect(ui->card_2c, &QPushButton::clicked,[&](){put_card_on_board(ui->card_2c->objectName());});
    connect(ui->card_2d, &QPushButton::clicked,[&](){put_card_on_board(ui->card_2d->objectName());});
    connect(ui->card_2e, &QPushButton::clicked,[&](){put_card_on_board(ui->card_2e->objectName());});

    connect(ui->card_32, &QPushButton::clicked,[&](){put_card_on_board(ui->card_32->objectName());});
    connect(ui->card_33, &QPushButton::clicked,[&](){put_card_on_board(ui->card_33->objectName());});
    connect(ui->card_34, &QPushButton::clicked,[&](){put_card_on_board(ui->card_34->objectName());});
    connect(ui->card_35, &QPushButton::clicked,[&](){put_card_on_board(ui->card_35->objectName());});
    connect(ui->card_36, &QPushButton::clicked,[&](){put_card_on_board(ui->card_36->objectName());});
    connect(ui->card_37, &QPushButton::clicked,[&](){put_card_on_board(ui->card_37->objectName());});
    connect(ui->card_38, &QPushButton::clicked,[&](){put_card_on_board(ui->card_38->objectName());});
    connect(ui->card_39, &QPushButton::clicked,[&](){put_card_on_board(ui->card_39->objectName());});
    connect(ui->card_3a, &QPushButton::clicked,[&](){put_card_on_board(ui->card_3a->objectName());});
    connect(ui->card_3b, &QPushButton::clicked,[&](){put_card_on_board(ui->card_3b->objectName());});
    connect(ui->card_3c, &QPushButton::clicked,[&](){put_card_on_board(ui->card_3c->objectName());});
    connect(ui->card_3d, &QPushButton::clicked,[&](){put_card_on_board(ui->card_3d->objectName());});
    connect(ui->card_3e, &QPushButton::clicked,[&](){put_card_on_board(ui->card_3e->objectName());});

    connect(ui->board_0, &QPushButton::clicked,[&](){if(ui->board_0->text()!="") remove_card_from_board(ui->board_0->text());});
    connect(ui->board_1, &QPushButton::clicked,[&](){if(ui->board_1->text()!="") remove_card_from_board(ui->board_1->text());});
    connect(ui->board_2, &QPushButton::clicked,[&](){if(ui->board_2->text()!="") remove_card_from_board(ui->board_2->text());});
    connect(ui->board_3, &QPushButton::clicked,[&](){if(ui->board_3->text()!="") remove_card_from_board(ui->board_3->text());});
    connect(ui->board_4, &QPushButton::clicked,[&](){if(ui->board_4->text()!="") remove_card_from_board(ui->board_4->text());});


    connect(ui->select_range_1, &QPushButton::clicked,[&](){
        WinSelectRange ws;
        ws.setModal(true);
        ws.initRange(ui->range_1->text(), 1);
        ws.setSelectedRange(1);
        ws.exec();
        //ok?
        if(ws.result()){
            ui->range_1->setText(ws.getRange());
        }
    });

    connect(ui->select_range_2, &QPushButton::clicked,[&](){
        WinSelectRange ws;
        ws.setModal(true);
        ws.setSelectedRange(2);
        ws.exec();
        //ok?
        if(ws.result()){
            ui->range_2->setText(ws.getRange());
        }
    });

    connect(ui->select_range_3, &QPushButton::clicked,[&](){
        WinSelectRange ws;
        ws.setModal(true);
        ws.setSelectedRange(3);
        ws.exec();
        //ok?
        if(ws.result()){
            ui->range_3->setText(ws.getRange());
        }
    });


    connect(ui->select_range_4, &QPushButton::clicked,[&](){
        WinSelectRange ws;
        ws.setModal(true);
        ws.setSelectedRange(4);
        ws.exec();
        //ok?
        if(ws.result()){
            ui->range_4->setText(ws.getRange());
        }
    });

    connect(ui->select_range_5, &QPushButton::clicked,[&](){
        WinSelectRange ws;
        ws.setModal(true);
        ws.setSelectedRange(5);
        ws.exec();
        //ok?
        if(ws.result()){
            ui->range_5->setText(ws.getRange());
        }
    });

    connect(ui->select_range_6, &QPushButton::clicked,[&](){
        WinSelectRange ws;
        ws.setModal(true);
        ws.setSelectedRange(6);
        ws.exec();
        //ok?
        if(ws.result()){
            ui->range_6->setText(ws.getRange());
        }
    });

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::remove_card_from_board(QString act_text){
    //now remake act_card to hex format
    QChar tmp[2];
    tmp[0]=(QChar) act_text.at(1);
    tmp[1]=(QChar) act_text.at(0);

    QString str0=tmp[0],str1=tmp[1];

    std::string cadena_std0=str0.toStdString();
    std::string cadena_std1=str1.toStdString();

    int c0=cadena_std0[0];//suit
    int c1=cadena_std1[0];//letter

    QString act_card;
    QTextStream(&act_card) << "card_" <<hex << arr_suit_to_int[c0] << hex <<arr_let_to_int[c1];

    QPushButton *act_button = this->findChild<QPushButton *>(act_card);
    act_button->setChecked(false);

    put_card_on_board(act_card);
}
void MainWindow::put_card_on_board(QString act_card){
    QString tmp[2];
    QString var_card;
    int card[2];
        tmp[0]=(QString) act_card.at(5);
        tmp[1]=(QString) act_card.at(6);
        bool ok;
        card[0]=tmp[0].toInt(&ok,16);//suit
        card[1]=tmp[1].toInt(&ok,16);//card
        var_card=(QString) arr_int_to_let[card[1]]+arr_int_to_suit[card[0]];

    QPushButton *act_button = this->findChild<QPushButton *>(act_card);

    QString arr_card_colors[5];
    arr_card_colors[0]="card_red";
    arr_card_colors[1]="card_blue";
    arr_card_colors[2]="card_black";
    arr_card_colors[3]="card_green";
    arr_card_colors[4]="card_white";

    //start clear
    if(var_card==ui->board_0->text()){
        ui->board_0->setText("");
        ui->board_0->setProperty("class", arr_card_colors[4]);
        ui->board_0->style()->unpolish(ui->board_0);
        ui->board_0->style()->polish(ui->board_0);
        ui->board_0->update();
        return;
    }
    if(var_card==ui->board_1->text()){
        ui->board_1->setText("");
        ui->board_1->setProperty("class", arr_card_colors[4]);
        ui->board_1->style()->unpolish(ui->board_1);
        ui->board_1->style()->polish(ui->board_1);
        ui->board_1->update();
        return;
    }
    if(var_card==ui->board_2->text()){
        ui->board_2->setText("");
        ui->board_2->setProperty("class", arr_card_colors[4]);
        ui->board_2->style()->unpolish(ui->board_2);
        ui->board_2->style()->polish(ui->board_2);
        ui->board_2->update();
        return;
    }
    if(var_card==ui->board_3->text()){
        ui->board_3->setText("");
        ui->board_3->setProperty("class", arr_card_colors[4]);
        ui->board_3->style()->unpolish(ui->board_3);
        ui->board_3->style()->polish(ui->board_3);
        ui->board_3->update();
        return;
    }
    if(var_card==ui->board_4->text()){
        ui->board_4->setText("");
        ui->board_4->setProperty("class", arr_card_colors[4]);
        ui->board_4->style()->unpolish(ui->board_4);
        ui->board_4->style()->polish(ui->board_4);
        ui->board_4->update();
        return;
    }
    //end clear
    if(ui->board_0->text().isEmpty()){
        ui->board_0->setText(var_card);
        ui->board_0->setProperty("class", arr_card_colors[card[0]]);
        ui->board_0->style()->unpolish(ui->board_0);
        ui->board_0->style()->polish(ui->board_0);
        ui->board_0->update();
        return;
    }
    if(ui->board_1->text().isEmpty()){
        ui->board_1->setText(var_card);
        ui->board_1->setProperty("class", arr_card_colors[card[0]]);
        ui->board_1->style()->unpolish(ui->board_1);
        ui->board_1->style()->polish(ui->board_1);
        ui->board_1->update();
        return;
    }
    if(ui->board_2->text().isEmpty()){
        ui->board_2->setText(var_card);
        ui->board_2->setProperty("class", arr_card_colors[card[0]]);
        ui->board_2->style()->unpolish(ui->board_2);
        ui->board_2->style()->polish(ui->board_2);
        ui->board_2->update();
        return;
    }
    if(ui->board_3->text().isEmpty()){
       ui->board_3->setText(var_card);
       ui->board_3->setProperty("class", arr_card_colors[card[0]]);
       ui->board_3->style()->unpolish(ui->board_3);
       ui->board_3->style()->polish(ui->board_3);
       ui->board_3->update();
       return;
    }
    if(ui->board_4->text().isEmpty()){
       ui->board_4->setText(var_card);
       ui->board_4->setProperty("class", arr_card_colors[card[0]]);
       ui->board_4->style()->unpolish(ui->board_4);
       ui->board_4->style()->polish(ui->board_4);
       ui->board_4->update();
       return;
    }
    //if all board is full, and we are trying to insert a new card, simply denied it unchecking the card
    if(!ui->board_0->text().isEmpty() && !ui->board_1->text().isEmpty() && !ui->board_2->text().isEmpty() && !ui->board_3->text().isEmpty() && !ui->board_4->text().isEmpty()){
        act_button->setChecked(false);
    }
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



