#include "hnormalset.h"
#include "ui_normalset.h"
#include <QFileDialog>
#include <QDir>
#include <QColorDialog>

HNormalSetTab::HNormalSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalSet)
{
    ui->setupUi(this);
    pSysSetList = NULL;
    initTab();
}

HNormalSetTab::~HNormalSetTab()
{
    delete ui;
    clear();
}

void HNormalSetTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
    pSysSetList->clear();
}

void HNormalSetTab::initTab()
{
    clear();
    //时间设置
    ui->VYXTimeEdit->setText("30");
    ui->batYXTimeEdit->setText("30");
    ui->passwordTime->setText("60");

    //声音设置
    ui->yxopenEdit->setText("");
    ui->yxcloseEdit->setText("");
    ui->statusFailEdit->setText("");
    ui->ruleFailEdit->setText("");
    //创建按钮部分
    connect(ui->yxopenBtn,SIGNAL(clicked()),this,SLOT(yxOpenPath()));
    connect(ui->yxcloseBtn,SIGNAL(clicked()),this,SLOT(yxClosePath()));
    connect(ui->statusFailBtn,SIGNAL(clicked()),this,SLOT(statusFailPath()));
    connect(ui->ruleFailBtn,SIGNAL(clicked()),this,SLOT(ruleFailPath()));

    //颜色设置
    QString strBtnBackgoundColor;
    strYXChangeColor = "#FF0000";
    strBtnBackgoundColor = QString("background-color:")+ strYXChangeColor;
    ui->yxChangeColorBtn->setStyleSheet(strBtnBackgoundColor);
    strManualColor = "#A8A8A8";
    strBtnBackgoundColor = QString("background-color:")+ strManualColor;
    ui->yxManualColorBtn->setStyleSheet(strBtnBackgoundColor);
    strRepairColor = "#EE00EE";
    strBtnBackgoundColor = QString("background-color:")+ strRepairColor;
    ui->repairColorBtn->setStyleSheet(strBtnBackgoundColor);
    strWFStatusColor = "#A0522D";
    strBtnBackgoundColor = QString("background-color:")+ strWFStatusColor;
    ui->wfStatusColorBtn->setStyleSheet(strBtnBackgoundColor);

    connect(ui->yxChangeColorBtn,SIGNAL(clicked()),this,SLOT(yxChangeColor()));
    connect(ui->yxManualColorBtn,SIGNAL(clicked()),this,SLOT(yxManualColor()));
    connect(ui->repairColorBtn,SIGNAL(clicked()),this,SLOT(repairColor()));
    connect(ui->wfStatusColorBtn,SIGNAL(clicked()),this,SLOT(wfStatusColor()));

    //遥控选择
    ui->ykSelectTimeEdit->setText("30");
    ui->ykOperaTimeEdit->setText("30");
    ui->doubleYXTimeEdit->setText("30");
    ui->YKGuardCheck->setChecked(false);
    ui->YKCheckNameCheck->setChecked(false);
    ui->numberCaseCheck->setChecked(false);


}

void HNormalSetTab::readData()
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i < pSysSetList->count();i++)
    {
        SYSSET *sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            if(sysSet->id == SYS_PASSWORD_VALID_TIME)
            {
                ui->passwordTime->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_SEND_VIRTUAL_YX_TIME)
            {
                ui->VYXTimeEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_BAT_YX_VALID_TIME)
            {
                ui->batYXTimeEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_YX_CLOSE_SOUND)
            {
                ui->yxcloseEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_YX_OPEN_SOUND)
            {
                ui->yxopenEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_STATUS_CHECK_FAIL_SOUND)
            {
                ui->statusFailEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_RULE_CHECK_FAIL_SOUND)
            {
                ui->ruleFailEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_YX_CHANGE_COLOR)
            {
                QString strYXChangeColor = "background-color:" + sysSet->var.toString();
                ui->yxChangeColorBtn->setStyleSheet(strYXChangeColor);

            }
            else if(sysSet->id == SYS_YX_MANUAL_COLOR)
            {
                QString strManualColor = "background-color:" + sysSet->var.toString();
                ui->yxManualColorBtn->setStyleSheet(strManualColor);

            }
            else if(sysSet->id == SYS_YX_REPAIR_COLOR)
            {
                QString strRepairColor = "background-color:" + sysSet->var.toString();
                ui->repairColorBtn->setStyleSheet(strRepairColor);

            }
            else if(sysSet->id == SYS_WF_STATUS_COLOR)
            {
                QString strWFStatusColor = "background-color:" + sysSet->var.toString();
                ui->wfStatusColorBtn->setStyleSheet(strWFStatusColor);
            }
            else if(sysSet->id == SYS_CTRL_SELECT_TIMEOUT)
            {
                ui->ykSelectTimeEdit->setText(sysSet->var.toString());

            }
            else if(sysSet->id == SYS_CTRL_EXECUTE_TIMEOUT)
            {
                ui->ykOperaTimeEdit->setText(sysSet->var.toString());

            }
            else if(sysSet->id == SYS_CTRL_DOUBLEYX_TIMEOUT)
            {
                ui->doubleYXTimeEdit->setText(sysSet->var.toString());

            }
            else if(sysSet->id == SYS_CTRL_GUARD)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->YKGuardCheck->setChecked(bChecked);

            }
            else if(sysSet->id == SYS_CTRL_FORCED_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->YKCheckNameCheck->setChecked(bChecked);

            }
            else if(sysSet->id == SYS_NUMBER_CASE_SENSITIVE)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                 ui->numberCaseCheck->setChecked(bChecked);
            }
        }
    }
}

void HNormalSetTab::writeData()
{
    clear();
    //时间设置
    SYSSET *passwordTime = new SYSSET;
    if(passwordTime)
    {
        passwordTime->id = SYS_PASSWORD_VALID_TIME;
        passwordTime->var = QVariant(ui->passwordTime->text());
        pSysSetList->append(passwordTime);
    }

    SYSSET *VYXTime = new SYSSET;
    if(VYXTime)
    {
        VYXTime->id = SYS_SEND_VIRTUAL_YX_TIME;
        VYXTime->var = QVariant(ui->VYXTimeEdit->text());
        pSysSetList->append(VYXTime);
    }

    SYSSET *batYXTime = new SYSSET;
    if(batYXTime)
    {
        batYXTime->id = SYS_BAT_YX_VALID_TIME;
        batYXTime->var = QVariant(ui->batYXTimeEdit->text());
        pSysSetList->append(batYXTime);
    }

    //声音设置
    SYSSET *yxclose = new SYSSET;
    if(yxclose)
    {
        yxclose->id = SYS_YX_CLOSE_SOUND;
        yxclose->var = QVariant(ui->yxcloseEdit->text());
        pSysSetList->append(yxclose);
    }

    SYSSET *yxopen = new SYSSET;
    if(yxopen)
    {
        yxopen->id = SYS_YX_OPEN_SOUND;
        yxopen->var = QVariant(ui->yxopenEdit->text());
        pSysSetList->append(yxopen);
    }

    SYSSET *statusFail = new SYSSET;
    if(statusFail)
    {
        statusFail->id = SYS_STATUS_CHECK_FAIL_SOUND;
        statusFail->var = QVariant(ui->statusFailEdit->text());
        pSysSetList->append(statusFail);
    }

    SYSSET *ruleFail = new SYSSET;
    if(ruleFail)
    {
        ruleFail->id = SYS_RULE_CHECK_FAIL_SOUND;
        ruleFail->var = QVariant(ui->ruleFailEdit->text());
        pSysSetList->append(ruleFail);
    }

    //颜色设置
    SYSSET *yxChangeColor = new SYSSET;
    if(yxChangeColor)
    {
        yxChangeColor->id = SYS_YX_CHANGE_COLOR;
        yxChangeColor->var = QVariant(ui->yxChangeColorBtn->text());
        pSysSetList->append(yxChangeColor);
    }

    SYSSET *yxManualColor = new SYSSET;
    if(yxManualColor)
    {
        yxManualColor->id = SYS_YX_MANUAL_COLOR;
        yxManualColor->var = QVariant(ui->yxManualColorBtn->text());
        pSysSetList->append(yxManualColor);
    }

    SYSSET *repairColor = new SYSSET;
    if(repairColor)
    {
        repairColor->id = SYS_YX_REPAIR_COLOR;
        repairColor->var = QVariant(ui->repairColorBtn->text());
        pSysSetList->append(repairColor);
    }

    SYSSET *wfStatusColor = new SYSSET;
    if(wfStatusColor)
    {
        wfStatusColor->id = SYS_RULE_CHECK_FAIL_SOUND;
        wfStatusColor->var = QVariant(ui->wfStatusColorBtn->text());
        pSysSetList->append(wfStatusColor);
    }

    //遥控设置
    SYSSET *ykSelectTime = new SYSSET;
    if(ykSelectTime)
    {
        ykSelectTime->id = SYS_CTRL_SELECT_TIMEOUT;
        ykSelectTime->var = QVariant(ui->ykSelectTimeEdit->text());
        pSysSetList->append(ykSelectTime);
    }

    SYSSET *ykOperaTime = new SYSSET;
    if(ykOperaTime)
    {
        ykOperaTime->id = SYS_CTRL_EXECUTE_TIMEOUT;
        ykOperaTime->var = QVariant(ui->ykOperaTimeEdit->text());
        pSysSetList->append(ykOperaTime);
    }

    SYSSET *doubleYXTime = new SYSSET;
    if(doubleYXTime)
    {
        doubleYXTime->id = SYS_CTRL_DOUBLEYX_TIMEOUT;
        doubleYXTime->var = QVariant(ui->doubleYXTimeEdit->text());
        pSysSetList->append(doubleYXTime);
    }

    SYSSET *YKGuardCheck = new SYSSET;
    if(YKGuardCheck)
    {
        YKGuardCheck->id = SYS_CTRL_GUARD;
        YKGuardCheck->var = QVariant(ui->wfStatusColorBtn->text());
        pSysSetList->append(YKGuardCheck);
    }

    SYSSET *YKCheckNameCheck = new SYSSET;
    if(YKCheckNameCheck)
    {
        YKCheckNameCheck->id = SYS_CTRL_FORCED_CHECK;
        YKCheckNameCheck->var = QVariant(ui->wfStatusColorBtn->text());
        pSysSetList->append(YKCheckNameCheck);
    }

    SYSSET *numberCaseCheck = new SYSSET;
    if(numberCaseCheck)
    {
        numberCaseCheck->id = SYS_NUMBER_CASE_SENSITIVE;
        numberCaseCheck->var = QVariant(ui->wfStatusColorBtn->text());
        pSysSetList->append(numberCaseCheck);
    }
}

void HNormalSetTab::yxOpenPath()
{
    QString strPath = QDir::currentPath();
    strPath += "sound";
    QString fileName = QFileDialog::getOpenFileName(this,
        QStringLiteral("打开声音文件"), strPath, tr("Sound Files (*.wva)"));
    ui->yxopenEdit->setText(fileName);
}

void HNormalSetTab::yxClosePath()
{
    QString strPath = QDir::currentPath();
    strPath += "sound";
    QString fileName = QFileDialog::getOpenFileName(this,
        QStringLiteral("打开声音文件"), strPath, tr("Sound Files (*.wva)"));
    ui->yxcloseEdit->setText(fileName);
}

void HNormalSetTab::statusFailPath()
{
    QString strPath = QDir::currentPath();
    strPath += "sound";
    QString fileName = QFileDialog::getOpenFileName(this,
        QStringLiteral("打开声音文件"), strPath, tr("Sound Files (*.wva)"));
    ui->statusFailEdit->setText(fileName);
}

void HNormalSetTab::ruleFailPath()
{
    QString strPath = QDir::currentPath();
    //strPath += "sound";
    QString fileName = QFileDialog::getOpenFileName(this,
        QStringLiteral("打开声音文件"), strPath, tr("Sound Files (*.wva)"));
    ui->ruleFailEdit->setText(fileName);
}

void HNormalSetTab::yxChangeColor()
{
    QColor curColor = QColor(strYXChangeColor);
    const QColor color = QColorDialog::getColor(curColor, this, QStringLiteral("选择颜色"));
    if(!color.isValid()) return;
    strYXChangeColor = color.name(QColor::HexRgb);
    ui->yxChangeColorBtn->setStyleSheet(QString("background-color:") + strYXChangeColor);
}

void HNormalSetTab::yxManualColor()
{
    QColor curColor = QColor(strManualColor);
    const QColor color = QColorDialog::getColor(curColor, this, QStringLiteral("选择颜色"));
    if(!color.isValid()) return;
    strManualColor = color.name(QColor::HexRgb);
    ui->yxManualColorBtn->setStyleSheet(QString("background-color:")+strManualColor);
}

void HNormalSetTab::repairColor()
{
    QColor curColor = QColor(strRepairColor);
    const QColor color = QColorDialog::getColor(curColor, this, QStringLiteral("选择颜色"));
    if(!color.isValid()) return;
    strRepairColor = color.name(QColor::HexRgb);
    ui->repairColorBtn->setStyleSheet(QString("background-color:")+strRepairColor);
}

void HNormalSetTab::wfStatusColor()
{
    QColor curColor = QColor(strWFStatusColor);
    const QColor color = QColorDialog::getColor(curColor, this, QStringLiteral("选择颜色"));
    if(!color.isValid()) return;
    strWFStatusColor = color.name(QColor::HexRgb);
    ui->wfStatusColorBtn->setStyleSheet(QString("background-color:")+strWFStatusColor);
}
