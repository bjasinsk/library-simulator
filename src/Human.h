#ifndef __HUMAN__
#define __HUMAN__

#include <iostream>

class Human
{
    private:
        std::string name;
        std::string surname;
        int age;
    public:
        Human(std::string name_, std::string surname_, int age_) : name(name_), surname(surname_), age(age_){};

        //gettery
        std::string getName() const;
        std::string getSurname() const;
        int getAge() const;

        

};

#endif