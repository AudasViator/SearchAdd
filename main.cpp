#include "studentnumberselector.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StudentNumberSelector w;

    w.setFixedHeight(300);
    w.setFixedWidth(400);
    w.setWindowTitle("SearchAdditions");

    w.show();

    return a.exec();
}
