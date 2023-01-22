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
            customersMenu();
            break;
        case 3:
            sellersMenu();
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


void Menu::sellersMenu()
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << "1. Lista sprzedawcow" << endl;
        cout << "2. Rozpocznij prace" << endl;
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
            {
                int number_of_sellers = bookstore->printSellers();
                cout << "Wybierz sprzedawce:" << endl;
                cout << "0. Cofnij" << endl;
                int num;
                cin >> num;
                if (cin.fail() || num < 0 || choice > number_of_sellers)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if(num == 0)
                    return;
                this->seller = bookstore->getSellerByNum(num);
                sellerOptionsMenu();
                break;
            }
            case 2:
            {
                cout << "Podaj imie" << endl;
                string name = getStringFromUser();
                cout << "Podaj nazwisko" << endl;
                string surname = getStringFromUser();
                Seller seller(name, surname, this->bookstore->getBooshelfInstance());
                bookstore->addSeller(seller);
                break;
            }
            case 0:
                return;
        }
    }
    return;
}

void Menu::sellerOptionsMenu()
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << "1. Zapytaj o dostepnosc ksiazki" << endl;
        cout << "2. Pokaz ksiazki z kategorii" << endl;
        cout << "3. Pokaz ksiazki autora" << endl;
        cout << "4. Zakoncz prace" << endl;
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
            bookstore->removeSeller(*(this->seller));
            this->seller = nullptr;
            return;
        }
        case 0:
            return;
        }
    }
    return;
}



void Menu::customersMenu()
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << "1. Lista klientów" << endl;
        cout << "2. Dodaj klienta" << endl;
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
        {   
            int number_of_customers = bookstore->printCutomers();
            cout << "Wybierz klienta:" << endl;
            cout << "0. Cofnij" << endl;
            int num;
            cin >> num;
            if (cin.fail() || num < 0 || choice > number_of_customers)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if(num == 0)
                return;
            this->customer = bookstore->getCustomerByNum(num);
            customerOptionsMenu();
            break;
        }
        case 2:
        {
            cout << "Podaj imie" << endl;
            string name = getStringFromUser();
            cout << "Podaj nazwisko" << endl;
            string surname = getStringFromUser();

            Customer newCustomer(name, surname);
            bookstore->customerEntersStore(newCustomer);
            break;
        }
        case 0:
            return;
        }
    }
    return;
}



void Menu::customerOptionsMenu()
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << "1. Pokaż sprzedawców z ich kolejkami" << endl;

        cout << "2. Wejdź do kolejki" << endl;
        cout << "3. Pokaz ksiazki autora" << endl;
        
        cout << "4. Wyjdź ze sklepu" << endl;
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
        {
            bookstore->showAvailableSellersWithQueues();
            break;
        }
        case 2:
        {
            int number_of_sellers = bookstore->printSellers();
            cout << "Wybierz sprzedawce, do którego kolejki chcesz wejść:" << endl;
            cout << "0. Cofnij" << endl;
            int num;
            cin >> num;
            if (cin.fail() || num < 0 || choice > number_of_sellers)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if(num == 0)
                return;
            bookstore->getSellerByNum(num)->addCustomerToQueue(*customer.get());
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            bookstore->customerLeavesStore((*(this->customer)));
            this->customer = nullptr;
            return;
        }
        case 0:
            return;
        }
    }
    return;
}