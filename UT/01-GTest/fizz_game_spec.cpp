#include "gtest/gtest.h"
extern "C" {
#include "fizz_game.h"
}

TEST(Student, ShouldSayNumberDirectly) {
    ASSERT_STREQ("1", student_say(1));
    ASSERT_STREQ("22", student_say(22));
    ASSERT_STREQ("33", student_say(33));
}