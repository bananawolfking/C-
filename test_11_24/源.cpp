#include<iostream>
using namespace std;

namespace kele
{
    class Date
    {
    public:
        Date(size_t year = 0, size_t month = 0, size_t day = 0)
            :_year(year),
            _month(month),
            _day(day)
        {}

        bool operator>(const Date& d) const
        {
            if (_year > d._year)
                return true;
            else if (_year == d._year)
            {
                if (_month > d._month)
                    return true;
                else if (_month == d._month)
                {
                    if (_day > d._day)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        bool operator==(const Date& d) const
        {
            if (_year == d._year && _month == d._month && _day == d._day)
            {
                return true;
            }
            else
                return false;
        }

        bool operator<(const Date& d) const
        {
            return !(*this == d && *this > d);
        }
    private:
        size_t _year;
        size_t _month;
        size_t _day;
    };

    template<class T>
    struct less
    {
        bool operator()(const T& a, const T& b)
        {
            return a < b;
        }
    };

    template<class T>
    struct less<T*>
    {
        bool operator()(const T* a, const T* b)
        {
            return *a < *b;
        }
    };
    
    template<>
    struct less<Date>
    {
        bool operator()(const Date& a, const Date& b)
        {
            return a < b;
        }
    };

    template<class T>
    bool func( T a,   T b)
    {
        return a < b;
    }

    template<>
    bool func<Date*>( Date* a,  Date* b)
    {
        return *a < *b;
    }
}

using kele::Date;

int main()
{
    Date d1(2003, 1, 5);
    Date d2(2003, 1, 7);
    cout << kele::less<Date>()(d1, d2) << endl;
    cout << kele::less<Date*>()(&d1, &d2) << endl;

    cout << kele::less<int*>()(new int(1), new int(2));
    return 0;
}