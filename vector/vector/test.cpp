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

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	return 0;
}