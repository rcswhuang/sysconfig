﻿#ifndef HSYSCONFIGDLG_H
#define HSYSCONFIGDLG_H

#include <QDialog>
#include <QTabWidget>
#include "hsysconfig.h"
#include "hnormalset.h"
#include "hnetset.h"
#include "hsyspathset.h"
#include "hfunset.h"
#include "hticketnoset.h"
#include "hformatset.h"
#include "hotherset.h"

#include "hxml.h"

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
    //HSysConfig* pSysConfig;
};

#endif // HSYSCONFIG_H