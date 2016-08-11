
#include <cmock/cmock.h>
extern "C" {
    #include "fizz_game.h"
}
DECLARE_FUNCTION_MOCK2(DefaultRuleMock, default_rule, const char *(int, int *));
DECLARE_FUNCTION_MOCK2(MultipleRuleMock, multiple_rule, const char *(int, int *));
DECLARE_FUNCTION_MOCK2(SpecialWordRuleMock, special_word_rule, const char *(int, int *));

IMPLEMENT_FUNCTION_MOCK2(DefaultRuleMock, default_rule, const char *(int, int *));
IMPLEMENT_FUNCTION_MOCK2(MultipleRuleMock, multiple_rule, const char *(int, int *));
IMPLEMENT_FUNCTION_MOCK2(SpecialWordRuleMock, special_word_rule, const char *(int, int *));

using namespace ::testing;
TEST(Student, ShouldSayWordAccordingToRules) {
    rule_fn rules[] = {
        special_word_rule, multiple_rule, default_rule
    };

    int numbers[] = { 3, 5, 7 };
    SpecialWordRuleMock specialWordRuleMock;
    EXPECT_FUNCTION_CALL(specialWordRuleMock, (_, _)).WillRepeatedly(Return((const char *)NULL));
    EXPECT_FUNCTION_CALL(specialWordRuleMock, (3, _)).WillRepeatedly(Return("Hello"));

    MultipleRuleMock multipleRuleMock;
    EXPECT_FUNCTION_CALL(multipleRuleMock, (_, _)).WillRepeatedly(Return((const char *)NULL));
    EXPECT_FUNCTION_CALL(multipleRuleMock, (5, _)).WillRepeatedly(Return("World"));

    DefaultRuleMock defaultRuleMock;
    EXPECT_FUNCTION_CALL(defaultRuleMock, (_, _)).WillRepeatedly(Return("Nothing"));

    ASSERT_STREQ("Hello", student_say(3, numbers, rules, 3));
    ASSERT_STREQ("World", student_say(5, numbers, rules, 3));
    ASSERT_STREQ("Nothing", student_say(7, numbers, rules, 3));
}