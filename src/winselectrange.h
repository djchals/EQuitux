#ifndef WINSELECTRANGE_H
#define WINSELECTRANGE_H

#include <QDialog>
//rangeslider
#include <QHBoxLayout>
#include "RangeSlider.h"
#include <QButtonGroup>

//import from header.h
extern char arr_int_to_let[15];
extern int arr_let_to_int[85];
extern int arr_suit_to_int[116];
extern char arr_int_to_suit[4];
extern char HERO_COMBOS[6][1326][7];

//import from conv_pkr.h
void conv_range_pkr_to_hex(char tmp_range[],int i_player);
extern int reverse_hex(int tmp_hex);

namespace Ui {
    class WinSelectRange;
}

class WinSelectRange : public QDialog
{
    Q_OBJECT
public:
    explicit WinSelectRange(QWidget *parent = 0);
    ~WinSelectRange();
    void setSelectedRange(int act_range);
    void putComboOnRange(int num1, int num2,int flag_suited, bool flag_checked, bool flag_checked_suit_selector);
    void changeSuitSelector();
    QString getRange();
    void initRange(QString str_range, int i_player,bool flag_no_print_it);
    void convArrCombosToString(bool flag_separated_range);
    void initPcents();
    void unCheckAllCombos();
    void clearData();

private slots:
    void updatePFRVPIP();
    void savePFRVPIP();

private:
    Ui::WinSelectRange *ui;
    QString all_range;
    QString separated_range;
    int selected_range=0;
    bool arr_combos[0x3e3f]={};
    int arr_tmp_delete[0x3e3f]={0};

    QString old_separated;
    QString arr_all_pcent[100];
    bool cardMatrix[100][169]={false};
    QString arr_button_names[169];
    bool flag_pending_save=false;
    //rangeslider
    QWidget *widget;
    RangeSlider *RangePFRVPIP;
    QHBoxLayout *layout;
};

#endif // WINSELECTRANGE_H
