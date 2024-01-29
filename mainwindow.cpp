#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    root = new Composite("Bill", nullptr);
    composites.append(root);
    ui->parentList->addItem("Bill");
    connect(ui->addButton, SIGNAL(clicked()), SLOT(add()));
    connect(ui->isComposite, SIGNAL(stateChanged(int)), SLOT(compositeSwitch(int)));
    updateHierarchy();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete root;
}

void MainWindow::updateHierarchy()
{
    ui->hierarchyViewer->clear();
    ui->hierarchyViewer->addItems(root->getList());
}

void MainWindow::add()
{
    QList<QListWidgetItem*> selected = ui->parentList->selectedItems();
    if(selected.size() == 0)
    {
        return;
    }

    Component* parent = composites[ui->parentList->row(selected[0])];
    Component* newComponent;
    if(ui->isComposite->checkState() == Qt::Checked)
    {

        newComponent = new Composite(ui->name->text(), parent);
        ui->parentList->addItem(ui->name->text());
        composites.append(newComponent);
    }
    else
    {
        newComponent = new Leaf(ui->price->value(), ui->name->text(), parent);
    }
    parent->add(newComponent);
    updateHierarchy();
}

void MainWindow::compositeSwitch(int state)
{
    ui->price->setEnabled(state == Qt::Unchecked);
}

