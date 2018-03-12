#include "hnormalsettab.h"
#include "ui_normalset.h"
#include <QPalette>
HNormalSetTab::HNormalSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalSet)
{
    ui->setupUi(this);
    initNormalSetTab();
}

HNormalSetTab::~HNormalSetTab()
{
    delete ui;
}

void HNormalSetTab::initNormalSetTab()
{
  //  setAutoFillBackground(true);
  //  QPalette mainPalette = palette();
  //  mainPalette.setColor(QPalette::Background,QColor("lightGray"));
  //  setPalette(mainPalette);


    //ui->yxChangeColorBtn->setAutoFillBackground(true);
    //QPalette btnPalette = ui->yxChangeColorBtn->palette();
    //btnPalette.setColor(QPalette::ButtonText,QColor("red"));
    //ui->yxChangeColorBtn->setPalette(btnPalette);
    QString btnStyleSheet = "background-color:";
    btnStyleSheet += "yellow";
    ui->yxChangeColorBtn->setStyleSheet(btnStyleSheet);
    //ui->yxChangeColorBtn->setText("red");
}
