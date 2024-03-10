#pragma once
#include<assert.h>

template<class T>
struct HashFcn
{
	size_t operator()(const T& x)
	{
		return x;
	}
};

template<>
struct HashFcn<string>
{
	size_t operator()(const string& s)
	{
		size_t ret = 0;
		for (auto ch : s)
		{
			ret += ch;
			ret *= 31;
		}
		return ret;
	}
};

template<class T>
struct Equal_Key
{
	bool operator()(const T& key1, const T& key2)
	{
		return key1 == key2;
	}
};

namespace HashOpen
{
	template<class V>
	struct HashTableNode
	{
		typedef V value_type;

		value_type _data;
		HashTableNode<V>* _next;

		HashTableNode(const value_type& data)
			:_data(data),
			_next(nullptr)
		{}
	};

	template<class K, class V, class KeyOfValue, class HashFcn, class Pred>
	class HashTable;

	template<class K, class V, class Ptr, class Ref, class KeyOfValue, class HashFcn, class Pred>
	struct __hash_iterator
	{
		typedef HashTableNode<V> Node;
		typedef HashTable<K, V, KeyOfValue, HashFcn, Pred> Hash;
		typedef __hash_iterator<K, V, Ptr, Ref, KeyOfValue, HashFcn, Pred> Self;
		typedef __hash_iterator<K, V, V*, V&, KeyOfValue, HashFcn, Pred> iterator;

		Node* _cur;
		const Hash* _hs;

		__hash_iterator(Node* cur, const Hash* hs)
			:_cur(cur),
			_hs(hs)
		{}

		__hash_iterator(const iterator& it)
			:_cur(it._cur),
			_hs(it._hs)
		{}

		Ref operator*()
		{
			return _cur->_data;
		}
		Ptr operator->()
		{
			return &operator*();
		}
		bool operator!=(const Self& t)
		{
			return _cur != t._cur;
		}

		Self& operator++()
		{
			KeyOfValue kov;
			HashFcn hash;
			if (_cur == nullptr)
			{
				assert(1);
				return *this;
			}

			Node* next = _cur->_next;
			if (next == nullptr)
			{
				size_t _v_size = _hs->_v.size();
				size_t hashi = hash(kov(_cur->_data)) % _v_size;
				++hashi;
				_cur = nullptr;
				for (size_t i = hashi; hashi < _v_size; ++hashi)
				{
					if (_hs->_v[hashi])
					{
						_cur = _hs->_v[hashi];
						break;
					}
				}
			}
			else
			{
				_cur = next;
			}
			return *this;
		}

	};

	template<class K, class V, class KeyOfValue, class HashFcn, class Pred>
	class HashTable
	{
		template<class K, class V, class Ptr, class Ref, class KeyOfValue, class HashFcn, class Pred>
		friend struct __hash_iterator;
		typedef HashTableNode<V> Node;
		typedef HashTable<K, V, KeyOfValue, HashFcn, Pred> Self;
		typedef K key_type;
		typedef V value_type;
	public:
		typedef __hash_iterator<K, V, V*, V&, KeyOfValue, HashFcn, Pred> iterator;
		typedef __hash_iterator<K, V, const V*, const V&, KeyOfValue, HashFcn, Pred> const_iterator;

		HashTable() {}

		HashTable(const Self& hs)
			:_n(hs._n)
		{
			size_t _v_size = hs._v.size();
			_v.resize(_v_size);

			for (size_t i = 0; i < _v_size; ++i)
			{
				Node* cur1 = hs._v[i];
				Node* prev = nullptr;
				while (cur1)
				{
					Node* newnode = new Node(cur1->_data);
					if (prev)
					{
						prev->_next = newnode;
					}
					else
					{
						_v[i] = newnode;
					}
					
					cur1 = cur1->_next;
					prev = newnode;
				}
			}
		}

		~HashTable()
		{
			for (auto& cur : _v)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
			}
		}

		iterator begin()
		{
			size_t _v_size = _v.size();
			for (size_t i = 0; i < _v_size; ++i)
			{
				if (_v[i])
					return iterator(_v[i], this);
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const
		{
			size_t _v_size = _v.size();
			for (size_t i = 0; i < _v_size; ++i)
			{
				if (_v[i])
					return const_iterator(_v[i], this);
			}
			return end();
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this);//const this
		}

		size_t GetNextSize(size_t num)//质数
		{
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
			  53,         97,         193,       389,       769,
			  1543,       3079,       6151,      12289,     24593,
			  49157,      98317,      196613,    393241,    786433,
			  1572869,    3145739,    6291469,   12582917,  25165843,
			  50331653,   100663319,  201326611, 402653189, 805306457,
			  1610612741, 3221225473, 4294967291
			};
			size_t i = 0;
			for (; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > num)
					return __stl_prime_list[i];
			}

			return __stl_prime_list[i];
		}

		pair<iterator, bool> Insert(const value_type& data)
		{
			KeyOfValue kov;
			iterator it = Find(kov(data));
			if (it._cur)
				return make_pair(it, false);


			HashFcn hashfcn;
			//扩容
			size_t _v_size = _v.size();
			if (_v_size == _n)
			{
				//size_t newsize = GetNextSize(_v_size);
				size_t newsize = _v_size == 0 ? 10 : _v_size * 2;
				vector<Node*> newtable(newsize, nullptr);
				
				for (auto& cur : _v)//cur类型 Node*&
				{
					while (cur)
					{
						Node* next = cur->_next;//记录当前节点的下一个

						size_t newHashTablei = hashfcn(kov(cur->_data)) % newsize;//计算新表的插入位置
						//头插
						cur->_next = newtable[newHashTablei];//连尾
						newtable[newHashTablei] = cur;//改头

						cur = next;//cur更新，连带更改cur的值****
					}
				}
				_v.swap(newtable);
			}


			//头插
			_v_size = _v.size();
			size_t HashTablei = hashfcn(kov(data)) % _v_size;
			Node* newnode = new Node(data);
			newnode->_next = _v[HashTablei];
			_v[HashTablei] = newnode;
			_n++;
			return make_pair(iterator(newnode, this), true);
		}

		iterator Find(const key_type& key)
		{
			KeyOfValue kov;
			HashFcn hashfcn;
			Pred pred;
			size_t _v_size = _v.size();
			if (_v_size == 0 || _n == 0)
				return iterator(nullptr, this);

			size_t HashTablei = hashfcn(key) % _v_size;
			Node* cur = _v[HashTablei];
			while (cur)
			{
				if (pred(kov(cur->_data), key))
					return iterator(cur, this);
				else
					cur = cur->_next;
			}
			return iterator(nullptr, this);
		}

		bool Erase(const key_type& key)
		{
			HashFcn hashfcn;
			KeyOfValue kov;
			size_t _v_size = _v.size();
			if (_v_size == 0 || _n == 0)
				return false;

			size_t HashTablei = hashfcn(key) % _v_size;
			Node* cur = _v[HashTablei];
			Node* prev = nullptr;
			while (cur)
			{
				if (pred(kov(cur->_data), key))
				{
					if (prev == nullptr)
					{
						_v[HashTablei] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					_n--;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;

		}


	private:
		vector<Node*> _v;
		size_t _n = 0;
	};
}