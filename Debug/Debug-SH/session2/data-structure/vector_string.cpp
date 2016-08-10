#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

int main()
{
	srand(9527);

	std::string alphas = "abcdefghijklmnopqrstuvwxyz";

	std::vector<std::string> vec;
	for (int i = 0; i < 10; ++i)
	{
		std::random_shuffle(alphas.begin(), alphas.end());
		vec.push_back(alphas.substr(10));
	}

	return 0;
}
