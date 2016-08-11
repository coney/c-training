
#include <cmock/cmock.h>
extern "C" {
    #include "fizz_game.h"
}

TEST(Student, ShouldSayNumberDirectly) {
    int numbers[] = { 3, 5, 7 };
    ASSERT_STREQ("1", student_say(1, numbers));
    ASSERT_STREQ("2", student_say(2, numbers));
    ASSERT_STREQ("23", student_say(23, numbers));
}

TEST(Student, ShouldSayWordForSpecialNumber) {
    // TODO - write test case and make it green
}