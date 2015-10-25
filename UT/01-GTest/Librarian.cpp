#include "Librarian.h"

unsigned int Librarian::store(const std::string &name)
{
    books_.insert(name);
    return books_.size();
}

unsigned int Librarian::borrow(const std::string &name)
{
    throw std::runtime_error("not implemented");
}
