#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<string> date = { "", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    void Combinations(const string& digits, int dt, vector<string>& ret, string str)
    {
        if (dt == digits.size())
        {
            ret.push_back(str);
            return;
        }

        int num = digits[dt] - '0';

        for (auto x : date[num])
        {
            Combinations(digits, dt + 1, ret, str + x);// str + x 这里是+ 不是+= 至关重要的
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
        {
            return ret;
        }
        string str;
        Combinations(digits, 0, ret, str);
        return ret;
    }
};

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//
//	return 0;
//}

#include"vector.h"
template<class X>
void Print(const kele::vector<X>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    auto it = v.begin();//?
    //kele::vector<int>::const_iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << endl;
}

void test1()
{
    kele::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);

    Print(v);

    v.pop_back();
    v.pop_back();
    v.pop_back();
    Print(v);

    v.resize(20, 0);
    Print(v);

    auto pos = find(v.begin(), v.end(), 0);
    v.insert(pos, 30);
    Print(v);
    pos = find(v.begin(), v.end(), 0);
    v.erase(pos);
    Print(v);
}

void test2()
{
    kele::vector<string> v;
    v.resize(10, "nihao");
    Print(v);
    auto pos = find(v.begin(), v.end(), "nihao");
    v.insert(pos, "hello");
    Print(v);
}

int main()
{
    //test2();
    return 0;
}