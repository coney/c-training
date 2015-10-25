#ifndef __SEARCHENGINE_H__
#define __SEARCHENGINE_H__

#include <list>
#include "Book.h"

class SearchEngine
{
public:
    virtual ~SearchEngine();
    static BookList search(const BookStore &bookStore, const std::string &keyword);
};

#endif


