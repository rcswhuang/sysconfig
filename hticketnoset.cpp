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
}




void HWorkNoteSetTab::writeData()
{
    clear();

    SYSSET *lockYXCheck = new SYSSET;
    if(lockYXCheck)
    {
        lockYXCheck->id = WF_LOCKYX_CHECK;
        lockYXCheck->var = QVariant(ui->lockYXCheck->isChecked());
        pSysSetList->append(lockYXCheck);
    }

    SYSSET *autoMatchCheck = new SYSSET;
    if(autoMatchCheck)
    {
        autoMatchCheck->id = WF_AUTOMATCH_CHECK;
        autoMatchCheck->var = QVariant(ui->autoMatchCheck->isChecked());
        pSysSetList->append(autoMatchCheck);
    }

    SYSSET *allowWfYkCheck = new SYSSET;
    if(allowWfYkCheck)
    {
        allowWfYkCheck->id = WF_ALLWF_YK_CHECK;
        allowWfYkCheck->var = QVariant(ui->allowWfYkCheck->isChecked());
        pSysSetList->append(allowWfYkCheck);
    }

    SYSSET *promptCheck = new SYSSET;
    if(promptCheck)
    {
        promptCheck->id = WF_PROMPT_CHECK;
        promptCheck->var = QVariant(ui->promptCheck->isChecked());
        pSysSetList->append(promptCheck);
    }

    SYSSET *mnpConfirmCheck = new SYSSET;
    if(mnpConfirmCheck)
    {
        mnpConfirmCheck->id = WF_MNP_CONFIRM_CHECK;
        mnpConfirmCheck->var = QVariant(ui->mnpConfirmCheck->isChecked());
        pSysSetList->append(mnpConfirmCheck);
    }

    SYSSET *forbidMBEditorCheck = new SYSSET;
    if(forbidMBEditorCheck)
    {
        forbidMBEditorCheck->id = WF_FORBID_MB_EDITOR_CHECK;
        forbidMBEditorCheck->var = QVariant(ui->forbidMBEditorCheck->isChecked());
        pSysSetList->append(forbidMBEditorCheck);
    }

    SYSSET *execTicketCheck = new SYSSET;
    if(execTicketCheck)
    {
        execTicketCheck->id = WF_EXEC_TICKET_CHECK;
        execTicketCheck->var = QVariant(ui->execTicketCheck->isChecked());
        pSysSetList->append(execTicketCheck);
    }

    SYSSET *refreshTicketCheck = new SYSSET;
    if(refreshTicketCheck)
    {
        refreshTicketCheck->id = WF_REFRESH_TICKET_CHECK;
        refreshTicketCheck->var = QVariant(ui->refreshTicketCheck->isChecked());
        pSysSetList->append(refreshTicketCheck);
    }

    SYSSET *directOperaCheck = new SYSSET;
    if(directOperaCheck)
    {
        directOperaCheck->id = WF_DIRECT_OPERA_CHECK;
        directOperaCheck->var = QVariant(ui->directOperaCheck->isChecked());
        pSysSetList->append(directOperaCheck);
    }

    SYSSET *promptNetCheck = new SYSSET;
    if(promptNetCheck)
    {
        promptNetCheck->id = WF_PROMPT_NET_CHECK;
        promptNetCheck->var = QVariant(ui->promptNetCheck->isChecked());
        pSysSetList->append(promptNetCheck);
    }

    SYSSET *forbidPreCheck = new SYSSET;
    if(forbidPreCheck)
    {
        forbidPreCheck->id = WF_FORBID_PRE_CHECK;
        forbidPreCheck->var = QVariant(ui->forbidPreCheck->isChecked());
        pSysSetList->append(forbidPreCheck);
    }

    SYSSET *judgeMulCheck = new SYSSET;
    if(judgeMulCheck)
    {
        judgeMulCheck->id = WF_JUDGE_MUL_CHECK;
        judgeMulCheck->var = QVariant(ui->judgeMulCheck->isChecked());
        pSysSetList->append(judgeMulCheck);
    }

    SYSSET *lockAllCheck = new SYSSET;
    if(lockAllCheck)
    {
        lockAllCheck->id = WF_LOCK_ALL_CHECK;
        lockAllCheck->var = QVariant(ui->lockAllCheck->isChecked());
        pSysSetList->append(lockAllCheck);
    }

    SYSSET *clearTicketCheck = new SYSSET;
    if(clearTicketCheck)
    {
        clearTicketCheck->id = WF_CLEAR_TICKET_CHECK;
        clearTicketCheck->var = QVariant(ui->clearTicketCheck->isChecked());
        pSysSetList->append(clearTicketCheck);
    }

    SYSSET *sectionOperCheck = new SYSSET;
    if(sectionOperCheck)
    {
        sectionOperCheck->id = WF_SECTION_OPER_CHECK;
        sectionOperCheck->var = QVariant(ui->sectionOperCheck->isChecked());
        pSysSetList->append(sectionOperCheck);
    }

    SYSSET *forbidModifyCheck = new SYSSET;
    if(forbidModifyCheck)
    {
        forbidModifyCheck->id = WF_FORBID_MODIFY_CHECK;
        forbidModifyCheck->var = QVariant(ui->forbidModifyCheck->isChecked());
        pSysSetList->append(forbidModifyCheck);
    }

    SYSSET *saveForbidMBCheck = new SYSSET;
    if(saveForbidMBCheck)
    {
        saveForbidMBCheck->id = WF_SAVE_FORBIDMB_CHECK;
        saveForbidMBCheck->var = QVariant(ui->saveForbidMBCheck->isChecked());
        pSysSetList->append(saveForbidMBCheck);
    }

    SYSSET *clickPromptCheck = new SYSSET;
    if(clickPromptCheck)
    {
        clickPromptCheck->id = WF_CLICK_PROMPT_CHECK;
        clickPromptCheck->var = QVariant(ui->clickPromptCheck->isChecked());
        pSysSetList->append(clickPromptCheck);
    }

    SYSSET *fromMnpCheck = new SYSSET;
    if(fromMnpCheck)
    {
        fromMnpCheck->id = WF_FROM_MNP_CHECK;
        fromMnpCheck->var = QVariant(ui->fromMnpCheck->isChecked());
        pSysSetList->append(fromMnpCheck);
    }

    SYSSET *saveStateCheck = new SYSSET;
    if(saveStateCheck)
    {
        saveStateCheck->id = WF_SAVE_STATE_CHECK;
        saveStateCheck->var = QVariant(ui->saveStateCheck->isChecked());
        pSysSetList->append(saveStateCheck);
    }

    SYSSET *fujianModelCheck = new SYSSET;
    if(fujianModelCheck)
    {
        fujianModelCheck->id = WF_FUJIAN_MODEL_CHECK;
        fujianModelCheck->var = QVariant(ui->fujianModelCheck->isChecked());
        pSysSetList->append(fujianModelCheck);
    }

    SYSSET *promptUndownCheck = new SYSSET;
    if(promptUndownCheck)
    {
        promptUndownCheck->id = WF_PROMPT_UNDOWN_CHECK;
        promptUndownCheck->var = QVariant(ui->promptUndownCheck->isChecked());
        pSysSetList->append(promptUndownCheck);
    }

    SYSSET *printForbidWMCheck = new SYSSET;
    if(printForbidWMCheck)
    {
        printForbidWMCheck->id = WF_PRINT_FORBID_WM_CHECK;
        printForbidWMCheck->var = QVariant(ui->printForbidWMCheck->isChecked());
        pSysSetList->append(printForbidWMCheck);
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
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->lockYXCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_AUTOMATCH_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->autoMatchCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_ALLWF_YK_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->allowWfYkCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_PROMPT_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->promptCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_MNP_CONFIRM_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->mnpConfirmCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_FORBID_MB_EDITOR_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->forbidMBEditorCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_EXEC_TICKET_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->execTicketCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_REFRESH_TICKET_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->refreshTicketCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_DIRECT_OPERA_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->directOperaCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_PROMPT_NET_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->promptNetCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_FORBID_PRE_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->forbidPreCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_JUDGE_MUL_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->judgeMulCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_LOCK_ALL_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->lockAllCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_CLEAR_TICKET_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->clearTicketCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_SECTION_OPER_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->sectionOperCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_FORBID_MODIFY_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->forbidModifyCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_SAVE_FORBIDMB_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->saveForbidMBCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_CLICK_PROMPT_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->clickPromptCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_FROM_MNP_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->fromMnpCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_SAVE_STATE_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->saveStateCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_FUJIAN_MODEL_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->fujianModelCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_PROMPT_UNDOWN_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->promptUndownCheck->setChecked(bChecked);
            }
            else if(sysSet->id == WF_PRINT_FORBID_WM_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->printForbidWMCheck->setChecked(bChecked);
            }
        }
    }
}

void HWorkNoteSetTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
    pSysSetList->clear();
}
