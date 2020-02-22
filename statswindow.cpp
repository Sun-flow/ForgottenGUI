#include "statswindow.h"
#include "ui_statswindow.h"
#include <QApplication>

StatsWindow::StatsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatsWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 9; i++){
        ui->listWidget->addItem(QString::number(i) + " item here");
    }
}

StatsWindow::~StatsWindow()
{
    delete ui;
}
