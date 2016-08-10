#include <map>
#include <iostream>

int main()
{
	std::map<int, int> m1;
	for (int i = 0; i < 10; ++i)
	{
		m1.insert(std::make_pair(i, i + 10));
	}
	return 0;
}

/*

template <typename _Key, typename _Tp, ...>
class map 
{
	typedef _Rb_tree<key_type, value_type, ... > _Rep_type;
	_Rep_type _M_t;
};

template<typename _Key, typename _Val, ... >
class _Rb_tree
{
	struct _Rb_tree_impl
	{
		_Key_compare		_M_key_compare;
		_Rb_tree_node_base 	_M_header;
		size_type 			_M_node_count;
	};
	_Rb_tree_impl<_Compare> _M_impl;
};

struct _Rb_tree_node_base
{
	_Rb_tree_color	_M_color;
	_Base_ptr		_M_parent;
	_Base_ptr		_M_left;
	_Base_ptr		_M_right;
};

template<typename _Val>
struct _Rb_tree_node : public _Rb_tree_node_base
{
	typedef _Rb_tree_node<_Val>* _Link_type;
	_Val _M_value_field;
};
*/

