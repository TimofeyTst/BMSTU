#pragma once
#include <iostream> 
#include <fstream>
using namespace std;
template <typename TID, typename TCLASS>
class Base {
public:
    Base *prev, *next; //Почему не могу "prev,next"?
    Base() 
    {
        prev = next = nullptr;
    }

    virtual TID& print() = 0;

    virtual TCLASS& operator=(const TCLASS var_class) = 0;
    virtual ~Base() { static int i=1;  cout << "\nDestructor Base "<< i++ <<"\n"; };
    // virtual ostream& operator<< (ostream& os, const TCLASS& var_class) = 0;
};

class I_Class: public Base <int,I_Class> 
{
private:
    int num;
public:
    I_Class(int inum = 0) :Base(), num(inum) {}
    int& print() override
    {
        return num;
    }
    I_Class& operator = (const I_Class var_class) override
    {
       this->num = var_class.num;
       return *this;
    }
    
};
class D_Class : public Base <double, D_Class>
{
private:
    double num;
public:
    D_Class(double inum = 0.0) :Base(), num(inum) {}
    double& print() override
    {
        return num;
    }
    D_Class& operator = (const D_Class var_class) override
    {
        this->num = var_class.num;
        return *this;
    }
};
//Не запускается это, хоть и компилится
//ostream& operator<< (ostream& os, Base<int,I_Class>& var_class) 
//{
//    os << var_class.print();
//    return os;
//}
//ostream& operator<< (ostream& os, Base<double, D_Class>& var_class)
//{
//    os << var_class.print();
//    return os;
//}

template <typename TID,typename TCLASS> 
class ID_Massiv
{
private:
    Base<TID,TCLASS> * first, *last, *current;
    int len;
public:
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
    void Ate(Base<TID,TCLASS>* var_class)
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
    void ForEach(void (*func)(Base<TID,TCLASS>* var_class))
    {
        current = first;
        while (current != nullptr)
        {
            func(current);
            current = current->next;
        }

    };

    Base<TID,TCLASS>* get_first() { return current = first; };
    Base<TID,TCLASS>* get_last() { return current = last; };
    Base<TID, TCLASS>* get_current() { return current; };
    Base<TID, TCLASS>* get_next() { return current = current->next; };
    Base<TID, TCLASS>* get_prev() { return current = current->prev; };
    
    TID& operator[](int number)// [5] = 9; 
    {
        current = last;
        int i = 0;  bool key = true;
        while (current != nullptr && key)
        {
            if (i++ == number)
            {
                return current->print(); key = false;
            }
            current = current->prev;
        }

    }
};