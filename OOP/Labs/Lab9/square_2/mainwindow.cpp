#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    key = false;
    //
    ui->graphicsView->setHidden(true);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    black_pen = new QPen(Qt::yellow);
    black_pen->setWidth(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
}


void MainWindow::on_dial_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    ui->textEdit->append(QString::number(value));
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->dial->setValue(arg1);
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_dial_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    ui->textEdit_2->append(QString::number(value));
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->dial_2->setValue(arg1);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsView->setHidden(key);
    key = !key;
}


void MainWindow::on_pushButton_4_clicked()
{
    scene->clear();
    line1 = new QLine(0,0,100,100);
    scene->addLine(*line1, *black_pen);
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    black_pen->setWidth(arg1);
}


void MainWindow::on_pushButton_5_clicked()
{
    QPoint left_down = {-300,200}, right_top = {300,-200};
    QPolygon polygon;
    int Year_begin = 1995, fitt = 5;
    int dx = 40, dy = 40, count_x = (right_top.x() - left_down.x())/dx, count_y = (left_down.y() - right_top.y())/dy;
    //Рисуем горизонтальные
    for (int i = 0; i < count_y; ++i)
    {
    polygon << QPoint (left_down.x(), left_down.y() - i * dy) << QPoint (right_top.x(), left_down.y() - i * dy);
    ++i;
    polygon << QPoint (right_top.x(), left_down.y() - i * dy) << QPoint (left_down.x(), left_down.y() - i * dy);
    }
    //Рисуем вертикальные
    for ( int i = 0; i < count_x; ++i)
    {
        polygon << QPoint (left_down.x() + i * dx, left_down.y()) << QPoint (left_down.x() + i * dx, right_top.y());
        ++i;
        polygon << QPoint (left_down.x() + i * dx, right_top.y()) << QPoint (left_down.x() + i * dx, left_down.y());
    }
    //Для формы
        polygon << left_down << QPoint (left_down.x(), right_top.y()) << right_top << QPoint(right_top.x(), left_down.y());
        black_pen->setColor(Qt::red);
        scene->addPolygon(polygon);
    //Вставка цифр
        QFont font;
        QPainterPath path;
        for (int i = 1; i <= count_x ; ++i)
        {
        path.addText(left_down.x() - 10 + dx * i, left_down.y() + 12,font, QString::number(Year_begin + i * fitt));
        scene->addPath(path);
        }
        for (int i = 0; i <= count_y; ++i)
        {
            path.addText(left_down.x() - 12, left_down.y() - i * dy,font, QString::number(i));
            scene->addPath(path);
        }
}

