#include<iostream>
using namespace std;

#include<time.h>
#include"AVLtree.h"
#include"RBTree.h"

void testAVL1()
{
    srand((unsigned int)time(NULL));

    AVLtree<int, int> a;
    //int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15, 1, 22,30,32 };
    //for (auto e : arr)
    //{
    //    a.insert(make_pair(e, 0));
    //}
    //a.InOrder();
    //int d[] = { 1 };
    //for (auto e : d)
    //{
    //    cout << e << endl;
    //    a.erase(e);
    //    cout << a.check_balance() << "!";
    //    cout << endl;
    //    a.InOrder();
    //}
    //for (auto e : arr)
    //{
    //    cout << e << endl;
    //    a.erase(e);
    //    cout << a.check_balance() << "!";
    //    cout << endl;
    //    a.InOrder();
    //}


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

void testRBTree()
{
    srand((unsigned int)time(NULL));
    RBTree<int, int> a;
    //int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15, 1, 22,30,32 };
    //for (auto e : arr)
    //{
    //    a.Insert(make_pair(e, 0));
    //}
    //a.InOrder();

    for (int i = 0; i <= 1000; i++)
    {
        int ret2 = rand() % 1000 + 1;
        a.Insert(make_pair(i, 0));
    }
    //a.InOrder();

    cout << a.RBTree_Check() << endl;
    cout << a.TreeHightMax() << endl;
    cout << a.TreeHightMin() << endl;
}

int main()
{
    testAVL1();
    testRBTree();
    return 0;
}