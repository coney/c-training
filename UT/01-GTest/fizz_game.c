#include <stdlib.h>
#include "fizz_game.h"

const char * student_say(int number)
{
    static char buffer[128];
    return itoa(number, buffer, 10);
}
