#ifndef __AUTHOR_H__
#define __AUTHOR_H__

#include <iostream>

class Author
{
    private:
        std::string name;
        std::string surname;
    public:
        Author(std::string name, std::string surname);
        std::string get_name() const;
        std::string get_surname() const;
        bool operator==(const Author& t) const;
        bool operator!=(const Author& t) const;

    friend std::ostream& operator<<(std::ostream& os, const Author& author);
};

std::ostream& operator<<(std::ostream& os, const Author& author);

#endif