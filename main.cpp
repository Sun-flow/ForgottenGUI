#include "mainwindow.h"
#include "xmlreader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Character *myChar = new Character();
    XMLReader xmlReader(myChar);
    myChar->printCharInfo();

    MainWindow w;
    w.loadChar(myChar);
    w.show();
    return a.exec();
}
