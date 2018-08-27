#include "hsyspathset.h"
#include "ui_syspathset.h"
#include <QDir>
#include <QFileDialog>

HSysPathTab::HSysPathTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysPath)
{
    ui->setupUi(this);
    pSysSetList = NULL;
    initTab();
}

HSysPathTab::~HSysPathTab()
{
    delete ui;
    clear();
}


void HSysPathTab::initTab()
{
    clear();
    QString strPath = QDir::currentPath();
    //strPath += "sound";

    bool bPathUnite = true;
    ui->pathUniteCheck->setChecked(bPathUnite);
    if(bPathUnite)
    {
        ui->dataBasePathEdit->setText(strPath);
        ui->dataBasePathEdit->setCursorPosition(0);
        ui->dataBasePathEdit->setReadOnly(true);
        ui->dataBasePathBtn->setEnabled(false);

        ui->symbolPathEdit->setText(strPath);
        ui->symbolPathEdit->setCursorPosition(0);
        ui->symbolPathEdit->setReadOnly(true);
        ui->symbolPathBtn->setEnabled(false);

        ui->eventPathEdit->setText(strPath);
        ui->eventPathEdit->setCursorPosition(0);
        ui->eventPathEdit->setReadOnly(true);
        ui->eventPathBtn->setEnabled(false);

        ui->iniPathEdit->setText(strPath);
        ui->iniPathEdit->setCursorPosition(0);
        ui->iniPathEdit->setReadOnly(true);
        ui->iniPathBtn->setEnabled(false);

        ui->operaNotePathEdit->setText(strPath);
        ui->operaNotePathEdit->setCursorPosition(0);
        ui->operaNotePathEdit->setReadOnly(true);
        ui->operaNotePathBtn->setEnabled(false);

        ui->bitmapPathEdit->setText(strPath);
        ui->bitmapPathEdit->setCursorPosition(0);
        ui->bitmapPathEdit->setReadOnly(true);
        ui->bitmapPathBtn->setEnabled(false);

        ui->workNotePathEdit->setText(strPath);
        ui->workNotePathEdit->setCursorPosition(0);
        ui->workNotePathEdit->setReadOnly(true);
        ui->workNotePathBtn->setEnabled(false);

        ui->mediaPathEdit->setText(strPath);
        ui->mediaPathEdit->setCursorPosition(0);
        ui->mediaPathEdit->setReadOnly(true);
        ui->mediaPathBtn->setEnabled(false);

        ui->graphPathEdit->setText(strPath);
        ui->graphPathEdit->setCursorPosition(0);
        ui->graphPathEdit->setReadOnly(true);
        ui->graphPathBtn->setEnabled(false);

        ui->paiPathEdit->setText(strPath);
        ui->paiPathEdit->setCursorPosition(0);
        ui->paiPathEdit->setReadOnly(true);
        ui->paiPathBtn->setEnabled(false);

        ui->filPathEdit->setText(strPath);
        ui->filPathEdit->setCursorPosition(0);
        ui->filPathEdit->setReadOnly(true);
        ui->filPathBtn->setEnabled(false);

        ui->pluginPathEdit->setText(strPath);
        ui->pluginPathEdit->setCursorPosition(0);
        ui->pluginPathEdit->setReadOnly(true);
        ui->pluginPathBtn->setEnabled(false);
    }

    connect(ui->pathUniteCheck,SIGNAL(clicked()),this,SLOT(pathUniteCheck()));
    connect(ui->pathUniteBtn,SIGNAL(clicked()),this,SLOT(pathUnite()));
    connect(ui->dataBasePathBtn,SIGNAL(clicked()),this,SLOT(dataBasePath()));
    connect(ui->symbolPathBtn,SIGNAL(clicked()),this,SLOT(symbolPath()));
    connect(ui->eventPathBtn,SIGNAL(clicked()),this,SLOT(eventPath()));
    connect(ui->iniPathBtn,SIGNAL(clicked()),this,SLOT(iniPath()));
    connect(ui->operaNotePathBtn,SIGNAL(clicked()),this,SLOT(operaNotePath()));
    connect(ui->bitmapPathBtn,SIGNAL(clicked()),this,SLOT(bitmapPath()));
    connect(ui->workNotePathBtn,SIGNAL(clicked()),this,SLOT(workNotePath()));
    connect(ui->mediaPathBtn,SIGNAL(clicked()),this,SLOT(mediaPath()));
    connect(ui->graphPathBtn,SIGNAL(clicked()),this,SLOT(graphPath()));
    connect(ui->paiPathBtn,SIGNAL(clicked()),this,SLOT(paiPath()));
    connect(ui->filPathBtn,SIGNAL(clicked()),this,SLOT(filPath()));
    connect(ui->pluginPathBtn,SIGNAL(clicked()),this,SLOT(pluginPath()));

}

void HSysPathTab::writeData()
{
    clear();

    SYSSET *pathUniteCheck = new SYSSET;
    if(pathUniteCheck)
    {
        pathUniteCheck->id = SYS_PATH_DATA_SET;
        pathUniteCheck->var = QVariant(ui->pathUniteCheck->isChecked());
        pSysSetList->append(pathUniteCheck);
    }

    SYSSET *pathUniteEdit = new SYSSET;
    if(pathUniteEdit)
    {
        pathUniteEdit->id = SYS_PATH_DATA_SET;
        pathUniteEdit->var = QVariant(ui->pathUniteEdit->text());
        pSysSetList->append(pathUniteEdit);
    }

    SYSSET *dataBasePathEdit = new SYSSET;
    if(dataBasePathEdit)
    {
        dataBasePathEdit->id = SYS_PATH_DATA_SET;
        dataBasePathEdit->var = QVariant(ui->dataBasePathEdit->text());
        pSysSetList->append(dataBasePathEdit);
    }

    SYSSET *symbolPathEdit = new SYSSET;
    if(symbolPathEdit)
    {
        symbolPathEdit->id = SYS_PATH_ICON_SET;
        symbolPathEdit->var = QVariant(ui->symbolPathEdit->text());
        pSysSetList->append(symbolPathEdit);
    }

    SYSSET *eventPathEdit = new SYSSET;
    if(eventPathEdit)
    {
        eventPathEdit->id = SYS_PATH_EVENT_SET;
        eventPathEdit->var = QVariant(ui->eventPathEdit->text());
        pSysSetList->append(eventPathEdit);
    }

    SYSSET *iniPathEdit = new SYSSET;
    if(iniPathEdit)
    {
        iniPathEdit->id = SYS_PATH_INI_SET;
        iniPathEdit->var = QVariant(ui->iniPathEdit->text());
        pSysSetList->append(iniPathEdit);
    }

    SYSSET *operaNotePathEdit = new SYSSET;
    if(operaNotePathEdit)
    {
        operaNotePathEdit->id = SYS_PATH_OPSHEET_SET;
        operaNotePathEdit->var = QVariant(ui->operaNotePathEdit->text());
        pSysSetList->append(operaNotePathEdit);
    }

    SYSSET *bitmapPathEdit = new SYSSET;
    if(bitmapPathEdit)
    {
        bitmapPathEdit->id = SYS_PATH_BITMAP_SET;
        bitmapPathEdit->var = QVariant(ui->bitmapPathEdit->text());
        pSysSetList->append(bitmapPathEdit);
    }

    SYSSET *workNotePathEdit = new SYSSET;
    if(workNotePathEdit)
    {
        workNotePathEdit->id = SYS_PATH_WORKNOTE_SET;
        workNotePathEdit->var = QVariant(ui->workNotePathEdit->text());
        pSysSetList->append(workNotePathEdit);
    }

    SYSSET *mediaPathEdit = new SYSSET;
    if(mediaPathEdit)
    {
        mediaPathEdit->id = SYS_PATH_MEDIR_SET;
        mediaPathEdit->var = QVariant(ui->mediaPathEdit->text());
        pSysSetList->append(mediaPathEdit);
    }

    SYSSET *graphPathEdit = new SYSSET;
    if(graphPathEdit)
    {
        graphPathEdit->id = SYS_PATH_GRAPH_SET;
        graphPathEdit->var = QVariant(ui->graphPathEdit->text());
        pSysSetList->append(graphPathEdit);
    }

    SYSSET *paiPathEdit = new SYSSET;
    if(paiPathEdit)
    {
        paiPathEdit->id = SYS_PATH_SIGNPAD_SET;
        paiPathEdit->var = QVariant(ui->paiPathEdit->text());
        pSysSetList->append(paiPathEdit);
    }

    SYSSET *filPathEdit = new SYSSET;
    if(filPathEdit)
    {
        filPathEdit->id = SYS_PATH_FIL_SET;
        filPathEdit->var = QVariant(ui->filPathEdit->text());
        pSysSetList->append(filPathEdit);
    }

    SYSSET *pluginPathEdit = new SYSSET;
    if(pluginPathEdit)
    {
        pluginPathEdit->id = SYS_PATH_PLUGIN_SET;
        pluginPathEdit->var = QVariant(ui->pluginPathEdit->text());
        pSysSetList->append(pluginPathEdit);
    }
}

void HSysPathTab::readData()
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i < pSysSetList->count();i++)
    {
        SYSSET* sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            if(sysSet->id == SYS_PATH_UNITE_SET)
            {
                ui->pathUniteEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_UNITE_CHECK)
            {
                bool bChecked = false;
                if(sysSet->var.toUInt() == 1)
                    bChecked = true;
                ui->pathUniteCheck->setChecked(bChecked);
            }
            else if(sysSet->id == SYS_PATH_DATA_SET)
            {
                ui->dataBasePathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_ICON_SET)
            {
                ui->symbolPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_INI_SET)
            {
                ui->iniPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_EVENT_SET)
            {
                ui->eventPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_OPSHEET_SET)
            {
                ui->operaNotePathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_BITMAP_SET)
            {
                ui->bitmapPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_WORKNOTE_SET)
            {
                ui->workNotePathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_MEDIR_SET)
            {
                ui->mediaPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_GRAPH_SET)
            {
                ui->graphPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_SIGNPAD_SET)
            {
                ui->paiPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_FIL_SET)
            {
                ui->filPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_PLUGIN_SET)
            {
                ui->pluginPathEdit->setText(sysSet->var.toString());
            }
        }
    }
}

void HSysPathTab::clear()
{
    if(pSysSetList == NULL) return;
    while(!pSysSetList->isEmpty())
        delete (SYSSET*)pSysSetList->takeFirst();
    pSysSetList->clear();
}

void HSysPathTab::pathUniteCheck()
{
    bool bPathUnite = ui->pathUniteCheck->isChecked();
    if(bPathUnite)
    {
        QString strPath = ui->pathUniteEdit->text();
        ui->dataBasePathEdit->setText(strPath);
        ui->dataBasePathEdit->setCursorPosition(0);
        ui->dataBasePathEdit->setReadOnly(true);
        ui->dataBasePathBtn->setEnabled(false);

        ui->symbolPathEdit->setText(strPath);
        ui->symbolPathEdit->setCursorPosition(0);
        ui->symbolPathEdit->setReadOnly(true);
        ui->symbolPathBtn->setEnabled(false);

        ui->eventPathEdit->setText(strPath);
        ui->eventPathEdit->setCursorPosition(0);
        ui->eventPathEdit->setReadOnly(true);
        ui->eventPathBtn->setEnabled(false);

        ui->iniPathEdit->setText(strPath);
        ui->iniPathEdit->setCursorPosition(0);
        ui->iniPathEdit->setReadOnly(true);
        ui->iniPathBtn->setEnabled(false);

        ui->operaNotePathEdit->setText(strPath);
        ui->operaNotePathEdit->setCursorPosition(0);
        ui->operaNotePathEdit->setReadOnly(true);
        ui->operaNotePathBtn->setEnabled(false);

        ui->bitmapPathEdit->setText(strPath);
        ui->bitmapPathEdit->setCursorPosition(0);
        ui->bitmapPathEdit->setReadOnly(true);
        ui->bitmapPathBtn->setEnabled(false);

        ui->workNotePathEdit->setText(strPath);
        ui->workNotePathEdit->setCursorPosition(0);
        ui->workNotePathEdit->setReadOnly(true);
        ui->workNotePathBtn->setEnabled(false);

        ui->mediaPathEdit->setText(strPath);
        ui->mediaPathEdit->setCursorPosition(0);
        ui->mediaPathEdit->setReadOnly(true);
        ui->mediaPathBtn->setEnabled(false);

        ui->graphPathEdit->setText(strPath);
        ui->graphPathEdit->setCursorPosition(0);
        ui->graphPathEdit->setReadOnly(true);
        ui->graphPathBtn->setEnabled(false);

        ui->paiPathEdit->setText(strPath);
        ui->paiPathEdit->setCursorPosition(0);
        ui->paiPathEdit->setReadOnly(true);
        ui->paiPathBtn->setEnabled(false);

        ui->filPathEdit->setText(strPath);
        ui->filPathEdit->setCursorPosition(0);
        ui->filPathEdit->setReadOnly(true);
        ui->filPathBtn->setEnabled(false);

        ui->pluginPathEdit->setText(strPath);
        ui->pluginPathEdit->setCursorPosition(0);
        ui->pluginPathEdit->setReadOnly(true);
        ui->pluginPathBtn->setEnabled(false);
    }
    else
    {
        //QString strPath = ui->pathUniteEdit->text();
        //ui->dataBasePathEdit->setText(strPath);
        ui->dataBasePathEdit->setReadOnly(false);
        ui->dataBasePathBtn->setEnabled(true);

        //ui->symbolPathEdit->setText(strPath);
        ui->symbolPathEdit->setReadOnly(false);
        ui->symbolPathBtn->setEnabled(true);

        //ui->eventPathEdit->setText(strPath);
        ui->eventPathEdit->setReadOnly(false);
        ui->eventPathBtn->setEnabled(true);

        //ui->objGroupPathEdit->setText(strPath);
        ui->iniPathEdit->setReadOnly(false);
        ui->iniPathBtn->setEnabled(true);

        //ui->operaNotePathEdit->setText(strPath);
        ui->operaNotePathEdit->setReadOnly(false);
        ui->operaNotePathBtn->setEnabled(true);

        //ui->bitmapPathEdit->setText(strPath);
        ui->bitmapPathEdit->setReadOnly(false);
        ui->bitmapPathBtn->setEnabled(true);

        //ui->workNotePathEdit->setText(strPath);
        ui->workNotePathEdit->setReadOnly(false);
        ui->workNotePathBtn->setEnabled(true);

        //ui->mediaPathEdit->setText(strPath);
        ui->mediaPathEdit->setReadOnly(false);
        ui->mediaPathBtn->setEnabled(true);

        //ui->graphPathEdit->setText(strPath);
        ui->graphPathEdit->setReadOnly(false);
        ui->graphPathBtn->setEnabled(true);

        //ui->paiPathEdit->setText(strPath);
        ui->paiPathEdit->setReadOnly(false);
        ui->paiPathBtn->setEnabled(true);

        //ui->filPathEdit->setText(strPath);
        ui->filPathEdit->setReadOnly(false);
        ui->filPathBtn->setEnabled(true);

        ui->pluginPathEdit->setReadOnly(false);
        ui->pluginPathBtn->setEnabled(true);
    }
}

void HSysPathTab::pathUnite()
{
    QString strPath;
    strPath = ui->pathUniteEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->pathUniteEdit->setText(dir);
    ui->pathUniteEdit->setCursorPosition(0);

    //统一设置其他路径
    QString subDir;
    subDir = dir + "//Data"; //....遗留问题---huangw
}

void HSysPathTab::dataBasePath()
{
    QString strPath;
    strPath = ui->dataBasePathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->dataBasePathEdit->setText(dir);
    ui->dataBasePathEdit->setCursorPosition(0);
}

void HSysPathTab::symbolPath()
{
    QString strPath;
    strPath = ui->symbolPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->symbolPathEdit->setText(dir);
    ui->symbolPathEdit->setCursorPosition(0);
}

void HSysPathTab::eventPath()
{
    QString strPath;
    strPath = ui->eventPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->eventPathEdit->setText(dir);
    ui->eventPathEdit->setCursorPosition(0);
}

void HSysPathTab::iniPath()
{
    QString strPath;
    strPath = ui->iniPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->iniPathEdit->setText(dir);
    ui->iniPathEdit->setCursorPosition(0);
}

void HSysPathTab::operaNotePath()
{
    QString strPath;
    strPath = ui->operaNotePathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->operaNotePathEdit->setText(dir);
    ui->operaNotePathEdit->setCursorPosition(0);
}

void HSysPathTab::bitmapPath()
{
    QString strPath;
    strPath = ui->bitmapPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->bitmapPathEdit->setText(dir);
    ui->bitmapPathEdit->setCursorPosition(0);
}

void HSysPathTab::workNotePath()
{
    QString strPath;
    strPath = ui->workNotePathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->workNotePathEdit->setText(dir);
    ui->workNotePathEdit->setCursorPosition(0);
}

void HSysPathTab::mediaPath()
{
    QString strPath;
    strPath = ui->mediaPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->mediaPathEdit->setText(dir);
    ui->mediaPathEdit->setCursorPosition(0);
}

void HSysPathTab::graphPath()
{
    QString strPath;
    strPath = ui->graphPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->graphPathEdit->setText(dir);
    ui->graphPathEdit->setCursorPosition(0);
}

void HSysPathTab::paiPath()
{
    QString strPath;
    strPath = ui->paiPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->paiPathEdit->setText(dir);
    ui->paiPathEdit->setCursorPosition(0);
}

void HSysPathTab::filPath()
{
    QString strPath;
    strPath = ui->filPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->filPathEdit->setText(dir);
    ui->filPathEdit->setCursorPosition(0);
}

void HSysPathTab::pluginPath()
{
    QString strPath;
    strPath = ui->pluginPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->pluginPathEdit->setText(dir);
    ui->pluginPathEdit->setCursorPosition(0);
}
