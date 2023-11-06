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

int main()
{
    //string str = "ab-cd";
    //reverseOnlyLetters(str);
    string num1 = "123";
    string num2 = "12";
    string ret = addStrings(num1, num2);
    cout << ret << endl;
	return 0;
}