#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsItem>
#include <QMainWindow>
#include "classes.h"
#include <time.h> //не нужно
#include <QTimer>

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

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QBrush *my_brush;
    QPen *my_pen;

    Circle *my_circle;
    Ygolnik *my_ygolnik;
    Astroida *my_astroida;

    QTimer *timer;
    qreal T1, T2, T3;
    bool change1, change2, change3, first, is_pause;
private slots:
    void every_tick();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
