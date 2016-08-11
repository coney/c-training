#include <stdio.h>
#include <stdlib.h>
#include "fizz_game.h"

const char * student_say(int number, int special_numbers[], rule_fn rules[], size_t rule_count)
{
    for (size_t i = 0; i < rule_count; i++)
    {
        const char *result = rules[i](number, special_numbers);
        if (result) {
            return result;
        }
    }
    return NULL;
}
