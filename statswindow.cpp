#include "statswindow.h"
#include "ui_statswindow.h"
#include <QApplication>

StatsWindow::StatsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatsWindow)
{
    ui->setupUi(this);

    QString path = qApp->applicationDirPath() + "/bin/stats.txt";

    statsFile = new QFile(path);
    statsFile->open(QIODevice::ReadWrite | QIODevice::Text);

    this->readFile();
}

StatsWindow::~StatsWindow()
{
    delete ui;
    if(statsFile){
        statsFile->close();
    }
}

void StatsWindow::readFile(){
    QString line;
    QTextStream stream(statsFile);

    if(statsFile->isOpen()){

        while(!stream.atEnd()){
            line = stream.readLine();
            ui->tendsList->addItem(line);
        }

    }
}
