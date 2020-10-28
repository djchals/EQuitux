#ifndef WINSELECTRANGE_H
#define WINSELECTRANGE_H

#include <QDialog>

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
    void putComboOnRange(int num1, int num2,int flag_suited, bool flag_checked);
    void changeSuitSelector();

private:
    Ui::WinSelectRange *ui;
    int selected_range=0;
    int arr_combos[0x3e3f]={};
    int reverse_hex(int tmp_hex);
};

#endif // WINSELECTRANGE_H
