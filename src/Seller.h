#ifndef __SELLER__
#define __SELLER__

#include <iostream>
#include "Human.h"

class Seller : public Human
{
    private:
    public:
        Seller(std::string name) : Human(name) {};
};

#endif