#include "winselectrange.h"
#include "ui_winselectrange.h"
#include <qdebug.h>
WinSelectRange::WinSelectRange(QWidget *parent) : QDialog(parent),ui(new Ui::WinSelectRange){
    ui->setupUi(this);
    connect(ui->combo_AA, &QPushButton::clicked,[&](){putComboOnRange(0xee);});
    connect(ui->chk_suit_selector, &QPushButton::clicked,[&](){changeSuitSelector();});

}


WinSelectRange::~WinSelectRange()
{
    delete ui;
}
void WinSelectRange::setSelectedRange(int act_range){
    this->selected_range=act_range;
    qDebug() << this->selected_range;
}

void WinSelectRange::putComboOnRange(int act_combo){
    switch(act_combo){
        case 0xee:
            qDebug()<<"estamos en AA";
            break;
    }
}
void WinSelectRange::changeSuitSelector(){
    bool flag_buttons=ui->chk_suit_selector->isChecked();

    //enable/disable the buttons, are upsidedown with the checkbox

    ui->suit_00->setEnabled(flag_buttons);
    ui->suit_01->setEnabled(flag_buttons);
    ui->suit_02->setEnabled(flag_buttons);
    ui->suit_03->setEnabled(flag_buttons);
    ui->suit_10->setEnabled(flag_buttons);
    ui->suit_11->setEnabled(flag_buttons);
    ui->suit_12->setEnabled(flag_buttons);
    ui->suit_13->setEnabled(flag_buttons);
    ui->suit_20->setEnabled(flag_buttons);
    ui->suit_21->setEnabled(flag_buttons);
    ui->suit_22->setEnabled(flag_buttons);
    ui->suit_23->setEnabled(flag_buttons);
    ui->suit_30->setEnabled(flag_buttons);
    ui->suit_31->setEnabled(flag_buttons);
    ui->suit_32->setEnabled(flag_buttons);
    ui->suit_33->setEnabled(flag_buttons);
}
