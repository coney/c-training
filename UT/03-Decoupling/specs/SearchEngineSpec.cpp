#include <gmock/gmock.h>
#include "../src/SearchEngine.h"

TEST(SearchEngine, ShouldReturnBooksAccordingToKeywords) {
    BookStore store;
    store["C++ Primer"] = Book::create("C++ Primer");
    store["The C++ Programming Language"] = Book::create("The C++ Programming Language");
    store["Thinking in Java"] = Book::create("Thinking in Java");

    BookList bookList = SearchEngine::search(store, "C++");

    ASSERT_EQ(2, bookList.size());
    ASSERT_EQ("C++ Primer", bookList.front()->name());
    ASSERT_EQ("The C++ Programming Language", bookList.back()->name());
}