#ifndef __RECOMMENDENGINE_H__
#define __RECOMMENDENGINE_H__

#include "Book.h"

class RecommendEngine
{
public:
    virtual ~RecommendEngine();
    virtual std::shared_ptr<Book> filter(const BookList &bookList) const;
};

#endif
