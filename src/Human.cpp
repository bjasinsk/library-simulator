#include "Human.h"


std::string Human::getName() const{
    return name;
};

std::string Human::getSurname() const{
    return surname;
};

std::ostream &operator<<(std::ostream &os, const Human &human)
{
    os << human.getName() << " " << human.getSurname() << std::endl;
    return os;
}

bool Human::operator==(const Human& t) const
{
    return name==t.name && surname==t.surname;
}

bool Human::operator!=(const Human& t) const
{
    return !(*this==t);
}