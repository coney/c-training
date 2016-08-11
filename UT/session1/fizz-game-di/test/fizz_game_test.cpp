
#include <cmock/cmock.h>
extern "C" {
    #include "fizz_game.h"
}

using namespace ::testing;

static int numbers[] = { 3,5,7 };

TEST(default_rule, ShouldReturnNumberDirectly) {
    ASSERT_STREQ("1", default_rule(1, numbers));
    ASSERT_STREQ("2", default_rule(2, numbers));
    ASSERT_STREQ("13", default_rule(13, numbers));

}

TEST(multiple_rule, ShouldReturnWordsAccordingToMultiple) {
    ASSERT_STREQ("Fizz", multiple_rule(3, numbers));
    ASSERT_STREQ("BuzzWhizz", multiple_rule(35, numbers));
    ASSERT_STREQ("FizzBuzzWhizz", multiple_rule(105, numbers));
    ASSERT_EQ(NULL, special_word_rule(2, numbers));

}

TEST(special_word_rule, ShouldReturnWordAccordingToSpecialNumber) {
    ASSERT_STREQ("Fizz", special_word_rule(3, numbers));
    ASSERT_STREQ("Fizz", special_word_rule(13, numbers));
    ASSERT_STREQ("Fizz", special_word_rule(35, numbers));
    ASSERT_EQ(NULL, special_word_rule(9, numbers));
}



TEST(Student, ShouldSayWordAccordingToRules) {
    rule_fn rules[] = {
        special_word_rule, multiple_rule, default_rule
    };

    ASSERT_STREQ("1", student_say(1, numbers, rules, 3));
    ASSERT_STREQ("Fizz", student_say(3, numbers, rules, 3));
    ASSERT_STREQ("Buzz", student_say(5, numbers, rules, 3));
    ASSERT_STREQ("Whizz", student_say(7, numbers, rules, 3));
    ASSERT_STREQ("FizzBuzz", student_say(15, numbers, rules, 3));
    ASSERT_STREQ("FizzBuzzWhizz", student_say(105, numbers, rules, 3));
    ASSERT_STREQ("Fizz", student_say(35, numbers, rules, 3));
}