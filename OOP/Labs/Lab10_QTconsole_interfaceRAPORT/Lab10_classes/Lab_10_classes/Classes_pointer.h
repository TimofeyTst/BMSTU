#pragma once
#include <iostream> 
#include <fstream>


using namespace std;

enum class DataType {Integer,Double};
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
    virtual int& operator=(int var) = 0;
    virtual double& operator=(double var) = 0;
    virtual Base& operator=(Base& var_class) = 0;
    virtual ~Base() { static int i = 1;  cout << "\nDestructor Base " << i++ << "\n"; };
    friend ostream& operator<<(ostream& os,Base& var_class);
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
    int& operator = (int var)
    {
        this->num = var;
        return num;
    }
    double& operator= (double var)
    {
        double vrem =
        this->num = static_cast<int>(var);
        return vrem;
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
    double& operator = (double var)
    {
        this->num = var;
        return num;
    }
    int& operator = (int var)
    {
        int vrem =
            this->num = static_cast<double>(var);
        return vrem;
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


