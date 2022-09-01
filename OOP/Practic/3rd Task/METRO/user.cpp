#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    process = 0;
    ui->pushButton_OK->setEnabled(false);
    ui->lineEdit_INPUT->setEnabled(false);
    ui->lineEdit_OUTPUT->setReadOnly(true);

    ui->graphicsView->setHidden(true);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    My_pen = new QPen(Qt::blue);
    My_pen->setWidth(1);
}

User::~User()
{
    delete ui;
}

void User::on_pushButton_BACK_clicked()
{
    this->close();
    emit show_first();
}


void User::on_pushButton_View_clicked()
{
    ui->tableWidget->setHidden(false);
    ui->graphicsView->setHidden(true);
    File.open(file_name.toStdString());
    ui->tableWidget->clear();
    METRO_struct var;
    std::string buf;
    unsigned int size = 0;

    while (!File.eof())
    {
        ++size;
        File >> var.id >> var.model >> var.year >> var.life >> buf;
    }
    --size;

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(size);

    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,100);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Model" << "Inventory number"  << "Year production" << "Life time");


    File.clear();
    File.seekg(0);

    for (unsigned int i = 0; i < size; ++i)
    {
            File >> var.id >> var.model >> var.year >> var.life >> buf;
            add_to_table(i,var);
    }
    File.close();
}


void User::on_pushButton_SY_clicked()
{
    process = 1;

    process_choosen(true);
}


void User::on_pushButton_SM_clicked()
{
    process = 2;

    process_choosen(true);
}


void User::on_pushButton_SD_clicked()
{
    process = 3;

    process_choosen(true);
}

void User::process_choosen(bool key)
{
    ui->pushButton_SY->setEnabled(!key);
    ui->pushButton_SM->setEnabled(!key);
    ui->pushButton_SD->setEnabled(!key);

    ui->lineEdit_INPUT->setEnabled(key);
    ui->pushButton_OK->setEnabled(key);
}

void User::add_to_table (unsigned int row,METRO_struct var)
{
    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,100);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Model" << "Inventory number"  << "Year production" << "Life time");

    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::fromStdString(var.model)));
    ui->tableWidget->item(row,0)->setFlags(Qt::ItemIsEnabled);

    ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString::fromStdString(var.id)));
    ui->tableWidget->item(row,1)->setFlags(Qt::ItemIsEnabled);

    ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(var.year)));
    ui->tableWidget->item(row,2)->setFlags(Qt::ItemIsEnabled);

    ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(var.life)));
    ui->tableWidget->item(row,3)->setFlags(Qt::ItemIsEnabled);
}

void User::on_pushButton_OK_clicked()
{

    File.open(file_name.toStdString());
    ui->tableWidget->clear();
    METRO_struct var;
    std::string buf;
    unsigned int i = 0;

    switch(process)
    {
    case 1:
        {
        unsigned int search = ui->lineEdit_INPUT->text().toUInt();
        File >> var.id >> var.model >> var.year >> var.life >> buf;
        while (!File.eof())
        {
            if(var.year >= search)
            {
                add_to_table(i++,var);
            }
            File >> var.id >> var.model >> var.year >> var.life >> buf;
        }
        ui->lineEdit_OUTPUT->setText("Since year: " + QString::number(i));
        } break;
    case 2:
        {
        std::string search = ui->lineEdit_INPUT->text().toStdString();
        File >> var.id >> var.model >> var.year >> var.life >> buf;
        while (!File.eof())
        {
            if(var.model == search)
            {
                add_to_table(i++,var);
            }
            File >> var.id >> var.model >> var.year >> var.life >> buf;
        }
        ui->lineEdit_OUTPUT->setText("Models: " + QString::number(i));
        } break;
    case 3:
        {
        unsigned int search = ui->lineEdit_INPUT->text().toUInt(); unsigned int k = 0;
        File >> var.id >> var.model >> var.year >> var.life >> buf;
                while (!File.eof())
                {
                    if(var.year + var.life <= search)
                    {
                        add_to_table(i++,var);
                        if (var.year + var.life != search) ++k;
                    }
                    File >> var.id >> var.model >> var.year >> var.life >> buf;
                }
        ui->lineEdit_OUTPUT->setText("Disabled: " + QString::number(k));
        } break;
    }
    process_choosen(false);
    File.close();
}


void User::on_pushButton_GRAPHIC_clicked()
{
    ui->graphicsView->scene()->clear();
    ui->graphicsView->setHidden(false);
    ui->tableWidget->setHidden(true);
    QPoint left_down = {-280,100}, right_top = {280,-100};
    QPolygon polygon;
    int Year_begin = 1995, fitt = 5;
    int dx = 40, dy = 40,
            count_x = (right_top.x() - left_down.x())/dx,
            count_y = (left_down.y() - right_top.y())/dy;

    My_pen->setColor(Qt::black);
    My_pen->setWidth(1);
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
        scene->addPolygon(polygon, *My_pen);
    //Вставка цифр
        QFont font ("Times new Roman"); //font.setStyleHint(QFont::StyleHint);
        QPainterPath path;
        for (int i = 1; i <= count_x ; ++i)
        {
        path.addText(left_down.x() - 16 + dx * i, left_down.y() + 14,font, QString::number(Year_begin + i * fitt));
        scene->addPath(path);
        }
        for (int i = 0; i <= count_y; ++i)
        {
            path.addText(left_down.x() - 12, left_down.y() + 5 - i * dy,font, QString::number(i));
            scene->addPath(path);
        }
     //Подсчет
        My_pen->setColor(Qt::blue);
        My_pen->setWidth(5);

        METRO_struct var;
        std::string buf;
        int mas[count_x]; for (int i = 0; i < count_x; ++i) mas[i] = 0;
        File.open(file_name.toStdString());
        File >> var.id >> var.model >> var.year >> var.life >> buf;

        while (!File.eof())
        {
            if ((int)var.year <  Year_begin)
                mas[0] += 1;
            if ((int)var.year > Year_begin + count_x*fitt)
                mas[count_x] += 1;
            for (int i = 0; i <= count_x ; ++i)
            {
                if (((int)var.year > (Year_begin + i * fitt)) && (int)var.year <= (Year_begin + (i+1)*fitt))
                    mas[i+1] += 1;
            }
            File >> var.id >> var.model >> var.year >> var.life >> buf;
        }
        scene->addLine(left_down.x(), left_down.y() - mas[0] * dy, left_down.x() + dx, left_down.y() - mas[1] * dy, *My_pen);
        for (int i = 1; i < count_x; ++i)
        {
            scene->addLine(left_down.x() + i * dx, left_down.y() - mas[i] * dy, left_down.x() + (i+1) * dx, left_down.y() - mas[i+1] * dy, *My_pen );
        }
        scene->addLine(right_top.x() - dx, left_down.y() - mas[count_x-1] * dy, right_top.x(), left_down.y() - mas[count_x] * dy, *My_pen);
        File.close();
}

