#include "Librarian.h"

unsigned int Librarian::store(const std::string &name)
{
	books_.insert(name);
	return books_.size();
}

void Librarian::store(BookVendor &vendor)
{
    throw std::runtime_error("not implemented");
}

unsigned int Librarian::borrow(const std::string &name)
{
	Books::const_iterator it = books_.find(name);
	if (it == books_.end()) {
		throw std::invalid_argument(name + " is not available");
	}
	books_.erase(it);
	return books_.size();
}

