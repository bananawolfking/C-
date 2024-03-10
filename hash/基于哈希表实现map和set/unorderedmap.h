#pragma once

#include"hashtable.h"

namespace kele
{

	template<class K, class V, class Hash = HashFcn<K>, class Pred = Equal_Key<K>>
	class unorder_map
	{
		typedef K key_type;
		typedef V data_type;
		typedef pair<const K, V> value_type;
	public:
		struct _keyofvalue
		{
			const key_type& operator()(const value_type& value)
			{
				return value.first;
			}
		};

		typedef typename HashOpen::HashTable<key_type, value_type, _keyofvalue, Hash, Pred>::iterator iterator;
		typedef typename HashOpen::HashTable<key_type, value_type, _keyofvalue, Hash, Pred>::const_iterator const_iterator;

		iterator begin()
		{
			return ht.begin();
		}

		iterator end()
		{
			return ht.end();
		}

		const_iterator begin() const
		{
			return ht.begin();
		}

		const_iterator end() const
		{
			return ht.end();
		}

		pair<iterator, bool> insert(const value_type& value)
		{
			return ht.Insert(value);
		}

		iterator find(const key_type& key)
		{
			return ht.Find(key);
		}

		bool erase(const key_type& key)
		{
			return ht.Erase(key);
		}

		data_type& operator[](const key_type& key)
		{
			return (ht.Insert(make_pair(key, data_type())).first)->second;
		}

	private:
		HashOpen::HashTable<key_type, value_type, _keyofvalue, Hash, Pred> ht;
	};
}