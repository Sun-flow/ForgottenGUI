#include "memorieswindow.h"
#include "ui_memorieswindow.h"
#include <QDir>
#include <QByteArray>

MemoriesWindow::MemoriesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoriesWindow)
{
    ui->setupUi(this);

    QString path = qApp->applicationDirPath() + "/bin/memories.txt";

    memsFile = new QFile(path);
    memsFile->open(QIODevice::ReadWrite);

    this->readFile();
}

MemoriesWindow::~MemoriesWindow()
{
    delete ui;

    if(memsFile){
        memsFile->close();
    }
}

void MemoriesWindow::readFile(){
    QString line;
    QTextStream stream(memsFile);

    if(memsFile->isOpen()){

        while(!stream.atEnd()){
            line = stream.readLine();
            ui->memoryText->setText(ui->memoryText->toPlainText() + line + "\n");
        }

    }
}

void MemoriesWindow::on_memoryText_textChanged()
{
    memsFile->resize(0);
    QTextStream stream(memsFile);
    stream << ui->memoryText->toPlainText();
}
