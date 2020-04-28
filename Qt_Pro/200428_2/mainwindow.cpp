#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_collapsed(const QModelIndex &index)
{
    index.data();
}

void MainWindow::on_treeView_expanded(const QModelIndex &index)
{
    index.data();
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    index.model();
    index.column();
}
