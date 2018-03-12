#include "hsysconfigdlg.h"
#include "ui_sysconfig.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabBar>
HSysConfigDlg::HSysConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SysConfig)
{
    ui->setupUi(this);
    initTab();
}

HSysConfigDlg::~HSysConfigDlg()
{
    delete ui;
}

void HSysConfigDlg::initTab()
{
    //加载xml等配置文件
    //pSysConfig = new HSysConfig;

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
    pNormalSetTab = new HNormalSetTab(this);
    pConfigTabWidget->addTab(pNormalSetTab,QStringLiteral("一般设置"));
    pSysPathTab = new HSysPathTab(this);
    pConfigTabWidget->addTab(pSysPathTab,QStringLiteral("路径设置"));
    pFunSetTab = new HFunSetTab(this);
    pConfigTabWidget->addTab(pFunSetTab,QStringLiteral("功能设置"));
    pWorkNoteSetTab = new HWorkNoteSetTab(this);
    pConfigTabWidget->addTab(pWorkNoteSetTab,QStringLiteral("操作票设置"));
    pFormatSetTab = new HFormatSetTab(this);
    pConfigTabWidget->addTab(pFormatSetTab,QStringLiteral("操作票号设置"));
    pOtherSetTab = new HOtherSetTab(this);
    pConfigTabWidget->addTab(pOtherSetTab,QStringLiteral("其他设置"));

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(pConfigTabWidget);

    QHBoxLayout* btnLayout = new QHBoxLayout;
    btnLayout->addStretch(400);
    btnLayout->addWidget(ui->okBtn);
    btnLayout->addWidget(ui->cancelBtn);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
}
