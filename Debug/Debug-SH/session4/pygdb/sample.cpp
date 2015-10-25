#include <stdlib.h>

struct SubStruct
{
	int *p;
	int len;

	SubStruct() {
		len = rand() % 3 + 1;
		p = new int[len];
		for (int i = 0; i < len; ++i) {
			p[i] = rand() % 10;
		}
	}
};

class Sample 
{
public:
	Sample(int len) {
		length = len;
		data = new SubStruct[len];
	}
private:
	int length;
	SubStruct* data;
};

int main() {
	srand(9527);
	Sample s(3);
	return 0;
}
