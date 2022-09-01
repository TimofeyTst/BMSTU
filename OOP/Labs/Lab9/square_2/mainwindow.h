#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>


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

    void on_dial_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_dial_2_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_3_valueChanged(int arg1);

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    //
    QGraphicsScene *scene;
    bool key;
    QPen *black_pen;
    QLine *line1;

};
#endif // MAINWINDOW_H
