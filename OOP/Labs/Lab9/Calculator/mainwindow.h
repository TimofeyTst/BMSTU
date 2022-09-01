#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool is_result; //Если результат был, то сохраняем второе число меняя первое пока не нажата новая операция
    bool is_ClearAfterFirst; //Использую для очистки графы ответа для ввода второго числа после нажатия на любую операцию
    bool need_to_clear;
    double first_num; //Запоминаю первое число
    double second_num; //Запоминаю второе число
//Прикол в том, что нужно запомнить второе и отнимать его каждый раз, пока не нажал новую операцию
    QPushButton *current_button;

private slots:
    void number_pressed();
    void on_pushButton_dot_clicked();
    void on_pushButton_erase_clicked();
    void on_pushButton_eLast_clicked();
    void on_pushButton_pi_clicked();
    void on_pushButton_e_clicked();
    void on_PushButton_swap_clicked();
    void on_operations();
    void on_pushButton_anwser_clicked();
    //void clearing();
    void on_pushButton_log_clicked();
    void on_pushButton_fact_clicked();
};

int factorial (int num);
#endif // MAINWINDOW_H
