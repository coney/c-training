#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux. See feature_test_macros(7) */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>


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



typedef struct list_node {
    struct list_node *prev;
    struct list_node *next;
    char payload[];
} list_node_t;

#define list_get_payload(node, type) ((type*)(node)->payload)

list_node_t *list_create_node(const size_t payload_size) {
    return (list_node_t *)calloc(1, sizeof(list_node_t) + payload_size);
}

void list_add_tail(list_node_t *head, list_node_t *node) {
    head->next = node;
    node->prev = head;
}

list_node_t *generate_student_node() {
    list_node_t * node = list_create_node(sizeof(student_t));
    init_student(list_get_payload(node, student_t));
    return node;
}

int main(int argc, char **argv) {

    list_node_t *head = generate_student_node();
    list_node_t *current_node = head;
    for (size_t i = 0; i < 7; i++) {
        list_node_t * node = generate_student_node();
        list_add_tail(current_node, node);
        current_node = node;
    }
    return 0;
}
