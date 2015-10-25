#include "gtest/gtest.h"
#include "Librarian.h"

TEST(Librarian, ShouldIncreaseBookCountOnStore) {
	Librarian librarian;
	ASSERT_EQ(1, librarian.store("C++ Primer"));
	ASSERT_EQ(2, librarian.store("The C++ Programming Language"));
	ASSERT_EQ(3, librarian.store("Thinking in Java"));
}

TEST(Librarian, ShouldReduceBookCountOnBorrow) {
	Librarian librarian;
	librarian.store("C++ Primer");
	librarian.store("The C++ Programming Language");
	librarian.store("Thinking in Java");

	ASSERT_EQ(2, librarian.borrow("Thinking in Java"));
	ASSERT_EQ(1, librarian.borrow("C++ Primer"));
	ASSERT_EQ(0, librarian.borrow("The C++ Programming Language"));

}

TEST(Librarian, ShouldThrowExceptionWhenNoBookIsAvailable) {
	// how to assert an exception, look up the document
}