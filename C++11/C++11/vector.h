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
		{}

		vector(int n, const T& val = T())//int n 防止报错
		{
			reserve(n);
			while (n--)
			{
				push_back(val);
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
		{
			if (v._start)
			{
				reserve(v.capacity());
				size_t v_size = v.size();
				for (size_t i = 0; i < v_size; ++i)
				{
					_start[i] = v._start[i];
				}
				_finish = _start + v_size;
			}
		}


		// 移动拷贝
		vector(vector<T>&& v)
		{
			if (v._start)
			{
				reserve(v.capacity());
				size_t v_size = v.size();
				swap(v);
				_finish = _start + v_size;
			}
		}

		//vector(const vector<T>& v)
		//{
		//	if (v._start)
		//	{
		//		vector<T> tmp(v.begin(), v.end());
		//		swap(tmp);
		//	}
		//}

		vector<T>& operator=(const vector<T>& v)
		{
			if (v._start)
			{
				delete[] _start;
				reserve(v.capacity());
				size_t v_size = v.size();
				for (size_t i = 0; i < v_size; ++i)
				{
					_start[i] = v._start[i];
				}
				_finish = _start + v_size;
				return *this;
			}
		}

		// 移动赋值
		vector<T>& operator=(vector<T>&& v)
		{
			if (v._start)
			{
				delete[] _start;
				reserve(v.capacity());
				size_t v_size = v.size();
				swap(v);
				_finish = _start + v_size;
				return *this;
			}
		}

		//vector<T>& operator=(vector<T> v)
		//{
		//	if (v._start)
		//	{
		//		swap(v);
		//		return *this;
		//	}
		//}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		iterator begin() { return _start; }

		iterator end() { return _finish; }

		const_iterator begin() const { return _start; }

		const_iterator end() const { return _finish; }

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
				size_t sz = size();//
				iterator tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i];//深拷贝
					}
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
			*_finish++ = x; // 赋值重载
		}

		void push_back(T&& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(_start == nullptr ? 4 : capacity() * 2);
			}
			//*_finish++ = move(x); // 赋值重载 需要完美转发
			*_finish++ = forward<T>(x); // 赋值重载 需要完美转发
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

		iterator erase(iterator pos)
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

		void swap(vector<T>& x)
		{
			std::swap(this->_start, x._start);
			std::swap(this->_finish, x._finish);
			std::swap(this->_end_of_storage, x._end_of_storage);
		}

		bool empty()
		{
			return _start == _finish;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	class Solution {
	public:
		vector<vector<int>> generate(int numRows)
		{
			vector<vector<int>> vv;
			vv.resize(numRows, vector<int>());
			for (int i = 0; i < numRows; ++i)
			{
				vv[i].resize(i + 1, 0);
				vv[i][0] = vv[i][i] = 1;
			}

			for (int i = 0; i < numRows; ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
					}
				}
			}

			return vv;
		}
	};

}