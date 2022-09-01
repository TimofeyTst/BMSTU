#ifndef MYCONTAINERS_H
#define MYCONTAINERS_H
#include <iostream>
using namespace std;

enum class DataType { Char, Double };

class Base
{
protected:
    DataType type;
public:
    Base* prev, * next;
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
    double* get_double() override
    {
        return nullptr;
    }
    Base& operator = (Base& var_class) override
    {
        this->ch = *(var_class.get_char());
        return *this;
    }
    Base& operator = (char var) override
    {
        this->ch = var;
        return *this;
    }
    Base& operator= (double var) override
    {
        this->ch = static_cast<char>(var);
        return *this;
    }
    Base& operator = (int var) override
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
    double* get_double() override
    {
        return &num;
    }
    Base& operator = (Base& var_class) override
    {
        this->num = *(var_class.get_double());
        return *this;
    }
    Base& operator = (double var) override
    {
        this->num = var;
        return *this;
    }
    Base& operator = (int var) override
    {
        this->num = var;
        return *this;
    }
    Base& operator = (char var) override
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

    void Ate(Base* var_class);
    void Ate(int var) { D_Class* var_clas = new D_Class(var); Ate(var_clas); }
    void Ate(double var) { D_Class* var_clas = new D_Class(var); Ate(var_clas); }
    void Ate(char var) { S_Class* var_clas = new S_Class(var); Ate(var_clas); }

    void ForEach_stek(void (*func)(Base* var_class));
    void ForEach(void (*func)(Base* var_class));

    Base* get_first() { return current = first; };
    Base* get_last() { return current = last; };
    Base* get_current() { return current; };
    Base* get_next() { if (current->next!=nullptr) return current = current->next;
                     else return 0;};
    Base* get_prev() { if(current->prev != nullptr) return current = current->prev;
                     else return 0;};

    Base& operator[](int number);
    ~ID_Massiv();
};

ostream& operator<<(ostream& os, Base& var_class);

class child_ID_Massiv : public ID_Massiv
{
public:
    child_ID_Massiv() :ID_Massiv() {}
    double min_number();
};
#endif // MYCONTAINERS_H
