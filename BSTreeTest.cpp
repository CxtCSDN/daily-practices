#include "BSTree.h"
#include <iostream>
using namespace std;

int main()
{
    BSTree<int> t;
    int arr[] = {8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4};
    for (int val : arr)
    {
        t.insertR(val);
    }
    t.Inorder();

    BSTree<int> t2 = t;
    t2.Inorder();

    BSTree<int> t3;
    t3.insert(1);
    t3.insert(2);
    t3.insert(3);
    t2 = t3;
    t2.Inorder();
    // std::cout << std::endl;
    // t.erase(8);
    // t.Inorder();
    // t.erase(3);
    // t.Inorder();
    // t.erase(1);
    // t.Inorder();
    // t.erase(10);
    // t.Inorder();
    // t.erase(6);
    // t.Inorder();
    // t.erase(4);
    // t.Inorder();
    // t.erase(7);
    // t.Inorder();
    // t.erase(13);
    // t.Inorder();
    // t.erase(14);
    // t.Inorder();
    // t.Inorder();
    // for (int val : arr)
    // {
    //     t.eraseR(val);
    //     t.Inorder();
    // }
    return 0;
}