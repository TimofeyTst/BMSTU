/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton_form_data;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(365, 164);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 white, stop: 1 #eaeaea);\n"
" border: 1px solid #cecece;\n"
" border-radius: 10px;\n"
"\n"
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
" }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 10, 281, 121));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        pushButton_form_data = new QPushButton(groupBox);
        pushButton_form_data->setObjectName("pushButton_form_data");
        pushButton_form_data->setGeometry(QRect(20, 80, 81, 21));
        pushButton_form_data->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 80, 91, 21));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 40, 101, 21));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	  border: 0px solid gray;\n"
"}"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 365, 28));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Welcome to METRO database", nullptr));
        pushButton_form_data->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Who are you:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
