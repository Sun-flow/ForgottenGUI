#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "statswindow.h"
#include "memorieswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionStats_triggered();

    void on_actionMemories_triggered();

    void on_actionSession_Notes_triggered();

private:
    Ui::MainWindow *ui;

    StatsWindow *statsWin;
    MemoriesWindow *memWin;
};
#endif // MAINWINDOW_H