#include "hotherset.h"
#include "ui_otherset.h"

HOtherSetTab::HOtherSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtherSet)
{
    ui->setupUi(this);
    pSysSetList = NULL;
    initTab();
}

HOtherSetTab::~HOtherSetTab()
{
    delete ui;
    clear();
}

void HOtherSetTab::initTab()
{
    clear();
    ui->operaPreTicketCheck->setChecked(true);
    ui->savePreTicketCheck->setChecked(true);
    ui->groupNameRadio->setChecked(true);
    ui->stationNameCheck->setChecked(true);
    ui->interNameCheck->setChecked(true);
    ui->voltageCheck->setChecked(true);
    ui->digitalNameCheck->setChecked(true);
    ui->nullCheck->setChecked(true);
}

void HOtherSetTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
    pSysSetList->clear();
}

void HOtherSetTab::readData()
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i < pSysSetList->count();i++)
    {
        SYSSET *sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            if(sysSet->id == PRIV_SAVE_PRE_TICKET)
            {
                ui->savePreTicketCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == PRIV_OPERA_PRE_TICKET)
            {
                ui->operaPreTicketCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == NAME_GROUP_NAME)
            {
                 ui->groupNameRadio->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == NAME_CUSTOM_NAME)
            {
                ui->customNameRadio->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == STATE_CHANGE_STATION_NAME)
            {
                ui->stationNameCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == STATE_CHANGE_VOLTAGE)
            {
                 ui->voltageCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == STATE_CHANGE_INTERVAL_NAME)
            {
                 ui->interNameCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == STATE_CHANGE_DIGITAL_NAME)
            {
                 ui->digitalNameCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == STATE_CHANGE_NULL)
            {
                 ui->nullCheck->setChecked(sysSet->var.toBool());
            }
        }
    }
}

void HOtherSetTab::writeData()
{
    clear();
    SYSSET *operaPreTicket = new SYSSET;
    if(operaPreTicket)
    {
        operaPreTicket->id = PRIV_OPERA_PRE_TICKET;
        operaPreTicket->strObjName = ui->operaPreTicketCheck->text();
        operaPreTicket->var = QVariant(ui->operaPreTicketCheck->isChecked());
        pSysSetList->append(operaPreTicket);
    }

    SYSSET *savePreTicket = new SYSSET;
    if(savePreTicket)
    {
        savePreTicket->id = PRIV_SAVE_PRE_TICKET;
        savePreTicket->strObjName = ui->savePreTicketCheck->text();
        savePreTicket->var = QVariant(ui->savePreTicketCheck->isChecked());
        pSysSetList->append(savePreTicket);
    }

    bool bCheck = ui->groupNameRadio->isChecked();
    if(bCheck)
    {
        SYSSET *groupName = new SYSSET;
        if(groupName)
        {
            groupName->id = NAME_GROUP_NAME;
            groupName->strObjName = ui->groupNameRadio->text();
            groupName->var = QVariant(bCheck);
            pSysSetList->append(groupName);
        }
    }

    bCheck = ui->customNameRadio->isChecked();
    if(bCheck)
    {
        SYSSET *customName = new SYSSET;
        if(customName)
        {
            customName->id = NAME_CUSTOM_NAME;
            customName->strObjName = ui->customNameRadio->text();
            customName->var = QVariant(bCheck);
            pSysSetList->append(customName);
        }
    }

    SYSSET *stationName = new SYSSET;
    if(stationName)
    {
        stationName->id = STATE_CHANGE_STATION_NAME;
        stationName->strObjName = ui->stationNameCheck->text();
        stationName->var = QVariant(ui->stationNameCheck->isChecked());
        pSysSetList->append(stationName);
    }

    SYSSET *interName = new SYSSET;
    if(interName)
    {
        interName->id = STATE_CHANGE_INTERVAL_NAME;
        interName->strObjName = ui->interNameCheck->text();
        interName->var = QVariant(ui->interNameCheck->isChecked());
        pSysSetList->append(interName);
    }

    SYSSET *voltage = new SYSSET;
    if(voltage)
    {
        voltage->id = STATE_CHANGE_VOLTAGE;
        voltage->strObjName = ui->voltageCheck->text();
        voltage->var = QVariant(ui->voltageCheck->isChecked());
        pSysSetList->append(voltage);
    }

    SYSSET *digitalName = new SYSSET;
    if(digitalName)
    {
        digitalName->id = STATE_CHANGE_DIGITAL_NAME;
        digitalName->strObjName = ui->digitalNameCheck->text();
        digitalName->var = QVariant(ui->digitalNameCheck->isChecked());
        pSysSetList->append(digitalName);
    }

    SYSSET *null = new SYSSET;
    if(null)
    {
        null->id = STATE_CHANGE_NULL;
        null->strObjName = ui->nullCheck->text();
        null->var = QVariant(ui->nullCheck->isChecked());
        pSysSetList->append(null);
    }
}
