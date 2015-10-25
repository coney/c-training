#include <gmock/gmock.h>
#include "../src/BookVendor.h"

TEST(BookVendor, ShouldReturnVendorWithRandomBooksToSupply) {
	std::shared_ptr<BookVendor> vendor = BookVendor::create();
    BookList books = vendor->getBooks();
	ASSERT_GT(books.size(), 0U);

    for (BookList::const_iterator it = books.begin();
        it != books.end(); ++it) {
        std::shared_ptr<Book> book = *it;
        ASSERT_FALSE(book->name().empty());
        ASSERT_GT(book->price(), 0U);
    }
}