
// 删除更新
//#include<iostream>
//#include<vector>
//#include<stack>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    bool opera_test(char ch)
//    {
//        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == ' ')
//            return true;
//        return false;
//    }
//
//    bool opera_compare(char c1, char c2)//c1{+-*/(}c2{+-*/}
//    {
//        if (c1 == '(')
//            return true;
//        if (c2 == '+' || c2 == '-')
//            return false;
//        if (c1 == '+' || c1 == '-')
//            return true;
//        else
//            return false;
//    }
//
//    int evalRPN(vector<string>& tokens) {
//        stack<int> st;
//        for (auto& str : tokens)
//        {
//            if (!(str == "+" || str == "-" || str == "*" || str == "/"))
//            {
//                st.push(stoi(str));
//            }
//            else
//            {
//                int left = st.top();
//                st.pop();
//                int right = st.top();
//                st.pop();
//
//                switch (str[0])
//                {
//                case '+':
//                    st.push(right + left);
//                    break;
//                case '-':
//                    st.push(right - left);
//                    break;
//                case '*':
//                    st.push(right * left);
//                    break;
//                case '/':
//                    st.push(right / left);
//                    break;
//                }
//            }
//        }
//        return st.top();
//    }
//
//    int calculate(string s, vector<string>& vs) {
//        /*vector<string> vs;*/
//        stack<char> st;
//        auto p1 = s.begin();
//        auto p2 = p1 + 1;
//        int flag = 0;
//        int sign = 1;
//        while (p2 != s.end())
//        {
//            if (opera_test(*p1))
//            {
//                char ch = *p1; 
//                if (ch == ' ');//空格处理
//                else if (ch == '-' && p1 == s.begin())
//                {
//                    vs.push_back(string(1, '0'));
//                    st.push(ch);
//                }
//                else if (st.empty() || ch == '(')//空栈就入栈 或者 '('就入栈
//                {  
//                    st.push(ch);
//                    flag = 1;
//                }
//                else if (ch == ')')// ')'特殊处理
//                {
//                    while (st.top() != '(')
//                    {
//                        vs.push_back(string(1, st.top()));
//                        st.pop();
//                    }
//                    st.pop();
//                }
//                else //{ +-*/ }
//                {
//                    if (flag == 1 && ch == '-')
//                    {
//                        sign = -1;
//                    }
//                    else
//                    {
//                        while (!st.empty() && !opera_compare(st.top(), ch))
//                        {
//                            vs.push_back(string(1, st.top()));
//                            st.pop();
//                        }
//                        st.push(ch);
//                    }
//                }
//                ++p1;
//                ++p2;
//            }
//            else//数字字符串
//            {
//                flag = 0;
//
//                while (p2 != s.end() && !opera_test(*p2))
//                {
//                    ++p2;
//                }
//
//                if (sign == -1)
//                {
//                    string s = "-";
//                    vs.push_back(s += string(p1, p2));
//                }
//                else
//                    vs.push_back(string(p1, p2));
//
//                sign = 1;
//
//                if (p2 != s.end())
//                {
//                    p1 = p2++;
//                }
//                    
//            }
//        }
//        if (p2 - p1 != 1);
//        else if (opera_test(*p1))//操作符
//        {
//            char ch = *p1;
//            if (ch == ' ');//空格处理   
//            else if (ch == ')')// ')'特殊处理
//            {
//                while (st.top() != '(')
//                {
//                    vs.push_back(string(1, st.top()));
//                    st.pop();
//                }
//                st.pop();
//            }
//        }
//        else//数字字符串
//        {
//            vs.push_back(string(p1, p2));
//        }
//
//        while (!st.empty())
//        {
//            vs.push_back(string(1, st.top()));
//            st.pop();
//        }
//
//        return evalRPN(vs);
//    }
//};
//
//int main()
//{
//	//string s = "hello word";
//	//auto p = s.begin();
//	//auto p1 = s.begin() + 5;
//	//string s1(p, p1);
//	//cout << s1 << endl;
//    string s1 = "- (3 - (- (4 + 5) ) )";
//    vector<string> vs1;
//    auto x = Solution().calculate(s1, vs1);
//    for (auto& e : vs1)
//    {
//        cout << e <<endl;
//    }
//    cout << x << endl;
//    
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<stack>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    bool opera_test(char ch)
//    {
//        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == ' ')
//            return true;
//        return false;
//    }
//
//    bool opera_compare(char c1, char c2)//c1{+-*/(}c2{+-*/}
//    {
//        if (c1 == '(')
//            return true;
//        if (c2 == '+' || c2 == '-')
//            return false;
//        if (c1 == '+' || c1 == '-')
//            return true;
//        else
//            return false;
//    }
//
//    int evalRPN(vector<string>& tokens) {
//        stack<int> st;
//        for (auto& str : tokens)
//        {
//            if (!(str == "+" || str == "-" || str == "*" || str == "/"))
//            {
//                st.push(stoi(str));
//            }
//            else
//            {
//                int left = st.top();
//                st.pop();
//                int right = st.top();
//                st.pop();
//
//                switch (str[0])
//                {
//                case '+':
//                    st.push(right + left);
//                    break;
//                case '-':
//                    st.push(right - left);
//                    break;
//                case '*':
//                    st.push(right * left);
//                    break;
//                case '/':
//                    st.push(right / left);
//                    break;
//                }
//            }
//        }
//        return st.top();
//    }
//
//    int calculate(string s, vector<string>& vs) {
//        /*vector<string> vs;*/
//        stack<char> st;
//        auto p1 = s.begin();
//        auto p2 = p1 + 1;
//        int flag = 0;
//        int sign = 0;
//        while (p2 != s.end())
//        {
//            if (opera_test(*p1))
//            {
//                char ch = *p1;
//                if (ch == ' ');//空格处理
//                else if (ch == '-' && p1 == s.begin())
//                {
//                    vs.push_back(string(1, '0'));
//                    st.push(ch);
//                }
//                else if (st.empty() || ch == '(')//空栈就入栈 或者 '('就入栈
//                {
//                    st.push(ch);
//                    flag = 1;
//                }
//                else if (ch == ')')// ')'特殊处理
//                {
//                    while (st.top() != '(')
//                    {
//                        vs.push_back(string(1, st.top()));
//                        st.pop();
//                    }
//                    st.pop();
//                }
//                else //{ +-*/ }
//                {
//                    if (flag == 1 && ch == '-')
//                    {
//                        vs.push_back(string(1, '0'));
//                        st.push(ch);
//                    }
//                    else
//                    {
//                        while (!st.empty() && !opera_compare(st.top(), ch))
//                        {
//                            vs.push_back(string(1, st.top()));
//                            st.pop();
//                        }
//                        st.push(ch);
//                    }
//                }
//                ++p1;
//                ++p2;
//            }
//            else//数字字符串
//            {
//                flag = 0;
//
//                while (p2 != s.end() && !opera_test(*p2))
//                {
//                    ++p2;
//                }
//
//                vs.push_back(string(p1, p2));
//
//                sign = 0;
//
//                if (p2 != s.end())
//                {
//                    p1 = p2++;
//                }
//
//            }
//        }
//        if (p2 - p1 != 1);
//        else if (opera_test(*p1))//操作符
//        {
//            char ch = *p1;
//            if (ch == ' ');//空格处理   
//            else if (ch == ')')// ')'特殊处理
//            {
//                while (st.top() != '(')
//                {
//                    vs.push_back(string(1, st.top()));
//                    st.pop();
//                }
//                st.pop();
//            }
//        }
//        else//数字字符串
//        {
//            vs.push_back(string(p1, p2));
//        }
//
//        while (!st.empty())
//        {
//            vs.push_back(string(1, st.top()));
//            st.pop();
//        }
//
//        return evalRPN(vs);
//    }
//};
//
//int main()
//{
//    //string s = "hello word";
//    //auto p = s.begin();
//    //auto p1 = s.begin() + 5;
//    //string s1(p, p1);
//    //cout << s1 << endl;
//    string s1 = "- (3 - (- (4 + 5) ) )";
//    vector<string> vs1;
//    auto x = Solution().calculate(s1, vs1);
//    for (auto& e : vs1)
//    {
//        cout << e << endl;
//    }
//    cout << x << endl;
//
//    return 0;
//}


#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool opera_test(char ch)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == ' ')
            return true;
        return false;
    }

    bool opera_compare(char c1, char c2)//c1{+-*/(}c2{+-*/}
    {
        if (c1 == '(')
            return true;
        if (c2 == '+' || c2 == '-')
            return false;
        if (c1 == '+' || c1 == '-')
            return true;
        else
            return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& str : tokens)
        {
            if (!(str == "+" || str == "-" || str == "*" || str == "/"))
            {
                st.push(stoi(str));
            }
            else
            {
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();

                switch (str[0])
                {
                case '+':
                    st.push(right + left);
                    break;
                case '-':
                    st.push(right - left);
                    break;
                case '*':
                    st.push(right * left);
                    break;
                case '/':
                    st.push(right / left);
                    break;
                }
            }
        }
        return st.top();
    }

    int calculate(string s, vector<string>& vs) {
        stack<char> st;
        auto p1 = s.begin();
        auto p2 = p1 + 1;
        int flag = 0;
        while (p1 != s.end())
        {
            if (opera_test(*p1))//操作符
            {
                char ch = *p1;
                if (ch == ' ');//空格处理
                else if (ch == '-' && p1 == s.begin())//首位置
                {
                    vs.push_back(string(1, '0'));
                    st.push(ch);
                }
                else if (st.empty() || ch == '(')//空栈就入栈 或者 '('就入栈
                {
                    st.push(ch);
                    flag = 1;
                }
                else if (ch == ')')// ')'特殊处理
                {
                    while (st.top() != '(')
                    {
                        vs.push_back(string(1, st.top()));
                        st.pop();
                    }
                    st.pop();
                }
                else //{ +-*/ }
                {
                    if (flag == 1 && ch == '-')
                    {
                        vs.push_back(string(1, '0'));
                    }

                    while (!st.empty() && !opera_compare(st.top(), ch))
                    {
                        vs.push_back(string(1, st.top()));
                        st.pop();
                    }
                    st.push(ch);
                }
                ++p1;
            }
            else//数字字符串
            {
                flag = 0;

                while (p2 != s.end() && !opera_test(*p2))
                {
                    ++p2;
                }

                vs.push_back(string(p1, p2));
                p1 = p2;
            }
            if (p2 != s.end())
                p2++;
        }

        while (!st.empty())
        {
            vs.push_back(string(1, st.top()));
            st.pop();
        }

        return evalRPN(vs);
    }
};

int main()
{
    string s1 = "- (3 - (- (4 + 5) ) )";
    vector<string> vs1;
    auto x = Solution().calculate(s1, vs1);
    for (auto& e : vs1)
    {
        cout << e << endl;
    }
    cout << x << endl;

    return 0;
}