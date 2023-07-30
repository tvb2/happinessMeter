#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QObject>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    QStringList uiLanguages;// = QLocale::system().uiLanguages();
    uiLanguages << "English" << "Russian";
    QString lang = QInputDialog::getItem(NULL, "Select language",
                                         "Language", uiLanguages);
    if (lang == "Russian"){
        translator.load(":/happinessMeter_ru_RU.qm");
    }
    if (lang != "English"){
        a.installTranslator(&translator);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
