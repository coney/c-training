#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <functional>
#include "Book.h"
#include "BookVendor.h"
#include "SearchEngine.h"
#include "RecommendEngine.h"

class Librarian {
public:
    Librarian();
    unsigned int store(const std::shared_ptr<Book>& book);
    unsigned int borrow(const std::string &name);
    void store(BookVendor &vendor);

    std::shared_ptr<Book> recommend(const std::string &keyword);

private:
    std::shared_ptr<RecommendEngine> recommendEngine_;
    BookStore books_;
};


#endif // __LIBRARIAN_H__
