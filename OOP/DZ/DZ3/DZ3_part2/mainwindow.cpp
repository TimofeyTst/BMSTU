#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    my_pen = new QPen(Qt::blue);
    my_pen->setWidth(5);
    my_brush = new QBrush(Qt::red);

    my_circle = new Circle(0, 0, 0, scene, *my_brush, *my_pen);
    my_ygolnik = new Ygolnik(0, 0, 0, scene, *my_brush, *my_pen);
    my_astroida = new Astroida (0, 0, 0, scene, *my_brush, *my_pen);

    srand(time(NULL)); // Не нужно

    first = true;
    T1 = T2 = T3 = 0;
    change1 = change2 = change3 = is_pause = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(every_tick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (first)
    {
        timer->start(10); //Каждую 1 мс вызываем timeout
        ui->pushButton->setText("Pause");
        first = false;
    } else {
        if (is_pause)
        {
            ui->pushButton->setText("Pause");
            is_pause = false;
            timer->start(10); //Каждую 1 мс вызываем timeout
        } else
        {
            ui->pushButton->setText("Continue");
            is_pause = true;
            timer->stop();
        }
    }
}

void MainWindow::every_tick()
{
    scene->clear();
    if (change1)
    {
        T1 -= 1;
        if (T1 < -120) change1 = false;
    } else {
        T1 += 1;
        if (T1 > 120 ) change1 = true;
    }
    if (change2)
    {
        T2 -= 2;
        if (T2 < -120) change2 = false;
    } else {
        T2 += 2;
        if (T2 > 120 ) change2 = true;
    }
    if (change3)
    {
        T3 -= 3;
        if (T3 < -120) change3 = false;
    } else {
        T3 += 3;
        if (T3 > 120 ) change3 = true;
    }
    my_pen->setColor(Qt::white);
    my_pen->setWidth(0);

    my_brush->setColor(Qt::yellow);

    my_circle->reset(-150, T1 - 70, 70);
    my_circle->draw(*my_pen, *my_brush);

    my_brush->setColor(QColor (212, 175, 55));

    my_ygolnik->reset(185, T2, 70);
    my_ygolnik->draw(*my_pen, *my_brush);

    my_brush->setColor(QColor(212, 50, 205));

    my_astroida->reset (450, T3, 70);
    my_astroida->draw (*my_pen, *my_brush);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scene()->clear();
    timer->stop();
    first = true;
    T1 = T2 = T3 = 0;
    change1 = change2 = change3 = is_pause = false;
    ui->pushButton->setText("Begin");
}

