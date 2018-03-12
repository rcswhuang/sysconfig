#ifndef NORMALSET_H
#define NORMALSET_H

#include <QWidget>

namespace Ui {
class NormalSet;
}

class HNormalSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit HNormalSetTab(QWidget *parent = 0);
    ~HNormalSetTab();

public:
    void initNormalSetTab();
private:
    Ui::NormalSet *ui;
};

#endif // NORMALSET_H
