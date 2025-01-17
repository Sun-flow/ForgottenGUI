#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QWidget>
#include <QFile>
#include <QTextEdit>
#include <QTextStream>

namespace Ui {
class StatsWindow;
}

class StatsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatsWindow(QWidget *parent = nullptr);
    ~StatsWindow();

private slots:

    void readFile();

private:
    Ui::StatsWindow *ui;

    QFile *statsFile;
};

#endif // STATSWINDOW_H
