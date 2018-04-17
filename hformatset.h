#ifndef HFORMATSET_H
#define HFORMATSET_H

#include <QWidget>
#include "hconfigapi.h"

namespace Ui {
class FormatSet;
}

class HFormatSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit HFormatSetTab(QWidget *parent = 0);
    ~HFormatSetTab();
public:
    void initTab();
    void writeData();
    void readData();
    void clear();

public slots:
    void addHeadTail();
    //void showHeadTail();
    void prefix();
    void suffix();
    void fixlength();
    void modifyPreTicketNum();
    void modifySerialNum();
public:
    HSysSetList* pSysSetList;
private:
    Ui::FormatSet *ui;
};

#endif // HFORMATSET_H
