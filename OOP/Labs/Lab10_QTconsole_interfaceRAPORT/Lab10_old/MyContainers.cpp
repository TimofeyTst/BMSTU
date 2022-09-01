#include "MyContainers.h"

void ID_Massiv:: Ate(Base *var_class)
{
    if (first == nullptr)
            {
                last = current = first = var_class; len++;
            }
            else {
                var_class->next = first;
                first->prev = var_class;
                first = var_class;
                len++;
            }
}

void ID_Massiv::ForEach_stek(void (*func)(Base* var_class))
{
    current = first;
     while (current != nullptr)
     {
         func(current);
         current = current->next;
     }
}

void ID_Massiv::ForEach(void (*func)(Base* var_class))
{
     current = last;
     while (current != nullptr)
     {
         func(current);
         current = current->prev;
     }
}

Base& ID_Massiv::operator[](int number)
{
    current = last;
    int i = 0;  bool key = true;
    while (current != nullptr && key)
    {
        if (i++ == number)
        {
            return *current;
            key = false;
        }
        current = current->prev;
    }
}

ID_Massiv::~ID_Massiv()
{
    current = first;
    while (first != nullptr)
    {
        first = first->next;
        delete  current;
        current = first;
    }
}

ostream& operator<<(ostream& os, Base& var_class)
{
    if (var_class.type == DataType::Char)
        os << *(var_class.get_char());
    else
        os << *(var_class.get_double());
    return os;
}

double child_ID_Massiv::min_number()
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
