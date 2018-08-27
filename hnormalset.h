#ifndef NORMALSET_H
#define NORMALSET_H

#include <QWidget>
#include "hconfigapi.h"
namespace Ui {
class NormalSet;
}

class HNormalSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit HNormalSetTab(QWidget *parent = 0);
    ~HNormalSetTab();

    void initTab();
    void writeData();
    void readData();
    void clear();

public:
    HSysSetList* pSysSetList;
private:
    Ui::NormalSet *ui;
    QString strYXChangeColor;
    QString strManualColor;
    QString strRepairColor;
    QString strWFStatusColor;


private slots:
    void yxOpenPath();
    void yxClosePath();
    void statusFailPath();
    void ruleFailPath();

    void yxChangeColor();
    void yxManualColor();
    void repairColor();
    void wfStatusColor();
};

#endif // NORMALSET_H
