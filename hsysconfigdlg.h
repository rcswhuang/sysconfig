#ifndef HSYSCONFIGDLG_H
#define HSYSCONFIGDLG_H

#include <QDialog>
#include <QTabWidget>
#include "hnormalset.h"
#include "hnetset.h"
#include "hsyspathset.h"
#include "hfunset.h"
#include "hticketnoset.h"
#include "hformatset.h"
#include "hotherset.h"

class QTimer;
/*
SETTING* findSettingById(ushort wSettingId)
{
    return NULL;
}*/

namespace Ui {
class SysConfig;
}

class HSysConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit HSysConfigDlg(QWidget *parent = 0);
    ~HSysConfigDlg();
public:
    void initTab();
    void apply();

public slots:
    void ok_clicked();
    void cancle_clicked();
    void apply_clicked();
    void license_check();
private:
    Ui::SysConfig *ui;
public:
    QTabWidget* pConfigTabWidget;
    HNormalSetTab* pNormalSetTab;
    HNetSetTab* pNetSetTab;
    HSysPathTab* pSysPathTab;
    HFunSetTab* pFunSetTab;
    HWorkNoteSetTab* pWorkNoteSetTab;
    HFormatSetTab* pFormatSetTab;
    HOtherSetTab* pOtherSetTab;
    QTimer* m_timer;
    //HSysConfig* pSysConfig;
};

#endif // HSYSCONFIG_H
