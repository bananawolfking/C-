#pragma once
#include <iostream>
#include <cstring>

namespace kele
{
	class string
	{
		friend std::ostream& operator<<(std::ostream& out, const string& str);
		//friend istream& operator>>(istream& in, const string& str);
	public:
		string() : _str(nullptr), _size(0), _capacity(0)
		{}

		string(const char* str) :string()
		{
			size_t sz = strlen(str);
			_str = new char[sz + 1] {0};
			strcpy(_str, str);
			_size = sz;
			_capacity = sz + 1;
		}

		string(const string& str)
			: string(str.c_str())
		{}

		string& operator==(string str)
		{
			if(this != &str)
				swap(str);
			return *this;
		}

		~string()
		{
			delete[] _str;
		}

		string& operator+=(const string& str)
		{
			size_t sz = strlen(str.c_str());
			if (sz + _size + 1 > _capacity)
			{
				reserve(_capacity * 2);
			}
			strcpy(_str + _size, str.c_str());
			return *this;
		}

		char& operator[](size_t pos)
		{
			return *(_str + pos);
		}

		void reserve(size_t newsize)
		{
			if (newsize > _capacity)
			{
				char* str = new char[newsize] {0};
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_capacity = newsize;
			}
		}

		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}

		const char* c_str() const 
		{
			return _str;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t string::npos = -1;

	//ostream& operator<<(ostream& out, const string& str)
	//{

	//}

	std::ostream& operator << (std::ostream& out, const string& d)
	{
		out << d.c_str();
		return out;
	}

}