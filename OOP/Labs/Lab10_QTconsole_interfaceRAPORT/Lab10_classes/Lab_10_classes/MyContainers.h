#pragma once
#include <iostream> 
#include <fstream>


using namespace std;

enum class DataType { Char, Double };
class Base
{
protected:
    DataType type;
public:
    Base* prev, * next; //Почему не могу "prev,next"?
    Base()
    {
        prev = next = nullptr; type = DataType::Char;
    }
    DataType get_type() { return type; }
    virtual char* get_char() = 0;
    virtual double* get_double() = 0;

    virtual Base& operator=(char var) = 0;
    virtual Base& operator=(double var) = 0;
    virtual Base& operator=(int var) = 0;
    virtual Base& operator=(Base& var_class) = 0;


    virtual ~Base() { static int i = 1; i++; /*cout << "\nDestructor Base " << i++ << "\n"; */ };
    friend ostream& operator<<(ostream& os, Base& var_class);
};


class S_Class : public Base
{
private:
    char ch;
public:
    S_Class(char ich = '\0') :Base(), ch(ich) { this->type = DataType::Char; }
    char* get_char() override
    {
        return &ch;
    }
    double* get_double()
    {
        return nullptr;
    }
    Base& operator = (Base& var_class)
    {
        this->ch = *(var_class.get_char());
        return *this;
    }
    Base& operator = (char var)
    {
        this->ch = var;
        return *this;
    }
    Base& operator= (double var)
    {
        this->ch = static_cast<char>(var);
        return *this;
    }
    Base& operator = (int var)
    {
        this->ch = static_cast<char>(var);
        return *this;
    }
};
class D_Class : public Base
{
private:
    double num;
public:
    D_Class(double inum = 0.0) :Base(), num(inum) { this->type = DataType::Double; }
    D_Class(int inum = 0) :Base(), num(inum) { this->type = DataType::Double; }
    char* get_char() override
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
        this->num = var;
        return *this;
    }
    Base& operator = (char var)
    {
        this->num = static_cast<double>(var);
        return *this;
    }
};

class ID_Massiv
{
protected:
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
    void Ate(int var) { D_Class* var_clas = new D_Class(var); Ate(var_clas); }
    void Ate(double var) { D_Class* var_clas = new D_Class(var); Ate(var_clas); }
    void Ate(char var) { S_Class* var_clas = new S_Class(var); Ate(var_clas); }

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
    if (var_class.type == DataType::Char)
        os << *(var_class.get_char());
    else
        os << *(var_class.get_double());
    return os;
}

class child_ID_Massiv : public ID_Massiv
{
public:
    child_ID_Massiv() :ID_Massiv() {}
    double min_number()
    {
        int i = 0, index = 0; double min = 0; bool is_first = true;
        current = last;
        while (current != nullptr)
        {
            if (current->get_type() == DataType::Double)
            {
                if (is_first) {
                    min = *current->get_double(); index = i; is_first = false;
                }
                else
                {
                    if (*current->get_double() < min) {
                        min = *current->get_double(); index = i;
                    }
                }
            }
            current = current->prev;
            i++;
        }
        return min;
    }
};
