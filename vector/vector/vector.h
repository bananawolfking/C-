#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

namespace kele
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		iterator begin(){return _start;}

		iterator end(){return _finish;}

		const_iterator begin() const{return _start;}

		const_iterator end() const{return _finish;}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				iterator tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				//memset(_finish, val, (n - size()) * sizeof(T));
				//_finish = _start + n;错误的，对于自定义类型无法赋值
				while (_finish != _start + n)
				{
					*_finish++ = val;
				}
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(_start == nullptr ? 4 : capacity() * 2);
			}
			*_finish++ = x;
		}

		void pop_back()
		{
			assert(!empty());

			--_finish;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(_start == nullptr ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;

			return pos;
		}

		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator begin = pos + 1;
			while (begin <= _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
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

		bool empty()
		{
			return _start == _finish;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

}