#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    file_name("MetroDataBase.txt"),
      ui(new Ui::MainWindow),
      admin_form (new Admin),
      user_form(new User),
      pswd_form(new Password)

{
    ui->setupUi(this);
    user_form->file_name = admin_form->file_name = this->file_name;

    connect(pswd_form, &Password::show_first, this, &MainWindow::show);
    connect(pswd_form, &Password::give_access, this, &MainWindow::give_access);
    connect(admin_form, &Admin::show_first, this, &MainWindow::show);
    connect(user_form, &User::show_first, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete pswd_form;
    delete user_form;
    delete admin_form;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::ifstream File;
    File.open(file_name.toStdString());
    if (File.is_open())
    {
        this->close();
        user_form->show();
        user_form->setModal(true);
        user_form->exec();
    } else {
        QMessageBox ms;
        ms.addButton("ok",QMessageBox::YesRole);
        ms.setText("Файл не существует!");
        ms.setWindowTitle("Ошибка");
        ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                         "border: 1px solid grey; border-radius: 5px; font-size: 12px; font-color:white; text-align: center;"
                         " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                         "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 20px; width: 30px;"
                         " font-size: 12px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                         "0 #4193ff, stop: 1 #9eeaff);}");
        ms.exec();
    }
}

void MainWindow::on_pushButton_form_data_clicked()
{
     this->close();
     pswd_form->show();
     pswd_form->setModal(true);
     pswd_form->exec();
}

void MainWindow::give_access()
{
    admin_form->show();
}
