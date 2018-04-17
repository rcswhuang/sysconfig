#ifndef HOTHERSETTAB_H
#define HOTHERSETTAB_H

#include <QWidget>
#include "hconfigapi.h"
namespace Ui {
class OtherSet;
}

class HOtherSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit HOtherSetTab(QWidget *parent = 0);
    ~HOtherSetTab();
    void initTab();
    void writeData();
    void readData();
    void clear();

public:
    HSysSetList* pSysSetList;
private:
    Ui::OtherSet *ui;
};

#endif // HOTHERSETTAB_H
