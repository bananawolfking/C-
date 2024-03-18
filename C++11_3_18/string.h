#pragma once

#include<iostream>
#include<assert.h>


using namespace std;

namespace kele
{
    class string
    {
    public:
        string(const char* str = "")//构造
            :_size(strlen(str))
        {
            cout << "构造" << endl;
            _capacity = _size == 0 ? 3 : _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        string(const string& str)//拷贝构造
            :_str(nullptr)
        {
            cout << "string(const string & str)//拷贝构造" << endl;
            string tmp(str._str);
            swap(tmp);
        }

        string(string&& str)//移动构造
            :_str(nullptr),
            _size(0),
            _capacity(0)
        {
            cout << "string(string&& str)//移动构造" << endl;
            swap(str);
        }

        string& operator=(string& str)//赋值重载
        {
            if (this != &str)
            {
                cout << "string& operator=(string str)//赋值重载" << endl;
                string tmp(str._str);
                swap(tmp);
                return *this;
            }
        }

        string& operator=(string&& str)//移动赋值重载
        {
            if (this != &str)
            {
                cout << "string& operator=(string&& str)//移动赋值重载" << endl;
                swap(str);
                return *this;
            }
        }

        void reserve(size_t n = 0)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        string& operator+=(const string& s)
        {
            size_t n = s._size;
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            strcpy(_str + _size, s._str);
            _size += n;
            return *this;
        }

        string operator+(const string& str)
        {
            string tmp(_str);
            tmp += str;
            return tmp;
        }

        ~string()
        {
            delete[] _str;
            _size = _capacity = 0;
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };
}