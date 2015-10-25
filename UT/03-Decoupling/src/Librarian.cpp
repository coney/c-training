#include "Librarian.h"

unsigned int Librarian::store(const std::shared_ptr<Book>& book)
{
    books_.insert(std::make_pair(book->name(), book));
    return books_.size();
}

void Librarian::store(BookVendor &vendor)
{
    unsigned int totalPrice = 0;
    for (size_t i = 0; i < vendor.getBookCount(); i++)
    {
        std::shared_ptr<Book> book = vendor.getBookAt(i);
        if (books_.count(book->name()) == 0) {
            books_[book->name()] = book;
            totalPrice += book->price();
        }
    }
    vendor.pay(totalPrice);
}

std::shared_ptr<Book> Librarian::recommend(const std::string &keyword)
{
    BookList booklist = SearchEngine::search(books_, keyword);
    return recommendEngine.filter(booklist);
}

unsigned int Librarian::borrow(const std::string &name)
{
    BookStore::const_iterator it = books_.find(name);
    if (it == books_.end()) {
        throw std::invalid_argument(name + " is not available");
    }
    books_.erase(it);
    return books_.size();
}

