#include "Bookshelf.h"

void Bookshelf::sortBooks()
{
    std::sort(books.begin(), books.end());
}

std::ostream &operator<<(std::ostream &os, const Bookshelf &b)
{
    int i = 1;
    for (std::shared_ptr<Book> book : b.books)
    {
        os << i++ << ". " << *book;
    }
    return os;
}

void Bookshelf::addBooks(const Book &book, unsigned int number)
{
    std::shared_ptr<Book> b = findBookIfExist(book);
    if (b != nullptr)
        b->addBooks(number);
    else
    {
        std::shared_ptr<Book> new_book(new Book(book));
        new_book->addBooks(number);
        books.push_back(new_book);
    }
}

void Bookshelf::removeBooks(const Book &book, unsigned int number)
{
    std::shared_ptr<Book> b = findBookIfExist(book);
    if (b != nullptr)
    {
        if (b->getNumberOfBooks() > number)
            b->removeBooks(number);
        else
        {
            for (std::vector<std::shared_ptr<Book>>::iterator it = books.begin(); it != books.end(); ++it)
            {
                if (**it == book)
                    books.erase(it);
            }
        }
    }
    else
    {
        // TODO: book not exist
    }
}

std::shared_ptr<Book> Bookshelf::findBookIfExist(const Book &b) const
{
    for (std::shared_ptr<Book> book : books)
    {
        if (*book == b)
            return book;
    }
    return nullptr;
}

unsigned int Bookshelf::checkBooksNumber(const Book &book) const
{
    std::shared_ptr<Book> b = findBookIfExist(book);
    if (b != nullptr)
        return b->getNumberOfBooks();
    else
        return 0;
}

void Bookshelf::printBooksByCategory(Book::BookType category)
{
    for (std::shared_ptr<Book> book : books)
    {
        Book::BookType type = (Book::BookType)book->getCategoryEnum();
        if(type == category)
            std::cout << *book;
    }
}

std::vector<std::shared_ptr<const Book>> Bookshelf::getBooks()
{
    std::vector<std::shared_ptr<const Book>> copy;
    for (std::shared_ptr<Book> book : books)
    {
        copy.push_back(book);
    }
    return copy;
};

std::vector<std::shared_ptr<const Book>> Bookshelf::getBooksByAuthor(Author author)
{
    std::vector<std::shared_ptr<const Book>> copy;
    for (std::shared_ptr<Book> book : books)
    {
        if (book->get_author() == author)
        copy.push_back(book);
    }
    return copy;
};

std::vector<std::shared_ptr<const Book>> Bookshelf::getBooksByTytle(std::string title)
{
    std::vector<std::shared_ptr<const Book>> copy;
    for (std::shared_ptr<Book> book : books)
    {
        if (book->get_title() == title)
        copy.push_back(book);
    }
    return copy;
};