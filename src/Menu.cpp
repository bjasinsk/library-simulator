#include "Menu.h"
#include <limits>
#include <algorithm>
#include <cctype>
#include <string>
#include "Book.h"

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
        cout << endl;
        cout << "1. Ksiazki" << endl;
        cout << "2. Klienci" << endl;
        cout << "3. Sprzedawcy" << endl;
        cout << "4. Kasa" << endl;
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
            cashMenu();
            break;
        case 0:
            return;
        }
    }
    return;
}

void Menu::cashMenu()
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << endl;
        cout << "1. Wypisz wartosc w kasie" << endl;
        cout << "2. Pokaz zamowienia" << endl;
        cout << "3. Zrealizuj zamowienia" << endl;
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
            cout << "W kasie jest: "<< this->bookstore->getBudget() << "zl" << endl;
            break;
        case 2:
            this->bookstore->printCurrentOrders();
            break;
        case 3:
            this->bookstore->realizeOrders();
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
        cout << endl;
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
                auto seller = bookstore->getSellerByNum(num);
                sellerOptionsMenu(seller);
                break;
            }
            case 2:
            {
                cout << "Podaj imie" << endl;
                string name = getStringFromUser();
                cout << "Podaj nazwisko" << endl;
                string surname = getStringFromUser();
                Seller seller(name, surname, this->bookstore->getBooshelfInstance(), bookstore->accessToBudget());
                bookstore->addSeller(seller);
                break;
            }
            case 0:
                return;
        }
    }
    return;
}

void Menu::sellerOptionsMenu(std::shared_ptr<Seller> seller)
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << "1. Zapytaj o dostepnosc ksiazki" << endl;
        cout << "2. Pokaz ksiazki z kategorii" << endl;
        cout << "3. Pokaz ksiazki autora" << endl;
        cout << "4. Pokaz kolejke" << endl;
        cout << "5. Obsluz klienta" << endl;
        cout << "6. Zamów książke"<< endl;
        cout << "7. Zakoncz prace" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 7)
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
            seller->printQueueOfCustomers();
            break;
        }
        case 5:
        {
            seller->serveFirstCustomerInQueue();
            break;
        }
        case 6:
        {   
            try
            {
                cout << endl << "Podaj imie autora: " << endl;
                string authorName = getStringFromUser();

                cout << endl << "Podaj nazwisko autora: " << endl;
                string authorSurname = getStringFromUser();

                Author new_author(authorName, authorSurname);

                cout << "Podaj nazwe tytułu: " << endl;
                string new_title = getStringFromUser();

                cout << "Podaj cene: " << endl;
                string price = getStringFromUser();
                int new_price = std::stoi(price);

                cout << "Podaj date publikacji: " << endl;
                string publication_date = getStringFromUser();
                unsigned int publication = std::stoul(publication_date);

                cout << "Podaj kategorie książki, jedną z poniższych: Adventure\n Cookery\n Crime\n History\n Sci-fi\n Poetry\n" << endl;
                string category = getStringFromUser();

                Book::BookType t = Book::string_to_BookType(category);
                Book newBook(new_author, new_title, new_price, publication, t);

                cout << "Podaj ilość: " << endl;
                string new_quantity = getStringFromUser();
                int quantity = std::stoi(new_quantity);
                
                std::queue<std::shared_ptr<Customer>> customersFromQueue = seller->getQueueOfCustomers();
                if(!customersFromQueue.empty()){
                    bookstore->makeAnOrder(newBook, quantity, *customersFromQueue.front());
                }
                else
                    cout << "Brak klienta w kolejce, kto zamawai?" << endl;
                break;
            }
            catch (...)
            {
                cerr << "Nieprawidlowa kategoria" << endl;
                return;
            }
        }
        case 7:
        {
            bookstore->removeSeller(*seller);
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
        cout << endl;
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
            cout << endl;
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
            shared_ptr<Customer> customer = bookstore->getCustomerByNum(num);
            customerOptionsMenu(customer);
            break;
        }
        case 2:
        {
            cout << endl << "Podaj imie" << endl;
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



void Menu::customerOptionsMenu(std::shared_ptr<Customer> customer)
{
    using namespace std;
    int choice;
    while (true)
    {
        cout << endl;
        cout << "1. Pokaż sprzedawców z ich kolejkami" << endl;
        cout << "2. Wejdź do kolejki" << endl;
        cout << "3. Dodaj książke do koszyka" << endl;
        cout << "4. Aktualny koszyk" << endl;
        cout << "5. Usuń książke z koszyka" << endl;
        cout << "6. Wyjdź ze sklepu" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 6)
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
            cout << endl << "Wybierz sprzedawce, do którego kolejki chcesz wejść:" << endl;
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
            bookstore->getSellerByNum(num)->addCustomerToQueue(customer);
            break;
        }
        case 3:
        {
            auto book = getBook();
            customer->addToShoppingCart(*book);
            break;
        }
        case 4:
        {   
            cout << endl;
            customer->printActualShoppingCart();
            break;
        }
        case 5:
        {
            customer->printActualShoppingCart();
            std::vector<std::shared_ptr<Book>> books = customer->getShoppingCart();
            std::cout << "Wybierz, którą książke chcesz usunąć\n";
            int num;
            cin >> num;
            if (cin.fail() || num < 0 || num >= (int)books.size())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            customer->removeFromShoppingCart(*(books[num]));
            break;
        }
        case 6:
        {
            bookstore->customerLeavesStore((*customer));
            return;
        }
        case 0:
            return;
        }
    }
    return;
}

std::shared_ptr<const Book> Menu::getBook()
{
    using namespace std;
    int choice;
    while (true)
    {
        int i = 0;
        cout << endl;
        auto books = bookstore->getBooshelfInstance().getBooks();
        for (auto book : books)
            cout << i++  << ". "<< *book;
        cout << "Wybierz ksiazke: ";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice >= (int)books.size())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << *(books[choice]);
        return books[choice];  
    }
}