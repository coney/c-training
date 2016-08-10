#include <string.h>

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

//void generate_random_string(const char *buffer, size_t size) {
//    while (--size) {
//        *(buffer++) = rand() % 26 + 'a';
//    }
//    *buffer = 0;
//}

int main()
{
    student_t student;
    strcpy(student.name, "Allen");
    student.age = 35;
    strcpy(student.address.city, "Xi'an");
    strcpy(student.address.street, "Jinye Rd");
    student.address.zipcode = 710000;
    return 0;
}
