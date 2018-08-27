#ifndef HSYSPATHTAB_H
#define HSYSPATHTAB_H

#include <QWidget>
#include "hconfigapi.h"
#include "publicdata.h"
namespace Ui {
class SysPath;
}

class HSysPathTab : public QWidget
{
    Q_OBJECT

public:
    explicit HSysPathTab(QWidget *parent = 0);
    ~HSysPathTab();
    void initTab();
    void writeData();
    void readData();
    void clear();

public:
    HSysSetList* pSysSetList;
    QString m_strAppPath;
private:
    Ui::SysPath *ui;

private slots:
    void pathUniteCheck();
    void pathUnite();

    void dataBasePath();
    void pluginPath();
    void eventPath();
    void operaNotePath();
    void workNotePath();

    void iconPath();
    void mediaPath();
    void graphPath();
    void paiPath();
    void iniPath();
};

#endif // HSYSPATHTAB_H
