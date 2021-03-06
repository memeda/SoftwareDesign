#include <iostream>
#include "../lib_x/ThreadedTreeNEW.h"
using namespace std;

int main()
{
    ThreadedTree<char> x ;
    cout <<"首先建立二叉树\n" ;
    x.BTInit() ;
    char* menus = "\n1.先序化二叉树并遍历\n2.中序线索化二叉树并遍历\n3.后续线索化二叉树并遍历\n4.退出\n" ;
    int choice ;
    while(cout <<menus)
    {
        cin >> choice ;
        switch(choice)
        {
        case 1:
        {
            cout <<"二叉树先序遍历的序列为\n" ;
            x.PreOrder(x.getRoot()) ;
            cout <<endl ;
            cout <<"对二叉树进行先序线索化\n" ;
            x.PreOrderTh() ;
            cout <<"先序线索化完成\n" ;
            cout <<"先序线索二叉树遍历为\n" ;
            x.ThPreOrder() ;
            x.ClearThread() ;
            break ;
        }
        case 2 :
        {
            cout <<"二叉树中序序遍历的序列为\n" ;
            x.InOrder(x.getRoot()) ;
            cout <<endl ;
            cout <<"对二叉树进行中序线索化\n" ;
            x.InOrderTh() ;
            cout <<"中序线索化完成\n" ;
            cout <<"中序线索二叉树遍历为\n" ;
            x.ThInOrder() ;
            x.ClearThread() ;
            break ;
        }
        case 3 :
        {
            cout <<"二叉树后序遍历的序列为\n" ;
            x.PostOrder(x.getRoot()) ;
            cout <<endl ;
            cout <<"对二叉树进行后序线索化\n" ;
            x.PostOrderTh() ;
            cout <<"后序线索化完成\n" ;
            cout <<"后序线索二叉树遍历为\n" ;
            x.ThPostOrder() ;
            x.ClearThread() ;
            break ;
        }
        case 4 :
            return 0 ;
        default :
            cout <<"无效的选项\n" ;
        }
    }
    x.BTInit() ;
    return 0;
}
