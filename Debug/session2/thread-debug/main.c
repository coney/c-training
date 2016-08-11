#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define ARRAY_SIZE  10

int arr[ARRAY_SIZE] = {0};

void dump_array(){
  for (size_t i = 0; i < ARRAY_SIZE; i++) {
    printf("%zu ", arr[i]);
  }
  puts("\n");
}

void *thread_proc(void *arg) {
  size_t index = (size_t)arg;
  while (1) {
    ++arr[index];
    sleep(1);
  }
}

int main(int argc, char **argv) {

  for (size_t i = 0; i < ARRAY_SIZE; i++) {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_proc, (void *)i);
  }

  while (1) {
    dump_array();
    sleep(3);
  }

  return 0;
}
