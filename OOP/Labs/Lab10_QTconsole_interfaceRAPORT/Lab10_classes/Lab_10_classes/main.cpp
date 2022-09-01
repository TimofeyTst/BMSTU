#include <iostream>
#include <conio.h>
//#define Classes_template_on
#define Classes_pointer_on
//*****************************
//****** preprocessing *******
//*****************************

//FOR DONT WORKING CLASSES
using namespace std;
#ifdef Classes_template_on

#include "Classes_template.h"
ostream& operator<< (ostream& os, Base<int,I_Class>& var_class) 
{
    os << var_class.print();
    return os;
}
ostream& operator<< (ostream& os, Base<double, D_Class>& var_class)
{
    os << var_class.print();
    return os;
}
template <typename TID2, typename TCLASS2>
void *show_all(Base<TID2, TCLASS2>* var_class) 
{
	cout << var_class->print() << "\n";
};
template <typename TID, typename TCLASS>

int main()
{
	I_Class i1(10),i2(8),i3(9);
	D_Class d1(5.33),d2(7.67),d3(2.1);
	cout << i1 << endl;
	cout << i2.print() << " " << i2 << endl;
	cout << i3.print() << " " << i3 << endl;
	cout << d1.print() << " " << d1 << endl;
	cout << d2.print() << " " << d2 << endl;
	cout << d3.print() << " " << d3 << endl;
	cout << "============ Testing ============\n";
	i1 = i3;
	cout << i1.print() << " " << i1 << endl;
	cout << (i1 = i2).print() << " " << (i1 = i2) << endl;
	cout << "============ Working ============\n";
	ID_Massiv<TID,TCLASS> massiv;
#ifdef DEBUG
	cout << "Press\n'1' for int | '2' for double | '#' for end... ";
	char ch = 0;
	while ((ch = _getche ()) != '#')
	switch (ch)
	{
	case '1': {
		int number = 0; I_Class* I_element = nullptr;
		cout << "Input integer number: ";
		cin >> number;
		I_element = new I_Class(number);
		massiv.Ate(I_element);
	} break;

	case '2': {
		double number = 0; D_Class* D_element = nullptr;
		cout << "Input double number: ";
		cin >> number;
		D_element = new D_Class(number);
		massiv.Ate(D_element);
	} break;
	default: cout << "\nWrong symbol\n'1' for int | '2' for double | '#' for end... ";
		break;
	}
	massiv.ForEach(show_all);
#endif
	
	return 0;
}
#endif
//END DONT WORKING CLASSES

//FOR WORKING CLASSES
#ifdef Classes_pointer_on

#include "Classes_pointer.h"
void show(Base* var_class)
{
	if (dynamic_cast<I_Class*>(var_class))
		cout << *var_class->get_int() << endl;
	else cout << *var_class->get_double() << endl;
}


ostream& operator<<(ostream& os, Base& var_class)
{
	if (var_class.type == DataType::Integer)
		os << *(var_class.get_int());
	else
		os << *(var_class.get_double());
	return os;
}

int main()
{
	ID_Massiv massiv;

	cout << "Press\n'1' for int | '2' for double | '#' for end... ";
	char ch = 0;
	while ((ch = _getch()) != '#')
		switch (ch)
		{
		case '1': {
			int number = 0; I_Class* I_element = nullptr;
			cout << "Input integer number: ";
			cin >> number;
			I_element = new I_Class(number);
			massiv.Ate(I_element);
			cout << "Success, add new or end?\t";
		} break;

		case '2': {
			double number = 0; D_Class* D_element = nullptr;
			cout << "Input double number: ";
			cin >> number;
			D_element = new D_Class(number);
			massiv.Ate(D_element);
			cout << "Success, add new or end?\t";
		} break;
		default: cout << "\nWrong symbol\n'1' for int | '2' for double | '#' for end... ";
			break;
		}
	cout << "\n===== [] ======" << endl;
	for (int i = 0; i < massiv.get_len(); i++)
	{
		cout << massiv[i] << endl;
	}
	cout << "===== Show ======" << endl;
	for (int i = 0; i < massiv.get_len(); i++)
	{
		massiv[i] = 0.5;
	}
	massiv.ForEach(show);
	return 0;
}

#endif
//END WORKING CLASSES
