#include "gmock/gmock.h"
#include "../src/Librarian.h"

// you should not edit this file
TEST(Librarian, ShouldRecommendBooksByKeyword) {
    Librarian librarian;
    librarian.store(Book::create("C++ Primer", 10));
    librarian.store(Book::create("The C++ Programming Language", 20));
    librarian.store(Book::create("Thinking in Java", 30));

    std::shared_ptr<Book> book = librarian.recommend("C++");
    ASSERT_EQ("The C++ Programming Language", book->name());
}