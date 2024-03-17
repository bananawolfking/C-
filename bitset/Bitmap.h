#pragma once
#include<vector>

namespace kele
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
			:_table(N / 8 + 1)
		{}

		void set(size_t x)
		{
			if (x > N)
				return;

			size_t index = x / 8;
			size_t pos = x % 8;
			_table[index] |= (1 << pos);
		}

		void reset(size_t x)
		{
			if (x > N)
				return;

			size_t index = x / 8;
			size_t pos = x % 8;
			_table[index] &= ~(1 << pos);
		}

		bool test(size_t x)
		{
			if (x > N)
				return false;

			size_t index = x / 8;
			size_t pos = x % 8;
			return _table[index] & (1 << pos);

		}

	private:
		vector<char> _table;
	};


	template<size_t N, class K, class Hash1, class Hash2, class Hash3>
	class BloomFilter
	{
	public:
		void set(const K& key)
		{
			size_t hash1 = Hash1()(key) % N;
			size_t hash2 = Hash2()(key) % N;
			size_t hash3 = Hash3()(key) % N;

			_set.set(hash1);
			_set.set(hash2);
			_set.set(hash3);
		}

		bool test(const K& key)
		{
			size_t hash1 = Hash1()(key) % N;
			size_t hash2 = Hash2()(key) % N;
			size_t hash3 = Hash3()(key) % N;

			return _set.test(hash1) && _set.test(hash2) && _set.test(hash3);
		}


	private:
		bitset<N> _set;
	};
}