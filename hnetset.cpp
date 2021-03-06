﻿#if defined (_MSC_VER) && (_MSC_VER >=1600)
#pragma execution_character_set("utf-8")
#endif
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
    strComSel<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->keyComSelCombo->addItems(strComSel);
    ui->keyComSelCombo->setCurrentIndex((int)-1);

    QStringList strComBaut;
    strComBaut<<"300,n,8,1"<<"600,n,8,1"<<"1200,n,8,1"<<"2400,n,8,1"<<"3600,n,8,1"<<"4800,n,8,1"<<"9600,n,8,1"<<"12800,n,8,1";
    strComBaut<<"14400,n,8,1"<<"19200,n,8,1"<<"25600,n,8,1"<<"28800,n,8,1"<<"38400,n,8,1"<<"56000,n,8,1";
    ui->keyComSetCombo->addItems(strComBaut);
    ui->keyComSetCombo->setCurrentIndex((int)-1);

    ui->keyComTimeOut->setText("30");

    //模拟屏盘
    //strComSel<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->mnpComSelCombo->addItems(strComSel);
    ui->mnpComSelCombo->setCurrentIndex((int)-1);

    //strComBaut<<"9600,n,8,1";
    ui->mnpComSetCombo->addItems(strComBaut);
    ui->mnpComSetCombo->setCurrentIndex((int)-1);

    ui->mnpComTimeOut->setText("30");

    //优特
    //strComSel<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->ytComSelCombo->addItems(strComSel);
    ui->ytComSelCombo->setCurrentIndex((int)-1);

    //strComBaut<<"9600,n,8,1";
    ui->ytComSetCombo->addItems(strComBaut);
    ui->ytComSetCombo->setCurrentIndex((int)-1);

    ui->ytComTimeOut->setText("30");

    //模拟屏2
    //strComSel<<""<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->mnp2ComSelCombo->addItems(strComSel);
    ui->mnp2ComSelCombo->setCurrentIndex((int)-1);

    //strComBaut<<"9600,n,8,1";
    ui->mnp2ComSetCombo->addItems(strComBaut);
    ui->mnp2ComSetCombo->setCurrentIndex((int)-1);

    ui->mnp2ComTimeOut->setText("30");

    //闭锁控制器
    //strComSel<<""<<"com1"<<"com2"<<"com3"<<"com4"<<"com5"<<"com6"<<"com7"<<"com8";
    ui->bsqComSelCombo->addItems(strComSel);
    ui->bsqComSelCombo->setCurrentIndex((int)-1);

    //strComBaut<<"9600,n,8,1";
    ui->bsqComSetCombo->addItems(strComBaut);
    ui->bsqComSetCombo->setCurrentIndex((int)-1);

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
                int index = ui->keyComSelCombo->findText(sysSet->var.toString());
                if(index == (int)-1)
                    ui->keyComSelCombo->setCurrentIndex((int)-1);
                else
                    ui->keyComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_KEY_COM_SET)
            {
                int index = ui->keyComSetCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->keyComSetCombo->setCurrentIndex((int)-1);
                else
                    ui->keyComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_KEY_COM_TIME)
            {
                ui->keyComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_MNP_COM_SELECT)
            {
                int index = ui->mnpComSelCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->mnpComSelCombo->setCurrentIndex((int)-1);
                else
                    ui->mnpComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP_COM_SET)
            {
                int index = ui->mnpComSetCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->mnpComSetCombo->setCurrentIndex((int)-1);
                else
                    ui->mnpComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP_COM_TIME)
            {
                ui->mnpComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_MNP2_COM_SELECT)
            {
                int index = ui->mnp2ComSelCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->mnp2ComSelCombo->setCurrentIndex((int)-1);
                else
                    ui->mnp2ComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP2_COM_SET)
            {
                int index = ui->mnp2ComSetCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->mnp2ComSetCombo->setCurrentIndex((int)-1);
                else
                    ui->mnp2ComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_MNP2_COM_TIME)
            {
                ui->mnp2ComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_YT_COM_SELECT)
            {
                int index = ui->ytComSelCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->ytComSelCombo->setCurrentIndex((int)-1);
                else
                    ui->ytComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_YT_COM_SET)
            {
                int index = ui->ytComSetCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->ytComSetCombo->setCurrentIndex((int)-1);
                else
                    ui->ytComSetCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_YT_COM_TIME)
            {
                ui->ytComTimeOut->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_BSQ_COM_SELECT)
            {
                int index = ui->bsqComSelCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->bsqComSelCombo->setCurrentIndex((int)-1);
                else
                    ui->bsqComSelCombo->setCurrentIndex(index);
            }
            else if(sysSet->id == SYS_BSQ_COM_SET)
            {
                int index = ui->bsqComSelCombo->findText(sysSet->var.toString());
                if((int)-1 == index)
                    ui->bsqComSelCombo->setCurrentIndex((int)-1);
                else
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
        }//
    }
}

void HNetSetTab::writeData()
{
    clear();
    //电脑钥匙
    if(ui->keyComSelCombo->currentIndex() != (int)-1 && ui->keyComSetCombo->currentIndex() != (int)-1)
    {
        SYSSET *keyComSelect = new SYSSET;
        keyComSelect->id = SYS_KEY_COM_SELECT;
        keyComSelect->strObjName = "电脑钥匙串口号";
        keyComSelect->var = QVariant(ui->keyComSelCombo->currentText());
        pSysSetList->append(keyComSelect);

        SYSSET *keyComSet = new SYSSET;
        keyComSet->id = SYS_KEY_COM_SET;
        keyComSet->strObjName = "电脑钥匙串口设置";
        keyComSet->var = QVariant(ui->keyComSetCombo->currentText());
        pSysSetList->append(keyComSet);

        SYSSET *keyComTimeout = new SYSSET;
        keyComTimeout->id = SYS_KEY_COM_TIME;
        keyComTimeout->strObjName = "电脑钥匙串口超时";
        keyComTimeout->var = QVariant(ui->keyComTimeOut->text());
        pSysSetList->append(keyComTimeout);
    }

    //模拟屏
    if((int)-1 != ui->mnpComSelCombo->currentIndex() && (int)-1 != ui->mnpComSetCombo->currentIndex())
    {
        SYSSET *mnpComSelect = new SYSSET;
        mnpComSelect->id = SYS_MNP_COM_SELECT;
        mnpComSelect->strObjName = "模拟屏串口号";
        mnpComSelect->var = QVariant(ui->mnpComSelCombo->currentText());
        pSysSetList->append(mnpComSelect);

        SYSSET *mnpComSet = new SYSSET;
        mnpComSet->id = SYS_MNP_COM_SET;
        mnpComSet->strObjName = "模拟屏串口设置";
        mnpComSet->var = QVariant(ui->mnpComSetCombo->currentText());
        pSysSetList->append(mnpComSet);

        SYSSET *mnpComTimeout = new SYSSET;
        mnpComTimeout->id = SYS_MNP_COM_TIME;
        mnpComTimeout->strObjName = "模拟屏串口超时";
        mnpComTimeout->var = QVariant(ui->mnpComTimeOut->text());
        pSysSetList->append(mnpComTimeout);
    }

    //模拟屏2
    if((int)-1 != ui->mnp2ComSelCombo->currentIndex() && (int)-1 != ui->mnp2ComSetCombo->currentIndex())
    {
        SYSSET *mnp2ComSelect = new SYSSET;
        mnp2ComSelect->id = SYS_MNP2_COM_SELECT;
        mnp2ComSelect->strObjName = "模拟屏2串口号";
        mnp2ComSelect->var = QVariant(ui->mnp2ComSelCombo->currentText());
        pSysSetList->append(mnp2ComSelect);

        SYSSET *mnp2ComSet = new SYSSET;
        mnp2ComSet->id = SYS_MNP_COM_SELECT;
        mnp2ComSet->strObjName = "模拟屏2串口设置";
        mnp2ComSet->var = QVariant(ui->mnp2ComSetCombo->currentText());
        pSysSetList->append(mnp2ComSet);

        SYSSET *mnp2ComTimeout = new SYSSET;
        mnp2ComTimeout->id = SYS_MNP_COM_SELECT;
        mnp2ComTimeout->strObjName = "模拟屏2串口超时";
        mnp2ComTimeout->var = QVariant(ui->mnp2ComTimeOut->text());
        pSysSetList->append(mnp2ComTimeout);
    }

    //优特
    if((int)-1 != ui->ytComSelCombo->currentIndex() && (int)-1 != ui->ytComSetCombo->currentIndex())
    {
        SYSSET *ytComSelect = new SYSSET;
        ytComSelect->id = SYS_YT_COM_SELECT;
        ytComSelect->strObjName = "优特五防串口号";
        ytComSelect->var = QVariant(ui->ytComSelCombo->currentText());
        pSysSetList->append(ytComSelect);

        SYSSET *ytComSet = new SYSSET;
        ytComSet->id = SYS_YT_COM_SELECT;
        ytComSet->strObjName = "优特五防串口设置";
        ytComSet->var = QVariant(ui->ytComSetCombo->currentText());
        pSysSetList->append(ytComSet);

        SYSSET *ytComTimeout = new SYSSET;
        ytComTimeout->id = SYS_YT_COM_SELECT;
        ytComTimeout->strObjName = "优特五防串口超时";
        ytComTimeout->var = QVariant(ui->ytComTimeOut->text());
        pSysSetList->append(ytComTimeout);
    }

    //闭锁控制器
    if((int)-1 != ui->bsqComSelCombo->currentIndex() && (int)-1 != ui->bsqComSetCombo->currentIndex())
    {
        SYSSET *bsqComSelect = new SYSSET;
        bsqComSelect->id = SYS_BSQ_COM_SELECT;
        bsqComSelect->strObjName = "闭锁控制器串口号";
        bsqComSelect->var = QVariant(ui->bsqComSelCombo->currentText());
        pSysSetList->append(bsqComSelect);

        SYSSET *bsqComSet = new SYSSET;
        bsqComSet->id = SYS_BSQ_COM_SELECT;
        bsqComSet->strObjName = "闭锁控制器串口设置";
        bsqComSet->var = QVariant(ui->bsqComSetCombo->currentText());
        pSysSetList->append(bsqComSet);

        SYSSET *bsqComTimeout = new SYSSET;
        bsqComTimeout->id = SYS_BSQ_COM_SELECT;
        bsqComTimeout->strObjName = "闭锁控制器串口超时";
        bsqComTimeout->var = QVariant(ui->bsqComTimeOut->text());
        pSysSetList->append(bsqComTimeout);
    }

    //五防网络
    SYSSET *wfNetA = new SYSSET;
    wfNetA->id = SYS_WF_NET_IPA;
    wfNetA->strObjName = "五防网络A";
    wfNetA->var = QVariant(ui->netAEdit->text());
    pSysSetList->append(wfNetA);

    SYSSET *wfNetB = new SYSSET;
    wfNetB->id = SYS_WF_NET_IPB;
    wfNetB->strObjName = "五防网络B";
    wfNetB->var = QVariant(ui->netBEdit->text());
    pSysSetList->append(wfNetB);

    SYSSET *wfPort = new SYSSET;
    wfPort->id = SYS_WF_NET_PORT;
    wfPort->strObjName = "五防网络端口号";
    wfPort->var = QVariant(ui->portEdit->text());
    pSysSetList->append(wfPort);

    //编号
    SYSSET *wfKeyNum = new SYSSET;
    wfKeyNum->id = SYS_WF_KEY_NUM;
    wfKeyNum->strObjName = "五防机编号";
    wfKeyNum->var = QVariant(ui->wfNumberEdit->text());
    pSysSetList->append(wfKeyNum);

}
