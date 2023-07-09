#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <stdexcept>
#include <iostream>

class ExceptionLibraryWrongValue : public std::invalid_argument
{
    public:
        ExceptionLibraryWrongValue(const std::string& mess) :
            std::invalid_argument("Not correct values: " + mess){};
};

class ExceptionLibraryNoValue : public std::exception
{
    public:
        ExceptionLibraryNoValue(const std::string& mess)
        : message(mess) {};
        std::string what () {
            std::string text = "No value: " + message;
            return text;
        }
    private:
        std::string message;
};

#endif
