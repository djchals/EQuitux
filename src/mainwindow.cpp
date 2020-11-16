#include "boards.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "winselectrange.h"
#include "threadcalculate.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    srand(time(NULL));
    init_vars();
    ui->setupUi(this);
    this->setWindowTitle("EQuitux");
    mThread=new ThreadCalculate(this);
    connect(mThread,&ThreadCalculate::show_win_pcent,[&](int i_player, float num_pcent){
        int act_i_player=arr_pos_pcent[i_player];
        switch(act_i_player){
            case 1:ui->win_1->display(num_pcent);break;
            case 2:ui->win_2->display(num_pcent);break;
            case 3:ui->win_3->display(num_pcent);break;
            case 4:ui->win_4->display(num_pcent);break;
            case 5:ui->win_5->display(num_pcent);break;
            case 6:ui->win_6->display(num_pcent);break;
            break;
        }
    });
    connect(mThread,&ThreadCalculate::finished,[&](){
       this->calculate_stop();
    });


    connect(ui->button_calculate,&QPushButton::clicked,[&](){
           calculate_ranges();
    });
    connect(ui->button_clear_0, &QPushButton::clicked,[&](){
        for(int i=0;i<5;i++){
            QString tmp_name;
            QTextStream(&tmp_name) << "board_" << i;
            QPushButton *act_button = this->findChild<QPushButton *>(tmp_name);

            if(!act_button->text().isEmpty()){
                QString tmp=act_button->text();
                char cmp0=tmp.at(0).toLatin1();
                char cmp1=tmp.at(1).toLatin1();

                QString var_card;
                QTextStream(&var_card) << "card_" <<hex << arr_suit_to_int[cmp1] << hex <<arr_let_to_int[cmp0];
                QPushButton *act_button = this->findChild<QPushButton *>(var_card);

                put_card_on_board(var_card);
                act_button->setChecked(false);
            }
        }
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
    connect(ui->button_clear_all, &QPushButton::clicked,[&](){
        this->clearAll();
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
        ws.initRange(ui->range_2->text(), 2);
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
        ws.initRange(ui->range_3->text(), 3);
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
        ws.initRange(ui->range_4->text(), 4);
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
        ws.initRange(ui->range_5->text(), 5);
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
        ws.initRange(ui->range_6->text(), 6);
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
    for(int i=0;i<5;++i){
        QString var_board;
        QTextStream (&var_board) << "board_" << i;
        QPushButton *act_board=this->findChild<QPushButton *>(var_board);
        if(var_card==act_board->text()){
            act_board->setText("");
            act_board->setProperty("class", arr_card_colors[4]);
            act_board->style()->unpolish(act_board);
            act_board->style()->polish(act_board);
            act_board->update();
            return;
        }
    }
    //end clear

    //put color on card
    for(int i=0;i<5;++i){
        QString var_board;
        QTextStream (&var_board) << "board_" << i;
        QPushButton *act_board=this->findChild<QPushButton *>(var_board);
        if(act_board->text().isEmpty()){
            act_board->setText(var_card);
            act_board->setProperty("class", arr_card_colors[card[0]]);
            act_board->style()->unpolish(act_board);
            act_board->style()->polish(act_board);
            act_board->update();
            return;
        }
    }
    //

    //if all board is full, and we are trying to insert a new card, simply denied it unchecking the card
    if(!ui->board_0->text().isEmpty() && !ui->board_1->text().isEmpty() && !ui->board_2->text().isEmpty() && !ui->board_3->text().isEmpty() && !ui->board_4->text().isEmpty()){
        act_button->setChecked(false);
    }
}
void MainWindow::calculate_ranges(){
    //start calculate process
    if(ui->button_calculate->text()=="Calculate EQ"){
       this->calculate_beginning();
    }
    //stop calculate process
    else{
        this->calculate_stop();
    }
}
void MainWindow::calculate_stop(){
    mThread->setStopProcess(true);
   ui->button_calculate->setText("Calculate EQ");
   ui->button_calculate->setToolTip("Calculate the EQ for the selected ranges");
   ui->button_calculate->setEnabled(true);
   this->setAllEnabled(true);
}

void MainWindow::calculate_beginning(){
    //first of all clean the last vars
    this->clearVars();
    //
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
    if(i>=2 && (
                (!ui->board_0->text().isEmpty() && !ui->board_1->text().isEmpty() && !ui->board_2->text().isEmpty() && ui->board_3->text().isEmpty() && ui->board_4->text().isEmpty()) ||
                (!ui->board_0->text().isEmpty() && !ui->board_1->text().isEmpty() && !ui->board_2->text().isEmpty() && !ui->board_3->text().isEmpty() && ui->board_4->text().isEmpty()) ||
                (!ui->board_0->text().isEmpty() && !ui->board_1->text().isEmpty() && !ui->board_2->text().isEmpty() && !ui->board_3->text().isEmpty() && !ui->board_4->text().isEmpty())
                )
       ){
        //have flop
        board[0]=arr_suit_to_int[ui->board_0->text().toStdString().at(1)];
        board[1]=arr_let_to_int[ui->board_0->text().toStdString().at(0)];
        board[2]=arr_suit_to_int[ui->board_1->text().toStdString().at(1)];
        board[3]=arr_let_to_int[ui->board_1->text().toStdString().at(0)];
        board[4]=arr_suit_to_int[ui->board_2->text().toStdString().at(1)];
        board[5]=arr_let_to_int[ui->board_2->text().toStdString().at(0)];

        //have turn
        if(!ui->board_3->text().isEmpty()){
            board[6]=arr_suit_to_int[ui->board_3->text().toStdString().at(1)];
            board[7]=arr_let_to_int[ui->board_3->text().toStdString().at(0)];
        }
        //have river
        if(!ui->board_4->text().isEmpty()){
            board[8]=arr_suit_to_int[ui->board_4->text().toStdString().at(1)];
            board[9]=arr_let_to_int[ui->board_4->text().toStdString().at(0)];
        }
        this->setAllEnabled(false);
        ui->button_calculate->setText("Calculating...");
        ui->button_calculate->setEnabled(false);
        mThread->num_players=i;
        mThread->start();


    }//preflop
    else if(i>=2 && (ui->board_0->text().isEmpty() && ui->board_1->text().isEmpty() && ui->board_2->text().isEmpty() && ui->board_3->text().isEmpty() && ui->board_4->text().isEmpty())){
        this->setAllEnabled(false);
        ui->button_calculate->setText("Stop");
        ui->button_calculate->setToolTip("Stop the process (if stop it too early, the displayed results may not be accurate)");
        mThread->num_players=i;
        mThread->start();
    }
}
void MainWindow::setAllEnabled(bool flag_enable){
    ui->button_clear_all->setEnabled(flag_enable);
    ui->button_clear_0->setEnabled(flag_enable);
    ui->button_clear_1->setEnabled(flag_enable);
    ui->button_clear_2->setEnabled(flag_enable);
    ui->button_clear_3->setEnabled(flag_enable);
    ui->button_clear_4->setEnabled(flag_enable);
    ui->button_clear_5->setEnabled(flag_enable);
    ui->button_clear_6->setEnabled(flag_enable);

    ui->select_range_1->setEnabled(flag_enable);
    ui->select_range_2->setEnabled(flag_enable);
    ui->select_range_3->setEnabled(flag_enable);
    ui->select_range_4->setEnabled(flag_enable);
    ui->select_range_5->setEnabled(flag_enable);
    ui->select_range_6->setEnabled(flag_enable);

    ui->range_1->setEnabled(flag_enable);
    ui->range_2->setEnabled(flag_enable);
    ui->range_3->setEnabled(flag_enable);
    ui->range_4->setEnabled(flag_enable);
    ui->range_5->setEnabled(flag_enable);
    ui->range_6->setEnabled(flag_enable);

    ui->board_0->setEnabled(flag_enable);
    ui->board_1->setEnabled(flag_enable);
    ui->board_2->setEnabled(flag_enable);
    ui->board_3->setEnabled(flag_enable);
    ui->board_4->setEnabled(flag_enable);

    for(int i=0;i<52;++i){
        QString var_card,hexadecimal;
        hexadecimal.setNum(card_int_to_hex[i],16);
        QTextStream (&var_card) << "card_" << hexadecimal.rightJustified(2,'0');
        QPushButton *act_button=this->findChild<QPushButton *>(var_card);
        act_button->setEnabled(flag_enable);
    }
}

void MainWindow::clearAll(){
    this->clearVars();
    emit ui->button_clear_0->click();
    emit ui->button_clear_1->click();
    emit ui->button_clear_2->click();
    emit ui->button_clear_3->click();
    emit ui->button_clear_4->click();
    emit ui->button_clear_5->click();
    emit ui->button_clear_6->click();
}

void MainWindow::clearVars(){
    memset(HERO_COMBOS,0,sizeof(int)*6*1326*7);
    memset(arr_pos_pcent,0,sizeof(int)*6);
    memset(HERO_H_VALUES,0,sizeof(int)*6*1326*1326);
    long_all_boards=0;
    memset(board,0,sizeof(int)*10);
    memset(arr_all_boards,0,sizeof(int)*NUM_HANDS_PREFLOP*10);
    memset(range_pkr,0,sizeof(char)*6*3700);
    memset(long_hex_pos,0,sizeof(int)*6);
}
