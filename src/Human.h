#ifndef __HUMAN__
#define __HUMAN__

#include <iostream>

class Human
{
    private:
        std::string name;
        std::string surname;
    public:
        Human(std::string name_, std::string surname_) : name(name_), surname(surname_){};
};

#endif