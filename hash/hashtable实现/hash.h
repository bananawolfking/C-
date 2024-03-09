#pragma once

namespace HashClose
{
	enum state
	{
		EMPTY,
		EXITE,
		DELETE
	};

	template<class K, class V>
	struct HashTable_Ndoe
	{
		//HashTable_Ndoe(const pair<K, V>& kv)
		//	:_state(EMPTY),
		//	_kv(kv)
		//{}

		pair<K, V> _kv;
		state _state = EMPTY;

	};

	template<class K, class V>
	class HashTable
	{
		typedef HashTable_Ndoe<K, V> Node;
	public:

		bool Insert(const pair<K, V>& kv)
		{
			//判断空间是否足够
			size_t _v_size = _v.size();
			if (_v_size == 0)
			{
				_v.resize(10);
			}
			else if (_n * 10 / _v_size > 7)
			{
				size_t newsize = _v_size * 2;
				HashTable<K, V> newHashTable;
				newHashTable._v.resize(newsize);
				for (int i = 0; i < _v_size; ++i)
				{
					if (_v[i]._state == EXITE)
						newHashTable.Insert(_v[i]._kv);
				}
				_v.swap(newHashTable._v);
			}

			_v_size = _v.size();
			//找到对应位置
			size_t index = kv.first % _v_size;
			//线性探测
			int x = 1;
			while (_v[index]._state == EXITE)
			{
				if (_v[index]._kv.first == kv.first)
					return false;
				index = index + x;
				index %= _v_size;
			}
			_v[index]._kv = kv;
			_v[index]._state = EXITE;
			_n++;
			return true;

		}

		Node* Find(const K& key)
		{
			size_t _v_size = _v.size();
			if (_v_size == 0)
				return nullptr;
			size_t index = key % _v_size;
			size_t flag = index;
			int x = 1;
			while (_v[index]._state != EMPTY)
			{
				if (_v[index]._state == EXITE && _v[index]._kv.first == key)
					return &_v[index];
				index = index + x;
				index %= _v_size;
				if (flag == index)
					break;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* ret = Find(key);
			if (ret == nullptr)
				return false;

			ret->_state = DELETE;
			_n--;
			return true;
		}


	private:
		vector<Node> _v;
		size_t _n = 0;
	};
}


namespace HashOpen
{
	template<class K, class V>
	struct HashTableNode
	{
		pair<K, V> _kv;
		HashTableNode<K, V>* _next;

		HashTableNode(const pair<K, V>& kv)
			:_kv(kv),
			_next(nullptr)
		{}
	};
	
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

	template<class K, class V, class HashFcn = HashFcn<K>>
	class HashTable
	{
		typedef HashTableNode<K, V> Node;
	public:
		HashTable() {}

		HashTable(const HashTable<K, V>& hs)
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
					Node* newnode = new Node(cur1->_kv);
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

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;


			HashFcn hashfcn;
			//扩容
			size_t _v_size = _v.size();
			if (_v_size == _n)
			{
				size_t newsize = GetNextSize(_v_size);
				vector<Node*> newtable(newsize, nullptr);
				
				for (auto& cur : _v)//cur类型 Node*&
				{
					while (cur)
					{
						Node* next = cur->_next;//记录当前节点的下一个

						size_t newHashTablei = hashfcn(cur->_kv.first) % newsize;//计算新表的插入位置
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
			size_t HashTablei = hashfcn(kv.first) % _v_size;
			Node* newnode = new Node(kv);
			newnode->_next = _v[HashTablei];
			_v[HashTablei] = newnode;
			_n++;
			return true;
		}

		Node* Find(const K& key)
		{
			HashFcn hashfcn;
			size_t _v_size = _v.size();
			if (_v_size == 0 || _n == 0)
				return nullptr;

			size_t HashTablei = hashfcn(key) % _v_size;
			Node* cur = _v[HashTablei];
			while (cur)
			{
				if (cur->_kv.first == key)
					return cur;
				else
					cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashFcn hashfcn;
			size_t _v_size = _v.size();
			if (_v_size == 0 || _n == 0)
				return false;

			size_t HashTablei = hashfcn(key) % _v_size;
			Node* cur = _v[HashTablei];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
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