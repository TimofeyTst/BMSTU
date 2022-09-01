#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

//Дописал
#include <fstream>
#include "METRO_struct.h"
#include <stdio.h>
#include <QMessageBox>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    QString file_name;
    std::fstream File;
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
//
  signals:
    void show_first();
//
private slots:
    void on_pushButton_BACK_clicked();

    void on_pushButton_ATD_clicked();

    void on_pushButton_ate_clicked();

    void on_pushButton_aAf_clicked();

    void on_pushButton_aOPos_clicked();

    void on_pushButton_swap_clicked();

    void on_pushButton_DELA_clicked();

    void on_pushButton_dOPos_clicked();

    void on_pushButton_CLEAR_clicked();

    void on_pushButton_view_clicked();

private:
    Ui::Admin *ui;

};

#endif // ADMIN_H
