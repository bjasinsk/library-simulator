#include "Author.h"

Author::Author(std::string name, std::string surname)
{
    this->name = name;
    this->surname = surname;
}

bool Author::operator==(const Author& t) const
{
    return name==t.name && surname==t.surname;
}

bool Author::operator!=(const Author& t) const
{
    return !(*this==t);
}

std::string Author::get_name() const
{
    return name;
}

std::string Author::get_surname() const
{
    return surname;
}

std::ostream& operator<<(std::ostream& os, const Author& author)
{
    os << author.name << " " << author.surname;
    return os;
}