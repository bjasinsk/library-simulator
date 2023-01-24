#ifndef __AUTHOR_H__
#define __AUTHOR_H__

#include <iostream>
#include "Human.h"
/**
 * Klasa Author reprezentująca autora książki.
*/
class Author: public Human
{
    private:
    public:
        Author(std::string name, std::string surname) : Human(name, surname){};
};

#endif