#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "component.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateHierarchy();
public slots:
    void add();
    void compositeSwitch(int state);

private:
    Component* root;
    QList<Component*> composites;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
