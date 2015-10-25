struct SubStruct 
{
	int *p;
	int len;

	SubStruct() {
		len = 2;
		p = new int[len];
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
	Sample s(3);
	return 0;
}
