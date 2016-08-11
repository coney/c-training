#include <stdio.h>
#include <stdlib.h>


typedef struct _address {
    char city[10];
    char street[20];
    int  zipcode;
} address_t;

typedef struct _student {
    char name[10];
    int age;
    address_t address;
} student_t;


void _generate_random_string(const char *buffer, size_t size) {
    char *buf = (char *)buffer;
    while (--size) {
        *(buf++) = rand() % 26 + 'a';
    }
    *buf = 0;
}

#define generate_random_string(buffer) _generate_random_string(buffer, sizeof(buffer))

void init_student(student_t *s) {
    generate_random_string(s->name);
    s->age = rand() % 40 + 20;
    generate_random_string(s->address.city);
    generate_random_string(s->address.street);
    s->address.zipcode = 700000 + rand() % 100000;
}

int main(int argc, char **argv) {
    const size_t count = 10;
    student_t * students = (student_t *)calloc(count, sizeof(student_t));
    for (size_t i = 0; i < count; i++)
    {
        init_student(students + i);
    }
    
    return 0;
}
