#ifndef MEMORIESWINDOW_H
#define MEMORIESWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QFile>
#include <QDebug>
#include "character.h"

namespace Ui {
class MemoriesWindow;
}

class MemoriesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MemoriesWindow(QWidget *parent = nullptr);

    ~MemoriesWindow();

    void loadChar(Character *newChar);

private slots:

    void readFile();

    void on_memoryText_textChanged();

private:
    Ui::MemoriesWindow *ui;

    QFile *memsFile;
};

#endif // MEMORIESWINDOW_H
