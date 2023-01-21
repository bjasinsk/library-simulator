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