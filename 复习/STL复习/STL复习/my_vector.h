#pragma once
#include <cstring>
#include <cassert>

namespace kele
{
	template<class T>
	class vector
	{
		typedef T* iterator;
	public:
		iterator begain() { return _start; }
		iterator end() { return _finish; }

		vector():_start(nullptr), _finish(nullptr), _end(nullptr)
		{}

		vector(size_t n, T val = T()) :vector()
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = val;
			}
			_finish = _start + n;
		}

		vector(const vector& v) :vector()
		{
			reserve(v.size());
			_finish = _start + v.size();
			for (size_t i = 0; i < v.size(); ++i)
			{
				operator[](i) = v[i];
			}
		}

		~vector()
		{
			delete[] _start;
		}

		void push_back(T val)
		{
			insert(_finish, val);
		}

		void pop_back()
		{
			erase(_finish - 1);
		}

		void insert(iterator pos, T val = T())
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish + 1 > _end)
			{
				size_t pos_size = pos - _start;
				reserve(size() + 1);
				pos = _start + pos_size;
			}
			iterator cur = _finish;
			while (cur != pos)
			{
				*cur = *(cur - 1);
				--cur;
			}
			*pos = val;
			_finish += 1;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator cur = pos;
			while (cur != _finish)
			{
				*cur = *(cur + 1);
				++cur;
			}
			_finish -= 1;
			return pos;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const 
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t newcapacity)
		{
			size_t capacity = _end - _start;
			size_t size = _finish - _start;
			if (capacity < newcapacity)
			{
				newcapacity = newcapacity < 2 * capacity ? 2 * capacity : newcapacity;
				T* newv = new T[newcapacity];
				if(_start)
					memcpy(newv, _start, size * sizeof(T));
				delete[] _start;
				_start = newv;
				_end = newv + newcapacity;
				_finish = _start + size;
			}
		}

		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _end - _start; }


	private:
		iterator _start;
		iterator _finish;
		iterator _end;
	};
}