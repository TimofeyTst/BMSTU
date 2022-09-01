#ifndef USER_H
#define USER_H

#include <QDialog>

#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <vector>

//дописал
#include <fstream>
#include "METRO_struct.h"

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    QString file_name;
    std::ifstream File;
    explicit User(QWidget *parent = nullptr);
    ~User();
//
    void process_choosen(bool key);
    void add_to_table (unsigned int row, METRO_struct var);
  signals:
    void show_first();
//
private slots:
    void on_pushButton_BACK_clicked();

    void on_pushButton_View_clicked();

    void on_pushButton_SY_clicked();

    void on_pushButton_SM_clicked();

    void on_pushButton_SD_clicked();

    void on_pushButton_OK_clicked();

    void on_pushButton_GRAPHIC_clicked();

private:
    unsigned int process;
    Ui::User *ui;
    QGraphicsScene *scene;
    QPen *My_pen;
};

#endif // USER_H
