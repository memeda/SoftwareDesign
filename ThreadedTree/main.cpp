#include <iostream>
#include "..\lib_x\ThreadedTree.h"
/**
    **程序名称：线索树
    **数据结构：链表实现的线索树
*/
using namespace std;

int main()
{
    ThreadedTree<char> x ;
    char * menus = "\t请选择：\n\t1.插入节点\n\t2.查看树（中序序列）\n\t3.退出\n" ;
    while(cout <<menus)
    {
        int choice ;
        cin >> choice ;
        switch(choice)
        {
            case 1 :
            {
                char info ;
                if(x.isThreadedTreeEmpty() == true)
                {
                    cout <<"树为空。\n请输入根节点信息\n" ;
                    cin >> info ;
                    Node<char>* tmp = new Node<char>(info) ;
                    x.LInsert(tmp,x.getHead()) ;
                     cout <<"新节点插入成功\n" ;
                }
                else
                {
                    cout <<"请选择在下列那个节点后插入\n" ;
                    x.ThInOrder() ;
                    char forSearch ;
                    cin >> forSearch ;
                    Node<char> * pos = x.Retrieve(forSearch) ;
                    if(pos == NULL)
                    {
                        cout <<"不存在的节点\n" ;
                        break ;
                    }
                    else
                    {
                        cout <<"请输入要插入节点的信息\n" ;
                        char infoInput ;
                        cin >> infoInput ;
                        Node<char>* newNode = new Node<char>(infoInput) ;
                        cout <<"请选择将该节点插入到"<<info<<"节点的左子树或是右子树\n" ;
                        cout <<"1.左子树\t2.右子树\n" ;
                        int choiceWhere ;
                        cin >> choiceWhere ;
                        if(choiceWhere == 1)
                        {
                            x.LInsert(newNode,pos) ;
                        }
                        else if(choiceWhere == 2)
                        {
                            x.RInsert(newNode,pos) ;
                        }
                        else
                        {
                            cout <<"无效的选项\n" ;
                            delete newNode ;
                            break ;
                        }
                        cout <<"新节点插入成功\n" ;
                    }
                }
                break ;
            }
            case 2 :
            {
                cout <<"树的中序遍历为：\n" ;
                x.ThInOrder() ;
                break ;
            }
            case 3:
            return 0 ;
            default :
            cout <<"无效的输入\n" ;
        }
    }
    return 0;
}
