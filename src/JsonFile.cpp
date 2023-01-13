#include "JsonFile.h"
#include <iostream>

nlohmann::json JsonFile::readFile(std::string path)
{
    std::ifstream f(path);
    nlohmann::json data = nlohmann::json::parse(f);
    return data;
}

void JsonFile::readData(std::string path, Bookshelf& dst)
{
    nlohmann::json data = readFile(path);
    for (auto i : data["Authors"])
    {
        std::string name = i["name"];
        std::string surname = i["surname"];
        Author author(name, surname);
        for (auto j : i["Books"])
        {
            std::string title = j["title"];
            double price = j["price"];
            int year = j["year"];
            std::string type = j["type"];
            int number = j["number"];
            Book book(author, title, price, year, Book::string_to_BookType(type));
            dst.addBooks(book, number);
        }
    }
}
