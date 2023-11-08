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

        size_t capacity() const
        {
            return _capacity;
        }

        bool empty() const
        {
            return _size == 0;
        }

        const char* c_str() const
        {
            return _str;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = _capacity = 0;
        }

        void resize(size_t n, char ch)
        {
            if (n > _size)
            {
                if (n > _capacity)
                {
                    reserve(n);
                }
                memset(_str + _size, ch, n - _size);
            }
            _size = n;
            _str[_size] = '\0';
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

        void push_back(const char ch)
        {
            if (_size + 1 > _capacity)
            {
                reserve(_capacity * 2);
            }
            _str[_size++] = ch;
            _str[_size] = '\0';
        }

        string substr(size_t pos = 0, size_t len = npos) const
        {
            assert(pos <= _size);

            string ret;
            size_t size = len >= _size - pos ? _size - pos : len;
            ret.reserve(size);
            while (size--)
            {
                ret += _str[pos++];
            }
            return ret;
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
            size_t cur = _size + 1;
            while (cur > pos)//cur - 1 >= pos 
            {
                _str[cur] = _str[cur - 1];
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
            size_t cur = _size + n;
            while (cur - n + 1 > pos)//cur - n >= pos 当pos为0时会出错
            {
                _str[cur] = _str[cur - n];
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
            size_t cur = _size + n;
            while (cur - n + 1 > pos)//cur - n >= pos 当pos为0时会出错
            {
                _str[cur] = _str[cur - n];
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


        size_t find(char ch, size_t pos = 0) const
        {
            assert(pos <= _size);

            for (size_t i = pos; i < _size; ++i)
            {
                if (_str[i] == ch)
                {
                    return i;
                }
            }
            return npos;
        }

        size_t find(const char* s, size_t pos = 0) const
        {
            assert(pos <= _size);

            const char* p = strstr(_str + pos, s);
            if (p == nullptr)
            {
                return npos;
            }

            return p - _str;
        }

        size_t find(const string& s, size_t pos = 0) const
        {
            assert(pos <= _size);

            const char* p = strstr(_str + pos, s._str);
            if (p == nullptr)
            {
                return npos;
            }

            return p - _str;
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
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

    void swap(string& x, string& y)
    {
        x.swap(y);
    }

    ostream& operator<<(ostream& out, const string& s)
    {
        for (auto ch : s)
        {
            out << ch;
        }
        return out;
    }

    istream& operator>>(istream& in, string& s)
    {
        s.clear();

        //char ch = in.get();
        //while (ch != ' ' && ch != '\n')
        //{
        //    s += ch;
        //    ch = in.get();
        //}

        char buff[128];
        size_t i = 0;
        char ch = in.get();
        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            ch = in.get();
            if (i == 127)
            {
                buff[127] = '\0';
                s += buff;
                i = 0;
            }
        }

        if (i != 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }

    istream& getline(istream& in, string& s, char delim = '\n')
    {
        s.clear();

        char buff[128];
        size_t i = 0;
        char ch = in.get();
        while (ch != delim)
        {
            buff[i++] = ch;
            ch = in.get();
            if (i == 127)
            {
                buff[127] = '\0';
                s += buff;
                i = 0;
            }
        }

        if (i != 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }

}