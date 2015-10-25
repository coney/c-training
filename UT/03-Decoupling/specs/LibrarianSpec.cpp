#include "gmock/gmock.h"
#include "../src/Librarian.h"
#include "../mocks/BookVendorMock.h"

class LibrarianSpec : public testing::Test {
protected:
    virtual void SetUp() {
        librarian_ = std::make_shared<Librarian>();
    }

    virtual void TearDown() {
    }

    Librarian &librarian() {
        return *librarian_;
    }

    void prepareBooks()
    {
        librarian().store(Book::create("C++ Primer", 10));
        librarian().store(Book::create("The C++ Programming Language", 20));
        librarian().store(Book::create("Thinking in Java", 30));
    }

    std::shared_ptr<BookVendorMock> createBookVendor() {
        std::shared_ptr<BookVendorMock> vendor = std::make_shared<BookVendorMock>();
        EXPECT_CALL(*vendor, getBookCount())
            .WillRepeatedly(testing::Return(3));
        EXPECT_CALL(*vendor, getBookAt(0))
            .WillRepeatedly(testing::Return(Book::create("C++ Primer", 10)));
        EXPECT_CALL(*vendor, getBookAt(1))
            .WillRepeatedly(testing::Return(Book::create("The C++ Programming Language", 20)));
        EXPECT_CALL(*vendor, getBookAt(2))
            .WillRepeatedly(testing::Return(Book::create("Thinking in Java", 30)));
        EXPECT_CALL(*vendor, pay(testing::_)).Times(testing::AnyNumber());
        return vendor;
    }

    std::shared_ptr<Librarian> librarian_;
};

TEST_F(LibrarianSpec, ShouldIncreaseBookCountOnStore) {
    ASSERT_EQ(1, librarian().store(Book::create("The C Programming Language")));
    ASSERT_EQ(2, librarian().store(Book::create("Thinking in Java")));
}

TEST_F(LibrarianSpec, ShouldReduceBookCountOnBorrow) {
    prepareBooks();
    ASSERT_EQ(2, librarian().borrow("Thinking in Java"));
    ASSERT_EQ(1, librarian().borrow("C++ Primer"));
    ASSERT_EQ(0, librarian().borrow("The C++ Programming Language"));
}

TEST_F(LibrarianSpec, ShouldThrowExceptionWhenNoBookIsAvailable) {
    prepareBooks();
    ASSERT_THROW({
        librarian().borrow("Learning Python");
    }, std::invalid_argument);
}

TEST_F(LibrarianSpec, ShouldStoreBooksWhichAreNotCurrentlyInLibraryFromVendor) {
    // Librarian will check all books from the vendor
    // and then store those books which are not in the library yet

    std::shared_ptr<BookVendorMock> vendor = createBookVendor();
    librarian().store(*vendor);
    ASSERT_EQ(2, librarian().borrow("The C++ Programming Language"));
    ASSERT_EQ(1, librarian().borrow("C++ Primer"));
    ASSERT_EQ(0, librarian().borrow("Thinking in Java"));

}

TEST_F(LibrarianSpec, ShouldPayVendorForTheStoredBooks) {
    // After the librarian store the books from the vendor,
    // the librarian needs to pay for the books

    std::shared_ptr<BookVendorMock> vendor = createBookVendor();
    // Library already has "C++ Primer" in store
    librarian().store(Book::create("C++ Primer"));

    EXPECT_CALL(*vendor, pay(50)).Times(1);
    librarian().store(*vendor);
}

TEST_F(LibrarianSpec, ShouldRecommendTheMostPopularBookByKeyword) {
    prepareBooks();
    std::shared_ptr<Book> book = librarian().recommend("C++");
    ASSERT_TRUE(book);
    ASSERT_EQ("The C++ Programming Language", book->name());
}