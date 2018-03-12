#include "hfunset.h"
#include "ui_funset.h"

HFunSetTab::HFunSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunSet)
{
    ui->setupUi(this);
    pSysSetList = NULL;
    initTab();
}

HFunSetTab::~HFunSetTab()
{
    delete ui;
    clear();
}

void HFunSetTab::initTab()
{
    clear();
    ui->operaNoteCheck->setChecked(true);
    ui->eventCheck->setChecked(true);
    ui->graphEditorCheck->setChecked(true);
    ui->lockCheck->setChecked(true);
    ui->workNoteCheck->setChecked(true);
    ui->printCheck->setChecked(true);
    ui->wfConfigCheck->setChecked(true);

    ui->keyNoRadio->setChecked(true);
}

void HFunSetTab::writeData()
{
    clear();
    //操作票管理
    SYSSET *operaNote = new SYSSET;
    if(operaNote)
    {
        operaNote->id = SYS_FUN_OPNOTE_MANAGER;
        operaNote->var = QVariant(ui->operaNoteCheck->isChecked());
        pSysSetList->append(operaNote);
    }

    //事件管理
    SYSSET *event = new SYSSET;
    if(event)
    {
        event->id = SYS_FUN_EVENT_SCAN;
        event->var = QVariant(ui->eventCheck->isChecked());
        pSysSetList->append(event);
    }

    //图形浏览管理
    SYSSET *graphEditor = new SYSSET;
    if(graphEditor)
    {
        graphEditor->id = SYS_FUN_GRAPH_EDITOR;
        graphEditor->var = QVariant(ui->graphEditorCheck->isChecked());
        pSysSetList->append(graphEditor);
    }

    //五防锁管理
    SYSSET *wfLock = new SYSSET;
    if(wfLock)
    {
        wfLock->id = SYS_FUN_WFLOCK_SCAN;
        wfLock->var = QVariant(ui->lockCheck->isChecked());
        pSysSetList->append(wfLock);
    }

    //工作票管理
    SYSSET *workNote = new SYSSET;
    if(workNote)
    {
        workNote->id = SYS_FUN_WORKNOET_MANGER;
        workNote->var = QVariant(ui->workNoteCheck->isChecked());
        pSysSetList->append(workNote);
    }

    //打印管理
    SYSSET *print = new SYSSET;
    if(print)
    {
        print->id = SYS_FUN_PRINT_SET;
        print->var = QVariant(ui->printCheck->isChecked());
        pSysSetList->append(print);
    }

    //五防配置管理
    SYSSET *wfConfig = new SYSSET;
    if(wfConfig)
    {
        wfConfig->id = SYS_FUN_WF_CONFIG;
        wfConfig->var = QVariant(ui->wfConfigCheck->isChecked());
        pSysSetList->append(wfConfig);
    }

    //USB电脑钥匙
    SYSSET *keyUSB = new SYSSET;
    if(keyUSB)
    {
        keyUSB->id = SYS_KEY_NR_USB;
        keyUSB->var = QVariant(ui->keyUsbRadio->isChecked());
        pSysSetList->append(keyUSB);
    }

    //No电脑钥匙
    SYSSET *keyNo = new SYSSET;
    if(keyNo)
    {
        keyNo->id = SYS_KEY_NULL;
        keyNo->var = QVariant(ui->keyNoRadio->isChecked());
        pSysSetList->append(keyNo);
    }

    //26版钥匙
    SYSSET *keyYT26 = new SYSSET;
    if(keyYT26)
    {
        keyYT26->id = SYS_KEY_YT26;
        keyYT26->var = QVariant(ui->key26Radio->isChecked());
        pSysSetList->append(keyYT26);
    }

    //27版钥匙
    SYSSET *keyYT27 = new SYSSET;
    if(keyYT27)
    {
        keyYT27->id = SYS_KEY_YT27;
        keyYT27->var = QVariant(ui->key27Radio->isChecked());
        pSysSetList->append(keyYT27);
    }

}

void HFunSetTab::readData()
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i< pSysSetList->count();i++)
    {
        SYSSET* sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            if(sysSet->id == SYS_FUN_OPNOTE_MANAGER)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->operaNoteCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_FUN_PRINT_SET)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->printCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_FUN_WORKNOET_MANGER)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->workNoteCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_FUN_GRAPH_EDITOR)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->graphEditorCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_FUN_EVENT_SCAN)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->eventCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_FUN_WFLOCK_SCAN)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->lockCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_FUN_WF_CONFIG)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->wfConfigCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_KEY_NULL)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->keyNoRadio->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_KEY_YT26)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->key26Radio->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_KEY_YT27)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->key27Radio->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_KEY_NR_USB)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->keyUsbRadio->setChecked(bChecked);
            }
        }
    }
}

void HFunSetTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
    pSysSetList->clear();
}
