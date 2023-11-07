#include"string.h"



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



//int main()
//{
//    kele::string str1 = "abc";
//    const kele::string str2 = "hello word";
//    str1 = str2;
//    cout << str1.c_str() << endl;
//    cout << str2.c_str() << endl;
//    for (char ch : str1)
//    {
//        cout << ch;
//        ch++;
//    }
//    cout << endl;
//
//    auto begin = str2.begin();
//    auto end = str2.end();
//    while (begin != end)
//    {
//        cout << *begin;
//        ++begin;
//    }
//    cout << endl;
//
//    kele::operator<<(cout, str1);
//    cout << str1 << endl;;
//
//    cout << (str1 < str2) << endl;
//    cout << (str1 == str2) << endl;
//
//
//    return 0;
//}


int main()
{
    kele::string s1 = "xxx";
    kele::string s2 = "hello word";

    //cout << s2.append(s1) << endl;

    //s1.push_back('x');
    //cout << s1 << endl;
    //s1.push_back('x');
    //cout << s1 << endl;
    //s1.push_back('x');
    //cout << s1 << endl;

    //cout << (s2 += s1) << endl;
    //s2 += s2;
    //s2 += "hello word";
    //s2 += '*';
    cout << s2 << endl;
    cout << s2.insert(0, '&') << endl;
    cout << s2.insert(5, "xxx") << endl;
    cout << s2.insert(5, s1) << endl;
    cout << s2.erase(0, 1) << endl;
    cout << s2.erase(4, 6) << endl;
    cout << s2.erase(9, 1) << endl;
    cout << s2.erase(1) << endl;
    return 0;
}