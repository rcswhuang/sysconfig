#if defined (_MSC_VER) && (_MSC_VER >=1600)
#pragma execution_character_set("utf-8")
#endif
#include "hticketnoset.h"
#include "ui_ticketnoset.h"

HWorkNoteSetTab::HWorkNoteSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkNoteSet)
{
    ui->setupUi(this);
    pSysSetList = NULL;
    initTab();
}


HWorkNoteSetTab::~HWorkNoteSetTab()
{
    delete ui;
    clear();
}

void HWorkNoteSetTab::initTab()
{
    clear();
    ui->lockYXCheck->setChecked(false);
    ui->autoMatchCheck->setChecked(false);
    ui->allowWfYkCheck->setChecked(false);
    ui->promptCheck->setChecked(false);
    ui->mnpConfirmCheck->setChecked(false);
    ui->forbidMBEditorCheck->setChecked(false);
    ui->execTicketCheck->setChecked(false);
    ui->refreshTicketCheck->setChecked(false);
    ui->directOperaCheck->setChecked(false);
    ui->promptNetCheck->setChecked(false);
    ui->forbidPreCheck->setChecked(false);
    ui->judgeMulCheck->setChecked(false);
    ui->lockAllCheck->setChecked(false);
    ui->clearTicketCheck->setChecked(false);
    ui->sectionOperCheck->setChecked(false);
    ui->forbidModifyCheck->setChecked(false);
    ui->saveForbidMBCheck->setChecked(false);
    ui->clickPromptCheck->setChecked(false);
    ui->fromMnpCheck->setChecked(false);
    ui->saveStateCheck->setChecked(false);
    ui->fujianModelCheck->setChecked(false);
    ui->promptUndownCheck->setChecked(false);
    ui->printForbidWMCheck->setChecked(false);

    ui->ticketNum->setText("12");
    ui->ticketWindows->setText("1");

    ui->addEndCheck->setChecked(false);
    ui->endEdit->setEnabled(false);
    ui->alignCenterCheck->setChecked(false);
    ui->pageSpecialCheck->setChecked(false);
    connect(ui->addEndCheck,SIGNAL(clicked()),this,SLOT(addEndText1()));
}




void HWorkNoteSetTab::writeData()
{
    clear();

    SYSSET *lockYXCheck = new SYSSET;
    if(lockYXCheck)
    {
        lockYXCheck->id = WF_LOCKYX_CHECK;
        lockYXCheck->strObjName = "五防机闭锁全部遥信";
        lockYXCheck->var = QVariant(ui->lockYXCheck->isChecked());
        pSysSetList->append(lockYXCheck);
    }

    SYSSET *autoMatchCheck = new SYSSET;
    if(autoMatchCheck)
    {
        autoMatchCheck->id = WF_AUTOMATCH_CHECK;
        autoMatchCheck->strObjName = "自动匹配检查项";
        autoMatchCheck->var = QVariant(ui->autoMatchCheck->isChecked());
        pSysSetList->append(autoMatchCheck);
    }

    SYSSET *allowWfYkCheck = new SYSSET;
    if(allowWfYkCheck)
    {
        allowWfYkCheck->id = WF_ALLWF_YK_CHECK;
        allowWfYkCheck->strObjName = "允许五防机遥控";
        allowWfYkCheck->var = QVariant(ui->allowWfYkCheck->isChecked());
        pSysSetList->append(allowWfYkCheck);
    }

    SYSSET *promptCheck = new SYSSET;
    if(promptCheck)
    {
        promptCheck->id = WF_PROMPT_CHECK;
        promptCheck->strObjName = "五防机执行提示操作";
        promptCheck->var = QVariant(ui->promptCheck->isChecked());
        pSysSetList->append(promptCheck);
    }

    SYSSET *mnpConfirmCheck = new SYSSET;
    if(mnpConfirmCheck)
    {
        mnpConfirmCheck->id = WF_MNP_CONFIRM_CHECK;
        mnpConfirmCheck->strObjName = "遥控前要求模拟屏确认";
        mnpConfirmCheck->var = QVariant(ui->mnpConfirmCheck->isChecked());
        pSysSetList->append(mnpConfirmCheck);
    }

    SYSSET *forbidMBEditorCheck = new SYSSET;
    if(forbidMBEditorCheck)
    {
        forbidMBEditorCheck->id = WF_FORBID_MB_EDITOR_CHECK;
        forbidMBEditorCheck->strObjName = "禁止模板票编辑";
        forbidMBEditorCheck->var = QVariant(ui->forbidMBEditorCheck->isChecked());
        pSysSetList->append(forbidMBEditorCheck);
    }

    SYSSET *execTicketCheck = new SYSSET;
    if(execTicketCheck)
    {
        execTicketCheck->id = WF_EXEC_TICKET_CHECK;
        execTicketCheck->strObjName = "转为执行票直接执行";
        execTicketCheck->var = QVariant(ui->execTicketCheck->isChecked());
        pSysSetList->append(execTicketCheck);
    }

    SYSSET *refreshTicketCheck = new SYSSET;
    if(refreshTicketCheck)
    {
        refreshTicketCheck->id = WF_REFRESH_TICKET_CHECK;
        refreshTicketCheck->strObjName = "系统启动时刷新操作票";
        refreshTicketCheck->var = QVariant(ui->refreshTicketCheck->isChecked());
        pSysSetList->append(refreshTicketCheck);
    }

    SYSSET *directOperaCheck = new SYSSET;
    if(directOperaCheck)
    {
        directOperaCheck->id = WF_DIRECT_OPERA_CHECK;
        directOperaCheck->strObjName = "预演结束后直接执行";
        directOperaCheck->var = QVariant(ui->directOperaCheck->isChecked());
        pSysSetList->append(directOperaCheck);
    }

    SYSSET *promptNetCheck = new SYSSET;
    if(promptNetCheck)
    {
        promptNetCheck->id = WF_PROMPT_NET_CHECK;
        promptNetCheck->strObjName = "预演时需提示网络状态";
        promptNetCheck->var = QVariant(ui->promptNetCheck->isChecked());
        pSysSetList->append(promptNetCheck);
    }

    SYSSET *forbidPreCheck = new SYSSET;
    if(forbidPreCheck)
    {
        forbidPreCheck->id = WF_FORBID_PRE_CHECK;
        forbidPreCheck->strObjName = "禁止模板票预演";
        forbidPreCheck->var = QVariant(ui->forbidPreCheck->isChecked());
        pSysSetList->append(forbidPreCheck);
    }

    SYSSET *judgeMulCheck = new SYSSET;
    if(judgeMulCheck)
    {
        judgeMulCheck->id = WF_JUDGE_MUL_CHECK;
        judgeMulCheck->strObjName = "预演时判断多任务冲突";
        judgeMulCheck->var = QVariant(ui->judgeMulCheck->isChecked());
        pSysSetList->append(judgeMulCheck);
    }

    SYSSET *lockAllCheck = new SYSSET;
    if(lockAllCheck)
    {
        lockAllCheck->id = WF_LOCK_ALL_CHECK;
        lockAllCheck->strObjName = "系统启动时闭锁所有间隔";
        lockAllCheck->var = QVariant(ui->lockAllCheck->isChecked());
        pSysSetList->append(lockAllCheck);
    }

    SYSSET *clearTicketCheck = new SYSSET;
    if(clearTicketCheck)
    {
        clearTicketCheck->id = WF_CLEAR_TICKET_CHECK;
        clearTicketCheck->strObjName = "执行取消/结束后钥匙清零";
        clearTicketCheck->var = QVariant(ui->clearTicketCheck->isChecked());
        pSysSetList->append(clearTicketCheck);
    }

    SYSSET *sectionOperCheck = new SYSSET;
    if(sectionOperCheck)
    {
        sectionOperCheck->id = WF_SECTION_OPER_CHECK;
        sectionOperCheck->strObjName = "直接装载断面执行";
        sectionOperCheck->var = QVariant(ui->sectionOperCheck->isChecked());
        pSysSetList->append(sectionOperCheck);
    }

    SYSSET *forbidModifyCheck = new SYSSET;
    if(forbidModifyCheck)
    {
        forbidModifyCheck->id = WF_FORBID_MODIFY_CHECK;
        forbidModifyCheck->strObjName = "禁止预演时拉合操作修改";
        forbidModifyCheck->var = QVariant(ui->forbidModifyCheck->isChecked());
        pSysSetList->append(forbidModifyCheck);
    }

    SYSSET *saveForbidMBCheck = new SYSSET;
    if(saveForbidMBCheck)
    {
        saveForbidMBCheck->id = WF_SAVE_FORBIDMB_CHECK;
        saveForbidMBCheck->strObjName = "保存时屏蔽模板票";
        saveForbidMBCheck->var = QVariant(ui->saveForbidMBCheck->isChecked());
        pSysSetList->append(saveForbidMBCheck);
    }

    SYSSET *clickPromptCheck = new SYSSET;
    if(clickPromptCheck)
    {
        clickPromptCheck->id = WF_CLICK_PROMPT_CHECK;
        clickPromptCheck->strObjName = "启动画面点击提示操作";
        clickPromptCheck->var = QVariant(ui->clickPromptCheck->isChecked());
        pSysSetList->append(clickPromptCheck);
    }

    SYSSET *fromMnpCheck = new SYSSET;
    if(fromMnpCheck)
    {
        fromMnpCheck->id = WF_FROM_MNP_CHECK;
        fromMnpCheck->strObjName = "从模拟屏开票";
        fromMnpCheck->var = QVariant(ui->fromMnpCheck->isChecked());
        pSysSetList->append(fromMnpCheck);
    }

    SYSSET *saveStateCheck = new SYSSET;
    if(saveStateCheck)
    {
        saveStateCheck->id = WF_SAVE_STATE_CHECK;
        saveStateCheck->strObjName = "开票后保存状态继续开票";
        saveStateCheck->var = QVariant(ui->saveStateCheck->isChecked());
        pSysSetList->append(saveStateCheck);
    }

    SYSSET *fujianModelCheck = new SYSSET;
    if(fujianModelCheck)
    {
        fujianModelCheck->id = WF_FUJIAN_MODEL_CHECK;
        fujianModelCheck->strObjName = "福建模式";
        fujianModelCheck->var = QVariant(ui->fujianModelCheck->isChecked());
        pSysSetList->append(fujianModelCheck);
    }

    SYSSET *promptUndownCheck = new SYSSET;
    if(promptUndownCheck)
    {
        promptUndownCheck->id = WF_PROMPT_UNDOWN_CHECK;
        promptUndownCheck->strObjName = "提示操作不下传";
        promptUndownCheck->var = QVariant(ui->promptUndownCheck->isChecked());
        pSysSetList->append(promptUndownCheck);
    }

    SYSSET *printForbidWMCheck = new SYSSET;
    if(printForbidWMCheck)
    {
        printForbidWMCheck->id = WF_PRINT_FORBID_WM_CHECK;
        printForbidWMCheck->strObjName = "打印操作票屏蔽网门";
        printForbidWMCheck->var = QVariant(ui->printForbidWMCheck->isChecked());
        pSysSetList->append(printForbidWMCheck);
    }

    SYSSET *ticketNum = new SYSSET;
    if(ticketNum)
    {
        ticketNum->id = WF_TICKET_NUM;
        ticketNum->strObjName = "每操作票行数";
        ticketNum->var = QVariant(ui->ticketNum->text());
        pSysSetList->append(ticketNum);
    }

    SYSSET *ticketWindows = new SYSSET;
    if(ticketWindows)
    {
        ticketWindows->id = WF_TICKET_WINDOWS;
        ticketWindows->strObjName = "操作票执行窗口数";
        ticketWindows->var = QVariant(ui->ticketWindows->text());
        pSysSetList->append(ticketWindows);
    }

    SYSSET* addEndText = new SYSSET;
    if(addEndText)
    {
        addEndText->id = WF_ADD_END_TEXT;
        addEndText->strObjName ="增加结束语";
        addEndText->var = QVariant(ui->addEndCheck->isChecked());
    }

    SYSSET* endText = new SYSSET;
    if(endText)
    {
        endText->id = WF_END_TEXT;
        endText->strObjName ="结束语";
        endText->var = QVariant(ui->endEdit->text());
    }

    SYSSET* alignCenter = new SYSSET;
    if(alignCenter)
    {
        alignCenter->id = WF_ALIGN_CENTER;
        alignCenter->strObjName ="居中显示";
        alignCenter->var = QVariant(ui->alignCenterCheck->isChecked());
    }

    SYSSET* pageSpecial = new SYSSET;
    if(pageSpecial)
    {
        pageSpecial->id = WF_PAGE_SPECIAL;
        pageSpecial->strObjName ="整页时特殊处理";
        pageSpecial->var = QVariant(ui->pageSpecialCheck->isChecked());
    }
}

void HWorkNoteSetTab::readData()
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i < pSysSetList->count();i++)
    {
        SYSSET* sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            if(sysSet->id == WF_LOCKYX_CHECK)
            {
                ui->lockYXCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_AUTOMATCH_CHECK)
            {
                ui->autoMatchCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_ALLWF_YK_CHECK)
            {
                ui->allowWfYkCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_PROMPT_CHECK)
            {
                ui->promptCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_MNP_CONFIRM_CHECK)
            {
                ui->mnpConfirmCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_FORBID_MB_EDITOR_CHECK)
            {
                ui->forbidMBEditorCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_EXEC_TICKET_CHECK)
            {
                ui->execTicketCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_REFRESH_TICKET_CHECK)
            {
                ui->refreshTicketCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_DIRECT_OPERA_CHECK)
            {
                ui->directOperaCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_PROMPT_NET_CHECK)
            {
                ui->promptNetCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_FORBID_PRE_CHECK)
            {
                ui->forbidPreCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_JUDGE_MUL_CHECK)
            {
                ui->judgeMulCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_LOCK_ALL_CHECK)
            {
                ui->lockAllCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_CLEAR_TICKET_CHECK)
            {
                ui->clearTicketCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_SECTION_OPER_CHECK)
            {
                ui->sectionOperCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_FORBID_MODIFY_CHECK)
            {
                ui->forbidModifyCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_SAVE_FORBIDMB_CHECK)
            {
                ui->saveForbidMBCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_CLICK_PROMPT_CHECK)
            {
                ui->clickPromptCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_FROM_MNP_CHECK)
            {
                ui->fromMnpCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_SAVE_STATE_CHECK)
            {
                ui->saveStateCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_FUJIAN_MODEL_CHECK)
            {
                ui->fujianModelCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_PROMPT_UNDOWN_CHECK)
            {
                ui->promptUndownCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_PRINT_FORBID_WM_CHECK)
            {
                ui->printForbidWMCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_TICKET_NUM)
            {
                ui->ticketNum->setText(sysSet->var.toString());
            }
            else if(sysSet->id == WF_TICKET_WINDOWS)
            {
                ui->ticketWindows->setText(sysSet->var.toString());
            }
            else if(sysSet->id == WF_ADD_END_TEXT)
            {
                ui->addEndCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_END_TEXT)
            {
                ui->endEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == WF_ALIGN_CENTER)
            {
                ui->alignCenterCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == WF_PAGE_SPECIAL)
            {
                ui->pageSpecialCheck->setChecked(sysSet->var.toBool());
            }
        }
    }

    ui->endEdit->setEnabled(ui->addEndCheck->isChecked());
    ui->alignCenterCheck->setEnabled(ui->addEndCheck->isChecked());
    ui->pageSpecialCheck->setEnabled(ui->addEndCheck->isChecked());
}

void HWorkNoteSetTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
    pSysSetList->clear();
}

void HWorkNoteSetTab::addEndText1()
{
    bool bCheck = ui->addEndCheck->isChecked();
    if(bCheck)
    {
        ui->endEdit->setEnabled(true);
        ui->alignCenterCheck->setEnabled(true);
        ui->pageSpecialCheck->setEnabled(true);
    }
    else
    {
        ui->endEdit->setEnabled(false);
        ui->alignCenterCheck->setEnabled(false);
        ui->pageSpecialCheck->setEnabled(false);
    }
}
