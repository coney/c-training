#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include "Book.h"
#include "BookVendor.h"
#include "SearchEngine.h"
#include "RecommendEngine.h"

class Librarian {
public:
    unsigned int store(const std::shared_ptr<Book>& book);
    unsigned int borrow(const std::string &name);
    void store(BookVendor &vendor);

    std::shared_ptr<Book> recommend(const std::string &keyword);

private:
    RecommendEngine recommendEngine;
    BookStore books_;
};


#endif // __LIBRARIAN_H__
