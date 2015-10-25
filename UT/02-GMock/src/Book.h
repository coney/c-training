#ifndef __BOOK_H__
#define __BOOK_H__

#include <list>
#include <string>
#include <memory>

class Book {
public:
	virtual ~Book();
	virtual const std::string name() const = 0;
	virtual const unsigned int price() const = 0;

    // create Book instance with specified name and price
	static std::shared_ptr<Book> create(
        const std::string &name, unsigned int price);
};

typedef std::list<std::shared_ptr<Book>> BookList;

#endif
