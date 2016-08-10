#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>

std::string generateRandomString(int n);

class Sample
{
public:
	virtual ~Sample(){}
	Sample(){
		int sz = rand() % 3 + 1;
		for (int i = 0; i < sz; ++i)  randomStrings.push_back(generateRandomString(rand() % 5 +1));
	}

	Sample(const Sample& rhs)
	{
		randomStrings = rhs.randomStrings;
	}

private:
	std::vector<std::string> randomStrings;
};

int main()
{
	srand(9527);
	std::list<Sample> samples;
	int cnt = rand() % 3 + 1;
	for (int i = 0; i < cnt; ++i)
	{
		samples.push_back(Sample());
	}
	return 0;
}

std::string generateRandomString(int n)
{
	std::string alphas = "abcdefghijklmnopqrstuvwxyz";
	std::random_shuffle(alphas.begin(), alphas.end());
	return alphas.substr(0, n);
}
