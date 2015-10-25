#include <gmock/gmock.h>
#include "../src/BookVendor.h"

TEST(BookVendor, ShouldReturnVendorWithRandomBooksToSupply) {
    std::shared_ptr<BookVendor> vendor = BookVendor::create();
    ASSERT_GT(vendor->getBookCount(), 0U);
    for (size_t i = 0; i < vendor->getBookCount(); i++)
    {
        std::shared_ptr<Book> book = vendor->getBookAt(i);
        ASSERT_FALSE(book->name().empty());
        ASSERT_GT(book->price(), 0U);
    }
}