#include "password.h"
#include "ui_password.h"

#include <QCloseEvent>
#include <QString>
#include <QMessageBox>
static QString password = "tima", file_name = "MetroDataBase.txt";
static int tryes = 3;
Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{
    ui->setupUi(this);
    ui->Edit_pswd->setEchoMode(QLineEdit::Password);
}

Password::~Password()
{
    delete ui;
}
void Password::closeEvent(QCloseEvent *event)
{
    if (ui->Edit_pswd->text()==password) { ui->Edit_pswd->setText(""); emit give_access(); }
    else {
        event->ignore();
        QMessageBox ms;
        QAbstractButton *yes = ms.addButton("🙉",QMessageBox::YesRole);
        ms.addButton("🙈",QMessageBox::NoRole);
        ms.setText("Ты думал ты Админ?");
        ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                             "border: 1px solid grey; border-radius: 5px; font-size: 15px; text-align: center;"
                             " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                             "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 10px; height: 30px; width: 80px;"
                             " font-size: 25px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                             "0 #4193ff, stop: 1 #9eeaff);}");
        ms.exec();
        if(ms.clickedButton() == yes)
        {
            emit show_first();
            event->accept();
        }
    }
}
void Password::on_pushButton_clicked()
{
    if (ui->Edit_pswd->text()==password)
    {
        this->close();

        tryes = 3;
    } else {
        QMessageBox ms;
        ms.addButton("ok",QMessageBox::YesRole);
        ms.setText("Uncorrect Password, tryes remaining: " + QString::number(--tryes));
        ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                         "border: 1px solid grey; border-radius: 5px; font-size: 12px; font-color:white; text-align: center;"
                         " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                         "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 20px; width: 30px;"
                         " font-size: 12px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                         "0 #4193ff, stop: 1 #9eeaff);}");
        ms.exec();
       // QMessageBox::critical();
        if (tryes < 1)
        {
            this->close();
            qApp->quit();
        }
    }
}

