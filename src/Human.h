#ifndef __HUMAN__
#define __HUMAN__

#include <iostream>

/**
 * Klasa Human reprezentująca człowieka. Klasa zawiera imię i nazwisko, metody zwracające dane człowieka, przeciążone operatory porównania.
*/
class Human
{
    private:
        std::string name;
        std::string surname;
    public:
        Human(std::string name_, std::string surname_) : name(name_), surname(surname_){};

        /**
         * Metoda zwracająca imię
        */
        std::string getName() const;
        /**
         * Metoda zwracająca nazwisko
        */
        std::string getSurname() const;

        bool operator==(const Human& t) const;
        bool operator!=(const Human& t) const;
        friend std::ostream &operator<<(std::ostream &os, const Human &human);
};
std::ostream &operator<<(std::ostream &os, const Human &human);

#endif