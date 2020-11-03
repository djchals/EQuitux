#include "winselectrange.h"
#include "ui_winselectrange.h"

#include <qdebug.h>
//rangeslider
#include <QDesktopWidget>
#include <QPoint>
//

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
        int j=0;
        for(int i=0;i<=0x3e3e;i++){
            if(this->arr_combos[i]==true){
                j++;
            }
        }
        qDebug() << "el valor de j: " << j;
                qDebug() << "separated_range: " << this->separated_range;
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
    int i,j,tmp_hex;
    int tmp_arr_combos[0x3e3f]={0};
    for(i=0;i<=0x3e3e;i++){
        if(this->arr_combos[i]==true){
            tmp_arr_combos[i]=true;
        }
    }
    //define vars for create the subranges
    QString tmp_range;
    QString tmp_sub_range;
    int cont=0,k,l;
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
void WinSelectRange::updatePFRVPIP(){
    int i,tmp_hex;
    memset(arr_tmp_delete,0,sizeof(int)*0x3e3f);

    int num_lower=this->RangePFRVPIP->GetLowerValue();
    int num_upper=this->RangePFRVPIP->GetUpperValue();

    ui->line_pfr->setText(QString::number(num_lower));
    ui->line_vpip->setText(QString::number(num_upper));

    int pfr=num_lower;
    int vpip=num_upper;

    //if have it, first save the combos for delete in arr_tmp_delete(prf)
    if(num_lower>0){
        memset(HERO_COMBOS[4],0,sizeof(char)*((1326*7)-1));
        initRange(this->arr_all_pcent[pfr],4);
        for(i=0;i<1326;i++){
            if(HERO_COMBOS[4][i][2]!=0 && HERO_COMBOS[4][i][4]!=0){
                qDebug() << "antes";
                tmp_hex=(0x1000*HERO_COMBOS[4][i][1])+(0x100*HERO_COMBOS[4][i][2])+(0x10*HERO_COMBOS[4][i][3])+HERO_COMBOS[4][i][4];
                //for adjust it is in conv_pkr.h, line 34 int ovector[2048] works fine.
                if(tmp_hex<0x3e3f && tmp_hex>=0x202){
                //el error anda por aquí
                    arr_tmp_delete[tmp_hex]=1;
                    qDebug() << "tmp_hex_delete: " << hex << tmp_hex;
                }
            }
        }
    }
    //
    memset(HERO_COMBOS[5],0,sizeof(char)*((1326*7)-1));
    //now get the all the combos selected in this->arr_combos
    initRange(this->arr_all_pcent[vpip],5);
    //
//    if(num_lower>0){
        //and do the rest vpip-pfr
        for(i=0;i<0x3e3f;i++){
            if(arr_tmp_delete[i]==1){
                qDebug() << "borrando: " << hex <<i;
                this->arr_combos[i]=false;
            }
        }
//    }

        convArrCombosToString(true);

    qDebug() << "separated" << this->separated_range;
    QString i_button;
    QStringList button_list= this->separated_range.split(QLatin1Char(','), QString::SkipEmptyParts);
    unCheckAllCombos();
    foreach(i_button,button_list){
        i_button.prepend("combo_");
//        qDebug() << "i_button: " << i_button;
        QPushButton *act_button = this->findChild<QPushButton *>(i_button);
        qDebug() << act_button;
        act_button->setChecked(true);//esta línea si la comento deja de fallar al mover el slider hacia el 99 fallando justo en el 69
    }
}
void WinSelectRange::initRange(QString str_range, int i_player){
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
    this->separated_range="";
    this->all_range="";
    for(i=0;i<1326;i++){
        if(HERO_COMBOS[i_player][i][2]!=0 && HERO_COMBOS[i_player][i][4]!=0){
            tmp_hex=(0x1000*HERO_COMBOS[i_player][i][1])+(0x100*HERO_COMBOS[i_player][i][2])+(0x10*HERO_COMBOS[i_player][i][3])+HERO_COMBOS[i_player][i][4];
//            qDebug() << arr_int_to_suit[HERO_COMBOS[i_player][i][1]] << arr_int_to_let[HERO_COMBOS[i_player][i][2]] << arr_int_to_suit[HERO_COMBOS[i_player][i][3]] << arr_int_to_let[HERO_COMBOS[i_player][i][4]];
            this->arr_combos[tmp_hex]=true;
        }
    }
    convArrCombosToString(true);

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
//    QAbstractButton *checkButton = this->cardMatrix->checkedButton();

//    if(checkButton){
//        qDebug() << checkButton;
//        checkButton->setChecked(false);
//    }
    int i,j;
    QString i_button;
    for(i=2;i<=14;i++){
       i_button="";
        QTextStream(&i_button) << "combo_" <<hex << arr_int_to_let[i] << hex <<arr_int_to_let[i];
        QPushButton *act_button = this->findChild<QPushButton *>(i_button);
        act_button->setChecked(false);
    }
    for(i=0x0e;i>=3;--i){
        for(j=i-1;j>=2;--j){
            i_button="";
            QTextStream(&i_button) << "combo_" <<hex << arr_int_to_let[i] << hex <<arr_int_to_let[j] << "s";
            QPushButton *act_button  = this->findChild<QPushButton *>(i_button);
            act_button->setChecked(false);
            i_button="";
            QTextStream(&i_button) << "combo_" <<hex << arr_int_to_let[i] << hex <<arr_int_to_let[j] << "o";
            act_button = this->findChild<QPushButton *>(i_button);
            act_button->setChecked(false);
        }
    }
}
void WinSelectRange::initPcents(){
    this->arr_all_pcent[0]="";
    this->arr_all_pcent[1]="QQ+";
    this->arr_all_pcent[2]="TT+";
    this->arr_all_pcent[3]="99+,AKs";
    this->arr_all_pcent[4]="99+,AQs+,AKo";
    this->arr_all_pcent[5]="88+,AJs+,KQs,AKo";
    this->arr_all_pcent[6]="88+,ATs+,KQs,AQo+";
    this->arr_all_pcent[7]="88+,ATs+,KTs+,AQo+";
    this->arr_all_pcent[8]="88+,ATs+,KTs+,QJs,AJo+";
    this->arr_all_pcent[9]="88+,ATs+,KTs+,QJs,AJo+,KQo";
    this->arr_all_pcent[10]="77+,A9s+,KTs+,QTs+,AJo+,KQo";
    this->arr_all_pcent[11]="77+,A9s+,KTs+,QTs+,ATo+,KQo";
    this->arr_all_pcent[12]="77+,A9s+,KTs+,QTs+,JTs,ATo+,KJo+";
    this->arr_all_pcent[13]="77+,A8s+,K9s+,QTs+,JTs,ATo+,KJo+,QJo";
    this->arr_all_pcent[14]="77+,A7s+,K9s+,QTs+,JTs,ATo+,KTo+,QJo";
    this->arr_all_pcent[15]="77+,A7s+,K9s+,QTs+,JTs,ATo+,KTo+,QJo";
    this->arr_all_pcent[16]="66+,A7s+,A5s,K9s+,Q9s+,JTs,ATo+,KTo+,QJo";
    this->arr_all_pcent[17]="66+,A5s+,K9s+,Q9s+,JTs,ATo+,KTo+,QTo+";
    this->arr_all_pcent[18]="66+,A5s+,K9s+,Q9s+,J9s+,A9o+,KTo+,QTo+";
    this->arr_all_pcent[19]="66+,A4s+,K9s+,Q9s+,J9s+,T9s,A9o+,KTo+,QTo+";
    this->arr_all_pcent[20]="66+,A4s+,K8s+,Q9s+,J9s+,T9s,A9o+,KTo+,QTo+,JTo";
    this->arr_all_pcent[21]="66+,A4s+,K7s+,Q9s+,J9s+,T9s,A8o+,KTo+,QTo+,JTo";
    this->arr_all_pcent[22]="66+,A3s+,K7s+,Q8s+,J9s+,T9s,A8o+,KTo+,QTo+,JTo";
    this->arr_all_pcent[23]="66+,A3s+,K7s+,Q8s+,J9s+,T9s,A8o+,K9o+,QTo+,JTo";
    this->arr_all_pcent[24]="66+,A2s+,K6s+,Q8s+,J8s+,T8s+,A8o+,K9o+,QTo+,JTo";
    this->arr_all_pcent[25]="66+,A2s+,K6s+,Q8s+,J8s+,T8s+,A7o+,K9o+,QTo+,JTo";
    this->arr_all_pcent[26]="55+,A2s+,K6s+,Q8s+,J8s+,T8s+,A7o+,K9o+,Q9o+,JTo";
    this->arr_all_pcent[27]="55+,A2s+,K5s+,Q8s+,J8s+,T8s+,98s,A7o+,K9o+,Q9o+,JTo";
    this->arr_all_pcent[28]="55+,A2s+,K5s+,Q7s+,J8s+,T8s+,98s,A7o+,K9o+,Q9o+,J9o+";
    this->arr_all_pcent[29]="55+,A2s+,K5s+,Q7s+,J8s+,T8s+,98s,A7o+,A5o,K9o+,Q9o+,J9o+";
    this->arr_all_pcent[30]="55+,A2s+,K5s+,Q7s+,J8s+,T8s+,98s,A7o+,A5o,K9o+,Q9o+,J9o+,T9o";
    this->arr_all_pcent[31]="55+,A2s+,K5s+,Q7s+,J8s+,T8s+,98s,A5o+,K9o+,Q9o+,J9o+,T9o";
    this->arr_all_pcent[32]="55+,A2s+,K4s+,Q7s+,J8s+,T8s+,98s,A5o+,K8o+,Q9o+,J9o+,T9o";
    this->arr_all_pcent[33]="55+,A2s+,K4s+,Q6s+,J7s+,T7s+,98s,A5o+,K8o+,Q9o+,J9o+,T9o";
    this->arr_all_pcent[34]="55+,A2s+,K4s+,Q6s+,J7s+,T7s+,98s,A4o+,K8o+,Q9o+,J9o+,T9o";
    this->arr_all_pcent[35]="55+,A2s+,K3s+,Q5s+,J7s+,T7s+,97s+,87s,A4o+,K8o+,Q9o+,J9o+,T9o";
    this->arr_all_pcent[36]="55+,A2s+,K3s+,Q5s+,J7s+,T7s+,97s+,87s,A4o+,K7o+,Q9o+,J9o+,T9o";
    this->arr_all_pcent[37]="44+,A2s+,K3s+,Q5s+,J7s+,T7s+,97s+,87s,A4o+,K7o+,Q8o+,J9o+,T9o";
    this->arr_all_pcent[38]="44+,A2s+,K3s+,Q5s+,J7s+,T7s+,97s+,87s,A3o+,K7o+,Q8o+,J9o+,T9o";
    this->arr_all_pcent[39]="44+,A2s+,K2s+,Q5s+,J7s+,T7s+,97s+,87s,A3o+,K7o+,Q8o+,J8o+,T9o";
    this->arr_all_pcent[40]="44+,A2s+,K2s+,Q4s+,J7s+,T7s+,97s+,87s,A3o+,K7o+,Q8o+,J8o+,T8o+";
    this->arr_all_pcent[41]="44+,A2s+,K2s+,Q4s+,J6s+,T7s+,97s+,87s,A3o+,K7o+,Q8o+,J8o+,T8o+";
    this->arr_all_pcent[42]="44+,A2s+,K2s+,Q4s+,J6s+,T7s+,97s+,87s,A3o+,K6o+,Q8o+,J8o+,T8o+";
    this->arr_all_pcent[43]="44+,A2s+,K2s+,Q4s+,J6s+,T6s+,97s+,87s,A2o+,K6o+,Q8o+,J8o+,T8o+";
    this->arr_all_pcent[44]="44+,A2s+,K2s+,Q4s+,J6s+,T6s+,97s+,87s,A2o+,K6o+,Q8o+,J8o+,T8o+,98o";
    this->arr_all_pcent[45]="44+,A2s+,K2s+,Q4s+,J6s+,T6s+,96s+,86s+,76s,A2o+,K6o+,Q8o+,J8o+,T8o+,98o";
    this->arr_all_pcent[46]="44+,A2s+,K2s+,Q3s+,J5s+,T6s+,96s+,86s+,76s,A2o+,K5o+,Q8o+,J8o+,T8o+,98o";
    this->arr_all_pcent[47]="44+,A2s+,K2s+,Q3s+,J5s+,T6s+,96s+,86s+,76s,A2o+,K5o+,Q7o+,J8o+,T8o+,98o";
    this->arr_all_pcent[48]="44+,A2s+,K2s+,Q2s+,J4s+,T6s+,96s+,86s+,76s,A2o+,K5o+,Q7o+,J8o+,T8o+,98o";
    this->arr_all_pcent[49]="33+,A2s+,K2s+,Q2s+,J4s+,T6s+,96s+,86s+,76s,65s,A2o+,K5o+,Q7o+,J7o+,T8o+,98o";
    this->arr_all_pcent[50]="33+,A2s+,K2s+,Q2s+,J4s+,T6s+,96s+,86s+,76s,65s,A2o+,K5o+,Q7o+,J7o+,T7o+,98o";
    this->arr_all_pcent[51]="33+,A2s+,K2s+,Q2s+,J4s+,T6s+,96s+,86s+,76s,65s,A2o+,K4o+,Q7o+,J7o+,T7o+,98o";
    this->arr_all_pcent[52]="33+,A2s+,K2s+,Q2s+,J4s+,T5s+,96s+,86s+,75s+,65s,A2o+,K4o+,Q7o+,J7o+,T7o+,98o";
    this->arr_all_pcent[53]="33+,A2s+,K2s+,Q2s+,J4s+,T5s+,96s+,86s+,75s+,65s,A2o+,K4o+,Q6o+,J7o+,T7o+,98o";
    this->arr_all_pcent[54]="33+,A2s+,K2s+,Q2s+,J3s+,T5s+,95s+,86s+,75s+,65s,A2o+,K4o+,Q6o+,J7o+,T7o+,98o,87o";
    this->arr_all_pcent[55]="33+,A2s+,K2s+,Q2s+,J3s+,T5s+,95s+,85s+,75s+,65s,A2o+,K4o+,Q6o+,J7o+,T7o+,97o+,87o";
    this->arr_all_pcent[56]="33+,A2s+,K2s+,Q2s+,J3s+,T4s+,95s+,85s+,75s+,65s,A2o+,K4o+,Q6o+,J7o+,T7o+,97o+,87o";
    this->arr_all_pcent[57]="33+,A2s+,K2s+,Q2s+,J3s+,T4s+,95s+,85s+,75s+,65s,A2o+,K3o+,Q6o+,J7o+,T7o+,97o+,87o";
    this->arr_all_pcent[58]="33+,A2s+,K2s+,Q2s+,J2s+,T4s+,95s+,85s+,75s+,65s,54s,A2o+,K3o+,Q5o+,J7o+,T7o+,97o+,87o";
    this->arr_all_pcent[59]="33+,A2s+,K2s+,Q2s+,J2s+,T3s+,95s+,85s+,75s+,64s+,54s,A2o+,K3o+,Q5o+,J7o+,T7o+,97o+,87o";
    this->arr_all_pcent[60]="22+,A2s+,K2s+,Q2s+,J2s+,T3s+,95s+,85s+,75s+,64s+,54s,A2o+,K2o+,Q5o+,J7o+,T7o+,97o+,87o";
    this->arr_all_pcent[61]="22+,A2s+,K2s+,Q2s+,J2s+,T3s+,95s+,85s+,74s+,64s+,54s,A2o+,K2o+,Q5o+,J7o+,T7o+,97o+,87o,76o";
    this->arr_all_pcent[62]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,95s+,85s+,74s+,64s+,54s,A2o+,K2o+,Q4o+,J7o+,T7o+,97o+,87o,76o";
    this->arr_all_pcent[63]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,95s+,85s+,74s+,64s+,54s,A2o+,K2o+,Q4o+,J6o+,T7o+,97o+,87o,76o";
    this->arr_all_pcent[64]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,95s+,84s+,74s+,64s+,54s,A2o+,K2o+,Q4o+,J6o+,T7o+,97o+,87o,76o";
    this->arr_all_pcent[65]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,94s+,84s+,74s+,64s+,54s,A2o+,K2o+,Q4o+,J6o+,T7o+,97o+,86o+,76o";
    this->arr_all_pcent[66]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,94s+,84s+,74s+,64s+,54s,A2o+,K2o+,Q4o+,J6o+,T6o+,97o+,86o+,76o";
    this->arr_all_pcent[67]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,94s+,84s+,74s+,64s+,54s,A2o+,K2o+,Q4o+,J6o+,T6o+,96o+,86o+,76o";
    this->arr_all_pcent[68]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,93s+,84s+,74s+,64s+,53s+,A2o+,K2o+,Q3o+,J6o+,T6o+,96o+,86o+,76o";
    this->arr_all_pcent[69]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,93s+,84s+,74s+,64s+,53s+,A2o+,K2o+,Q3o+,J5o+,T6o+,96o+,86o+,76o";
    this->arr_all_pcent[70]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,93s+,84s+,74s+,63s+,53s+,43s,A2o+,K2o+,Q3o+,J5o+,T6o+,96o+,86o+,76o";
    this->arr_all_pcent[71]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,84s+,73s+,63s+,53s+,43s,A2o+,K2o+,Q3o+,J5o+,T6o+,96o+,86o+,76o,65o";
    this->arr_all_pcent[72]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,84s+,73s+,63s+,53s+,43s,A2o+,K2o+,Q2o+,J5o+,T6o+,96o+,86o+,76o,65o";
    this->arr_all_pcent[73]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,84s+,73s+,63s+,53s+,43s,A2o+,K2o+,Q2o+,J4o+,T6o+,96o+,86o+,76o,65o";
    this->arr_all_pcent[74]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,83s+,73s+,63s+,53s+,43s,A2o+,K2o+,Q2o+,J4o+,T6o+,96o+,86o+,75o+,65o";
    this->arr_all_pcent[75]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,83s+,73s+,63s+,52s+,43s,A2o+,K2o+,Q2o+,J4o+,T6o+,96o+,85o+,75o+,65o";
    this->arr_all_pcent[76]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,73s+,63s+,52s+,43s,A2o+,K2o+,Q2o+,J4o+,T6o+,96o+,85o+,75o+,65o";
    this->arr_all_pcent[77]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,73s+,63s+,52s+,43s,A2o+,K2o+,Q2o+,J4o+,T5o+,96o+,85o+,75o+,65o";
    this->arr_all_pcent[78]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,73s+,63s+,52s+,43s,A2o+,K2o+,Q2o+,J3o+,T5o+,95o+,85o+,75o+,65o";
    this->arr_all_pcent[79]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,73s+,62s+,52s+,43s,A2o+,K2o+,Q2o+,J3o+,T5o+,95o+,85o+,75o+,65o";
    this->arr_all_pcent[80]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,73s+,62s+,52s+,43s,A2o+,K2o+,Q2o+,J3o+,T5o+,95o+,85o+,75o+,65o,54o";
    this->arr_all_pcent[81]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,73s+,62s+,52s+,42s+,A2o+,K2o+,Q2o+,J3o+,T4o+,95o+,85o+,75o+,65o,54o";
    this->arr_all_pcent[82]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,73s+,62s+,52s+,42s+,A2o+,K2o+,Q2o+,J2o+,T4o+,95o+,85o+,75o+,65o,54o";
    this->arr_all_pcent[83]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,A2o+,K2o+,Q2o+,J2o+,T4o+,95o+,85o+,75o+,64o+,54o";
    this->arr_all_pcent[84]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,A2o+,K2o+,Q2o+,J2o+,T3o+,95o+,85o+,75o+,64o+,54o";
    this->arr_all_pcent[85]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T3o+,95o+,85o+,74o+,64o+,54o";
    this->arr_all_pcent[86]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T3o+,95o+,84o+,74o+,64o+,54o";
    this->arr_all_pcent[87]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,95o+,84o+,74o+,64o+,54o";
    this->arr_all_pcent[88]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,94o+,84o+,74o+,64o+,54o";
    this->arr_all_pcent[89]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,94o+,84o+,74o+,64o+,53o+";
    this->arr_all_pcent[90]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,93o+,84o+,74o+,64o+,53o+";
    this->arr_all_pcent[91]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,93o+,84o+,74o+,63o+,53o+,43o";
    this->arr_all_pcent[92]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,84o+,74o+,63o+,53o+,43o";
    this->arr_all_pcent[93]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,84o+,73o+,63o+,53o+,43o";
    this->arr_all_pcent[94]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,83o+,73o+,63o+,53o+,43o";
    this->arr_all_pcent[95]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,83o+,73o+,63o+,52o+,43o";
    this->arr_all_pcent[96]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,83o+,73o+,63o+,52o+,43o";
    this->arr_all_pcent[97]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,82o+,73o+,63o+,52o+,42o+";
    this->arr_all_pcent[98]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,82o+,73o+,62o+,52o+,42o+";
    this->arr_all_pcent[99]="22+,A2s+,K2s+,Q2s+,J2s+,T2s+,92s+,82s+,72s+,62s+,52s+,42s+,32s,A2o+,K2o+,Q2o+,J2o+,T2o+,92o+,82o+,72o+,62o+,52o+,42o+,32o";

//    //SI ACTIVO ESTO DESAPARECEN LOS COMBOS AL SELECCIONARLOS
//    cardMatrix=new QButtonGroup(this);
//    cardMatrix->addButton(ui->combo_AA);
//    cardMatrix->addButton(ui->combo_KK);
//    cardMatrix->addButton(ui->combo_QQ);
//    cardMatrix->addButton(ui->combo_JJ);
//    cardMatrix->addButton(ui->combo_TT);
//    cardMatrix->addButton(ui->combo_99);
//    cardMatrix->addButton(ui->combo_88);
//    cardMatrix->addButton(ui->combo_77);
//    cardMatrix->addButton(ui->combo_66);
//    cardMatrix->addButton(ui->combo_55);
//    cardMatrix->addButton(ui->combo_44);
//    cardMatrix->addButton(ui->combo_33);
//    cardMatrix->addButton(ui->combo_22);
//    cardMatrix->addButton(ui->combo_AKs);
//    cardMatrix->addButton(ui->combo_AQs);
//    cardMatrix->addButton(ui->combo_AJs);
//    cardMatrix->addButton(ui->combo_ATs);
//    cardMatrix->addButton(ui->combo_A9s);
//    cardMatrix->addButton(ui->combo_A8s);
//    cardMatrix->addButton(ui->combo_A7s);
//    cardMatrix->addButton(ui->combo_A6s);
//    cardMatrix->addButton(ui->combo_A5s);
//    cardMatrix->addButton(ui->combo_A4s);
//    cardMatrix->addButton(ui->combo_A3s);
//    cardMatrix->addButton(ui->combo_A2s);
//    cardMatrix->addButton(ui->combo_KQs);
//    cardMatrix->addButton(ui->combo_KJs);
//    cardMatrix->addButton(ui->combo_KTs);
//    cardMatrix->addButton(ui->combo_K9s);
//    cardMatrix->addButton(ui->combo_K8s);
//    cardMatrix->addButton(ui->combo_K7s);
//    cardMatrix->addButton(ui->combo_K6s);
//    cardMatrix->addButton(ui->combo_K5s);
//    cardMatrix->addButton(ui->combo_K4s);
//    cardMatrix->addButton(ui->combo_K3s);
//    cardMatrix->addButton(ui->combo_K2s);
//    cardMatrix->addButton(ui->combo_QJs);
//    cardMatrix->addButton(ui->combo_QTs);
//    cardMatrix->addButton(ui->combo_Q9s);
//    cardMatrix->addButton(ui->combo_Q8s);
//    cardMatrix->addButton(ui->combo_Q7s);
//    cardMatrix->addButton(ui->combo_Q6s);
//    cardMatrix->addButton(ui->combo_Q5s);
//    cardMatrix->addButton(ui->combo_Q4s);
//    cardMatrix->addButton(ui->combo_Q3s);
//    cardMatrix->addButton(ui->combo_Q2s);
//    cardMatrix->addButton(ui->combo_JTs);
//    cardMatrix->addButton(ui->combo_J9s);
//    cardMatrix->addButton(ui->combo_J8s);
//    cardMatrix->addButton(ui->combo_J7s);
//    cardMatrix->addButton(ui->combo_J6s);
//    cardMatrix->addButton(ui->combo_J5s);
//    cardMatrix->addButton(ui->combo_J4s);
//    cardMatrix->addButton(ui->combo_J3s);
//    cardMatrix->addButton(ui->combo_J2s);
//    cardMatrix->addButton(ui->combo_T9s);
//    cardMatrix->addButton(ui->combo_T8s);
//    cardMatrix->addButton(ui->combo_T7s);
//    cardMatrix->addButton(ui->combo_T6s);
//    cardMatrix->addButton(ui->combo_T5s);
//    cardMatrix->addButton(ui->combo_T4s);
//    cardMatrix->addButton(ui->combo_T3s);
//    cardMatrix->addButton(ui->combo_T2s);
//    cardMatrix->addButton(ui->combo_98s);
//    cardMatrix->addButton(ui->combo_97s);
//    cardMatrix->addButton(ui->combo_96s);
//    cardMatrix->addButton(ui->combo_95s);
//    cardMatrix->addButton(ui->combo_94s);
//    cardMatrix->addButton(ui->combo_93s);
//    cardMatrix->addButton(ui->combo_92s);
//    cardMatrix->addButton(ui->combo_87s);
//    cardMatrix->addButton(ui->combo_86s);
//    cardMatrix->addButton(ui->combo_85s);
//    cardMatrix->addButton(ui->combo_84s);
//    cardMatrix->addButton(ui->combo_83s);
//    cardMatrix->addButton(ui->combo_82s);
//    cardMatrix->addButton(ui->combo_76s);
//    cardMatrix->addButton(ui->combo_75s);
//    cardMatrix->addButton(ui->combo_74s);
//    cardMatrix->addButton(ui->combo_73s);
//    cardMatrix->addButton(ui->combo_72s);
//    cardMatrix->addButton(ui->combo_65s);
//    cardMatrix->addButton(ui->combo_64s);
//    cardMatrix->addButton(ui->combo_63s);
//    cardMatrix->addButton(ui->combo_62s);
//    cardMatrix->addButton(ui->combo_54s);
//    cardMatrix->addButton(ui->combo_53s);
//    cardMatrix->addButton(ui->combo_52s);
//    cardMatrix->addButton(ui->combo_43s);
//    cardMatrix->addButton(ui->combo_42s);
//    cardMatrix->addButton(ui->combo_32s);
//    cardMatrix->addButton(ui->combo_AKo);
//    cardMatrix->addButton(ui->combo_AQo);
//    cardMatrix->addButton(ui->combo_AJo);
//    cardMatrix->addButton(ui->combo_ATo);
//    cardMatrix->addButton(ui->combo_A9o);
//    cardMatrix->addButton(ui->combo_A8o);
//    cardMatrix->addButton(ui->combo_A7o);
//    cardMatrix->addButton(ui->combo_A6o);
//    cardMatrix->addButton(ui->combo_A5o);
//    cardMatrix->addButton(ui->combo_A4o);
//    cardMatrix->addButton(ui->combo_A3o);
//    cardMatrix->addButton(ui->combo_A2o);
//    cardMatrix->addButton(ui->combo_KQo);
//    cardMatrix->addButton(ui->combo_KJo);
//    cardMatrix->addButton(ui->combo_KTo);
//    cardMatrix->addButton(ui->combo_K9o);
//    cardMatrix->addButton(ui->combo_K8o);
//    cardMatrix->addButton(ui->combo_K7o);
//    cardMatrix->addButton(ui->combo_K6o);
//    cardMatrix->addButton(ui->combo_K5o);
//    cardMatrix->addButton(ui->combo_K4o);
//    cardMatrix->addButton(ui->combo_K3o);
//    cardMatrix->addButton(ui->combo_K2o);
//    cardMatrix->addButton(ui->combo_QJo);
//    cardMatrix->addButton(ui->combo_QTo);
//    cardMatrix->addButton(ui->combo_Q9o);
//    cardMatrix->addButton(ui->combo_Q8o);
//    cardMatrix->addButton(ui->combo_Q7o);
//    cardMatrix->addButton(ui->combo_Q6o);
//    cardMatrix->addButton(ui->combo_Q5o);
//    cardMatrix->addButton(ui->combo_Q4o);
//    cardMatrix->addButton(ui->combo_Q3o);
//    cardMatrix->addButton(ui->combo_Q2o);
//    cardMatrix->addButton(ui->combo_JTo);
//    cardMatrix->addButton(ui->combo_J9o);
//    cardMatrix->addButton(ui->combo_J8o);
//    cardMatrix->addButton(ui->combo_J7o);
//    cardMatrix->addButton(ui->combo_J6o);
//    cardMatrix->addButton(ui->combo_J5o);
//    cardMatrix->addButton(ui->combo_J4o);
//    cardMatrix->addButton(ui->combo_J3o);
//    cardMatrix->addButton(ui->combo_J2o);
//    cardMatrix->addButton(ui->combo_T9o);
//    cardMatrix->addButton(ui->combo_T8o);
//    cardMatrix->addButton(ui->combo_T7o);
//    cardMatrix->addButton(ui->combo_T6o);
//    cardMatrix->addButton(ui->combo_T5o);
//    cardMatrix->addButton(ui->combo_T4o);
//    cardMatrix->addButton(ui->combo_T3o);
//    cardMatrix->addButton(ui->combo_T2o);
//    cardMatrix->addButton(ui->combo_98o);
//    cardMatrix->addButton(ui->combo_97o);
//    cardMatrix->addButton(ui->combo_96o);
//    cardMatrix->addButton(ui->combo_95o);
//    cardMatrix->addButton(ui->combo_94o);
//    cardMatrix->addButton(ui->combo_93o);
//    cardMatrix->addButton(ui->combo_92o);
//    cardMatrix->addButton(ui->combo_87o);
//    cardMatrix->addButton(ui->combo_86o);
//    cardMatrix->addButton(ui->combo_85o);
//    cardMatrix->addButton(ui->combo_84o);
//    cardMatrix->addButton(ui->combo_83o);
//    cardMatrix->addButton(ui->combo_82o);
//    cardMatrix->addButton(ui->combo_76o);
//    cardMatrix->addButton(ui->combo_75o);
//    cardMatrix->addButton(ui->combo_74o);
//    cardMatrix->addButton(ui->combo_73o);
//    cardMatrix->addButton(ui->combo_72o);
//    cardMatrix->addButton(ui->combo_65o);
//    cardMatrix->addButton(ui->combo_64o);
//    cardMatrix->addButton(ui->combo_63o);
//    cardMatrix->addButton(ui->combo_62o);
//    cardMatrix->addButton(ui->combo_54o);
//    cardMatrix->addButton(ui->combo_53o);
//    cardMatrix->addButton(ui->combo_52o);
//    cardMatrix->addButton(ui->combo_43o);
//    cardMatrix->addButton(ui->combo_42o);
//    cardMatrix->addButton(ui->combo_32o);
}
