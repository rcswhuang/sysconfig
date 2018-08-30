#include "hsyspathset.h"
#include "ui_syspathset.h"
#include <QDir>
#include <QFileDialog>
#include <QProcessEnvironment>
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
    QString strConfigFilePath = QProcessEnvironment::systemEnvironment().value("wfsystem_dir");
    if(strConfigFilePath.isEmpty())
    {
        strConfigFilePath = QCoreApplication::applicationDirPath();
        strConfigFilePath = strConfigFilePath.left(strConfigFilePath.lastIndexOf("/"));
    }
    m_strAppPath = strConfigFilePath;

    bool bPathUnite = true;
    ui->pathUniteCheck->setChecked(bPathUnite);
    ui->pathUniteEdit->setText(m_strAppPath);
    //读取时应该所有都读取，读取结束后按照此标志来进行设置

    connect(ui->pathUniteCheck,SIGNAL(clicked()),this,SLOT(pathUniteCheck()));
    connect(ui->pathUniteBtn,SIGNAL(clicked()),this,SLOT(pathUnite()));

    connect(ui->dataBasePathBtn,SIGNAL(clicked()),this,SLOT(dataBasePath()));
    connect(ui->pluginPathBtn,SIGNAL(clicked()),this,SLOT(pluginPath()));
    connect(ui->eventPathBtn,SIGNAL(clicked()),this,SLOT(eventPath()));
    connect(ui->operaNotePathBtn,SIGNAL(clicked()),this,SLOT(operaNotePath()));
    connect(ui->workNotePathBtn,SIGNAL(clicked()),this,SLOT(workNotePath()));

    connect(ui->iconPathBtn,SIGNAL(clicked()),this,SLOT(iconPath()));
    connect(ui->iniPathBtn,SIGNAL(clicked()),this,SLOT(iniPath()));
    connect(ui->mediaPathBtn,SIGNAL(clicked()),this,SLOT(mediaPath()));
    connect(ui->graphPathBtn,SIGNAL(clicked()),this,SLOT(graphPath()));
    connect(ui->paiPathBtn,SIGNAL(clicked()),this,SLOT(paiPath()));
}

void HSysPathTab::writeData()
{
    clear();

    SYSSET *pathUniteCheck = new SYSSET;
    if(pathUniteCheck)
    {
        pathUniteCheck->id = SYS_PATH_UNITE_CHECK;
        pathUniteCheck->strObjName = QStringLiteral("是否统一设置");
        pathUniteCheck->var = QVariant(ui->pathUniteCheck->isChecked());
        pSysSetList->append(pathUniteCheck);
    }

    SYSSET *pathUniteEdit = new SYSSET;
    if(pathUniteEdit)
    {
        pathUniteEdit->id = SYS_PATH_UNITE_SET;
        pathUniteCheck->strObjName = QStringLiteral("统一路径");
        pathUniteEdit->var = QVariant(ui->pathUniteEdit->text());
        pSysSetList->append(pathUniteEdit);
    }

    SYSSET *pluginPathEdit = new SYSSET;
    if(pluginPathEdit)
    {
        pluginPathEdit->id = SYS_PATH_PLUGIN_SET;
        pluginPathEdit->strObjName = QStringLiteral("插件库路径");
        pluginPathEdit->var = QVariant(ui->pluginPathEdit->text());
        pSysSetList->append(pluginPathEdit);
    }

    SYSSET *dataBasePathEdit = new SYSSET;
    if(dataBasePathEdit)
    {
        dataBasePathEdit->id = SYS_PATH_DATA_SET;
        dataBasePathEdit->strObjName = QStringLiteral("数据库路径");
        dataBasePathEdit->var = QVariant(ui->dataBasePathEdit->text());
        pSysSetList->append(dataBasePathEdit);
    }

    SYSSET *eventPathEdit = new SYSSET;
    if(eventPathEdit)
    {
        eventPathEdit->id = SYS_PATH_EVENT_SET;
        eventPathEdit->strObjName = QStringLiteral("事件库路径");
        eventPathEdit->var = QVariant(ui->eventPathEdit->text());
        pSysSetList->append(eventPathEdit);
    }

    SYSSET *operaNotePathEdit = new SYSSET;
    if(operaNotePathEdit)
    {
        operaNotePathEdit->id = SYS_PATH_OPSHEET_SET;
        operaNotePathEdit->strObjName = QStringLiteral("操作票库路径");
        operaNotePathEdit->var = QVariant(ui->operaNotePathEdit->text());
        pSysSetList->append(operaNotePathEdit);
    }

    SYSSET *workNotePathEdit = new SYSSET;
    if(workNotePathEdit)
    {
        workNotePathEdit->id = SYS_PATH_WORKNOTE_SET;
        workNotePathEdit->strObjName = QStringLiteral("工作票库路径");
        workNotePathEdit->var = QVariant(ui->workNotePathEdit->text());
        pSysSetList->append(workNotePathEdit);
    }

    SYSSET *iconPathEdit = new SYSSET;
    if(iconPathEdit)
    {
        iconPathEdit->id = SYS_PATH_ICON_SET;
        iconPathEdit->strObjName = QStringLiteral("图符库路径");
        iconPathEdit->var = QVariant(ui->iconPathEdit->text());
        pSysSetList->append(iconPathEdit);
    }

    SYSSET *mediaPathEdit = new SYSSET;
    if(mediaPathEdit)
    {
        mediaPathEdit->id = SYS_PATH_MEDIR_SET;
        mediaPathEdit->strObjName = QStringLiteral("媒体库路径");
        mediaPathEdit->var = QVariant(ui->mediaPathEdit->text());
        pSysSetList->append(mediaPathEdit);
    }

    SYSSET *graphPathEdit = new SYSSET;
    if(graphPathEdit)
    {
        graphPathEdit->id = SYS_PATH_GRAPH_SET;
        graphPathEdit->strObjName = QStringLiteral("图形库路径");
        graphPathEdit->var = QVariant(ui->graphPathEdit->text());
        pSysSetList->append(graphPathEdit);
    }

    SYSSET *paiPathEdit = new SYSSET;
    if(paiPathEdit)
    {
        paiPathEdit->id = SYS_PATH_SIGNPAD_SET;
        paiPathEdit->strObjName = QStringLiteral("接地牌库路径");
        paiPathEdit->var = QVariant(ui->paiPathEdit->text());
        pSysSetList->append(paiPathEdit);
    }

    SYSSET *iniPathEdit = new SYSSET;
    if(iniPathEdit)
    {
        iniPathEdit->id = SYS_PATH_INI_SET;
        iniPathEdit->strObjName = QStringLiteral("配置库路径");
        iniPathEdit->var = QVariant(ui->iniPathEdit->text());
        pSysSetList->append(iniPathEdit);
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
                if(sysSet->var.isValid())
                    ui->pathUniteEdit->setText(sysSet->var.toString());
                else
                    ui->pathUniteEdit->setText(m_strAppPath);
            }
            else if(sysSet->id == SYS_PATH_UNITE_CHECK)
            {
                ui->pathUniteCheck->setChecked(sysSet->var.toBool());
            }
            else if(sysSet->id == SYS_PATH_DATA_SET)
            {
                ui->dataBasePathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_PLUGIN_SET)
            {
                ui->pluginPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_EVENT_SET)
            {
                ui->eventPathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_OPSHEET_SET)
            {
                ui->operaNotePathEdit->setText(sysSet->var.toString());
            }
            else if(sysSet->id == SYS_PATH_ICON_SET)
            {
                ui->iconPathEdit->setText(sysSet->var.toString());
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
            else if(sysSet->id == SYS_PATH_INI_SET)
            {
                ui->iniPathEdit->setText(sysSet->var.toString());
            }
        }
    }
    //读完需要触发一下统一check信号
    pathUniteCheck();
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
        QString strPath1 = ui->pathUniteEdit->text();
        strPath1 += "/";
        QString strSubPath = PATH_DATA;
        QString strPath =  strPath1 + strSubPath + "/";
        ui->dataBasePathEdit->setText(strPath);
        ui->dataBasePathEdit->setCursorPosition(0);
        ui->dataBasePathEdit->setReadOnly(true);
        ui->dataBasePathBtn->setEnabled(false);
        ui->dataBasePathEdit->setToolTip(strPath);

        strSubPath = PATH_PLUGIN;
        strPath =  strPath1 + strSubPath + "/";
        ui->pluginPathEdit->setText(strPath);
        ui->pluginPathEdit->setCursorPosition(0);
        ui->pluginPathEdit->setReadOnly(true);
        ui->pluginPathBtn->setEnabled(false);

        strSubPath = PATH_EVENT;
        strPath =  strPath1 + strSubPath + "/";
        ui->eventPathEdit->setText(strPath);
        ui->eventPathEdit->setCursorPosition(0);
        ui->eventPathEdit->setReadOnly(true);
        ui->eventPathBtn->setEnabled(false);

        strSubPath = PATH_OPERATETICKET;
        strPath =  strPath1 + strSubPath + "/";
        ui->operaNotePathEdit->setText(strPath);
        ui->operaNotePathEdit->setCursorPosition(0);
        ui->operaNotePathEdit->setReadOnly(true);
        ui->operaNotePathBtn->setEnabled(false);

        strSubPath = PATH_WORKNOTE;
        strPath =  strPath1 + strSubPath + "/";
        ui->workNotePathEdit->setText(strPath);
        ui->workNotePathEdit->setCursorPosition(0);
        ui->workNotePathEdit->setReadOnly(true);
        ui->workNotePathBtn->setEnabled(false);

        strSubPath = PATH_ICON;
        strPath =  strPath1 + strSubPath + "/";
        ui->iconPathEdit->setText(strPath);
        ui->iconPathEdit->setCursorPosition(0);
        ui->iconPathEdit->setReadOnly(true);
        ui->iconPathBtn->setEnabled(false);

        strSubPath = PATH_GRAPH;
        strPath =  strPath1 + strSubPath + "/";
        ui->graphPathEdit->setText(strPath);
        ui->graphPathEdit->setCursorPosition(0);
        ui->graphPathEdit->setReadOnly(true);
        ui->graphPathBtn->setEnabled(false);

        strSubPath = PATH_MEDIA;
        strPath =  strPath1 + strSubPath + "/";
        ui->mediaPathEdit->setText(strPath);
        ui->mediaPathEdit->setCursorPosition(0);
        ui->mediaPathEdit->setReadOnly(true);
        ui->mediaPathBtn->setEnabled(false);

        strSubPath = PATH_SIGNPAD;
        strPath =  strPath1 + strSubPath + "/";
        ui->paiPathEdit->setText(strPath);
        ui->paiPathEdit->setCursorPosition(0);
        ui->paiPathEdit->setReadOnly(true);
        ui->paiPathBtn->setEnabled(false);

        strSubPath = PATH_INI;
        strPath =  strPath1 + strSubPath + "/";
        ui->iniPathEdit->setText(strPath);
        ui->iniPathEdit->setCursorPosition(0);
        ui->iniPathEdit->setReadOnly(true);
        ui->iniPathBtn->setEnabled(false);
    }
    else
    {
        ui->pluginPathEdit->setReadOnly(false);
        ui->pluginPathBtn->setEnabled(true);

        ui->dataBasePathEdit->setReadOnly(false);
        ui->dataBasePathBtn->setEnabled(true);

        ui->eventPathEdit->setReadOnly(false);
        ui->eventPathBtn->setEnabled(true);

        ui->operaNotePathEdit->setReadOnly(false);
        ui->operaNotePathBtn->setEnabled(true);

        ui->workNotePathEdit->setReadOnly(false);
        ui->workNotePathBtn->setEnabled(true);

        ui->iconPathEdit->setReadOnly(false);
        ui->iconPathBtn->setEnabled(true);

        ui->graphPathEdit->setReadOnly(false);
        ui->graphPathBtn->setEnabled(true);

        ui->mediaPathEdit->setReadOnly(false);
        ui->mediaPathBtn->setEnabled(true);

        ui->paiPathEdit->setReadOnly(false);
        ui->paiPathBtn->setEnabled(true);

        ui->iniPathEdit->setReadOnly(false);
        ui->iniPathBtn->setEnabled(true);
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
    pathUniteCheck();
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

//right
void HSysPathTab::iconPath()
{
    QString strPath;
    strPath = ui->iconPathEdit->text();
    if(strPath.isEmpty())
        strPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, ("浏览目录"),strPath,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty()) return;
    ui->iconPathEdit->setText(dir);
    ui->iconPathEdit->setCursorPosition(0);
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
