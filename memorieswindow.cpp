#include "memorieswindow.h"
#include "ui_memorieswindow.h"

MemoriesWindow::MemoriesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoriesWindow)
{
    ui->setupUi(this);
}

MemoriesWindow::~MemoriesWindow()
{
    delete ui;
}
