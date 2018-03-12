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
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->savePreTicketCheck->setChecked(bChecked);

            }
            else if(sysSet->id == PRIV_OPERA_PRE_TICKET)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->operaPreTicketCheck->setChecked(bChecked);

            }
            else if(sysSet->id == NAME_GROUP_NAME)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                 ui->groupNameRadio->setChecked(bChecked);
            }
            else if(sysSet->id == NAME_CUSTOM_NAME)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->customNameRadio->setChecked(bChecked);

            }
            else if(sysSet->id == STATE_CHANGE_STATION_NAME)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->stationNameCheck->setChecked(bChecked);

            }
            else if(sysSet->id == STATE_CHANGE_VOLTAGE)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                 ui->voltageCheck->setChecked(bChecked);
            }
            else if(sysSet->id == STATE_CHANGE_INTERVAL_NAME)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                 ui->interNameCheck->setChecked(bChecked);
            }
            else if(sysSet->id == STATE_CHANGE_DIGITAL_NAME)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                 ui->digitalNameCheck->setChecked(bChecked);
            }
            else if(sysSet->id == STATE_CHANGE_NULL)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                 ui->nullCheck->setChecked(bChecked);
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
        operaPreTicket->var = QVariant(ui->operaPreTicketCheck->text());
        pSysSetList->append(operaPreTicket);
    }

    SYSSET *savePreTicket = new SYSSET;
    if(savePreTicket)
    {
        savePreTicket->id = PRIV_SAVE_PRE_TICKET;
        savePreTicket->var = QVariant(ui->savePreTicketCheck->text());
        pSysSetList->append(savePreTicket);
    }

    SYSSET *groupName = new SYSSET;
    if(groupName)
    {
        groupName->id = NAME_GROUP_NAME;
        groupName->var = QVariant(ui->groupNameRadio->text());
        pSysSetList->append(groupName);
    }

    SYSSET *customName = new SYSSET;
    if(customName)
    {
        customName->id = NAME_CUSTOM_NAME;
        customName->var = QVariant(ui->customNameRadio->text());
        pSysSetList->append(customName);
    }

    SYSSET *stationName = new SYSSET;
    if(stationName)
    {
        stationName->id = STATE_CHANGE_STATION_NAME;
        stationName->var = QVariant(ui->stationNameCheck->text());
        pSysSetList->append(stationName);
    }

    SYSSET *interName = new SYSSET;
    if(interName)
    {
        interName->id = STATE_CHANGE_INTERVAL_NAME;
        interName->var = QVariant(ui->interNameCheck->text());
        pSysSetList->append(interName);
    }

    SYSSET *voltage = new SYSSET;
    if(voltage)
    {
        voltage->id = STATE_CHANGE_VOLTAGE;
        voltage->var = QVariant(ui->voltageCheck->text());
        pSysSetList->append(voltage);
    }

    SYSSET *digitalName = new SYSSET;
    if(digitalName)
    {
        digitalName->id = STATE_CHANGE_DIGITAL_NAME;
        digitalName->var = QVariant(ui->digitalNameCheck->text());
        pSysSetList->append(digitalName);
    }

    SYSSET *null = new SYSSET;
    if(null)
    {
        null->id = STATE_CHANGE_NULL;
        null->var = QVariant(ui->nullCheck->text());
        pSysSetList->append(null);
    }
}
