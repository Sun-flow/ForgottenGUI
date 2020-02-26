#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "statswindow.h"
#include "memorieswindow.h"
#include "character.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadChar(Character *inChar);

private slots:
    void on_actionStats_triggered();

    void on_actionMemories_triggered();

    void on_actionSession_Notes_triggered();

    //void readFile();

private:
    Ui::MainWindow *ui;

    StatsWindow *statsWin;
    MemoriesWindow *memWin;
};
#endif // MAINWINDOW_H
