#include "hnetset.h"
#include "ui_netset.h"
#include <QRegExp>
HNetSetTab::HNetSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetSet)
{
    ui->setupUi(this);
    pSysSetList = NULL;
    initTab();
}

HNetSetTab::~HNetSetTab()
{
    delete ui;
    clear();
}

void HNetSetTab::initTab()
{
    clear();
    //电脑钥匙
    QStringList strComSel;
    strComSel<<""<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->keyComSelCombo->addItems(strComSel);
    ui->keyComSelCombo->setCurrentIndex(0);

    QStringList strComBaut;
    strComBaut<<"9600,n,8,1";
    ui->keyComSetCombo->addItems(strComBaut);
    ui->keyComSetCombo->setCurrentIndex(0);

    ui->keyComTimeOut->setText("30");

    //模拟屏盘
    strComSel<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->mnpComSelCombo->addItems(strComSel);
    ui->mnpComSelCombo->setCurrentIndex(0);

    strComBaut<<"9600,n,8,1";
    ui->mnpComSetCombo->addItems(strComBaut);
    ui->mnpComSetCombo->setCurrentIndex(0);

    ui->mnpComTimeOut->setText("30");

    //优特
    strComSel<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->ytComSelCombo->addItems(strComSel);
    ui->ytComSelCombo->setCurrentIndex(0);

    strComBaut<<"9600,n,8,1";
    ui->ytComSetCombo->addItems(strComBaut);
    ui->ytComSetCombo->setCurrentIndex(0);

    ui->ytComTimeOut->setText("30");

    //模拟屏2
    strComSel<<""<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->mnp2ComSelCombo->addItems(strComSel);
    ui->mnp2ComSelCombo->setCurrentIndex(0);

    strComBaut<<"9600,n,8,1";
    ui->mnp2ComSetCombo->addItems(strComBaut);
    ui->mnp2ComSetCombo->setCurrentIndex(0);

    ui->mnp2ComTimeOut->setText("30");

    //闭锁控制器
    strComSel<<""<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->bsqComSelCombo->addItems(strComSel);
    ui->bsqComSelCombo->setCurrentIndex(0);

    strComBaut<<"9600,n,8,1";
    ui->bsqComSetCombo->addItems(strComBaut);
    ui->bsqComSetCombo->setCurrentIndex(0);

    ui->bsqComTimeOut->setText("30");

    //网络部分
    QRegExp rx("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
    QRegExpValidator *m_IPValidator = new QRegExpValidator(rx, this);
    ui->netAEdit->setValidator(m_IPValidator);
    ui->netBEdit->setValidator(m_IPValidator);

    ui->netAEdit->setText("198.120.0.0");
    ui->netBEdit->setText("198.121.0.0");
    ui->portEdit->setText("9999");

    //五防机编号
    ui->wfNumberEdit->setText("1");

}

void HNetSetTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
    pSysSetList->clear();
}

void HNetSetTab::readData()
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i< pSysSetList->count();i++)
    {
        SYSSET* sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            if(sysSet->id == SYS_KEY_COM_SELECT)
            {
                int index = ui->keyComSelCombo->findData(sysSet->var);
                ui->keyComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_KEY_COM_SET)
            {
                int index = ui->keyComSetCombo->findData(sysSet->var);
                ui->keyComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_KEY_COM_TIME)
            {
                ui->keyComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_MNP_COM_SELECT)
            {
                int index = ui->mnpComSelCombo->findData(sysSet->var);
                ui->mnpComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP_COM_SET)
            {
                int index = ui->mnpComSetCombo->findData(sysSet->var);
                ui->mnpComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP_COM_TIME)
            {
                ui->mnpComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_MNP2_COM_SELECT)
            {
                int index = ui->mnp2ComSelCombo->findData(sysSet->var);
                ui->mnp2ComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP2_COM_SET)
            {
                int index = ui->mnp2ComSetCombo->findData(sysSet->var);
                ui->mnp2ComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP2_COM_TIME)
            {
                ui->mnp2ComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_YT_COM_SELECT)
            {
                int index = ui->ytComSelCombo->findData(sysSet->var);
                ui->ytComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_YT_COM_SET)
            {
                int index = ui->ytComSetCombo->findData(sysSet->var);
                ui->ytComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_YT_COM_TIME)
            {
                ui->ytComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_BSQ_COM_SELECT)
            {
                int index = ui->bsqComSelCombo->findData(sysSet->var);
                ui->bsqComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_BSQ_COM_SET)
            {
                int index = ui->bsqComSelCombo->findData(sysSet->var);
                ui->bsqComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_BSQ_COM_TIME)
            {
                ui->bsqComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_WF_NET_IPA)
            {
                ui->netAEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_WF_NET_IPB)
            {
                ui->netBEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_WF_NET_PORT)
            {
                ui->portEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_WF_KEY_NUM)
            {
                ui->wfNumberEdit->setText(sysSet->var.toString());
            }
        }
    }
}

void HNetSetTab::writeData()
{
    clear();
    //电脑钥匙
    SYSSET *keyComSelect = new SYSSET;
    keyComSelect->id = SYS_KEY_COM_SELECT;
    keyComSelect->var = QVariant(ui->keyComSelCombo->currentText());
    pSysSetList->append(keyComSelect);

    SYSSET *keyComSet = new SYSSET;
    keyComSet->id = SYS_KEY_COM_SET;
    keyComSet->var = QVariant(ui->keyComSetCombo->currentText());
    pSysSetList->append(keyComSet);

    SYSSET *keyComTimeout = new SYSSET;
    keyComTimeout->id = SYS_KEY_COM_TIME;
    keyComTimeout->var = QVariant(ui->keyComTimeOut->text());
    pSysSetList->append(keyComTimeout);

    //模拟屏
    SYSSET *mnpComSelect = new SYSSET;
    mnpComSelect->id = SYS_MNP_COM_SELECT;
    mnpComSelect->var = QVariant(ui->mnpComSelCombo->currentText());
    pSysSetList->append(mnpComSelect);

    SYSSET *mnpComSet = new SYSSET;
    mnpComSet->id = SYS_MNP_COM_SELECT;
    mnpComSet->var = QVariant(ui->mnpComSetCombo->currentText());
    pSysSetList->append(mnpComSet);

    SYSSET *mnpComTimeout = new SYSSET;
    mnpComTimeout->id = SYS_MNP_COM_SELECT;
    mnpComTimeout->var = QVariant(ui->mnpComTimeOut->text());
    pSysSetList->append(mnpComTimeout);

    //模拟屏2
    SYSSET *mnp2ComSelect = new SYSSET;
    mnp2ComSelect->id = SYS_MNP2_COM_SELECT;
    mnp2ComSelect->var = QVariant(ui->mnp2ComSelCombo->currentText());
    pSysSetList->append(mnp2ComSelect);

    SYSSET *mnp2ComSet = new SYSSET;
    mnp2ComSet->id = SYS_MNP_COM_SELECT;
    mnp2ComSet->var = QVariant(ui->mnp2ComSetCombo->currentText());
    pSysSetList->append(mnp2ComSet);

    SYSSET *mnp2ComTimeout = new SYSSET;
    mnp2ComTimeout->id = SYS_MNP_COM_SELECT;
    mnp2ComTimeout->var = QVariant(ui->mnp2ComTimeOut->text());
    pSysSetList->append(mnp2ComTimeout);

    //优特
    SYSSET *ytComSelect = new SYSSET;
    ytComSelect->id = SYS_YT_COM_SELECT;
    ytComSelect->var = QVariant(ui->ytComSelCombo->currentText());
    pSysSetList->append(ytComSelect);

    SYSSET *ytComSet = new SYSSET;
    ytComSet->id = SYS_YT_COM_SELECT;
    ytComSet->var = QVariant(ui->ytComSetCombo->currentText());
    pSysSetList->append(ytComSet);

    SYSSET *ytComTimeout = new SYSSET;
    ytComTimeout->id = SYS_YT_COM_SELECT;
    ytComTimeout->var = QVariant(ui->ytComTimeOut->text());
    pSysSetList->append(ytComTimeout);

    //闭锁控制器
    SYSSET *bsqComSelect = new SYSSET;
    bsqComSelect->id = SYS_BSQ_COM_SELECT;
    bsqComSelect->var = QVariant(ui->bsqComSelCombo->currentText());
    pSysSetList->append(bsqComSelect);

    SYSSET *bsqComSet = new SYSSET;
    bsqComSet->id = SYS_BSQ_COM_SELECT;
    bsqComSet->var = QVariant(ui->bsqComSetCombo->currentText());
    pSysSetList->append(bsqComSet);

    SYSSET *bsqComTimeout = new SYSSET;
    bsqComTimeout->id = SYS_BSQ_COM_SELECT;
    bsqComTimeout->var = QVariant(ui->bsqComTimeOut->text());
    pSysSetList->append(bsqComTimeout);

    //五防网络
    SYSSET *wfNetA = new SYSSET;
    wfNetA->id = SYS_WF_NET_IPA;
    wfNetA->var = QVariant(ui->netAEdit->text());
    pSysSetList->append(wfNetA);

    SYSSET *wfNetB = new SYSSET;
    wfNetB->id = SYS_WF_NET_IPB;
    wfNetB->var = QVariant(ui->netBEdit->text());
    pSysSetList->append(wfNetB);

    SYSSET *wfPort = new SYSSET;
    wfPort->id = SYS_WF_NET_PORT;
    wfPort->var = QVariant(ui->portEdit->text());
    pSysSetList->append(wfPort);

    //编号
    SYSSET *wfKeyNum = new SYSSET;
    wfKeyNum->id = SYS_WF_KEY_NUM;
    wfKeyNum->var = QVariant(ui->wfNumberEdit->text());
    pSysSetList->append(wfKeyNum);

}
