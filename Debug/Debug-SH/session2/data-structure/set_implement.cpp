#include <set>

int main()
{
	std::set<int> intset;
	for (int i = 0; i < 10; ++i)
	{
		intset.insert(i);
	}
	return 0;
}
