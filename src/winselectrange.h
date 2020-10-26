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
    void putComboOnRange(int act_combo);
    void changeSuitSelector();

private:
    Ui::WinSelectRange *ui;
    int selected_range=0;
    int arr_combos[1326]={};
};

#endif // WINSELECTRANGE_H
