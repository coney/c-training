#include "Book.h"


class BookImpl : public Book {
public:
    BookImpl(const std::string &name, unsigned int price)
        : name_(name), price_(price) {

    }

    virtual const std::string name() const
    {
        return name_;
    }

    virtual const unsigned int price() const
    {
        return price_;
    }

private:
    std::string name_;
    unsigned int price_;
};

Book::~Book()
{

}

std::shared_ptr<Book> Book::create(const std::string &name, unsigned int price)
{
    return std::make_shared<BookImpl>(name, price);
}
