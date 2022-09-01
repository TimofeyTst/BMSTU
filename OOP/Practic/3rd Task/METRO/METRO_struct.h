#ifndef METRO_STRUCT_H
#define METRO_STRUCT_H
#include <string>
#include <iostream>

struct METRO_struct {
    unsigned int year, life;
    std::string id,model;
};

struct METRO_pointer: public METRO_struct
{
    METRO_pointer *next;
};


std::ostream &operator << (std::ostream& os, METRO_struct var );
#endif // METRO_STRUCT_H
