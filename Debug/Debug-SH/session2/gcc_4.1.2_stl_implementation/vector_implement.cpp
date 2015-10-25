
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i);
	}

	return 0;
}

/*

template <typename _Tp>
class _Vector_base
{
	struct _Vector_impl
	{
		_Tp*	_M_start;
		_Tp*	_M_finish;
		_Tp*	_M_end_of_storage;
	};

public:
	_Vector_impl _M_impl;
}

template <typename _Tp>
class vector : public _Vector_base< _Tp >
{
};

*/

