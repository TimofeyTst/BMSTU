/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QTableWidget *tableWidget;
    QLabel *label_OUTPUT;
    QLineEdit *lineEdit_OUTPUT;
    QPushButton *pushButton_View;
    QPushButton *pushButton_SY;
    QPushButton *pushButton_SM;
    QPushButton *pushButton_GRAPHIC;
    QPushButton *pushButton_SD;
    QLineEdit *lineEdit_INPUT;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_BACK;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName("User");
        User->resize(646, 385);
        User->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 white, stop: 1 #eaeaea);\n"
" border: 1px solid #cecece;\n"
" border-radius: 10px;\n"
"font-size: 12px;\n"
"}\n"
"QGroupBox {\n"
" border: 1px solid #cecece;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #4193ff, stop: 1 #9eeaff);\n"
"}\n"
" QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 white, stop: 1 #eaeaea);\n"
"\n"
" border: 0.5px solid rgb(206, 206, 206);\n"
" }\n"
"QLabel {\n"
"	background-color: rgb(193, 193, 193);\n"
"}"));
        tableWidget = new QTableWidget(User);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 40, 611, 281));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        label_OUTPUT = new QLabel(User);
        label_OUTPUT->setObjectName("label_OUTPUT");
        label_OUTPUT->setGeometry(QRect(440, 330, 63, 24));
        label_OUTPUT->setAlignment(Qt::AlignCenter);
        lineEdit_OUTPUT = new QLineEdit(User);
        lineEdit_OUTPUT->setObjectName("lineEdit_OUTPUT");
        lineEdit_OUTPUT->setGeometry(QRect(510, 330, 113, 26));
        lineEdit_OUTPUT->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(193, 193, 193);\n"
"}"));
        lineEdit_OUTPUT->setAlignment(Qt::AlignCenter);
        pushButton_View = new QPushButton(User);
        pushButton_View->setObjectName("pushButton_View");
        pushButton_View->setGeometry(QRect(270, 330, 101, 29));
        pushButton_SY = new QPushButton(User);
        pushButton_SY->setObjectName("pushButton_SY");
        pushButton_SY->setGeometry(QRect(130, 10, 101, 24));
        pushButton_SM = new QPushButton(User);
        pushButton_SM->setObjectName("pushButton_SM");
        pushButton_SM->setGeometry(QRect(240, 10, 101, 24));
        pushButton_GRAPHIC = new QPushButton(User);
        pushButton_GRAPHIC->setObjectName("pushButton_GRAPHIC");
        pushButton_GRAPHIC->setGeometry(QRect(30, 330, 141, 29));
        pushButton_SD = new QPushButton(User);
        pushButton_SD->setObjectName("pushButton_SD");
        pushButton_SD->setGeometry(QRect(350, 10, 101, 24));
        lineEdit_INPUT = new QLineEdit(User);
        lineEdit_INPUT->setObjectName("lineEdit_INPUT");
        lineEdit_INPUT->setGeometry(QRect(460, 10, 121, 26));
        pushButton_OK = new QPushButton(User);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setGeometry(QRect(590, 10, 31, 24));
        pushButton_BACK = new QPushButton(User);
        pushButton_BACK->setObjectName("pushButton_BACK");
        pushButton_BACK->setGeometry(QRect(10, 10, 101, 24));
        pushButton_BACK->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" background-color: rgb(193, 193, 193);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #4193ff, stop: 1 #9eeaff);\n"
"}"));
        graphicsView = new QGraphicsView(User);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(25, 51, 601, 271));

        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QDialog *User)
    {
        User->setWindowTitle(QCoreApplication::translate("User", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("User", "Inventory number", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("User", "Model", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("User", "Year production", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("User", "Life time", nullptr));
        label_OUTPUT->setText(QCoreApplication::translate("User", "Output:", nullptr));
        pushButton_View->setText(QCoreApplication::translate("User", "View all data", nullptr));
        pushButton_SY->setText(QCoreApplication::translate("User", "Since year...", nullptr));
        pushButton_SM->setText(QCoreApplication::translate("User", "Count model", nullptr));
        pushButton_GRAPHIC->setText(QCoreApplication::translate("User", "Production Graphic", nullptr));
        pushButton_SD->setText(QCoreApplication::translate("User", "D/d trams", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("User", "ok", nullptr));
        pushButton_BACK->setText(QCoreApplication::translate("User", "Back to Main", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
