#include <iostream>
#include <string>

int main()
{
	std::string s = "0123456789";
	std::cout << sizeof(s) << std::endl;
	return 0;
}

/*
struct string
{
	struct Alloc
	{
		char* _M_p;
	};

	Alloc _M_dataplus;
};

*/
