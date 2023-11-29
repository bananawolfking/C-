#include<iostream>
#include<string>
using namespace std;


//int main()
//{
//	string a = "hello world";
//
//	string b = a;
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	string c = b;
//
//	c = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	return 0;
//
//}

//void main()
//
//{
//
//	string s1 = "hello world";
//
//	string s2 = "change world";
//
//	string::iterator it = s1.begin();
//
//	//swap(s1, s2);
//
//	while (it != s1.end())
//
//	{
//		cout << *it;
//
//		cout << endl;
//	}
//
//}


//class Solution {
//public:
//    size_t Find(string& s, size_t pos)
//    {
//        size_t size = s.size();
//        for (size_t i = 0; i < size; ++i)
//        {
//            if (i != pos)
//            {
//                if (s[i] == s[pos])
//                    return i;
//            }
//        }
//        return string::npos;
//
//    }
//
//
//    int firstUniqChar(string s) {
//        size_t size = s.size();
//        size_t i = 0;
//        for (i = 0; i < size; ++i)
//        {
//            if (Find(s, i) == string::npos)
//                break;
//        }
//        if (i == size)
//            return -1;
//        return i;
//    }
//};


//int main() {
//    string str;
//    while (cin >> str)
//    {
//        int n = str.size() - 1;
//        int i = n;
//        while (i >= 0 && str[i] != ' ')
//        {
//            --i;
//        }
//        cout << (n - i);
//    }
//}

#include <algorithm>

class Solution {
public:
    string Add(const string& str1, const string& str2)
    {
        string str;
        int size1 = str1.size();
        int size2 = str2.size();
        str.reserve(size1 + size2);
        int i = 0, j = 0;
        int flag = 0;
        while (i < size1 || j < size2)
        {
            int num1 = i < size1 ? str1[i++] - '0' : 0;
            int num2 = j < size2 ? str2[j++] - '0' : 0;

           
            
            str += (num1 + num2 + flag) % 10 + '0';
            flag = (num1 + num2 + flag) / 10;
            
            
        }
        return str;
    }

    string multiply(string num1, string num2) 
    {
        string sum;
        string cur;

        int size1 = num1.size(), size2 = num2.size();
        sum.resize(size1 + size2, '0');
        cur.resize(size1 + size2, '0');
        int flag = 0;
        for (int i = size1 - 1; i >= 0; --i)
        {
            int x = num1[i] - '0';
            sum.clear();
            for (int k = i; k < size1 - 1; ++k)
            {
                sum += '0';
            }
            for (int j = size2 - 1; j >= 0; --j)
            {
                int y = num2[j] - '0';

                sum += (x * y + flag) % 10 + '0';
                flag = (x * y + flag) / 10;
            }
            sum += flag + '0';
            flag = 0;
            cur = Add(cur, sum);
        }
        reverse(cur.begin(), cur.end());
        auto it = cur.begin();
        while (it != cur.end())
        {
            if (*it != '0')
                break;
            ++it;
        }
        if (it == cur.end())
        {
            return "0";
        }
        else
        {
            string ret(it, cur.end());
            return ret;
        }
    }
};


int main()
{
    string str1 = "123456789";
    string str2 = "987654321";
    cout << Solution().multiply(str1, str2);

    return 0;
}