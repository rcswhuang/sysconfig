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
        operaNote->strObjName = "操作票管理";
        operaNote->var = QVariant(ui->operaNoteCheck->isChecked());
        pSysSetList->append(operaNote);
    }

    //事件管理
    SYSSET *event = new SYSSET;
    if(event)
    {
        event->id = SYS_FUN_EVENT_SCAN;
        event->strObjName = "事件管理";
        event->var = QVariant(ui->eventCheck->isChecked());
        pSysSetList->append(event);
    }

    //图形浏览管理
    SYSSET *graphEditor = new SYSSET;
    if(graphEditor)
    {
        graphEditor->id = SYS_FUN_GRAPH_EDITOR;
        graphEditor->strObjName = "图形浏览管理";
        graphEditor->var = QVariant(ui->graphEditorCheck->isChecked());
        pSysSetList->append(graphEditor);
    }

    //五防锁管理
    SYSSET *wfLock = new SYSSET;
    if(wfLock)
    {
        wfLock->id = SYS_FUN_WFLOCK_SCAN;
        wfLock->strObjName = "五防锁管理";
        wfLock->var = QVariant(ui->lockCheck->isChecked());
        pSysSetList->append(wfLock);
    }

    //工作票管理
    SYSSET *workNote = new SYSSET;
    if(workNote)
    {
        workNote->id = SYS_FUN_WORKNOET_MANGER;
        workNote->strObjName = "工作票管理";
        workNote->var = QVariant(ui->workNoteCheck->isChecked());
        pSysSetList->append(workNote);
    }

    //打印管理
    SYSSET *print = new SYSSET;
    if(print)
    {
        print->id = SYS_FUN_PRINT_SET;
        print->strObjName = "打印管理";
        print->var = QVariant(ui->printCheck->isChecked());
        pSysSetList->append(print);
    }

    //五防配置管理
    SYSSET *wfConfig = new SYSSET;
    if(wfConfig)
    {
        wfConfig->id = SYS_FUN_WF_CONFIG;
        wfConfig->strObjName = "五防配置管理";
        wfConfig->var = QVariant(ui->wfConfigCheck->isChecked());
        pSysSetList->append(wfConfig);
    }

    //No电脑钥匙
    bool bCheck = ui->keyNoRadio->isChecked();
    if(bCheck)
    {
        SYSSET *keyNo = new SYSSET;
        if(keyNo)
        {
            keyNo->id = SYS_KEY_NULL;
            keyNo->strObjName = "无电脑钥匙";
            keyNo->var = QVariant(bCheck);
            pSysSetList->append(keyNo);
        }
    }


    //USB电脑钥匙
    bCheck = ui->keyUsbRadio->isChecked();
    if(bCheck)
    {
        SYSSET *keyUSB = new SYSSET;
        if(keyUSB)
        {
            keyUSB->id = SYS_KEY_NR_USB;
            keyUSB->strObjName = "USB电脑钥匙";
            keyUSB->var = QVariant(bCheck);
            pSysSetList->append(keyUSB);
        }
    }

    //26版钥匙
    bCheck = ui->key26Radio->isChecked();
    if(bCheck)
    {
        SYSSET *keyYT26 = new SYSSET;
        if(keyYT26)
        {
            keyYT26->id = SYS_KEY_YT26;
            keyYT26->strObjName = "26版电脑钥匙";
            keyYT26->var = QVariant(bCheck);
            pSysSetList->append(keyYT26);
        }
    }

    //27版钥匙
    bCheck = ui->key27Radio->isChecked();
    if(bCheck)
    {
        SYSSET *keyYT27 = new SYSSET;
        if(keyYT27)
        {
            keyYT27->id = SYS_KEY_YT27;
            keyYT27->strObjName = "27版电脑钥匙";
            keyYT27->var = QVariant(bCheck);
            pSysSetList->append(keyYT27);
        }
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
                ui->operaNoteCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_FUN_PRINT_SET)
            {
                ui->printCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_FUN_WORKNOET_MANGER)
            {
                ui->workNoteCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_FUN_GRAPH_EDITOR)
            {
                ui->graphEditorCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_FUN_EVENT_SCAN)
            {
                ui->eventCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_FUN_WFLOCK_SCAN)
            {
                ui->lockCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_FUN_WF_CONFIG)
            {
                ui->wfConfigCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_KEY_NULL)
            {
                ui->keyNoRadio->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_KEY_YT26)
            {
                ui->key26Radio->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_KEY_YT27)
            {
                ui->key27Radio->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_KEY_NR_USB)
            {
                ui->keyUsbRadio->setChecked(sysSet->var.toBool());
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
