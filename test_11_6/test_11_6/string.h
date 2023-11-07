#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

namespace kele
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str + _size;
        }

        string(const char* str = "")//构造
            :_size(strlen(str))
        {
            _capacity = _size == 0 ? 3 : _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        string(const string& str)//拷贝构造
            :_size(str._size),
            _capacity(str._capacity)
        {
            _str = new char[_size + 1];
            strcpy(_str, str._str);
        }

        //string& operator=(const string& str)
        //{
        //    _size = str._size;
        //    if (_capacity < str._capacity)
        //    {
        //        _capacity = str._capacity;
        //        char* temp = (char*)realloc(_str, _capacity + 1);
        //        if (temp == nullptr)
        //        {
        //            perror("relloc fail");
        //            exit(-1);
        //        }
        //        _str = temp;
        //    }
        //    strcpy(_str, str._str);
        //    //memcpy(_str, str._str, _size + 1);
        //    return *this;
        //}

        string& operator=(const string& str)//赋值重载
        {
            if (this != &str)
            {
                delete[] _str;
                _str = new char[str._capacity + 1];
                _size = str._size;
                _capacity = str._capacity;
                strcpy(_str, str._str);
                return *this;
            }
        }

        char& operator[](size_t x)
        {
            return _str[x];
        }

        const char& operator[](size_t x) const
        {
            return _str[x];
        }

        ~string()
        {
            delete[] _str;
            _size = _capacity = 0;
        }

        size_t size() const
        {
            return _size;
        }

        bool empty() const
        {
            return _size == 0;
        }

        const char* c_str() const
        {
            return _str;
        }

        void reserve(size_t n = 0)
        {
            assert(n >= _size);
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }

        void push_back(const char ch)
        {
            if (_size + 1 > _capacity)
            {
                reserve(_capacity * 2);
            }
            _str[_size++] = ch;
            _str[_size] = '\0';
        }

        string& append(const char* s)
        {
            size_t n = strlen(s);
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            strcpy(_str + _size, s);
            _size += n;
            return *this;
        }

        string& append(const string s)
        {
            size_t n = s.size();
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            strcpy(_str + _size, s._str);
            _size += n;
            return *this;
        }

        string& operator+=(const char ch)
        {
            if (_size + 1 > _capacity)
            {
                reserve(_capacity * 2);
            }
            _str[_size++] = ch;
            _str[_size] = '\0';
            return *this;
        }

        string& operator+=(const char* s)
        {
            size_t n = strlen(s);
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            strcpy(_str + _size, s);
            _size += n;
            return *this;
        }

        string& operator+=(const string s)
        {
            size_t n = s.size();
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            strcpy(_str + _size, s._str);
            _size += n;
            return *this;
        }

        string& insert(size_t pos, const char ch)
        {
            assert(pos <= _size);

            if (_size + 1 > _capacity)
            {
                reserve(_capacity * 2);
            }
            int cur = _size;
            while (cur >= (int)pos)
            {
                _str[cur + 1] = _str[cur];
                cur--;
            }
            _str[pos] = ch;
            ++_size;
            return *this;
        }

        string& insert(size_t pos, const char* s)
        {
            assert(pos <= _size);

            size_t n = strlen(s);
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            int cur = _size;
            while (cur >= (int)pos)
            {
                _str[cur + n] = _str[cur];
                cur--;
            }
            for (int i = 0 ; i < n; i++)
            {
                _str[pos + i] = s[i];
            }
            _size += n;
            return *this;
        }

        string& insert(size_t pos, const string s)
        {
            assert(pos <= _size);

            size_t n = s.size();
            if (_size + n > _capacity)
            {
                reserve(_capacity + n);
            }
            int cur = _size;
            while (cur >= (int)pos)
            {
                _str[cur + n] = _str[cur];
                cur--;
            }
            for (int i = 0; i < n; i++)
            {
                _str[pos + i] = s[i];
            }
            _size += n;
            return *this;
        }

        string& erase(size_t pos, size_t len = npos)
        {
            assert(pos <= _size);

            if (len >= (_size - pos))
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                size_t cur = pos;
                while ((cur + len) <= _size)
                {
                    _str[cur] = _str[cur + len];
                    ++cur;
                }
                _size -= len;
            }
            return *this;
        }


        bool operator<(const string s) const
        {
            return strcmp(_str, s._str) < 0;
        }

        bool operator==(const string s) const
        {
            return strcmp(_str, s._str) == 0;
        }

        bool operator>(const string s) const
        {
            return !(*this < s || *this == s);
        }

        bool operator>=(const string s) const
        {
            return !(*this < s);
        }

        bool operator<=(const string s) const
        {
            return *this < s || *this == s;
        }

        bool operator!=(const string s) const
        {
            return !(*this == s);
        }



    private:
        char* _str;
        size_t _size;
        size_t _capacity;

        static const size_t npos;
    };

    const size_t string::npos = -1;

    ostream& operator<<(ostream& out, string& s)
    {
        out << s.c_str();
        return out;
    }

}