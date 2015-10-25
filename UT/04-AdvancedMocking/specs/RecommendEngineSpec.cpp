#include <gmock/gmock.h>
#include "../src/RecommendEngine.h"

TEST(RecommendEngine, ShouldReturnTheMostPopularBookFromTheBookList) {
    BookList bookList;
    bookList.push_back(Book::create("C++ Primer", 30));
    bookList.push_back(Book::create("The C++ Programming Language", 50));
    bookList.push_back(Book::create("Effective C++", 10));

    std::shared_ptr<RecommendEngine> engine = RecommendEngine::create();
    std::shared_ptr<Book> book = engine->filter(bookList);
    ASSERT_TRUE(book);
    ASSERT_EQ("The C++ Programming Language", book->name());
}