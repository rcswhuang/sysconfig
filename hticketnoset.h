#ifndef HWORKNOTESET_H
#define HWORKNOTESET_H

#include <QWidget>
#include "hconfigapi.h"
namespace Ui {
class WorkNoteSet;
}

class HWorkNoteSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit HWorkNoteSetTab(QWidget *parent = 0);
    ~HWorkNoteSetTab();
    void initTab();
    void writeData();
    void readData();
    void clear();

public:
    HSysSetList* pSysSetList;
private:
    Ui::WorkNoteSet *ui;
};

#endif // HWORKNOTESET_H
