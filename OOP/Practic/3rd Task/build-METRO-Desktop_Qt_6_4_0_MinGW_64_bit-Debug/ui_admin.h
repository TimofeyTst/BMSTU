/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton_swap;
    QPushButton *pushButton_DELA;
    QLabel *label_dCnt;
    QLabel *label_aPos;
    QLabel *label_dPos;
    QPushButton *pushButton_aAf;
    QPushButton *pushButton_ate;
    QPushButton *pushButton_aOPos;
    QPushButton *pushButton_dOPos;
    QLineEdit *lineEdit_dPos;
    QPushButton *pushButton_ATD;
    QLineEdit *lineEdit_aPos;
    QLineEdit *lineEdit_dCPos;
    QPushButton *pushButton_BACK;
    QPushButton *pushButton_view;
    QLineEdit *lineEdit_IN;
    QLineEdit *lineEdit_YP;
    QLineEdit *lineEdit_MD;
    QLineEdit *lineEdit_LTY;
    QLabel *label_IN;
    QLabel *label_MD;
    QLabel *label_YP;
    QLabel *label_LTY;
    QPushButton *pushButton_CLEAR;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(584, 550);
        Admin->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        tableWidget = new QTableWidget(Admin);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(50, 300, 481, 192));
        pushButton_swap = new QPushButton(Admin);
        pushButton_swap->setObjectName("pushButton_swap");
        pushButton_swap->setGeometry(QRect(260, 10, 93, 29));
        pushButton_DELA = new QPushButton(Admin);
        pushButton_DELA->setObjectName("pushButton_DELA");
        pushButton_DELA->setGeometry(QRect(420, 40, 93, 29));
        label_dCnt = new QLabel(Admin);
        label_dCnt->setObjectName("label_dCnt");
        label_dCnt->setGeometry(QRect(390, 120, 45, 22));
        label_dCnt->setAlignment(Qt::AlignCenter);
        label_aPos = new QLabel(Admin);
        label_aPos->setObjectName("label_aPos");
        label_aPos->setGeometry(QRect(40, 260, 71, 27));
        label_aPos->setAlignment(Qt::AlignCenter);
        label_dPos = new QLabel(Admin);
        label_dPos->setObjectName("label_dPos");
        label_dPos->setGeometry(QRect(380, 80, 58, 22));
        label_dPos->setAlignment(Qt::AlignCenter);
        pushButton_aAf = new QPushButton(Admin);
        pushButton_aAf->setObjectName("pushButton_aAf");
        pushButton_aAf->setGeometry(QRect(90, 220, 93, 29));
        pushButton_ate = new QPushButton(Admin);
        pushButton_ate->setObjectName("pushButton_ate");
        pushButton_ate->setGeometry(QRect(230, 220, 93, 29));
        pushButton_aOPos = new QPushButton(Admin);
        pushButton_aOPos->setObjectName("pushButton_aOPos");
        pushButton_aOPos->setGeometry(QRect(180, 260, 31, 29));
        pushButton_dOPos = new QPushButton(Admin);
        pushButton_dOPos->setObjectName("pushButton_dOPos");
        pushButton_dOPos->setGeometry(QRect(510, 100, 31, 29));
        lineEdit_dPos = new QLineEdit(Admin);
        lineEdit_dPos->setObjectName("lineEdit_dPos");
        lineEdit_dPos->setGeometry(QRect(452, 80, 41, 27));
        lineEdit_dPos->setAlignment(Qt::AlignCenter);
        pushButton_ATD = new QPushButton(Admin);
        pushButton_ATD->setObjectName("pushButton_ATD");
        pushButton_ATD->setGeometry(QRect(110, 40, 93, 29));
        lineEdit_aPos = new QLineEdit(Admin);
        lineEdit_aPos->setObjectName("lineEdit_aPos");
        lineEdit_aPos->setGeometry(QRect(120, 260, 51, 27));
        lineEdit_aPos->setAlignment(Qt::AlignCenter);
        lineEdit_dCPos = new QLineEdit(Admin);
        lineEdit_dCPos->setObjectName("lineEdit_dCPos");
        lineEdit_dCPos->setGeometry(QRect(452, 118, 41, 27));
        lineEdit_dCPos->setAlignment(Qt::AlignCenter);
        pushButton_BACK = new QPushButton(Admin);
        pushButton_BACK->setObjectName("pushButton_BACK");
        pushButton_BACK->setGeometry(QRect(10, 10, 101, 24));
        pushButton_BACK->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" background-color: rgb(193, 193, 193);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #4193ff, stop: 1 #9eeaff);\n"
"}"));
        pushButton_view = new QPushButton(Admin);
        pushButton_view->setObjectName("pushButton_view");
        pushButton_view->setGeometry(QRect(230, 510, 101, 29));
        lineEdit_IN = new QLineEdit(Admin);
        lineEdit_IN->setObjectName("lineEdit_IN");
        lineEdit_IN->setGeometry(QRect(211, 83, 125, 24));
        lineEdit_IN->setAlignment(Qt::AlignCenter);
        lineEdit_YP = new QLineEdit(Admin);
        lineEdit_YP->setObjectName("lineEdit_YP");
        lineEdit_YP->setGeometry(QRect(211, 149, 125, 24));
        lineEdit_YP->setAlignment(Qt::AlignCenter);
        lineEdit_MD = new QLineEdit(Admin);
        lineEdit_MD->setObjectName("lineEdit_MD");
        lineEdit_MD->setGeometry(QRect(211, 116, 125, 24));
        lineEdit_MD->setAlignment(Qt::AlignCenter);
        lineEdit_LTY = new QLineEdit(Admin);
        lineEdit_LTY->setObjectName("lineEdit_LTY");
        lineEdit_LTY->setGeometry(QRect(211, 182, 125, 24));
        lineEdit_LTY->setAlignment(Qt::AlignCenter);
        label_IN = new QLabel(Admin);
        label_IN->setObjectName("label_IN");
        label_IN->setGeometry(QRect(51, 82, 131, 22));
        label_IN->setAlignment(Qt::AlignCenter);
        label_MD = new QLabel(Admin);
        label_MD->setObjectName("label_MD");
        label_MD->setGeometry(QRect(51, 116, 131, 22));
        label_MD->setAlignment(Qt::AlignCenter);
        label_YP = new QLabel(Admin);
        label_YP->setObjectName("label_YP");
        label_YP->setGeometry(QRect(51, 150, 131, 22));
        label_YP->setAlignment(Qt::AlignCenter);
        label_LTY = new QLabel(Admin);
        label_LTY->setObjectName("label_LTY");
        label_LTY->setGeometry(QRect(51, 184, 131, 22));
        label_LTY->setAlignment(Qt::AlignCenter);
        pushButton_CLEAR = new QPushButton(Admin);
        pushButton_CLEAR->setObjectName("pushButton_CLEAR");
        pushButton_CLEAR->setGeometry(QRect(420, 510, 101, 29));
        QFont font;
        font.setBold(true);
        pushButton_CLEAR->setFont(font);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Dialog", nullptr));
        pushButton_swap->setText(QCoreApplication::translate("Admin", "Change", nullptr));
        pushButton_DELA->setText(QCoreApplication::translate("Admin", "Delete after", nullptr));
        label_dCnt->setText(QCoreApplication::translate("Admin", "Count:", nullptr));
        label_aPos->setText(QCoreApplication::translate("Admin", "Position:", nullptr));
        label_dPos->setText(QCoreApplication::translate("Admin", "Position:", nullptr));
        pushButton_aAf->setText(QCoreApplication::translate("Admin", "Add after", nullptr));
        pushButton_ate->setText(QCoreApplication::translate("Admin", "Add to end", nullptr));
        pushButton_aOPos->setText(QCoreApplication::translate("Admin", "ok", nullptr));
        pushButton_dOPos->setText(QCoreApplication::translate("Admin", "ok", nullptr));
        pushButton_ATD->setText(QCoreApplication::translate("Admin", "Add to data", nullptr));
        pushButton_BACK->setText(QCoreApplication::translate("Admin", "Back to Main", nullptr));
        pushButton_view->setText(QCoreApplication::translate("Admin", "View all data", nullptr));
        label_IN->setText(QCoreApplication::translate("Admin", "Inventory number:", nullptr));
        label_MD->setText(QCoreApplication::translate("Admin", "Model:", nullptr));
        label_YP->setText(QCoreApplication::translate("Admin", "Year production:", nullptr));
        label_LTY->setText(QCoreApplication::translate("Admin", "Life time in years:", nullptr));
        pushButton_CLEAR->setText(QCoreApplication::translate("Admin", "CLEAR DATA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
