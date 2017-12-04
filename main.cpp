#include "studentnumberselector.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator qtHelpTranslator;
    qtHelpTranslator.load("qt_help_ru",QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtHelpTranslator);

    QTranslator qtTranslator;
    qtTranslator.load("qt_ru",QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    StudentNumberSelector w;

    w.setWindowTitle("SearchAdditions");
    w.show();

    return a.exec();
}
