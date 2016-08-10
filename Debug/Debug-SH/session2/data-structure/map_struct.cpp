#include <map>
#include <set>
#include <string>
#include <time.h>
#include <algorithm>

std::string generateRandomString(int n);

class Sample
{
public:
	Sample() {
		v1 = rand() % 10000;
		v2 = rand() % 5 + 1;
		for (int i = 0; i < v2; ++i) {
			strs.insert(generateRandomString(5));
		}
	}
	int getV1() { return v1; }
private:
	int		v1;
	short	v2;
	std::set<std::string> strs;
};

int main()
{
	srand(9527);

	std::map<int, Sample> samples;
	for (int i = 0; i < 7; ++i)	{
		Sample s;
		if (samples.count(s.getV1()) == 0) {
			samples[s.getV1()] = s;
		}
	}
	return 0;
}

std::string generateRandomString(int n)
{
	std::string alphas = "abcdefghijklmnopqrstuvwxyz";
	std::random_shuffle(alphas.begin(), alphas.end());
	return alphas.substr(0, n);
}
