#include <stdio.h>

#define ARRSIZE 10
void process_array(int *arr) {
	for (int i = 0; i < ARRSIZE; ++i) {
		arr[i]++;
	}
}

int main(int argc, char **argv) {
	int arr[ARRSIZE] = {0};
	for(int i = 0; i < ARRSIZE; ++i) {
		arr[i] = i;
	}

	for(int j = 0; j < 10; ++j) {
		process_array(arr);
	}
	return 0;
}
