// É¾³ý¸üÐÂ
//#include <iostream>
//using namespace std;
//
//size_t retday(size_t year, size_t month)
//{
//    size_t arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
//    {
//        arr[2] = 29;
//    }
//    return arr[month];
//}
//
//class Date
//{
//    friend ostream& operator<<(ostream& out, const Date& d);
//public:
//    Date(size_t year = 0, size_t month = 0, size_t day = 0)
//        :_year(year),
//        _month(month),
//        _day(day)
//    {
//        size_t month_day = retday(_year, _month);
//        while (_day > month_day)
//        {
//            _day -= month_day;
//            _month++;
//            if (_month == 13)
//            {
//                _month = 1;
//                _year++;
//            }
//            month_day = retday(_year, _month);
//        }
//    }
//
//private:
//    size_t _year;
//    size_t _month;
//    size_t _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//    printf("%04zu-%02zu-%02zu", d._year, d._month, d._day);
//    return out;
//}
//
//
//int main()
//{
//    int year = 0, month = 1, day = 0;
//    while (cin >> year >> day)
//    {
//        Date d(year, month, day);
//        cout << d << endl;
//    }
//}



//#include <iostream>
//using namespace std;
//
//size_t retday(size_t year, size_t month)
//{
//    size_t arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
//    {
//        arr[2] = 29;
//    }
//    return arr[month];
//}
//
//int year_day(size_t year)
//{
//    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
//        return 366;
//    return 365;
//
//}
//
//class Date
//{
//    friend ostream& operator<<(ostream& out, const Date& d);
//public:
//    Date(size_t year = 0, size_t month = 0, size_t day = 0)
//        :_year(year),
//        _month(month),
//        _day(day)
//    {}
//
//    bool operator>(const Date& d)
//    {
//        if (_year > d._year)
//            return true;
//        else if (_year == d._year)
//        {
//            if (_month > d._month)
//                return true;
//            else if (_month == d._month)
//            {
//                if (_day > d._day)
//                {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    Date& operator--()
//    {
//        --_day;
//        if (_day == 0)
//        {
//            _month--;
//            if (_month == 0)
//            {
//                --_year;
//                _month = 12;
//            }
//            _day = retday(_year, _month);
//        }
//        return *this;
//    }
//
//    int operator-(const Date& d)
//    {
//        Date big = d;
//        Date little = *this;
//        int sign = 1;
//        if (*this > d)
//        {
//            big = *this;
//            little = d;
//            sign = -1;
//        }
//
//        int ret = 0;
//
//        while (big._year > little._year + 1)
//        {
//            ret += year_day(--big._year);
//        }
//
//        while (big > little)
//        {
//            --big;
//            ++ret;
//        }
//
//        return sign * ret;
//    }
//
//private:
//    size_t _year;
//    size_t _month;
//    size_t _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//    printf("%04zu-%02zu-%02zu", d._year, d._month, d._day);
//    return out;
//}
//
//
//int main()
//{
//    char str[8];
//    int year = 0, month = 0, day = 0;
//    while (cin >> str)
//    {
//        year = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
//        month = (str[4] - '0') * 10 + (str[5] - '0');
//        day = (str[6] - '0') * 10 + (str[7] - '0');
//        Date d1(year, month, day);
//        while (cin >> str)
//        {
//            year = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
//            month = (str[4] - '0') * 10 + (str[5] - '0');
//            day = (str[6] - '0') * 10 + (str[7] - '0');
//            Date d2(year, month, day);
//            cout << (d2 - d1) << endl;
//        }
//    }
//}

//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    Solution()
//    {
//        sum += count--;
//    }
//
//    int Sum_Solution(int n) {
//        count = n;
//        sum = 0;
//        new Solution[n]();
//        return sum;
//    }
//private:
//    static int sum;
//    static int count;
//};
//
//int Solution::sum = 0;
//int Solution::count = 0;
//
//int main()
//{
//    cout << Solution().Sum_Solution(5);
//    return 0;
//}

//#include<iostream>
//#include<queue>
//using namespace std;
//
//class MyStack {
//public:
//    MyStack() {}
//
//    void push(int x) {
//        if (!q1.empty())
//        {
//            q1.push(x);
//        }
//        else
//        {
//            q2.push(x);
//        }
//    }
//
//    int pop() {
//        int ret = 0;
//        auto& empty = q1;
//        auto& unempty = q2;
//        if (q2.empty())
//        {
//            swap(empty, unempty);
//        }
//
//        while (unempty.size() != 1)
//        {
//            empty.push(unempty.front());
//            unempty.pop();
//        }
//        ret = unempty.front();
//        unempty.pop();
//        return ret;
//    }
//
//    int top() {
//        if (!q1.empty())
//        {
//            return q1.back();
//        }
//        else
//        {
//            return q2.back();
//        }
//    }
//
//    bool empty() {
//        return q1.empty() && q2.empty();
//    }
//private:
//    queue<int> q1;
//    queue<int> q2;
//};
//
//int main()
//{
//    MyStack st;
//    st.push(1);
//    st.push(1);
//    st.top();
//    st.pop();
//    st.pop();
//    st.empty();
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//    char s[101];
//    while (cin >> s)
//    {
//        int i = 0, j = 1;
//        while (s[i])
//        {
//            while (s[j] && s[i] != s[j])
//            {
//                j++;
//            }
//            if (s[j] && s[i] != s[j])
//            {
//                break;
//            }
//            else
//            {
//                ++i;
//                j = i + 1;
//            }
//        }
//        if (s[i])
//        {
//            cout << s[i];
//        }
//        else
//        {
//            cout << -1;
//        }
//
//    }
//}


#include <iostream>
using namespace std;

int main() {
    string s;
    s.reserve(100);
    while (cin >> s)
    {
        int i = 0;
        for (i = 0; i < s.size(); ++i)
        {
            size_t count = 0;
            size_t pos = 0;
            while (pos != s.npos)
            {
                pos = s.find_first_of(s[i], pos);
                if (pos != s.npos)
                {
                    ++count;
                    ++pos;
                }   
            }
            if (count == 1)
            {
                cout << s[i];
                break;
            }
        }
        if (i == s.size())
            cout << -1;

    }
}

