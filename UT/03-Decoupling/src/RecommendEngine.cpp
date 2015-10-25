#include "RecommendEngine.h"

RecommendEngine::~RecommendEngine()
{
}

std::shared_ptr<Book> RecommendEngine::filter(const BookList &bookList) const
{
    std::shared_ptr<Book> target;
    for (BookList::const_iterator it = bookList.begin();
        it != bookList.end(); ++it) {
        if (!target || (*it)->price() > target->price()) {
            target = *it;
        }
    }
    return target;
}
