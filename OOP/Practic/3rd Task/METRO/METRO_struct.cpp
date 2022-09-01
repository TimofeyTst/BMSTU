#include "METRO_struct.h"

std::ostream &operator << (std::ostream& os, struct::METRO_struct var )
{
    os << var.id << '\n' << var.model << '\n' << var.year << '\n' << var.life << '\n' << "========\n";
    return os;
}
