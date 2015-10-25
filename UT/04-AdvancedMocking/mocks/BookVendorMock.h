#ifndef __BOOKVENDORMOCK_H__
#define __BOOKVENDORMOCK_H__

#include "../src/BookVendor.h"

class BookVendorMock : public BookVendor {
public:
    virtual ~BookVendorMock() {}
    MOCK_CONST_METHOD0(getBookCount, unsigned int());
    MOCK_CONST_METHOD1(getBookAt, std::shared_ptr<Book>(unsigned int index));
    MOCK_METHOD1(pay, void(unsigned int price));
};

#endif
