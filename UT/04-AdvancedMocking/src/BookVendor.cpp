#include <time.h>
#include <vector>
#include <algorithm>
#include "BookVendor.h"


class BookVendorImpl : public BookVendor {
public:
    virtual std::shared_ptr<Book> getBookAt(unsigned int index) const
    {
        return books_.at(index);
    }

    virtual unsigned int getBookCount() const
    {
        return books_.size();
    }

    void addBook(const std::shared_ptr<Book> &book) {
        books_.push_back(book);
    }

    virtual void pay(unsigned int price)
    {
        // do nothing but vendor is happy
    }

private:
    std::vector<std::shared_ptr<Book>> books_;
};

BookVendor::~BookVendor()
{

}

std::shared_ptr<BookVendor> BookVendor::create()
{
    srand((unsigned int)time(NULL));
    std::shared_ptr<BookVendorImpl> vendor = std::make_shared<BookVendorImpl>();

    unsigned int bookCount = rand() % 10 + 1;
    std::string bookName = "abcdefghijklmnopqrstuvwxyz";
    for (size_t i = 0; i < bookCount; i++)
    {
        std::random_shuffle(bookName.begin(), bookName.end());
        unsigned int bookPrice = rand() % 90 + 10;
        vendor->addBook(Book::create(bookName.substr(10), bookPrice));
    }

    return std::dynamic_pointer_cast<BookVendor>(vendor);
}
