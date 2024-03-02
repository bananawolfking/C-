#include<iostream>
using namespace std;

#include<time.h>
#include"set.h"
#include"map.h"
#include"AVLtree.h"
#include"RBTree.h"

void testAVL1()
{
    srand((unsigned int)time(NULL));

    AVLtree<int, int> a;


    for (int i = 0; i <= 1000; i++)
    {
        int ret2 = rand() % 1000 + 1;
        a.insert(make_pair(i, 0));
    }
    //a.InOrder();
    cout << a.check_balance() << endl;
    cout << a.TreeHightMax() << endl;
    cout << a.TreeHightMin() << endl;

    //for (int i = 0; i <= 1000; i++)
    //{
    //    int ret2 = rand() % 1000 + 1;
    //    a.erase(ret2);
    //    if (!a.check_balance())
    //        int x = 0;
    //}
    //a.InOrder();
    //cout << a.check_balance() << "!";
}

//void testRBTree()
//{
//    srand((unsigned int)time(NULL));
//    RBTree<int, pair<int,int>> a;
//    //int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15, 1, 22,30,32 };
//    //for (auto e : arr)
//    //{
//    //    a.Insert(make_pair(e, 0));
//    //}
//    //a.InOrder();
//
//    for (int i = 0; i <= 1000; i++)
//    {
//        int ret2 = rand() % 1000 + 1;
//        a.Insert(make_pair(i, 0));
//    }
//    //a.InOrder();
//
//    cout << a.RBTree_Check() << endl;
//    cout << a.TreeHightMax() << endl;
//    cout << a.TreeHightMin() << endl;
//
//    RBTree<int, pair<int, int>> b = a;
//    b.InOrder();
//}

void testset1()
{
    kele::set<int> s;
    s.Insert(2);
    s.Insert(3);
    s.Insert(1);
    s.InOrder();
}

void testmap1()
{
    srand((unsigned int)time(NULL));
    kele::map<int, int> m;
    for (int i = 0; i <= 1000; i++)
    {
        int ret2 = rand() % 1000 + 1;
        m.Insert(make_pair(i, 0));
    }
    m.Insert(make_pair(2, 2));
    m.Insert(make_pair(3, 3));
    m.Insert(make_pair(1, 1));
    m.InOrder();
    cout << m.RBTree_Check() << endl;
    cout << m.TreeHightMax() << endl;
    cout << m.TreeHightMin() << endl;
    less<int> com;
    cout << com(1, 3);
}

void InOrder(kele::map<int,int>::const_iterator it)
{
    while (it != nullptr)
    {
        cout << it->first << " ";
        ++it;
    }
}
void testmap2()
{
    srand((unsigned int)time(NULL));
    kele::map<int, int> m;
    for (int i = 0; i <= 1000; i++)
    {
        int ret2 = rand() % 1000 + 1;
        m.Insert(make_pair(i, 0));
    }
    m.Insert(make_pair(2, 2));
    m.Insert(make_pair(3, 3));
    m.Insert(make_pair(1, 1));
    auto it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " ";
        ++it;
    }
    InOrder(it);

}

void InOrder(kele::set<int>::const_iterator it)
{
    while (it != nullptr)
    {
        cout << *it << " ";
        ++it;
    }
}

void testset2()
{
    srand((unsigned int)time(NULL));
    kele::set<int> s;
    for (int i = 0; i <= 1000; i++)
    {
        int ret2 = rand() % 1000 + 1;
        s.Insert(i);
    }

    auto it = s.rbegin();
    while (it != s.rend())
    {
        cout << *it << " ";
        ++it;
    }
}

int main()
{
    //testAVL1();
    //testRBTree();
    //testset1();
    //testmap1();
    //testmap2();
    testset2();
    return 0;
}