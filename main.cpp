#include "hsysconfigdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HSysConfigDlg w;
    w.show();

    return a.exec();
}
