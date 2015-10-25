#include <list>

int main()
{
	std::list<int> l1;

	for (int i = 0; i < 10; ++i)
	{
		l1.push_back(i);
	}

	return 0;
}

/*
struct _List_node_base
{
	_List_node_base* _M_next;
	_List_node_base* _M_prev;
};

template <typename _Tp>
struct _List_node : public _List_node_base
{
	_Tp _M_data;
};

template <typename _Tp>
class _List_base
{
	struct _List_impl
	{
		_List_node_base _M_node;
	};
	_List_impl _M_impl;
};

template <typename _Tp>
class list : protected _List_base< _Tp >
{};
*/
