#include <iostream> 
#include <fstream>
#include <conio.h>

using namespace std;

enum class DataType { Integer, Double };
class Base {
protected:
    DataType type;
public:
    Base* prev, * next; //Почему не могу "prev,next"?
    Base()
    {
        prev = next = nullptr; type = DataType::Integer;
    }
    virtual int* get_int() = 0;
    virtual double* get_double() = 0;

    virtual Base& operator=(int var) = 0;
    virtual Base& operator=(double var) = 0;
    virtual Base& operator=(Base& var_class) = 0;

    virtual ~Base() { static int i = 1;  cout << "\nDestructor Base " << i++ << "\n"; };
    friend ostream& operator<<(ostream& os, Base& var_class);
};


class I_Class : public Base
{
private:
    int num;
public:
    I_Class(int inum = 0) :Base(), num(inum) { this->type = DataType::Integer; }
    int* get_int() override
    {
        return &num;
    }
    double* get_double()
    {
        return nullptr;
    }
    Base& operator = (Base& var_class)
    {
        this->num = *(var_class.get_int());
        return *this;
    }
    Base& operator = (int var)
    {
        this->num = var;
        return *this;
    }
    Base& operator= (double var)
    {
        this->num = static_cast<int>(var);
        return *this;
    }
};
class D_Class : public Base
{
private:
    double num;
public:
    D_Class(double inum = 0.0) :Base(), num(inum) { this->type = DataType::Double; }
    int* get_int() override
    {
        return nullptr;
    }
    double* get_double()
    {
        return &num;
    }
    Base& operator = (Base& var_class)
    {
        this->num = *(var_class.get_double());
        return *this;
    }
    Base& operator = (double var)
    {
        this->num = var;
        return *this;
    }
    Base& operator = (int var)
    {
        this->num = static_cast<double>(var);
        return *this;
    }
};

class ID_Massiv
{
private:
    Base* first, * last, * current;
    int len;
public:

    int get_len() { return len; }
    ID_Massiv() { first = last = current = nullptr; len = 0; }
    ~ID_Massiv()
    {
        current = first;
        while (first != nullptr)
        {
            first = first->next;
            delete  current;
            current = first;
        }
    };
    void Ate(Base* var_class)
    {
        if (first == nullptr) //Отредачить потом на проверку просто first
        {
            last = current = first = var_class; len++;
        }
        else {
            var_class->next = first;
            first->prev = var_class;
            first = var_class;
            len++;
        }

    };
    void ForEach_stek(void (*func)(Base* var_class))
    {
        current = first;
        while (current != nullptr)
        {
            func(current);
            current = current->next;
        }

    };
    void ForEach(void (*func)(Base* var_class))
    {
        current = last;
        while (current != nullptr)
        {
            func(current);
            current = current->prev;
        }

    };

    Base* get_first() { return current = first; };
    Base* get_last() { return current = last; };
    Base* get_current() { return current; };
    Base* get_next() { return current = current->next; };
    Base* get_prev() { return current = current->prev; };

    Base& operator[](int number)// -> decltype(&number)// [5] = 9; 
    {
        current = last;
        int i = 0;  bool key = true;
        while (current != nullptr && key)
        {
            if (i++ == number)
            {
                /*if (dynamic_cast<I_Class*>(current))
                    return (double&) * current->get_int();
                else
                    return  (*current->get_double()) ;*/
                return *current;
                key = false;
            }
            current = current->prev;
        }
    }

};

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

    //INPUT (U CAN ERASE IT)
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
    //END OF INPUT

    for (int i = 0; i < massiv.get_len(); i++)
    {
        cout << massiv[i] << endl;
    }
    cout << "===== Zapolnim all 0.5, SHOWING cout inline ======" << endl;
    for (int i = 0; i < massiv.get_len(); i++)
    {
        cout << (massiv[i] = 0.5) << endl;
    }
    cout << "===== Zapolnim all 2, SHOWING ======" << endl;
    for (int i = 0; i < massiv.get_len(); i++)
    {
        massiv[i] = 2;
        cout << massiv[i] << endl;
    }
    return 0;
}
