#ifndef HNETSET_H
#define HNETSET_H

#include <QWidget>
#include "sysconfigapi.h"

namespace Ui {
class NetSet;
}

class HNetSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit HNetSetTab(QWidget *parent = 0);
    ~HNetSetTab();
    void initTab();
    void writeData();
    void readData();
    void clear();

public:
    HSysSetList* pSysSetList;
private:
    Ui::NetSet *ui;
};

#endif // HNETSET_H
