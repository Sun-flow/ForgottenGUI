#ifndef MEMORIESWINDOW_H
#define MEMORIESWINDOW_H

#include <QWidget>

namespace Ui {
class MemoriesWindow;
}

class MemoriesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MemoriesWindow(QWidget *parent = nullptr);
    ~MemoriesWindow();

private:
    Ui::MemoriesWindow *ui;
};

#endif // MEMORIESWINDOW_H
