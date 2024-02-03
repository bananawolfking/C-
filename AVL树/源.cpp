#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

//class Solution {
//public:
//    class Compare
//    {
//    public:
//        bool operator()(const pair<int, string>& x1, const pair<int, string>& x2) const
//        {
//            return x1.first > x2.first || (x1.first == x2.first && x1.second < x2.second);
//        }
//    };
//
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> Mapcount;
//        for (auto& e : words)
//        {
//            Mapcount[e]++;
//        }
//
//        set<pair<int, string>, Compare> ret;
//        auto it = Mapcount.begin();
//        while (it != Mapcount.end())
//        {
//            ret.insert(make_pair(it->second, it->first));
//            ++it;
//        }
//        auto it1 = ret.begin();
//        vector<string> v;
//        while (k--)
//        {
//            v.push_back(it1->second);
//            ++it1;
//        }
//        return v;
//    }
//};

//class Solution {
//public:
//    class Compare
//    {
//    public:
//        bool operator()(const pair<int, string>& x1, const pair<int, string>& x2) const
//        {
//            return x1.first < x2.first || (x1.first == x2.first && x1.second > x2.second);
//        }
//    };
//
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> Mapcount;
//        for (auto& e : words)
//        {
//            Mapcount[e]++;
//        }
//
//        priority_queue<pair<int, string>, vector<pair<int,string>>, Compare> ret;
//        for (auto& e : Mapcount)
//        {
//            ret.push(make_pair(e.second, e.first));
//        }
//
//        vector<string> v;
//        while (k--)
//        {
//            const pair<int, string>& top = ret.top();
//            v.push_back(top.second);
//            ret.pop();
//        }
//        return v;
//    }
//};


//class Solution {
//public:
//    class Compare
//    {
//    public:
//        bool operator()(const pair<string, int>& x1, const pair<string, int>& x2) const
//        {
//            return x1.second > x2.second || (x1.second == x2.second && x1.first < x2.first);
//        }
//    };
//
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> Mapcount;
//        for (auto& e : words)
//        {
//            Mapcount[e]++;
//        }
//
//        vector<pair<string, int>> ret(Mapcount.begin(),Mapcount.end());
//        
//        sort(ret.begin(), ret.end(), Compare());
//        vector<string> v;
//        auto it = ret.begin();
//        while (k--)
//        {
//            v.push_back(it->first);
//            ++it;
//        }
//        return v;
//    }
//};


//class Solution {
//public:
//    class Compare
//    {
//    public:
//        bool operator()(const pair<string, int>& x1, const pair<string, int>& x2) const
//        {
//            return x1.second > x2.second;
//        }
//    };
//
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> Mapcount;
//        for (auto& e : words)
//        {
//            Mapcount[e]++;
//        }
//
//        vector<pair<string, int>> ret(Mapcount.begin(), Mapcount.end());
//
//        stable_sort(ret.begin(), ret.end(), Compare());
//        vector<string> v;
//        auto it = ret.begin();
//        while (k--)
//        {
//            v.push_back(it->first);
//            ++it;
//        }
//        return v;
//    }
//};



#include"AVLtree.h"

void testAVL1()
{
    AVLtree<int, int> a;
    int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
    for (auto e : arr)
    {
        a.insert(e, 0);
    }
    
}

int main()
{
    testAVL1();
    return 0;
}