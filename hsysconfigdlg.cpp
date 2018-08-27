#if defined(_MSC_VER) &&(_MSC_VER >=1600)
#pragma execution_character_set("utf-8")
#endif
#include "hsysconfigdlg.h"
#include "ui_sysconfig.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabBar>
#include <QMessageBox>
#include "hconfigapi.h"

/*
 * 获取系统配置文件目录:../WFS-9800/wfconfig.xml
 * 1.获取系统变量 wfsystem_dir=../WFS-9800
 * 2.如果获取不到系统变量，只能获取文件当前目录的父目录，当前目录应该是../WFS-9800/bin
*/
HSysConfigDlg::HSysConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SysConfig)
{
    ui->setupUi(this);

    initSysConfig();

    initTab();
}

HSysConfigDlg::~HSysConfigDlg()
{
    delete ui;
    exitSysConfig();
}

void HSysConfigDlg::initTab()
{
    //加载xml等配置文件
    //pSysConfig = new HSysConfig;
    connect(ui->okBtn,SIGNAL(clicked(bool)),this,SLOT(ok_clicked()));
    connect(ui->cancelBtn,SIGNAL(clicked(bool)),this,SLOT(cancle_clicked()));
    connect(ui->applyBtn,SIGNAL(clicked(bool)),this,SLOT(apply_clicked()));
    pConfigTabWidget = new QTabWidget;
    QString tabBarStyle = "QTabWidget::pane { border-top: 2px solid #C2C7CB;} \
                            QTabWidget::tab-bar { left: 5px; } \
            QTabBar::tab {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, \
            stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\
            stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3); \
            border: 2px solid #C4C4C3; \
            border-bottom-color: #C2C7CB; \
            border-top-left-radius: 4px; \
            border-top-right-radius: 4px; \
            min-width: 8ex;\
            padding: 2px; \
        } \
        QTabBar::tab:selected, QTabBar::tab:hover { \
            background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, \
                                        stop: 0 #fafafa, stop: 0.4 #f4f4f4, \
                                        stop: 0.5 #e7e7e7, stop: 1.0 #fafafa); \
        } \
        QTabBar::tab:selected { \
            border-color: #9B9B9B;  \
            border-bottom-color: #C2C7CB; \
        } \
        QTabBar::tab:!selected {margin-top: 2px; }";
    pConfigTabWidget->setStyleSheet(tabBarStyle);

    pNetSetTab = new HNetSetTab(this);
    pConfigTabWidget->addTab(pNetSetTab,QStringLiteral("网络设置"));
    getSysConfigByID(SYS_SET_NET,pNetSetTab->pSysSetList);
    pNetSetTab->readData();
    pNormalSetTab = new HNormalSetTab(this);
    pConfigTabWidget->addTab(pNormalSetTab,QStringLiteral("一般设置"));
    getSysConfigByID(SYS_SET_NORMAL,pNormalSetTab->pSysSetList);
    pNormalSetTab->readData();
    pSysPathTab = new HSysPathTab(this);
    pConfigTabWidget->addTab(pSysPathTab,QStringLiteral("路径设置"));
    getSysConfigByID(SYS_SET_PATH,pSysPathTab->pSysSetList);
    pSysPathTab->readData();
    pFunSetTab = new HFunSetTab(this);
    pConfigTabWidget->addTab(pFunSetTab,QStringLiteral("功能设置"));
    getSysConfigByID(SYS_SET_FUN,pFunSetTab->pSysSetList);
    pFunSetTab->readData();
    pWorkNoteSetTab = new HWorkNoteSetTab(this);
    pConfigTabWidget->addTab(pWorkNoteSetTab,QStringLiteral("操作票设置"));
    getSysConfigByID(SYS_SET_TICKET,pWorkNoteSetTab->pSysSetList);
    pWorkNoteSetTab->readData();
    pFormatSetTab = new HFormatSetTab(this);
    pConfigTabWidget->addTab(pFormatSetTab,QStringLiteral("操作票号设置"));
    getSysConfigByID(SYS_SET_FORMAT,pFormatSetTab->pSysSetList);
    pFormatSetTab->readData();
    pOtherSetTab = new HOtherSetTab(this);
    pConfigTabWidget->addTab(pOtherSetTab,QStringLiteral("其他设置"));
    getSysConfigByID(SYS_SET_OTHER,pOtherSetTab->pSysSetList);
    pOtherSetTab->readData();
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(pConfigTabWidget);

    QHBoxLayout* btnLayout = new QHBoxLayout;
    btnLayout->addStretch(400);
    btnLayout->addWidget(ui->okBtn);
    btnLayout->addWidget(ui->cancelBtn);
    btnLayout->addWidget(ui->applyBtn);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
}

void HSysConfigDlg::apply()
{
    pNetSetTab->writeData();
    pNormalSetTab->writeData();
    pSysPathTab->writeData();
    pFunSetTab->writeData();
    pWorkNoteSetTab->writeData();
    pFormatSetTab->writeData();
    pOtherSetTab->writeData();
    applySysConfig();
}

void HSysConfigDlg::ok_clicked()
{
    apply();
    QMessageBox::information(NULL,"提示","系统配置保存后，需要重启系统",QMessageBox::Ok);
    QDialog::accept();
}

void HSysConfigDlg::cancle_clicked()
{
    QDialog::reject();
}

void HSysConfigDlg::apply_clicked()
{
    apply();
}




