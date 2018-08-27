#ifndef FUNSET_H
#define FUNSET_H

#include <QWidget>
#include "hconfigapi.h"

namespace Ui {
class FunSet;
}

class HFunSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit HFunSetTab(QWidget *parent = 0);
    ~HFunSetTab();

public:
    void initTab();
    void writeData();
    void readData();
    void clear();


public:
    HSysSetList* pSysSetList;
private:
    Ui::FunSet *ui;
};

#endif // FUNSET_H
