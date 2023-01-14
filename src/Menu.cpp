#include "Menu.h"
#include <limits>
#include <algorithm>
#include <cctype>

Menu::Menu(const BookStore &bookstore)
{
    this->bookstore = new BookStore(bookstore);
}

void Menu::mainMenu()
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << "1. Ksiazki" << endl;
        cout << "2. Klienci" << endl;
        cout << "3. Sprzedawcy" << endl;
        cout << "4. Czas" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            booksMenu();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return;
        }
    }
    return;
}

void Menu::booksMenu()
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << "1. Lista  wszystkich ksiazek" << endl;
        cout << "2. Lista ksiazek z kategorii" << endl;
        cout << "3. Wyszukaj ksiazki po autorze" << endl;
        cout << "4. Wyszukaj ksiazki po tytule" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            cout << bookstore->getBooshelfInstance();
            break;
        case 2:
        {
            Book::BookType type = chooseBookCategory();
            bookstore->getBooshelfInstance().printBooksByCategory(type);
            break;
        }
        case 3:
        {
            cout << "Podaj imie" << endl;
            string name = getStringFromUser();
            cout << "Podaj nazwisko" << endl;
            string surname = getStringFromUser();
            Author author(name, surname);
            for(auto i : bookstore->getBooshelfInstance().getBooks())
                if(i->get_author() == author)
                    cout << *i;
            break;
        }
        case 4:
        {
            cout << "Podaj tytuł" << endl;
            string title = getStringFromUser();
            transform(title.begin(), title.end(), title.begin(), ::tolower);
            for(auto i : bookstore->getBooshelfInstance().getBooks())
            {
                string title_ = i->get_title();
                transform(title_.begin(), title_.end(), title_.begin(), ::tolower);
                if(title_.find(title) != std::string::npos)
                    cout << *i;
            }
            break;
        }
        case 0:
            return;
        }
    }
    return;
}

Book::BookType Menu::chooseBookCategory()
{
    using namespace std;
    int choice;
    while (true)
    {
        for (int i = 0; i < (int)Book::type_map.size(); i++)
        {
            auto it = Book::type_map.begin();
            std::advance(it, i);
            std::string value = it->second;
            std::cout << i + 1 << ". " << value << std::endl;
        }
        cin >> choice;
        if (cin.fail() || choice <= 0 || choice > (int)Book::type_map.size())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        auto it = Book::type_map.begin();
        std::advance(it, choice-1);
        Book::BookType value = it->first;
        return value;
    }
}

std::string Menu::getStringFromUser()
{
    std::string text;
    std::cin >> text;
    return text;
}
