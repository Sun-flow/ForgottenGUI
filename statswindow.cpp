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
    statsFile->open(QIODevice::ReadWrite);

    for(int i = 0; i < 9; i++){
        ui->listWidget->addItem(QString::number(i) + " item here");
    }
}

StatsWindow::~StatsWindow()
{
    delete ui;
}

void StatsWindow::readFile(){
    QString line;
    QTextStream stream(statsFile);

    if(statsFile->isOpen()){

        while(!stream.atEnd()){
            line = stream.readLine();
            ui->memoryText->setText(ui->memoryText->toPlainText() + line + "\n");
        }

    }
}
