#if defined (_MSC_VER) && (_MSC_VER >=1600)
#pragma execution_character_set("utf-8")
#endif
#include "hformatset.h"
#include "ui_formatset.h"

HFormatSetTab::HFormatSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormatSet)
{
    ui->setupUi(this);
    pSysSetList = NULL;
    initTab();
}

HFormatSetTab::~HFormatSetTab()
{
    delete ui;
    clear();
}


void HFormatSetTab::initTab()
{
    clear();
    ui->oneTicketNumRadio->setChecked(true);
    ui->addHeadTailCheck->setEnabled(true);
    ui->showHeadTailCheck->setEnabled(false);
    ui->headEdit->setText("上接#号操作票");
    ui->headEdit->setEnabled(false);
    ui->tailEdit->setText("下接$号操作票");
    ui->tailEdit->setEnabled(false);

    connect(ui->addHeadTailCheck,SIGNAL(clicked()),this,SLOT(addEndText()));

    ui->prefixCheck->setChecked(false);
    ui->prefixEdit->setEnabled(false);
    ui->suffixCheck->setChecked(false);
    ui->suffixEdit->setEnabled(false);
    ui->fixlenthCheck->setChecked(false);
    ui->fixlengthEdit->setEnabled(false);
    connect(ui->prefixCheck,SIGNAL(clicked()),this,SLOT(prefix()));
    connect(ui->suffixCheck,SIGNAL(clicked()),this,SLOT(suffix()));
    connect(ui->fixlenthCheck,SIGNAL(clicked()),this,SLOT(fixlength()));


    ui->modifyPreTicketNumCheck->setChecked(false);
    ui->nextTicketNumEdit->setEnabled(false);
    ui->modifyTicketNumCheck->setChecked(false);
    ui->modifySerialNumCheck->setChecked(false);
    ui->beginSerialNumEdit->setEnabled(false);
    connect(ui->modifyPreTicketNumCheck,SIGNAL(clicked()),this,SLOT(modifyPreTicketNum()));
    connect(ui->modifySerialNumCheck,SIGNAL(clicked()),this,SLOT(modifySerialNum()));
    //connect(ui->modifyTicketNumCheck,SIGNAL(clicked()),this,SLOT(modifyTicketNum()));

}

void HFormatSetTab::writeData()
{
    clear();

    if(ui->oneTicketNumRadio->isChecked())
    {
        SYSSET *oneTicketNum = new SYSSET;
        if(oneTicketNum)
        {
            oneTicketNum->id = TICKET_ONE_TICKET_NUM;
            oneTicketNum->strObjName = ui->oneTicketNumRadio->text();
            oneTicketNum->var = QVariant(ui->oneTicketNumRadio->isChecked());
            pSysSetList->append(oneTicketNum);
        }
    }

    if(ui->oneTicketPageNumRadio->isChecked())
    {
        SYSSET *oneTicketPageNum = new SYSSET;
        if(oneTicketPageNum)
        {
            oneTicketPageNum->id = TICKET_ONE_TICKET_PAGE_NUM;
            oneTicketPageNum->strObjName = ui->oneTicketPageNumRadio->text();
            oneTicketPageNum->var = QVariant(ui->oneTicketPageNumRadio->isChecked());
            pSysSetList->append(oneTicketPageNum);
        }
    }

    SYSSET *addHeadTail = new SYSSET;
    if(addHeadTail)
    {
        addHeadTail->id = TICKET_ADD_HEAD_TAIL;
        addHeadTail->strObjName = "添加页头页尾";
        addHeadTail->var = QVariant(ui->addHeadTailCheck->isChecked());
        pSysSetList->append(addHeadTail);
    }

    SYSSET *showHeadTail = new SYSSET;
    if(showHeadTail)
    {
        showHeadTail->id = TICKET_SHOW_HEAD_TAIL;
        showHeadTail->strObjName = "显示页头页尾";
        showHeadTail->var = QVariant(ui->showHeadTailCheck->isChecked());
        pSysSetList->append(showHeadTail);
    }

    SYSSET *headContent = new SYSSET;
    if(headContent)
    {
        headContent->id = TICKET_HEAD_CONTENT;
        headContent->strObjName = "页头";
        headContent->var = QVariant(ui->headEdit->text());
        pSysSetList->append(headContent);
    }

    SYSSET *tailContent = new SYSSET;
    if(tailContent)
    {
        tailContent->id = TICKET_TAIL_CONTENT;
        tailContent->strObjName = "页尾";
        tailContent->var = QVariant(ui->tailEdit->text());
        pSysSetList->append(tailContent);
    }

    SYSSET *prefix = new SYSSET;
    if(prefix)
    {
        prefix->id = TICKET_PREFIX_SET;
        prefix->strObjName = "是否前缀";
        prefix->var = QVariant(ui->prefixCheck->isChecked());
        pSysSetList->append(prefix);
    }

    SYSSET *suffix = new SYSSET;
    if(suffix)
    {
        suffix->id = TICKET_SUFFIX_SET;
        suffix->strObjName = "是否后缀";
        suffix->var = QVariant(ui->suffixCheck->isChecked());
        pSysSetList->append(suffix);
    }

    SYSSET *fixlength = new SYSSET;
    if(fixlength)
    {
        fixlength->id = TICKET_FIX_LENGTH_SET;
        fixlength->strObjName = "是否固定长度";
        fixlength->var = QVariant(ui->fixlenthCheck->isChecked());
        pSysSetList->append(fixlength);
    }

    SYSSET *prefixContent = new SYSSET;
    if(prefixContent)
    {
        prefixContent->id = TICKET_PREFIX_CONTENT;
        prefixContent->strObjName = "前缀";
        prefixContent->var = QVariant(ui->prefixEdit->text());
        pSysSetList->append(prefixContent);
    }

    SYSSET *suffixContent = new SYSSET;
    if(suffixContent)
    {
        suffixContent->id = TICKET_SUFFIX_CONTENT;
        suffixContent->strObjName = "后缀";
        suffixContent->var = QVariant(ui->suffixEdit->text());
        pSysSetList->append(suffixContent);
    }

    SYSSET *fixlengthContent = new SYSSET;
    if(fixlengthContent)
    {
        fixlengthContent->id = TICKET_FIX_LENGTH_CONTENT;
        fixlengthContent->strObjName = "固定长度";
        fixlengthContent->var = QVariant(ui->fixlengthEdit->text());
        pSysSetList->append(fixlengthContent);
    }

    SYSSET *modifyPreTicketNum = new SYSSET;
    if(modifyPreTicketNum)
    {
        modifyPreTicketNum->id = TICKET_MODIFY_PRETICKET_SET;
        modifyPreTicketNum->strObjName = "修改预开票";
        modifyPreTicketNum->var = QVariant(ui->modifyPreTicketNumCheck->isChecked());
        pSysSetList->append(modifyPreTicketNum);
    }

    SYSSET *nextTicketNum = new SYSSET;
    if(nextTicketNum)
    {
        nextTicketNum->id = TICKET_MODIFY_NEXT_NUM;
        nextTicketNum->strObjName = "下一预开票号";
        nextTicketNum->var = QVariant(ui->nextTicketNumEdit->text());
        pSysSetList->append(nextTicketNum);
    }

    SYSSET *modifyTicketNum = new SYSSET;
    if(modifyTicketNum)
    {
        modifyTicketNum->id = TICKET_MODIFY_TICKET_SET;
        modifyTicketNum->strObjName = "修改临时模板票号";
        modifyTicketNum->var = QVariant(ui->modifyTicketNumCheck->text());
        pSysSetList->append(modifyTicketNum);
    }

    SYSSET *modifySerialNum = new SYSSET;
    if(modifySerialNum)
    {
        modifySerialNum->id = TICKET_MODIFY_SERIAL_SET;
        modifySerialNum->strObjName = "修改流水号";
        modifySerialNum->var = QVariant(ui->modifySerialNumCheck->isChecked());
        pSysSetList->append(modifySerialNum);
    }

    SYSSET *beginSerialNum = new SYSSET;
    if(beginSerialNum)
    {
        beginSerialNum->id = TICKET_BEGIN_SERIAL_NUM;
        beginSerialNum->strObjName = "流水号始于";
        beginSerialNum->var = QVariant(ui->beginSerialNumEdit->text());
        pSysSetList->append(beginSerialNum);
    }
}



void HFormatSetTab::readData()
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i < pSysSetList->count();i++)
    {
        SYSSET *sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            if(sysSet->id == TICKET_ONE_TICKET_NUM)
            {
                ui->oneTicketNumRadio->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_ONE_TICKET_PAGE_NUM)
            {
                ui->oneTicketPageNumRadio->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_ADD_HEAD_TAIL)
            {
                ui->addHeadTailCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_SHOW_HEAD_TAIL)
            {
                ui->showHeadTailCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_HEAD_CONTENT)
            {
                ui->headEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == TICKET_TAIL_CONTENT)
            {
                ui->tailEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == TICKET_PREFIX_SET)
            {
                ui->prefixCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_PREFIX_CONTENT)
            {
                ui->prefixEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == TICKET_SUFFIX_SET)
            {
                ui->suffixCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_SUFFIX_CONTENT)
            {
                ui->suffixEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == TICKET_FIX_LENGTH_SET)
            {
                ui->fixlenthCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_FIX_LENGTH_CONTENT)
            {
                ui->fixlengthEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == TICKET_MODIFY_PRETICKET_SET)
            {
                ui->modifyPreTicketNumCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_MODIFY_NEXT_NUM)
            {
                ui->nextTicketNumEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == TICKET_MODIFY_TICKET_SET)
            {
                ui->modifyTicketNumCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_MODIFY_SERIAL_SET)
            {
                ui->modifySerialNumCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == TICKET_BEGIN_SERIAL_NUM)
            {
                ui->beginSerialNumEdit->setText(sysSet->var.toString());
            }
        }
    }

    ui->showHeadTailCheck->setEnabled(ui->addHeadTailCheck->isChecked());
    bool bCheck = ui->showHeadTailCheck->isChecked() && ui->addHeadTailCheck->isChecked();
    if(bCheck)
    {
        ui->headEdit->setEnabled(bCheck);
        ui->tailEdit->setEnabled(bCheck);
    }
    ui->prefixEdit->setEnabled(ui->prefixCheck->isChecked());
    ui->suffixEdit->setEnabled(ui->suffixCheck->isChecked());
    ui->fixlengthEdit->setEnabled(ui->fixlenthCheck->isChecked());
    ui->nextTicketNumEdit->setEnabled(ui->modifyPreTicketNumCheck->isChecked());
    ui->beginSerialNumEdit->setEnabled(ui->modifySerialNumCheck->isChecked());


}

void HFormatSetTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
}

void HFormatSetTab::addHeadTail()
{
    bool bShow = ui->addHeadTailCheck->isChecked();
    if(bShow)
    {
        ui->showHeadTailCheck->setEnabled(true);
        ui->headEdit->setEnabled(true);
        ui->tailEdit->setEnabled(true);
    }
    else
    {
        ui->showHeadTailCheck->setEnabled(false);
        ui->showHeadTailCheck->setChecked(false);
        ui->headEdit->setEnabled(false);
        ui->tailEdit->setEnabled(false);
    }

}

void HFormatSetTab::prefix()
{
    bool bSelect = ui->prefixCheck->isChecked();
    if(bSelect)
    {
        ui->prefixEdit->setEnabled(true);
    }
    else
    {
        ui->prefixEdit->setEnabled(false);
    }
}

void HFormatSetTab::suffix()
{
    bool bSelect = ui->suffixCheck->isChecked();
    if(bSelect)
    {
        ui->suffixEdit->setEnabled(true);
    }
    else
    {
        ui->suffixEdit->setEnabled(false);
    }
}

void HFormatSetTab::fixlength()
{
    bool bSelect = ui->fixlenthCheck->isChecked();
    if(bSelect)
    {
        ui->fixlengthEdit->setEnabled(true);
    }
    else
    {
        ui->fixlengthEdit->setEnabled(false);
    }
}

void HFormatSetTab::modifyPreTicketNum()
{
    bool bSelect = ui->modifyPreTicketNumCheck->isChecked();
    if(bSelect)
    {
        ui->nextTicketNumEdit->setEnabled(true);
    }
    else
    {
        ui->nextTicketNumEdit->setEnabled(false);
    }
}

void HFormatSetTab::modifySerialNum()
{
    bool bSelect = ui->modifySerialNumCheck->isChecked();
    if(bSelect)
    {
        ui->beginSerialNumEdit->setEnabled(true);
    }
    else
    {
        ui->beginSerialNumEdit->setEnabled(false);
    }
}


