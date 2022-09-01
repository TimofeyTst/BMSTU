#include "admin.h"
#include "ui_admin.h"


Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    file_name = "";

    //Блокируем до выбора
    ui->pushButton_swap->setEnabled(false);

    ui->pushButton_ate->setEnabled(false);

    ui->pushButton_aAf->setEnabled(false);
    ui->pushButton_aOPos->setEnabled(false);
    ui->lineEdit_aPos->setEnabled(false);
    ui->label_aPos->setEnabled(false);

    ui->label_IN->setEnabled(false);
    ui->label_MD->setEnabled(false);
    ui->label_YP->setEnabled(false);
    ui->label_LTY->setEnabled(false);
    ui->lineEdit_IN->setEnabled(false);
    ui->lineEdit_MD->setEnabled(false);
    ui->lineEdit_YP->setEnabled(false);
    ui->lineEdit_LTY->setEnabled(false);

    ui->lineEdit_dPos->setEnabled(false);
    ui->lineEdit_dCPos->setEnabled(false);
    ui->pushButton_dOPos->setEnabled(false);
    ui->label_dPos->setEnabled(false);
    ui->label_dCnt->setEnabled(false);

    ui->lineEdit_aPos->setText("0");
    ui->lineEdit_dPos->setText("0");
    ui->lineEdit_dCPos->setText("0");
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_swap_clicked()
{
    ui->pushButton_swap->setEnabled(false);

    ui->pushButton_ate->setEnabled(false);

    ui->pushButton_aAf->setEnabled(false);
    ui->pushButton_aOPos->setEnabled(false);
    ui->lineEdit_aPos->setEnabled(false);
    ui->label_aPos->setEnabled(false);

    ui->label_IN->setEnabled(false);
    ui->label_MD->setEnabled(false);
    ui->label_YP->setEnabled(false);
    ui->label_LTY->setEnabled(false);
    ui->lineEdit_IN->setEnabled(false);
    ui->lineEdit_MD->setEnabled(false);
    ui->lineEdit_YP->setEnabled(false);
    ui->lineEdit_LTY->setEnabled(false);

    ui->lineEdit_dPos->setEnabled(false);
    ui->lineEdit_dCPos->setEnabled(false);
    ui->pushButton_dOPos->setEnabled(false);
    ui->label_dPos->setEnabled(false);
    ui->label_dCnt->setEnabled(false);

    ui->pushButton_ATD->setEnabled(true);
    ui->pushButton_DELA->setEnabled(true);
}

void Admin::on_pushButton_BACK_clicked()
{
    this->close();
    emit show_first();
}


void Admin::on_pushButton_ATD_clicked()
{
    ui->pushButton_ATD->setEnabled(false);
    ui->pushButton_DELA->setEnabled(false);
    ui->pushButton_swap->setEnabled(true);

    ui->label_IN->setEnabled(true);
    ui->label_MD->setEnabled(true);
    ui->label_YP->setEnabled(true);
    ui->label_LTY->setEnabled(true);
    ui->lineEdit_IN->setEnabled(true);
    ui->lineEdit_MD->setEnabled(true);
    ui->lineEdit_YP->setEnabled(true);
    ui->lineEdit_LTY->setEnabled(true);

    ui->pushButton_ate->setEnabled(true);
    ui->pushButton_aAf->setEnabled(true);
}


void Admin::on_pushButton_ate_clicked()
{
    using namespace std;
    File.open(file_name.toStdString(), std::ios::app);
    METRO_struct var;
    if (ui->lineEdit_IN->text()=="") var.id ="None";
    else var.id = ui->lineEdit_IN->text().toStdString();
    if (ui->lineEdit_MD->text() == "") var.model ="None";
    else var.model = ui->lineEdit_MD->text().toStdString();
    var.year = ui->lineEdit_YP->text().toUInt();
    var.life = ui->lineEdit_LTY->text().toUInt();
    //File.write((char*)&var, sizeof(METRO_struct));
    File << var;
    File.close();
    /*ui->lineEdit_IN->setText("");
    ui->lineEdit_MD->setText("");
    ui->lineEdit_YP->setText("");
    ui->lineEdit_LTY->setText("");*/
}


void Admin::on_pushButton_aAf_clicked()
{
    ui->pushButton_ate->setEnabled(false);

    ui->pushButton_aAf->setEnabled(false);
    ui->pushButton_aOPos->setEnabled(true);
    ui->lineEdit_aPos->setEnabled(true);
    ui->label_aPos->setEnabled(true);
}


void Admin::on_pushButton_aOPos_clicked()
{
    METRO_struct var;
    if (ui->lineEdit_IN->text()=="") var.id ="None";
    else var.id = ui->lineEdit_IN->text().toStdString();
    if (ui->lineEdit_MD->text() == "") var.model ="None";
    else var.model = ui->lineEdit_MD->text().toStdString();
    var.year = ui->lineEdit_YP->text().toUInt();
    var.life = ui->lineEdit_LTY->text().toUInt();
   /* ui->lineEdit_IN->setText("");
    ui->lineEdit_MD->setText("");
    ui->lineEdit_YP->setText("");
    ui->lineEdit_LTY->setText(""); */

    File.open(file_name.toStdString(), std::ios::app);
    if (File.is_open())
    {
        File.close();
        rename("MetroDataBase.txt","MetroDataBaseDELETE.txt");

        METRO_struct var2;
        std::string buf;
        unsigned int num = ui->lineEdit_aPos->text().toUInt(), i = 0;
        std::ofstream NFile;

        NFile.open(file_name.toStdString());
        File.open("MetroDataBaseDELETE.txt", std::ios::in);

        while (!File.eof())
        {
            if (i == num)
                NFile << var.id << '\n' << var.model << '\n' << var.year << '\n' << var.life << '\n' << "========\n";
            else
            {
                File >> var2.id >> var2.model >> var2.year >> var2.life >> buf;
                if (!File.eof())
                NFile << var2.id << '\n' << var2.model << '\n' << var2.year << '\n' << var2.life << '\n' << "========\n";
            }
            i++;
        }
        if (i<=num)
        {
            QMessageBox ms;
            ms.addButton("OK",QMessageBox::YesRole);
            ms.setWindowTitle("Важно");
            ms.setText("Позиция добавления превышает размер записей\n💡Выполнено добавление в конец");
            ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                             "border: 1px solid grey; border-radius: 5px; font-size: 12px; font-color:white; text-align: center;"
                             " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                             "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 20px; width: 30px;"
                             " font-size: 12px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                             "0 #4193ff, stop: 1 #9eeaff);}");
            ms.exec();
            NFile << var.id << '\n' << var.model << '\n' << var.year << '\n' << var.life << '\n' << "========\n";
        }
        File.close();
        NFile.close();
        remove("MetroDataBaseDELETE.txt");
    }
    else
    {
        File << var.id << '\n' << var.model << '\n' << var.year << '\n' << var.life << '\n' << "========\n";
        File.close();
    }

    ui->pushButton_ate->setEnabled(true);

    ui->pushButton_aAf->setEnabled(true);
    ui->pushButton_aOPos->setEnabled(false);
    ui->lineEdit_aPos->setEnabled(false);
    ui->label_aPos->setEnabled(false);
}


void Admin::on_pushButton_DELA_clicked()
{
    ui->pushButton_ATD->setEnabled(false);
    ui->pushButton_DELA->setEnabled(false);
    ui->pushButton_swap->setEnabled(true);

    ui->label_dPos->setEnabled(true);
    ui->label_dCnt->setEnabled(true);

    ui->lineEdit_dPos->setEnabled(true);
    ui->lineEdit_dCPos->setEnabled(true);

    ui->pushButton_dOPos->setEnabled(true);
}


void Admin::on_pushButton_dOPos_clicked()
{
    File.open(file_name.toStdString());
    if(File.is_open())
    {
        File.close();
        rename ("MetroDataBase.txt","MetroDataBaseDELETE.txt");

        unsigned int pos = ui->lineEdit_dPos->text().toUInt(), count = ui->lineEdit_dCPos->text().toUInt(), i = 0;
        std::string buf;
        METRO_struct var;
        std::ofstream NFile;
        bool is_delete = true;

        NFile.open(file_name.toStdString()); //Открыли новый для записи
        File.open("MetroDataBaseDELETE.txt", std::ios::in); //Открыли старый для чтения

        while (!File.eof())
        {
            if (i == pos)
            {
                for (unsigned int k = 0; k < count; ++k)
                if (!File.eof())
                {
                    File >> var.id >> var.model >> var.year >> var.life >> buf;
                } else
                {
                    QMessageBox ms;
                            ms.addButton("OK",QMessageBox::YesRole);
                            ms.setText("Количество удаляемых элементов больше размера записей\nУдалено все, что больше позиции");
                            ms.setWindowTitle("Ошибка");
                            ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                                             "border: 1px solid grey; border-radius: 5px; font-size: 12px; font-color:white; text-align: center;"
                                             " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                             "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 20px; width: 30px;"
                                             " font-size: 12px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                                             "0 #4193ff, stop: 1 #9eeaff);}");
                            ms.exec(); k = count; is_delete = false;
                }
            }
            else
            {
                File >> var.id >> var.model >> var.year >> var.life >> buf;
                if (!File.eof())
                NFile << var.id << '\n' << var.model << '\n' << var.year << '\n' << var.life << '\n' << "========\n";
            }
            i++;
        }
        File.close();
        NFile.close();
        remove ("MetroDataBaseDELETE.txt");

        if(i<=pos)
        {
            QMessageBox ms;
            ms.addButton("OK",QMessageBox::YesRole);
            ms.setText("Указанная позиция больше размера файла\nФайл остался без изменений");
            ms.setWindowTitle("Информация");
            ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                                     "border: 1px solid grey; border-radius: 5px; font-size: 12px; font-color:white; text-align: center;"
                                     " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                     "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 20px; width: 30px;"
                                     " font-size: 12px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                                     "0 #4193ff, stop: 1 #9eeaff);}");
            ms.exec();
        }
        else if (is_delete)
        {
            QMessageBox ms;
            ms.addButton("OK",QMessageBox::YesRole);
            ms.setText("Удаление произошло успешно!");
            ms.setWindowTitle("Информация");
            ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                                     "border: 1px solid grey; border-radius: 5px; font-size: 12px; font-color:white; text-align: center;"
                                     " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                     "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 20px; width: 30px;"
                                     " font-size: 12px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                                     "0 #4193ff, stop: 1 #9eeaff);}");
            ms.exec();
        }
    }
    else
    {
        QMessageBox ms;
        ms.addButton("ok",QMessageBox::YesRole);
        ms.setText("Файл пустой!");
        ms.setWindowTitle("Ошибка");
        ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                         "border: 1px solid grey; border-radius: 5px; font-size: 12px; font-color:white; text-align: center;"
                         " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                         "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 20px; width: 30px;"
                         " font-size: 12px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                         "0 #4193ff, stop: 1 #9eeaff);}");
        ms.exec();
    }
}


void Admin::on_pushButton_CLEAR_clicked()
{
    QMessageBox ms;
    File.open(file_name.toStdString());
    ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                         "border: 1px solid grey; border-radius: 5px; font-size: 20px; text-align: center;"
                         " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                         "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 30px; width: 70px;"
                         " font-size: 25px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                         "0 #4193ff, stop: 1 #9eeaff);}");
    if (File.is_open()) {
    QAbstractButton *YES = ms.addButton("✅",QMessageBox::YesRole);
    ms.addButton("❌",QMessageBox::NoRole);
    ms.setText("Удалить ВСЕ данные?");
    ms.exec();
    if(ms.clickedButton() == YES)
    {
        File.close();
        remove("MetroDataBase.txt");
    }
    } else {
        ms.setStyleSheet("QMessageBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 #eaeaea); "
                             "border: 1px solid grey; border-radius: 5px; font-size: 12px; text-align: center;"
                             " } QPushButton { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                             "stop: 0 white, stop: 1 #eaeaea); border: 0.5px solid rgb(206, 206, 206); border-radius: 5px; height: 10px; width: 15px;"
                             " font-size: 9px;} QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "
                             "0 #4193ff, stop: 1 #9eeaff);}");
        ms.addButton("✅",QMessageBox::AcceptRole);
        ms.setText("Ошибка удаления: Файл пуст");
        ms.exec();
    }
}


void Admin::on_pushButton_view_clicked()
{
    ui->tableWidget->clear();
    File.open(file_name.toStdString());
    if(File.is_open())
    {
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

        ui->tableWidget->setColumnWidth(0,120);
        ui->tableWidget->setColumnWidth(1,110);
        ui->tableWidget->setColumnWidth(2,100);
        ui->tableWidget->setColumnWidth(3,80);

        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Model" << "Inventory number"  << "Year production" << "Life time");


        File.clear();
        File.seekg(0);

        for (unsigned int i = 0; i < size; ++i)
        {
                File >> var.id >> var.model >> var.year >> var.life >> buf;

                ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(var.model)));
                ui->tableWidget->item(i,0)->setFlags(Qt::ItemIsEnabled);

                ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(var.id)));
                ui->tableWidget->item(i,1)->setFlags(Qt::ItemIsEnabled);

                ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(var.year)));
                ui->tableWidget->item(i,2)->setFlags(Qt::ItemIsEnabled);

                ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(var.life)));
                ui->tableWidget->item(i,3)->setFlags(Qt::ItemIsEnabled);
        }
    }
    File.close();
}
