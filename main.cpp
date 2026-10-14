#include "numtransdlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumTransDlg w;
    w.setWindowTitle("數字轉換器");
    w.show();
    return QApplication::exec();
}
