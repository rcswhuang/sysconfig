#ifndef HSYSPATHTAB_H
#define HSYSPATHTAB_H

#include <QWidget>
#include "sysconfigapi.h"
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
private:
    Ui::SysPath *ui;

private slots:
    void pathUniteCheck();
    void pathUnite();
    void dataBasePath();
    void symbolPath();
    void eventPath();
    void objGroupPath();
    void operaNotePath();
    void bitmapPath();
    void workNotePath();
    void mediaPath();
    void graphPath();
    void paiPath();
    void filPath();
};

#endif // HSYSPATHTAB_H
