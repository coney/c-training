#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <set>
#include <string>
#include "BookVendor.h"

class Librarian {
public:
	unsigned int store(const std::string &name);
	unsigned int borrow(const std::string &name);
    void store(BookVendor &vendor);

private:
	typedef std::set<std::string> Books;
	Books books_;
};


#endif // __LIBRARIAN_H__
