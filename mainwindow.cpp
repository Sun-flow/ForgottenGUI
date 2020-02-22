#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statsWin = new StatsWindow;
    memWin = new MemoriesWindow;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionStats_triggered()
{
    statsWin->show();
}

void MainWindow::on_actionMemories_triggered()
{
    memWin->show();
}

void MainWindow::on_actionSession_Notes_triggered()
{

}
