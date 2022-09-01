#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//Дописал
#include "password.h"
#include "admin.h"
#include "user.h"
#include <fstream>

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
    void on_pushButton_clicked();
    void give_access();
    void on_pushButton_form_data_clicked();

private:
    QString file_name;
    Ui::MainWindow *ui;
    Admin *admin_form;
    User *user_form;
    Password *pswd_form;
};
#endif // MAINWINDOW_H
