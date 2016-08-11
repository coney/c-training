#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"

const char * default_rule(int number, int *special_numbers)
{
    static char buffer[128];
    sprintf(buffer, "%d", number);
    return buffer;
}

const char * multiple_rule(int number, int *special_numbers)
{
    static char buffer[128];
    memset(buffer, 0, sizeof(buffer));
    if (number % special_numbers[0] == 0) {
        strcat(buffer, "Fizz");
    }
    if (number % special_numbers[1] == 0) {
        strcat(buffer, "Buzz");
    }
    if (number % special_numbers[2] == 0) {
        strcat(buffer, "Whizz");
    }
    return *buffer ? buffer : NULL;
}

const char * special_word_rule(int number, int *special_numbers)
{
    if (strchr(default_rule(number, special_numbers),
        '0' + special_numbers[0])) {
        return "Fizz";
    }
    return NULL;
}
