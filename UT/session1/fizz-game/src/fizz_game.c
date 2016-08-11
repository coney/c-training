#include <stdio.h>
#include <stdlib.h>
#include "fizz_game.h"

const char * student_say(int number, int special_numbers[])
{
    static char buf[128];
    sprintf(buf, "%d", number);
    return buf;
}
