#include "winselectrange.h"
#include "ui_winselectrange.h"

#include <qdebug.h>
//rangeslider
#include <QDesktopWidget>
#include <QPoint>
//
#include "init_cardmatrix.h"

WinSelectRange::WinSelectRange(QWidget *parent) : QDialog(parent),ui(new Ui::WinSelectRange){
    // Load an application style
    ui->setupUi(this);
    this->initPcents();
    widget = new QWidget(this);
    RangePFRVPIP = new RangeSlider(Qt::Horizontal, RangeSlider::Option::DoubleHandles, nullptr);
    RangePFRVPIP->setFixedWidth(445);
    RangePFRVPIP->setMinimum(0);
    RangePFRVPIP->setMaximum(99);
    RangePFRVPIP->setLowerValue(0);
    RangePFRVPIP->setUpperValue(0);
    layout = new QHBoxLayout();
    layout->addWidget(RangePFRVPIP);
    widget->setLayout(layout);
    widget->move(5,330);

    connect(this->RangePFRVPIP,SIGNAL(lowerValueChanged(int)),this,SLOT(updatePFRVPIP()));
    connect(this->RangePFRVPIP,SIGNAL(upperValueChanged(int)),this,SLOT(updatePFRVPIP()));

    connect(ui->combo_AA, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xe,0,ui->combo_AA->isChecked());});
    connect(ui->combo_KK, &QPushButton::clicked,[&](){putComboOnRange(0xd,0xd,0,ui->combo_KK->isChecked());});
    connect(ui->combo_QQ, &QPushButton::clicked,[&](){putComboOnRange(0xc,0xc,0,ui->combo_QQ->isChecked());});
    connect(ui->combo_JJ, &QPushButton::clicked,[&](){putComboOnRange(0xb,0xb,0,ui->combo_JJ->isChecked());});
    connect(ui->combo_TT, &QPushButton::clicked,[&](){putComboOnRange(0xa,0xa,0,ui->combo_TT->isChecked());});
    connect(ui->combo_99, &QPushButton::clicked,[&](){putComboOnRange(9,9,0,ui->combo_99->isChecked());});
    connect(ui->combo_88, &QPushButton::clicked,[&](){putComboOnRange(8,8,0,ui->combo_88->isChecked());});
    connect(ui->combo_77, &QPushButton::clicked,[&](){putComboOnRange(7,7,0,ui->combo_77->isChecked());});
    connect(ui->combo_66, &QPushButton::clicked,[&](){putComboOnRange(6,6,0,ui->combo_66->isChecked());});
    connect(ui->combo_55, &QPushButton::clicked,[&](){putComboOnRange(5,5,0,ui->combo_55->isChecked());});
    connect(ui->combo_44, &QPushButton::clicked,[&](){putComboOnRange(4,4,0,ui->combo_44->isChecked());});
    connect(ui->combo_33, &QPushButton::clicked,[&](){putComboOnRange(3,3,0,ui->combo_33->isChecked());});
    connect(ui->combo_22, &QPushButton::clicked,[&](){putComboOnRange(2,2,0,ui->combo_22->isChecked());});

    connect(ui->combo_AKs, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xd,1,ui->combo_AKs->isChecked());});
    connect(ui->combo_AQs, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xc,1,ui->combo_AQs->isChecked());});
    connect(ui->combo_AJs, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xb,1,ui->combo_AJs->isChecked());});
    connect(ui->combo_ATs, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xa,1,ui->combo_ATs->isChecked());});
    connect(ui->combo_A9s, &QPushButton::clicked,[&](){putComboOnRange(0xe,9,1,ui->combo_A9s->isChecked());});
    connect(ui->combo_A8s, &QPushButton::clicked,[&](){putComboOnRange(0xe,8,1,ui->combo_A8s->isChecked());});
    connect(ui->combo_A7s, &QPushButton::clicked,[&](){putComboOnRange(0xe,7,1,ui->combo_A7s->isChecked());});
    connect(ui->combo_A6s, &QPushButton::clicked,[&](){putComboOnRange(0xe,6,1,ui->combo_A6s->isChecked());});
    connect(ui->combo_A5s, &QPushButton::clicked,[&](){putComboOnRange(0xe,5,1,ui->combo_A5s->isChecked());});
    connect(ui->combo_A4s, &QPushButton::clicked,[&](){putComboOnRange(0xe,4,1,ui->combo_A4s->isChecked());});
    connect(ui->combo_A3s, &QPushButton::clicked,[&](){putComboOnRange(0xe,3,1,ui->combo_A3s->isChecked());});
    connect(ui->combo_A2s, &QPushButton::clicked,[&](){putComboOnRange(0xe,2,1,ui->combo_A2s->isChecked());});

    connect(ui->combo_KQs, &QPushButton::clicked,[&](){putComboOnRange(0xd,0xc,1,ui->combo_KQs->isChecked());});
    connect(ui->combo_KJs, &QPushButton::clicked,[&](){putComboOnRange(0xd,0xb,1,ui->combo_KJs->isChecked());});
    connect(ui->combo_KTs, &QPushButton::clicked,[&](){putComboOnRange(0xd,0xa,1,ui->combo_KTs->isChecked());});
    connect(ui->combo_K9s, &QPushButton::clicked,[&](){putComboOnRange(0xd,9,1,ui->combo_K9s->isChecked());});
    connect(ui->combo_K8s, &QPushButton::clicked,[&](){putComboOnRange(0xd,8,1,ui->combo_K8s->isChecked());});
    connect(ui->combo_K7s, &QPushButton::clicked,[&](){putComboOnRange(0xd,7,1,ui->combo_K7s->isChecked());});
    connect(ui->combo_K6s, &QPushButton::clicked,[&](){putComboOnRange(0xd,6,1,ui->combo_K6s->isChecked());});
    connect(ui->combo_K5s, &QPushButton::clicked,[&](){putComboOnRange(0xd,5,1,ui->combo_K5s->isChecked());});
    connect(ui->combo_K4s, &QPushButton::clicked,[&](){putComboOnRange(0xd,4,1,ui->combo_K4s->isChecked());});
    connect(ui->combo_K3s, &QPushButton::clicked,[&](){putComboOnRange(0xd,3,1,ui->combo_K3s->isChecked());});
    connect(ui->combo_K2s, &QPushButton::clicked,[&](){putComboOnRange(0xd,2,1,ui->combo_K2s->isChecked());});

    connect(ui->combo_QJs, &QPushButton::clicked,[&](){putComboOnRange(0xc,0xb,1,ui->combo_QJs->isChecked());});
    connect(ui->combo_QTs, &QPushButton::clicked,[&](){putComboOnRange(0xc,0xa,1,ui->combo_QTs->isChecked());});
    connect(ui->combo_Q9s, &QPushButton::clicked,[&](){putComboOnRange(0xc,9,1,ui->combo_Q9s->isChecked());});
    connect(ui->combo_Q8s, &QPushButton::clicked,[&](){putComboOnRange(0xc,8,1,ui->combo_Q8s->isChecked());});
    connect(ui->combo_Q7s, &QPushButton::clicked,[&](){putComboOnRange(0xc,7,1,ui->combo_Q7s->isChecked());});
    connect(ui->combo_Q6s, &QPushButton::clicked,[&](){putComboOnRange(0xc,6,1,ui->combo_Q6s->isChecked());});
    connect(ui->combo_Q5s, &QPushButton::clicked,[&](){putComboOnRange(0xc,5,1,ui->combo_Q5s->isChecked());});
    connect(ui->combo_Q4s, &QPushButton::clicked,[&](){putComboOnRange(0xc,4,1,ui->combo_Q4s->isChecked());});
    connect(ui->combo_Q3s, &QPushButton::clicked,[&](){putComboOnRange(0xc,3,1,ui->combo_Q3s->isChecked());});
    connect(ui->combo_Q2s, &QPushButton::clicked,[&](){putComboOnRange(0xc,2,1,ui->combo_Q2s->isChecked());});

    connect(ui->combo_JTs, &QPushButton::clicked,[&](){putComboOnRange(0xb,0xa,1,ui->combo_JTs->isChecked());});
    connect(ui->combo_J9s, &QPushButton::clicked,[&](){putComboOnRange(0xb,9,1,ui->combo_J9s->isChecked());});
    connect(ui->combo_J8s, &QPushButton::clicked,[&](){putComboOnRange(0xb,8,1,ui->combo_J8s->isChecked());});
    connect(ui->combo_J7s, &QPushButton::clicked,[&](){putComboOnRange(0xb,7,1,ui->combo_J7s->isChecked());});
    connect(ui->combo_J6s, &QPushButton::clicked,[&](){putComboOnRange(0xb,6,1,ui->combo_J6s->isChecked());});
    connect(ui->combo_J5s, &QPushButton::clicked,[&](){putComboOnRange(0xb,5,1,ui->combo_J5s->isChecked());});
    connect(ui->combo_J4s, &QPushButton::clicked,[&](){putComboOnRange(0xb,4,1,ui->combo_J4s->isChecked());});
    connect(ui->combo_J3s, &QPushButton::clicked,[&](){putComboOnRange(0xb,3,1,ui->combo_J3s->isChecked());});
    connect(ui->combo_J2s, &QPushButton::clicked,[&](){putComboOnRange(0xb,2,1,ui->combo_J2s->isChecked());});

    connect(ui->combo_T9s, &QPushButton::clicked,[&](){putComboOnRange(0xa,9,1,ui->combo_T9s->isChecked());});
    connect(ui->combo_T8s, &QPushButton::clicked,[&](){putComboOnRange(0xa,8,1,ui->combo_T8s->isChecked());});
    connect(ui->combo_T7s, &QPushButton::clicked,[&](){putComboOnRange(0xa,7,1,ui->combo_T7s->isChecked());});
    connect(ui->combo_T6s, &QPushButton::clicked,[&](){putComboOnRange(0xa,6,1,ui->combo_T6s->isChecked());});
    connect(ui->combo_T5s, &QPushButton::clicked,[&](){putComboOnRange(0xa,5,1,ui->combo_T5s->isChecked());});
    connect(ui->combo_T4s, &QPushButton::clicked,[&](){putComboOnRange(0xa,4,1,ui->combo_T4s->isChecked());});
    connect(ui->combo_T3s, &QPushButton::clicked,[&](){putComboOnRange(0xa,3,1,ui->combo_T3s->isChecked());});
    connect(ui->combo_T2s, &QPushButton::clicked,[&](){putComboOnRange(0xa,2,1,ui->combo_T2s->isChecked());});

    connect(ui->combo_98s, &QPushButton::clicked,[&](){putComboOnRange(9,8,1,ui->combo_98s->isChecked());});
    connect(ui->combo_97s, &QPushButton::clicked,[&](){putComboOnRange(9,7,1,ui->combo_97s->isChecked());});
    connect(ui->combo_96s, &QPushButton::clicked,[&](){putComboOnRange(9,6,1,ui->combo_96s->isChecked());});
    connect(ui->combo_95s, &QPushButton::clicked,[&](){putComboOnRange(9,5,1,ui->combo_95s->isChecked());});
    connect(ui->combo_94s, &QPushButton::clicked,[&](){putComboOnRange(9,4,1,ui->combo_94s->isChecked());});
    connect(ui->combo_93s, &QPushButton::clicked,[&](){putComboOnRange(9,3,1,ui->combo_93s->isChecked());});
    connect(ui->combo_92s, &QPushButton::clicked,[&](){putComboOnRange(9,2,1,ui->combo_92s->isChecked());});

    connect(ui->combo_87s, &QPushButton::clicked,[&](){putComboOnRange(8,7,1,ui->combo_87s->isChecked());});
    connect(ui->combo_86s, &QPushButton::clicked,[&](){putComboOnRange(8,6,1,ui->combo_86s->isChecked());});
    connect(ui->combo_85s, &QPushButton::clicked,[&](){putComboOnRange(8,5,1,ui->combo_85s->isChecked());});
    connect(ui->combo_84s, &QPushButton::clicked,[&](){putComboOnRange(8,4,1,ui->combo_84s->isChecked());});
    connect(ui->combo_83s, &QPushButton::clicked,[&](){putComboOnRange(8,3,1,ui->combo_83s->isChecked());});
    connect(ui->combo_82s, &QPushButton::clicked,[&](){putComboOnRange(8,2,1,ui->combo_82s->isChecked());});

    connect(ui->combo_76s, &QPushButton::clicked,[&](){putComboOnRange(7,6,1,ui->combo_76s->isChecked());});
    connect(ui->combo_75s, &QPushButton::clicked,[&](){putComboOnRange(7,5,1,ui->combo_75s->isChecked());});
    connect(ui->combo_74s, &QPushButton::clicked,[&](){putComboOnRange(7,4,1,ui->combo_74s->isChecked());});
    connect(ui->combo_73s, &QPushButton::clicked,[&](){putComboOnRange(7,3,1,ui->combo_73s->isChecked());});
    connect(ui->combo_72s, &QPushButton::clicked,[&](){putComboOnRange(7,2,1,ui->combo_72s->isChecked());});

    connect(ui->combo_65s, &QPushButton::clicked,[&](){putComboOnRange(6,5,1,ui->combo_65s->isChecked());});
    connect(ui->combo_64s, &QPushButton::clicked,[&](){putComboOnRange(6,4,1,ui->combo_64s->isChecked());});
    connect(ui->combo_63s, &QPushButton::clicked,[&](){putComboOnRange(6,3,1,ui->combo_63s->isChecked());});
    connect(ui->combo_62s, &QPushButton::clicked,[&](){putComboOnRange(6,2,1,ui->combo_62s->isChecked());});

    connect(ui->combo_54s, &QPushButton::clicked,[&](){putComboOnRange(5,4,1,ui->combo_54s->isChecked());});
    connect(ui->combo_53s, &QPushButton::clicked,[&](){putComboOnRange(5,3,1,ui->combo_53s->isChecked());});
    connect(ui->combo_52s, &QPushButton::clicked,[&](){putComboOnRange(5,2,1,ui->combo_52s->isChecked());});

    connect(ui->combo_43s, &QPushButton::clicked,[&](){putComboOnRange(4,3,1,ui->combo_43s->isChecked());});
    connect(ui->combo_42s, &QPushButton::clicked,[&](){putComboOnRange(4,2,1,ui->combo_42s->isChecked());});

    connect(ui->combo_32s, &QPushButton::clicked,[&](){putComboOnRange(3,2,1,ui->combo_32s->isChecked());});

    connect(ui->combo_AKo, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xd,0,ui->combo_AKo->isChecked());});
    connect(ui->combo_AQo, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xc,0,ui->combo_AQo->isChecked());});
    connect(ui->combo_AJo, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xb,0,ui->combo_AJo->isChecked());});
    connect(ui->combo_ATo, &QPushButton::clicked,[&](){putComboOnRange(0xe,0xa,0,ui->combo_ATo->isChecked());});
    connect(ui->combo_A9o, &QPushButton::clicked,[&](){putComboOnRange(0xe,9,0,ui->combo_A9o->isChecked());});
    connect(ui->combo_A8o, &QPushButton::clicked,[&](){putComboOnRange(0xe,8,0,ui->combo_A8o->isChecked());});
    connect(ui->combo_A7o, &QPushButton::clicked,[&](){putComboOnRange(0xe,7,0,ui->combo_A7o->isChecked());});
    connect(ui->combo_A6o, &QPushButton::clicked,[&](){putComboOnRange(0xe,6,0,ui->combo_A6o->isChecked());});
    connect(ui->combo_A5o, &QPushButton::clicked,[&](){putComboOnRange(0xe,5,0,ui->combo_A5o->isChecked());});
    connect(ui->combo_A4o, &QPushButton::clicked,[&](){putComboOnRange(0xe,4,0,ui->combo_A4o->isChecked());});
    connect(ui->combo_A3o, &QPushButton::clicked,[&](){putComboOnRange(0xe,3,0,ui->combo_A3o->isChecked());});
    connect(ui->combo_A2o, &QPushButton::clicked,[&](){putComboOnRange(0xe,2,0,ui->combo_A2o->isChecked());});

    connect(ui->combo_KQo, &QPushButton::clicked,[&](){putComboOnRange(0xd,0xc,0,ui->combo_KQo->isChecked());});
    connect(ui->combo_KJo, &QPushButton::clicked,[&](){putComboOnRange(0xd,0xb,0,ui->combo_KJo->isChecked());});
    connect(ui->combo_KTo, &QPushButton::clicked,[&](){putComboOnRange(0xd,0xa,0,ui->combo_KTo->isChecked());});
    connect(ui->combo_K9o, &QPushButton::clicked,[&](){putComboOnRange(0xd,9,0,ui->combo_K9o->isChecked());});
    connect(ui->combo_K8o, &QPushButton::clicked,[&](){putComboOnRange(0xd,8,0,ui->combo_K8o->isChecked());});
    connect(ui->combo_K7o, &QPushButton::clicked,[&](){putComboOnRange(0xd,7,0,ui->combo_K7o->isChecked());});
    connect(ui->combo_K6o, &QPushButton::clicked,[&](){putComboOnRange(0xd,6,0,ui->combo_K6o->isChecked());});
    connect(ui->combo_K5o, &QPushButton::clicked,[&](){putComboOnRange(0xd,5,0,ui->combo_K5o->isChecked());});
    connect(ui->combo_K4o, &QPushButton::clicked,[&](){putComboOnRange(0xd,4,0,ui->combo_K4o->isChecked());});
    connect(ui->combo_K3o, &QPushButton::clicked,[&](){putComboOnRange(0xd,3,0,ui->combo_K3o->isChecked());});
    connect(ui->combo_K2o, &QPushButton::clicked,[&](){putComboOnRange(0xd,2,0,ui->combo_K2o->isChecked());});

    connect(ui->combo_QJo, &QPushButton::clicked,[&](){putComboOnRange(0xc,0xb,0,ui->combo_QJo->isChecked());});
    connect(ui->combo_QTo, &QPushButton::clicked,[&](){putComboOnRange(0xc,0xa,0,ui->combo_QTo->isChecked());});
    connect(ui->combo_Q9o, &QPushButton::clicked,[&](){putComboOnRange(0xc,9,0,ui->combo_Q9o->isChecked());});
    connect(ui->combo_Q8o, &QPushButton::clicked,[&](){putComboOnRange(0xc,8,0,ui->combo_Q8o->isChecked());});
    connect(ui->combo_Q7o, &QPushButton::clicked,[&](){putComboOnRange(0xc,7,0,ui->combo_Q7o->isChecked());});
    connect(ui->combo_Q6o, &QPushButton::clicked,[&](){putComboOnRange(0xc,6,0,ui->combo_Q6o->isChecked());});
    connect(ui->combo_Q5o, &QPushButton::clicked,[&](){putComboOnRange(0xc,5,0,ui->combo_Q5o->isChecked());});
    connect(ui->combo_Q4o, &QPushButton::clicked,[&](){putComboOnRange(0xc,4,0,ui->combo_Q4o->isChecked());});
    connect(ui->combo_Q3o, &QPushButton::clicked,[&](){putComboOnRange(0xc,3,0,ui->combo_Q3o->isChecked());});
    connect(ui->combo_Q2o, &QPushButton::clicked,[&](){putComboOnRange(0xc,2,0,ui->combo_Q2o->isChecked());});

    connect(ui->combo_JTo, &QPushButton::clicked,[&](){putComboOnRange(0xb,0xa,0,ui->combo_JTo->isChecked());});
    connect(ui->combo_J9o, &QPushButton::clicked,[&](){putComboOnRange(0xb,9,0,ui->combo_J9o->isChecked());});
    connect(ui->combo_J8o, &QPushButton::clicked,[&](){putComboOnRange(0xb,8,0,ui->combo_J8o->isChecked());});
    connect(ui->combo_J7o, &QPushButton::clicked,[&](){putComboOnRange(0xb,7,0,ui->combo_J7o->isChecked());});
    connect(ui->combo_J6o, &QPushButton::clicked,[&](){putComboOnRange(0xb,6,0,ui->combo_J6o->isChecked());});
    connect(ui->combo_J5o, &QPushButton::clicked,[&](){putComboOnRange(0xb,5,0,ui->combo_J5o->isChecked());});
    connect(ui->combo_J4o, &QPushButton::clicked,[&](){putComboOnRange(0xb,4,0,ui->combo_J4o->isChecked());});
    connect(ui->combo_J3o, &QPushButton::clicked,[&](){putComboOnRange(0xb,3,0,ui->combo_J3o->isChecked());});
    connect(ui->combo_J2o, &QPushButton::clicked,[&](){putComboOnRange(0xb,2,0,ui->combo_J2o->isChecked());});

    connect(ui->combo_T9o, &QPushButton::clicked,[&](){putComboOnRange(0xa,9,0,ui->combo_T9o->isChecked());});
    connect(ui->combo_T8o, &QPushButton::clicked,[&](){putComboOnRange(0xa,8,0,ui->combo_T8o->isChecked());});
    connect(ui->combo_T7o, &QPushButton::clicked,[&](){putComboOnRange(0xa,7,0,ui->combo_T7o->isChecked());});
    connect(ui->combo_T6o, &QPushButton::clicked,[&](){putComboOnRange(0xa,6,0,ui->combo_T6o->isChecked());});
    connect(ui->combo_T5o, &QPushButton::clicked,[&](){putComboOnRange(0xa,5,0,ui->combo_T5o->isChecked());});
    connect(ui->combo_T4o, &QPushButton::clicked,[&](){putComboOnRange(0xa,4,0,ui->combo_T4o->isChecked());});
    connect(ui->combo_T3o, &QPushButton::clicked,[&](){putComboOnRange(0xa,3,0,ui->combo_T3o->isChecked());});
    connect(ui->combo_T2o, &QPushButton::clicked,[&](){putComboOnRange(0xa,2,0,ui->combo_T2o->isChecked());});

    connect(ui->combo_98o, &QPushButton::clicked,[&](){putComboOnRange(9,8,0,ui->combo_98o->isChecked());});
    connect(ui->combo_97o, &QPushButton::clicked,[&](){putComboOnRange(9,7,0,ui->combo_97o->isChecked());});
    connect(ui->combo_96o, &QPushButton::clicked,[&](){putComboOnRange(9,6,0,ui->combo_96o->isChecked());});
    connect(ui->combo_95o, &QPushButton::clicked,[&](){putComboOnRange(9,5,0,ui->combo_95o->isChecked());});
    connect(ui->combo_94o, &QPushButton::clicked,[&](){putComboOnRange(9,4,0,ui->combo_94o->isChecked());});
    connect(ui->combo_93o, &QPushButton::clicked,[&](){putComboOnRange(9,3,0,ui->combo_93o->isChecked());});
    connect(ui->combo_92o, &QPushButton::clicked,[&](){putComboOnRange(9,2,0,ui->combo_92o->isChecked());});

    connect(ui->combo_87o, &QPushButton::clicked,[&](){putComboOnRange(8,7,0,ui->combo_87o->isChecked());});
    connect(ui->combo_86o, &QPushButton::clicked,[&](){putComboOnRange(8,6,0,ui->combo_86o->isChecked());});
    connect(ui->combo_85o, &QPushButton::clicked,[&](){putComboOnRange(8,5,0,ui->combo_85o->isChecked());});
    connect(ui->combo_84o, &QPushButton::clicked,[&](){putComboOnRange(8,4,0,ui->combo_84o->isChecked());});
    connect(ui->combo_83o, &QPushButton::clicked,[&](){putComboOnRange(8,3,0,ui->combo_83o->isChecked());});
    connect(ui->combo_82o, &QPushButton::clicked,[&](){putComboOnRange(8,2,0,ui->combo_82o->isChecked());});

    connect(ui->combo_76o, &QPushButton::clicked,[&](){putComboOnRange(7,6,0,ui->combo_76o->isChecked());});
    connect(ui->combo_75o, &QPushButton::clicked,[&](){putComboOnRange(7,5,0,ui->combo_75o->isChecked());});
    connect(ui->combo_74o, &QPushButton::clicked,[&](){putComboOnRange(7,4,0,ui->combo_74o->isChecked());});
    connect(ui->combo_73o, &QPushButton::clicked,[&](){putComboOnRange(7,3,0,ui->combo_73o->isChecked());});
    connect(ui->combo_72o, &QPushButton::clicked,[&](){putComboOnRange(7,2,0,ui->combo_72o->isChecked());});

    connect(ui->combo_65o, &QPushButton::clicked,[&](){putComboOnRange(6,5,0,ui->combo_65o->isChecked());});
    connect(ui->combo_64o, &QPushButton::clicked,[&](){putComboOnRange(6,4,0,ui->combo_64o->isChecked());});
    connect(ui->combo_63o, &QPushButton::clicked,[&](){putComboOnRange(6,3,0,ui->combo_63o->isChecked());});
    connect(ui->combo_62o, &QPushButton::clicked,[&](){putComboOnRange(6,2,0,ui->combo_62o->isChecked());});

    connect(ui->combo_54o, &QPushButton::clicked,[&](){putComboOnRange(5,4,0,ui->combo_54o->isChecked());});
    connect(ui->combo_53o, &QPushButton::clicked,[&](){putComboOnRange(5,3,0,ui->combo_53o->isChecked());});
    connect(ui->combo_52o, &QPushButton::clicked,[&](){putComboOnRange(5,2,0,ui->combo_52o->isChecked());});

    connect(ui->combo_43o, &QPushButton::clicked,[&](){putComboOnRange(4,3,0,ui->combo_43o->isChecked());});
    connect(ui->combo_42o, &QPushButton::clicked,[&](){putComboOnRange(4,2,0,ui->combo_42o->isChecked());});

    connect(ui->combo_32o, &QPushButton::clicked,[&](){putComboOnRange(3,2,0,ui->combo_32o->isChecked());});
    connect(ui->button_clear, &QPushButton::clicked,[&](){this->clearData();});

    connect(ui->chk_suit_selector, &QPushButton::clicked,[&](){changeSuitSelector();});

    connect(ui->button_ok, &QPushButton::clicked,[&](){this->accept();});
    connect(ui->button_cancel, &QPushButton::clicked,[&](){this->reject();});
    connect(ui->button_clear, &QPushButton::clicked,[&](){
        this->clearData();
    });
    connect(ui->boton, &QPushButton::clicked,[&](){
//        int j=0;
//        for(int i=0;i<=0x3e3e;i++){
//            if(this->arr_combos[i]==true){
//                j++;
//            }
//        }
int i=0;
for(i=0;i<100;i++){
    ui->line_vpip->setText(QString::number(i));
}
    });
    connect(ui->line_pfr, &QLineEdit::textChanged,[&](){
        int cmp0=ui->line_pfr->text().toInt();
        int cmp1=ui->line_vpip->text().toInt();
        if(cmp0<cmp1 && cmp0>0 && cmp0<100){
            this->RangePFRVPIP->SetLowerValue(ui->line_pfr->text().toInt());
        }
    });
    connect(ui->line_vpip, &QLineEdit::textChanged,[&](){
        int cmp0=ui->line_pfr->text().toInt();
        int cmp1=ui->line_vpip->text().toInt();
        if(cmp1>cmp0 && cmp1>0 && cmp1<100){
            this->RangePFRVPIP->SetUpperValue(ui->line_vpip->text().toInt());
        }
    });
}
void WinSelectRange::clearData(){
//    memset(HERO_COMBOS,0,sizeof(int)*((1326*7*6)-1));
//    memset(this->arr_combos,0,0x3e3e*sizeof(bool));
//    this->separated_range="";
//    this->all_range="";
//    ui->line_pfr->setText("0");
//    ui->line_vpip->setText("0");
    this->unCheckAllCombos();
}
WinSelectRange::~WinSelectRange(){
    delete ui;
}
void WinSelectRange::setSelectedRange(int act_range){
    this->selected_range=act_range;
}

void WinSelectRange::putComboOnRange(int num1, int num2,int flag_suited, bool flag_checked){
    //flag_suited=0 -> offsuited, 1-> suited, 2->pocket pair
    bool flag_checked_suit_selector=ui->chk_suit_selector->isChecked();
    int tmp_hex;
    int i,j;

    //now put the combo in this->arr_combos[]
    if(!flag_checked){
        for(i=0;i<4;++i){
            for(j=0;j<4;++j){
                tmp_hex=(i*0x1000)+(num1*0x100)+(j*0x10)+num2;
                this->arr_combos[tmp_hex]=false;
            }
        }
    }else{
        if(!flag_checked_suit_selector){
            for(i=0;i<4;++i){
                for(j=0;j<4;++j){
                    if(
                            (flag_suited==1 && i==j) ||
                            (flag_suited==0 && i!=j)
                       ){
                        tmp_hex=(i*0x1000)+(num1*0x100)+(j*0x10)+num2;
                        if(!this->arr_combos[reverse_hex(tmp_hex)]){
                            this->arr_combos[tmp_hex]=true;
                        }
                    }
                }
            }
        }else{
            tmp_hex=(num1*0x100)+0+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=0){
                this->arr_combos[tmp_hex]=ui->suit_00->isChecked();
            }

            tmp_hex=(num1*0x100)+0x10+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_01->isChecked();
            }

            tmp_hex=(num1*0x100)+0x20+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_02->isChecked();
            }

            tmp_hex=(num1*0x100)+0x30+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_03->isChecked();
            }

            tmp_hex=0x1000+(num1*0x100)+0+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_10->isChecked();
            }

            tmp_hex=0x1000+(num1*0x100)+0x10+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=0){
                this->arr_combos[tmp_hex]=ui->suit_11->isChecked();
            }

            tmp_hex=0x1000+(num1*0x100)+0x20+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_12->isChecked();
            }

            tmp_hex=0x1000+(num1*0x100)+0x30+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_13->isChecked();
            }

            tmp_hex=0x2000+(num1*0x100)+0+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_20->isChecked();
            }

            tmp_hex=0x2000+(num1*0x100)+0x10+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_21->isChecked();
            }

            tmp_hex=0x2000+(num1*0x100)+0x20+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=0){
                this->arr_combos[tmp_hex]=ui->suit_22->isChecked();
            }
            tmp_hex=0x2000+(num1*0x100)+0x30+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_23->isChecked();
            }

            tmp_hex=0x3000+(num1*0x100)+0+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_30->isChecked();
            }

            tmp_hex=0x3000+(num1*0x100)+0x10+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_31->isChecked();
            }

            tmp_hex=0x3000+(num1*0x100)+0x20+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=1){
                this->arr_combos[tmp_hex]=ui->suit_32->isChecked();
            }

            tmp_hex=0x3000+(num1*0x100)+0x30+num2;
            if(!this->arr_combos[reverse_hex(tmp_hex)] && flag_suited!=0){
                this->arr_combos[tmp_hex]=ui->suit_33->isChecked();
            }
        }
    }
    convArrCombosToString(false);
}
void WinSelectRange::convArrCombosToString(bool flag_separated_range){
    //copy the main array arr_combos[] to tmp_arr_combos[] for manipulate it and create the string range
    int i,j;
    int tmp_hex;
    int tmp_arr_combos[0x3e3f]={0};
    for(i=0;i<=0x3e3e;i++){
        if(this->arr_combos[i]==true){
            tmp_arr_combos[i]=true;
        }
    }
    //define vars for create the subranges
    QString tmp_range;
    QString tmp_sub_range;
    int cont=0;
    int k,l;
    int cmp0=0,cmp1=0;
    bool flag_last_in_a_row=false, flag_last_in_this_subrange=false;
    bool flag_first=true;
    //create the POCKET PAIRS subrange

    for(i=0xe;i>=2;--i){
        for(k=0;k<4;k++){
            for(l=0;l<4;l++){
                if(k!=l){
                    tmp_hex=(k*0x1000)+(i*0x100)+(l*0x10)+i;
                    if(tmp_arr_combos[tmp_hex]){
                          cont++;
                    }
                }
            }
        }
        if(cont==6){
            //first in this sequence
            if(flag_first){
                cmp0=i;
                flag_first=false;
                tmp_range+=tmp_sub_range;
                tmp_sub_range="";
            }
            //delete for clean the analized combos
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    if(k!=l){
                        tmp_hex=(k*0x1000)+(i*0x100)+(l*0x10)+i;
                        tmp_arr_combos[tmp_hex]=false;
                    }
                }
            }
             cont=0;
             if(cmp0==i || flag_separated_range){
                tmp_sub_range+=(QString) arr_int_to_let[i] + arr_int_to_let[i]+",";
             }else{
                tmp_sub_range=(QString) arr_int_to_let[cmp0] + arr_int_to_let[cmp0] + "-" + arr_int_to_let[i] + arr_int_to_let[i] +",";
             }
        }else{
            cmp0=0;
            cont=0;
            flag_first=true;
        }
    }
    //concatenate the last here
    if(tmp_sub_range!=""){
       tmp_range+=tmp_sub_range;
    }

    //finish POCKET PAIRS here

    //create SUITED subrange
    tmp_sub_range="";
    cont=0,k=0;
    l=0;
    cmp0=0,cmp1=0;
    flag_last_in_a_row=false;
    flag_last_in_this_subrange=false;
    for(i=0x0e;i>=3;--i){
        cmp0=0;
        cmp1=0;
        cont=0;
        flag_last_in_a_row=false;
        for(j=i-1;j>=2;--j){
            for(k=0;k<4;k++){
                tmp_hex=(k*0x1000)+(i*0x100)+k*0x10+j;
                if(tmp_arr_combos[tmp_hex]){
                    cont++;
                }
            }
            if(cont==4){
                //special case for 32s
                if(i==3 && j==2){
                    cmp0=2;
                    cmp1=2;
                    flag_last_in_this_subrange=true;
                }else{
                    //all the rest
                    if(cmp0==0){
                        cmp0=j;
                    }
                    if(cmp1==0){
                        cmp1=j;
                    }else{
                        cmp1--;
                        if(cmp1==1){
                            cmp1=2;
                        }
                    }
                }

                //delete for clean the analized combos
                for(k=0;k<4;k++){
                     tmp_hex=(k*0x1000)+(i*0x100)+k*0x10+j;
                     tmp_arr_combos[tmp_hex]=false;
                }
                 cont=0;
                 if(!flag_last_in_a_row && tmp_sub_range!=""){
                     tmp_range+=tmp_sub_range;
                 }
                 if(cmp0==cmp1){
                     tmp_sub_range=(QString) arr_int_to_let[i]+arr_int_to_let[cmp0]+"s,";
                 }else{
                     if(!flag_separated_range){
                         tmp_sub_range=(QString) arr_int_to_let[i]+arr_int_to_let[cmp0]+"s-"+arr_int_to_let[i]+arr_int_to_let[cmp1]+"s,";
                     }else{
                        tmp_sub_range+=(QString) arr_int_to_let[i]+arr_int_to_let[cmp1]+"s,";
                     }
                 }

                 flag_last_in_a_row=true;
            }else{
                cmp0=0;
                cmp1=0;
                cont=0;
                flag_last_in_a_row=false;
            }
        }
    }
    //concatenate the last here
    if((!flag_last_in_a_row || (flag_last_in_this_subrange)) && tmp_sub_range!=""){
       tmp_range+=tmp_sub_range;
    }
    //finish here create SUITED subrange

    //create the OFFSUITED subrange
    tmp_sub_range="";
    cont=0;
    k=0;
    l=0;
    cmp0=0,cmp1=0;
    flag_last_in_a_row=false;
    flag_last_in_this_subrange=false;
    for(i=0x0e;i>=3;--i){
        cmp0=0;
        cmp1=0;
        cont=0;
        flag_last_in_a_row=false;
        for(j=i-1;j>=2;--j){
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    if(k!=l){
                        tmp_hex=(k*0x1000)+(i*0x100)+l*0x10+j;
                        if(tmp_arr_combos[tmp_hex]){
                          cont++;
                        }
                    }
                }
            }
            if(cont==12){
                //special case for 32o
                if(i==3 && j==2){
                    cmp0=2;
                    cmp1=2;
                    flag_last_in_this_subrange=true;
                }else{
                    //all the rest
                    if(cmp0==0){
                        cmp0=j;
                    }
                    if(cmp1==0){
                        cmp1=j;
                    }else{
                        cmp1--;
                        if(cmp1==1){
                            cmp1=2;
                        }
                    }
                }
                //delete for clean the analized combos
                for(k=0;k<4;k++){
                    for(l=0;l<4;l++){
                        if(k!=l){
                            tmp_hex=(k*0x1000)+(i*0x100)+l*0x10+j;
                            tmp_arr_combos[tmp_hex]=false;
                        }
                    }
                }
                 cont=0;
                 if(!flag_last_in_a_row && tmp_sub_range!=""){
                     tmp_range+=tmp_sub_range;
                 }
                 if(cmp0==cmp1){
                     tmp_sub_range=(QString) arr_int_to_let[i] + arr_int_to_let[cmp0] + "o,";
                 }else{
                     if(!flag_separated_range){
                         tmp_sub_range=(QString) arr_int_to_let[i]+arr_int_to_let[cmp0]+"o-"+arr_int_to_let[i]+arr_int_to_let[cmp1]+"o,";
                     }else{
                        tmp_sub_range+=(QString) arr_int_to_let[i]+arr_int_to_let[cmp1]+"o,";
                     }
                 }
                 flag_last_in_a_row=true;
            }else{
                cmp0=0;
                cmp1=0;
                cont=0;
                flag_last_in_a_row=false;
            }
        }
    }
    //concatenate the last here
    if((!flag_last_in_a_row || (flag_last_in_this_subrange)) && tmp_sub_range!=""){
       tmp_range+=tmp_sub_range;
    }

    //finish here create OFFSUITED subrange

//falta insertar los combos que no sean ni offsuited, ni suited, ni pocket pairs
    //loop for insert the rest
    int hex[4];
    for(i=0;i<=0x3e3e;i++){
        if(tmp_arr_combos[i]==true){
            hex[0]=(i/0x1000)%0x10;
            hex[1]=(i/0x100)%0x10;
            hex[2]=(i/0x10)%0x10;
            hex[3]=i%0x10;
            tmp_range+=(QString) arr_int_to_let[hex[1]]+arr_int_to_suit[hex[0]]+arr_int_to_let[hex[3]]+arr_int_to_suit[hex[2]]+",";
            tmp_arr_combos[i]=false;
        }
    }
    if(!tmp_range.isEmpty()){
        tmp_range.remove(tmp_range.length()-1,1);
    }
    if(flag_separated_range){
        this->separated_range=tmp_range;
    }else{
        this->all_range=tmp_range;
    }
}
void WinSelectRange::changeSuitSelector(){
    bool flag_buttons=ui->chk_suit_selector->isChecked();
    if(!flag_buttons){
        ui->suit_00->setChecked(true);
        ui->suit_01->setChecked(true);
        ui->suit_02->setChecked(true);
        ui->suit_03->setChecked(true);
        ui->suit_10->setChecked(true);
        ui->suit_11->setChecked(true);
        ui->suit_12->setChecked(true);
        ui->suit_13->setChecked(true);
        ui->suit_20->setChecked(true);
        ui->suit_21->setChecked(true);
        ui->suit_22->setChecked(true);
        ui->suit_23->setChecked(true);
        ui->suit_30->setChecked(true);
        ui->suit_31->setChecked(true);
        ui->suit_32->setChecked(true);
        ui->suit_33->setChecked(true);
    }
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
QString WinSelectRange::getRange(){
    return this->all_range;
}
//void WinSelectRange::saveRange(){
//    int i,tmp_hex;
//    memset(arr_tmp_delete,0,sizeof(int)*0x3e3f);

//    int num_lower=this->RangePFRVPIP->GetLowerValue();
//    int num_upper=this->RangePFRVPIP->GetUpperValue();

//    ui->line_pfr->setText(QString::number(num_lower));
//    ui->line_vpip->setText(QString::number(num_upper));

//    int pfr=num_lower;
//    int vpip=num_upper;

//    //if have it, first save the combos for delete in arr_tmp_delete(prf)
//    if(num_lower>0){
//        memset(HERO_COMBOS[4],0,sizeof(char)*((1326*7)-1));
//        initRange(this->arr_all_pcent[pfr],4,true);
//        for(i=0;i<1326;i++){
//            if(HERO_COMBOS[4][i][2]!=0 && HERO_COMBOS[4][i][4]!=0){
////                qDebug() << "antes";
//                tmp_hex=(0x1000*HERO_COMBOS[4][i][1])+(0x100*HERO_COMBOS[4][i][2])+(0x10*HERO_COMBOS[4][i][3])+HERO_COMBOS[4][i][4];
//                //for adjust it is in conv_pkr.h, line 34 int ovector[2048] works fine.
//                if(tmp_hex<0x3e3f && tmp_hex>=0x202){
//                //el error anda por aquí
//                    arr_tmp_delete[tmp_hex]=1;
//                }
//            }
//        }
//    }
//    //
//    memset(HERO_COMBOS[5],0,sizeof(char)*((1326*7)-1));
//    //now get the all the combos selected in this->arr_combos
//    initRange(this->arr_all_pcent[vpip],5,true);
//    //
//    if(num_lower>0){
//        //and do the rest vpip-pfr
//        for(i=0;i<0x3e3f;i++){
//            if(arr_tmp_delete[i]==1){
////                qDebug() << "borrando: " << hex <<i;
//                this->arr_combos[i]=false;
//            }
//        }
//    }

//    convArrCombosToString(true);
//    if(this->separated_range!=this->old_separated){
//        this->old_separated=this->separated_range;
//        qDebug() << "separated" << this->separated_range;
//    }
//    QString i_button;
//    QStringList button_list= this->separated_range.split(QLatin1Char(','), QString::SkipEmptyParts);
//    unCheckAllCombos();
//    foreach(i_button,button_list){
//        i_button.prepend("combo_");
////        qDebug() << "i_button: " << i_button;
//        QPushButton *act_button = this->findChild<QPushButton *>(i_button);
////        qDebug() << act_button;
//        act_button->setChecked(true);//esta línea si la comento deja de fallar al mover el slider hacia el 99 fallando justo en el 69
//    }
//}


void WinSelectRange::updatePFRVPIP(){
    int num_lower=this->RangePFRVPIP->GetLowerValue();
    int num_upper=this->RangePFRVPIP->GetUpperValue();
    int i=0;

    ui->line_pfr->setText(QString::number(num_lower));
    ui->line_vpip->setText(QString::number(num_upper));

    //uncheck the matrix first
    this->unCheckAllCombos();
    //

    //check the selected combos
    for(i=0;i<169;++i){
        if(!this->cardMatrix[num_lower][i] && this->cardMatrix[num_upper][i]){
            QPushButton *act_button = this->findChild<QPushButton *>(this->arr_button_names[i]);
            act_button->setChecked(true);
        }
    }
    //
}
void WinSelectRange::initRange(QString str_range, int i_player, bool flag_no_print_it){
    if(str_range==""){
        return;
    }
    int i,tmp_hex;

    //now remake str_range QString to char[] format
    std::string cadena_std0=str_range.toStdString();
    char tmp_range[str_range.length() + 1];

    strcpy(tmp_range, cadena_std0.c_str());

    //get the range reinitializating the vars and HERO_COMBOS and copy the result to this->arr_combos
    memset(HERO_COMBOS[i_player],0,sizeof(char)*((1326*7)-1));
    conv_range_pkr_to_hex(tmp_range,i_player);
    memset(this->arr_combos,0,0x3e3e*sizeof(bool));

    for(i=0;i<1326;i++){
        if(HERO_COMBOS[i_player][i][2]!=0 && HERO_COMBOS[i_player][i][4]!=0){
            tmp_hex=(0x1000*HERO_COMBOS[i_player][i][1])+(0x100*HERO_COMBOS[i_player][i][2])+(0x10*HERO_COMBOS[i_player][i][3])+HERO_COMBOS[i_player][i][4];
//            qDebug() << arr_int_to_suit[HERO_COMBOS[i_player][i][1]] << arr_int_to_let[HERO_COMBOS[i_player][i][2]] << arr_int_to_suit[HERO_COMBOS[i_player][i][3]] << arr_int_to_let[HERO_COMBOS[i_player][i][4]];
            this->arr_combos[tmp_hex]=true;
        }
    }
    if(flag_no_print_it){
        return;//if we are here, we are comming from updatePFRVPIP()
    }

    this->separated_range="";

    this->all_range="";
    convArrCombosToString(true);
//    qDebug() << this->separated_range;
    QString i_i_button;
    QStringList i_button_list= this->separated_range.split(QLatin1Char(','), QString::SkipEmptyParts);
    QPushButton *i_act_button;
    foreach(i_i_button,i_button_list){
        i_i_button.prepend("combo_");
        i_act_button = this->findChild<QPushButton *>(i_i_button);
        i_act_button->setChecked(true);
    }
}

void WinSelectRange::unCheckAllCombos(){
    //clear the matrix first
    for(i=0;i<169;++i){
        QPushButton *act_button = this->findChild<QPushButton *>(this->arr_button_names[i]);
        act_button->setChecked(false);
    }
}
