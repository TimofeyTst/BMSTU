#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    key = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit_2->append("Input: " + ui->textEdit->toPlainText());
    if (key)
        ui->textEdit_2->append("All lower: " + ui->textEdit->toPlainText().toLower());
    else ui->textEdit_2->append("All up: " + ui->textEdit->toPlainText().toUpper());
    key = !key;
}

