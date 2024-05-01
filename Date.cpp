#include<iostream>
using namespace std;


class Date
{
public:
    Date(size_t year = 0, size_t month = 0, size_t day = 0)
        :_year(year),
        _month(month),
        _day(day)
    {}

    bool operator>(const Date& d)
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

    bool operator==(const Date& d)
    {
        if (_year == d._year && _month == d._month && _day == d._day)
        {
            return true;
        }
        else
            return false;
    }

    bool operator<(const Date& d)
    {
        return !(*this == d && *this > d);
    }
private:
    size_t _year;
    size_t _month;
    size_t _day;
};

template<class T>
class Compare
{
    bool operator()(const T& a, const T& b)
    {
        return a < b;
    }
};

template<>
class Compare<Date>
{
    bool operator()(const Date& a, const Date& b)
    {
        return a < b;
    }
};



int main()
{
    Date d1(2003, 1, 5);
    Date d2(2003, 1, 7);
    cout << Compare<Date>()(d1, d2);

    
    return 0;
}