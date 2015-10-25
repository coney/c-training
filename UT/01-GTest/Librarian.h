#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <set>
#include <string>

class Librarian {
public:
	unsigned int store(const std::string &name);
	unsigned int borrow(const std::string &name);

private:
	std::set<std::string> books_;
};


#endif // __LIBRARIAN_H__
