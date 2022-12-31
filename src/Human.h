#ifndef __HUMAN__
#define __HUMAN__

#include <iostream>

class Human
{
    private:
        std::string name;
    public:
        Human(std::string name_) : name(name_){};
};

#endif