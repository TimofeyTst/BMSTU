/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Password
{
public:
    QGroupBox *groupBox;
    QLineEdit *Edit_pswd;
    QPushButton *pushButton;

    void setupUi(QDialog *Password)
    {
        if (Password->objectName().isEmpty())
            Password->setObjectName("Password");
        Password->resize(229, 113);
        Password->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
"QMessageBox QPushButton{\n"
" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 white, stop: 1 #eaeaea);\n"
" border-radius: 5px;\n"
" border: 0.5px solid rgb(206, 206, 206);\n"
"}\n"
"\n"
"QMessageBox QLabel {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 white, stop: 1 #eaeaea);\n"
" border: 0px solid #cecece;\n"
" border-radius: 0px;\n"
"font-size: 12px;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #4193ff, stop: 1 #9eeaff);\n"
"}\n"
" QPushButton {\n"
"backg"
                        "round-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 white, stop: 1 #eaeaea);\n"
"\n"
" border: 0.5px solid rgb(206, 206, 206);\n"
" }"));
        groupBox = new QGroupBox(Password);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 10, 181, 91));
        Edit_pswd = new QLineEdit(groupBox);
        Edit_pswd->setObjectName("Edit_pswd");
        Edit_pswd->setGeometry(QRect(20, 40, 113, 24));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 40, 31, 24));

        retranslateUi(Password);

        QMetaObject::connectSlotsByName(Password);
    } // setupUi

    void retranslateUi(QDialog *Password)
    {
        Password->setWindowTitle(QCoreApplication::translate("Password", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Password", "Input password", nullptr));
        pushButton->setText(QCoreApplication::translate("Password", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Password: public Ui_Password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
