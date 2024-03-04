#pragma once
#include"RBTree.h"

namespace kele
{
	template<class K, class V, class Compare = less<K>>
	class map
	{
	public:
		
		typedef K key_type;
		typedef V map_type;
		typedef pair<const K, V> value_type;
		
		struct _keyofvalue
		{
			const key_type& operator()(const value_type& value)
			{
				return value.first;
			}
		};

		typedef typename RBTree< key_type, value_type, _keyofvalue, Compare>::iterator iterator;
		typedef typename RBTree< key_type, value_type, _keyofvalue, Compare>::const_iterator const_iterator;
		typedef typename RBTree< key_type, value_type, _keyofvalue, Compare>::reverse_iterator reverse_iterator;
		typedef typename RBTree< key_type, value_type, _keyofvalue, Compare>::const_reverse_iterator const_reverse_iterator;

		iterator begin(){return _t.begin();}

		iterator end(){return _t.end();}

		const_iterator begin() const{return _t.begin();}

		const_iterator end() const{return _t.end();}

		reverse_iterator rbegin() { return _t.rbegin(); }

		reverse_iterator rend() { return _t.rend(); }

		const_reverse_iterator rbegin() const { return _t.rbegin(); }

		const_reverse_iterator rend() const { return _t.rend(); }

		map() {}

		map_type& operator[](const key_type& key)
		{
			return (_t.Insert(make_pair(key, map_type())).first)->second;
		}

		bool Insert(const value_type& x)
		{
			return _t.Insert(x).second;
		}

		void InOrder()
		{
			_t.InOrder();
		}

		bool RBTree_Check()
		{
			return _t.RBTree_Check();
		}

		int TreeHightMax()
		{
			return _t.TreeHightMax();
		}

		int TreeHightMin()
		{
			return _t.TreeHightMin();
		}

	private:
		RBTree<key_type, value_type, _keyofvalue, Compare> _t;
	};
}