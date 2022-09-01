#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
const int n=26;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(number_pressed()));
    connect(ui->pushButton_repeat,SIGNAL(clicked()),this,SLOT(on_operations()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(on_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(on_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(on_operations()));
    connect(ui->pushButton_power,SIGNAL(clicked()),this,SLOT(on_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_del->setCheckable(true);
    ui->pushButton_repeat->setCheckable(true);
    ui->pushButton_log->setCheckable(true);
    ui->pushButton_fact->setCheckable(true);
    ui->pushButton_power->setCheckable(true);
    is_result = false;
    is_ClearAfterFirst = false;
    need_to_clear = false;
    ui->Answer_help->setText("");
    current_button = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::number_pressed()
{
     QPushButton *button = (QPushButton*) sender();
     QString Answer = ui->Answer->text();
     if (is_result) {

         ui->Answer->setText(button->text());
         is_result = false;

     } else if (is_ClearAfterFirst) {

         ui->Answer->setText(button->text());
         is_ClearAfterFirst = false;

         } else if (Answer.length()<n) {
            double num = (Answer + button->text()).toDouble();
            QString last;
            if (Answer.contains("."))
                last = Answer + button->text();
            else
                last = QString::number(num,'g',15);
            ui->Answer->setText(last);
     }
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->Answer->text().contains("."))
    ui->Answer->setText(ui->Answer->text()+".");
}

/*void MainWindow::clearing()
{
    if (need_to_clear)
    {
        ui->Answer->setText("0");
        ui->Answer_help->setText("");
        is_result = false;
        is_ClearAfterFirst = false;
        current_button->setChecked(false);
        current_button = nullptr;
        first_num = 0;
        second_num = 0;
        need_to_clear = false;
    }
} */
void MainWindow::on_pushButton_erase_clicked()
{
    ui->Answer->setText("0");
    ui->Answer_help->setText("");
    is_result = false;
    is_ClearAfterFirst = false;
    if (current_button != nullptr)
    current_button->setChecked(false);
    first_num = 0;
    second_num = 0;
}


void MainWindow::on_pushButton_eLast_clicked()
{
        QString was = ui->Answer->text(), last;
        for (int i = 0; i<was.length()-1;i++)
        {
            last += was[i];
        }
        //проверка если ласт длина равна 0 то ласт равен 0
        if (last.length()==0) last = "0";
        ui->Answer->setText(last);
        first_num = last.toDouble();
}


void MainWindow::on_pushButton_pi_clicked()
{
    ui->Answer->setText("3.1415926535897932384");
}


void MainWindow::on_pushButton_e_clicked()
{
    ui->Answer->setText("2.7182818284590452353");
}


void MainWindow::on_PushButton_swap_clicked()
{
    QString answer = ui->Answer->text(),last;
    if (answer[0] == '-')
        for (int i=1;i<answer.length();i++)
            last += answer[i];
    else last = "-" + answer;
    if (last.length()==0) last = "0";
    ui->Answer->setText(last);
    first_num = last.toDouble();
}
void MainWindow::on_operations()
{
        if (current_button!=nullptr)
            current_button->setChecked(false);
        current_button = (QPushButton *) sender();
        first_num = ui->Answer->text().toDouble();
        QString s3 =current_button->text();
        if (s3 == "xʸ") s3 = "^";
        ui->Answer_help->setText(ui->Answer->text() + s3);

        current_button->setChecked(true);
        is_ClearAfterFirst = true;
        is_result = false;
}


void MainWindow::on_pushButton_anwser_clicked()
{
    bool is_error = false;
    double result = 0;
    if (!is_result)
        second_num = ui->Answer->text().toDouble(); //Не меняем второе число, пока не будет нажата новая операция
    if (ui->pushButton_plus->isChecked()) {
        result = first_num + second_num;
    } else if (ui->pushButton_minus->isChecked()) {
        result = first_num - second_num;
    } else if (ui->pushButton_repeat->isChecked()) {
        result = first_num * second_num;
    } else if (ui->pushButton_del->isChecked()) {
        if (second_num != 0) result = first_num / second_num;
        else { result = 0; is_error = true; }
    } else if (ui->pushButton_power->isChecked()) {
        result = qPow(first_num,second_num);
    }
    if (is_error) {
        ui->Answer_help->setText("Invalid parametres");
    }
    else if (current_button!=nullptr){
        QString s1 = QString::number(first_num,'g',n), s2 = QString::number(second_num,'g',n), s3 = current_button->text();
        if (current_button->text() == "xʸ") s3 = "^";
        ui->Answer_help->setText(s1 + s3 + s2 + " = ");
        ui->Answer->setText(QString::number(result,'g', n-1));
    }
    first_num = result;
    is_result = true;
}
int factorial (int num) {
    if (num ==0 ) return num;
    else if (num == 1) return num;
    else return num * factorial(num-1);
}


void MainWindow::on_pushButton_log_clicked()
{
    first_num = ui->Answer->text().toDouble();
    if (first_num <=0 ) ui->Answer_help->setText("Invalid parametres");
    else {
        ui->Answer_help->setText("lg"+ QString::number(first_num,'g',n-1) + " = ");
        double answer;
        answer = qLn(first_num)/qLn(10);
        ui->Answer->setText(QString::number(answer,'g',n-1));
    }
}


void MainWindow::on_pushButton_fact_clicked()
{
    first_num = qFloor(ui->Answer->text().toDouble());
    if (first_num <0 ) ui->Answer_help->setText("Invalid parametres");
    else if (first_num > 31)
        ui->Answer_help->setText("Overflow");
    else {
        ui->Answer_help->setText(QString::number(first_num,'g',n-1) + "! = ");
        ui->Answer->setText(QString::number(factorial(first_num),'g',n-1));
    }
}

