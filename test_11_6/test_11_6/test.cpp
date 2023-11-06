#include<iostream>
#include<string>

using namespace std;

bool IsLetter(char ch)
{
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    {
        return true;
    }
    return false;
}

string& reverseOnlyLetters(string& s) {
    auto begin = s.begin();
    auto end = s.end();
    end--;

    while (begin < end)
    {
        while (begin < end && !IsLetter(*begin))
        {
            begin++;
        }
        while (begin < end && !IsLetter(*end))
        {
            end--;
        }
        swap(*begin, *end);
        ++begin;
        --end;
    }
    return s;
}

//string addStrings(string num1, string num2) {
//    int end1 = num1.size() - 1;
//    int end2 = num2.size() - 1;
//    int next = 0;
//    string str;
//    while (end1 >= 0 || end2 >= 0)
//    {
//        int sum = 0;
//        if (end1 < 0)
//        {
//            sum = num2[end2] - '0';
//        }
//        else if (end2 < 0)
//        {
//            sum = num1[end1] - '0';
//        }
//        else
//        {
//            sum = num1[end1] + num2[end2] - '0' * 2;
//        }
//        sum += next;
//
//        if (sum / 10)
//        {
//            next = 1;
//        }
//        else
//        {
//            next = 0;
//        }
//
//        char ch = sum % 10 + '0';
//        str += ch;
//        end1--;
//        end2--;
//    }
//    reverse(str.begin(), str.end());
//    return str;
//}

string addStrings(string& num1, string& num2) {
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    int next = 0;
    string str;
    str.reserve(end1 > end2 ? end1 + 2 : end2 + 2);
    while (end1 >= 0 || end2 >= 0)
    {
        int val1 = end1 < 0 ? '0' : num1[end1--];
        int val2 = end2 < 0 ? '0' : num2[end2--];
        int sum = val1 + val2 - '0' * 2;
        sum += next;

        sum / 10 ? next = 1 : next = 0;

        str += (sum % 10 + '0');
    }

    if (next == 1)
        str += '1';
    reverse(str.begin(), str.end());
    return str;
}




//int main()
//{
//    //string str = "ab-cd";
//    //reverseOnlyLetters(str);
//    string num1 = "123";
//    string num2 = "12";
//    string ret = addStrings(num1, num2);
//    cout << ret << endl;
//	return 0;
//}



namespace kele
{
    class string
    {
    public:
        string(const char* str = "")
            :_size(strlen(str))
        {
            _capacity = _size;
            _str = new char[_size + 1];
            strcpy(_str, str);
        }

        string(const string& str)
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

        string& operator=(const string& str)
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


        ~string()
        {
            delete[] _str;
            _size = _capacity = 0;
        }

        const char* c_str()
        {
            return _str;
        }

    private:
        char* _str;
        int _size;
        int _capacity;
    };
}


int main()
{
    kele::string str1 = "abc";
    kele::string str2 = "hello word";
    str1 = str2;
    cout << str1.c_str() << endl;
    cout << str2.c_str() << endl;

    return 0;
}