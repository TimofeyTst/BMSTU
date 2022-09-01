#include <iostream>
#include "MyContainers.h"
#include <conio.h>
//#include <QCoreApplication>
//#include <QLocale>
//#include <QTranslator>
using namespace std;

void show(Base* var_class)
{
    if (dynamic_cast<S_Class*>(var_class))
        cout << *var_class->get_char() << endl;
    else cout << *var_class->get_double() << endl;
}


int main(int argc, char* argv[])
{
    /*
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "LAB_10_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    return a.exec();
    */
    child_ID_Massiv Massiv;

    std::cout << "Simple test, Press '1' for number | '2' for symbol | '#' for end: \t";
    cout << "Press\n'1' for symbol | '2' for float | '#' for end... ";
    char ch = 0;
    while ((ch = _getch()) != '#')
        switch (ch)
        {
        case '1': {
            char ch = '0';
            cout << "Input char symbol: ";
            cin >> ch;
            Massiv.Ate(ch);
            cout << "Success, add new or end?\t";
        } break;

        case '2': {
            double number = 0;
            cout << "Input float number: ";
            cin >> number;
            Massiv.Ate(number);
            cout << "Success, add new or end?\t";
        } break;
        default: cout << "\nWrong symbol\n'1' for symbol | '2' for float| '#' for end... ";
            break;
        }
    //Console
    cout << "\n===== Press any key for show all massiv[i] ======\t";
    _getch();
    cout << endl;
    for (int i = 0; i < Massiv.get_len(); i++)
    {
        if (Massiv[i].get_type() == DataType::Double)
            cout << i << " - double - " << Massiv[i] << endl;
        else cout << i << " - char - " << Massiv[i] << endl;
    }

    cout << "\n===== Press any key for show all massiv.forEach ======\t";
    _getch();
    cout << endl;
    Massiv.ForEach(show);

    int i;
    cout << "\n===== Input number for change this element of massiv: ";
    cin >> i;
    cout << endl;
    cout << "You want to change element " << Massiv[i];
    if (dynamic_cast<S_Class*>(&Massiv[i]))
    {
        char ch;
        cout << " It is a char element, so input new symbol: ";
        cin >> ch;
        Massiv[i] = ch;
    }
    else {
        double num;
        cout << " It is a float element, so input new number: ";
        cin >> num;
        Massiv[i] = num;
    }
    cout << "\nNow Massiv[i] consist element: " << Massiv[i] << endl;

    cout << "\n===== Press any key for show all massiv[i] ======\t";
    _getch();
    cout << endl;
    for (int i = 0; i < Massiv.get_len(); i++)
    {
        if(Massiv[i].get_type() == DataType::Double)
            cout << i << " - double - " << Massiv[i] << endl;
        else cout << i << " - char - " << Massiv[i] << endl;
    }

    cout << "\n===== Press any key for show min number ======\t";
    _getch();
    cout << endl;
    cout << "Min number: " << Massiv.min_number() << endl;

    cout << "\n===== Press any key for see adrress first & last element ======\t";
    _getch();
    cout << endl;
    cout << "First address: " << Massiv.get_first();
    cout << "\nNext element: " << Massiv.get_next();
    cout << "\nPrev element: " << Massiv.get_prev();
    cout << "\nLast element: " << Massiv.get_last() << endl;
    system("pause");
    return 0;
}
