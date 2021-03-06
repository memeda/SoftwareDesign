#include <iostream>
#include <fstream>
#include "../lib_x/List_cursor.h"
using namespace std;
/**
    **程序名称：动态内存分配模拟
    **数据结构：静态链表
    **主要操作：插入，删除，读取，获取位置
*/
int main()
{
    ListCursor<int> ls ;
    cout <<"插入第一个元素\n" ;
    ls.Insert(1,ls.end()) ;
    cout <<"第一个元素是"<<ls.Retrieve(ls.first()) << endl ;
    cout <<"插入第二个元素\n" ;
    ls.Insert(2,ls.end()) ;
    cout <<"第二个元素是"<<ls.Retrieve(ls.next(ls.first())) <<endl ;
    cout <<"删除第一个元素\n" ;
    ls.Delete(ls.first()) ;
    cout <<"删除第一个元素后\n现在第一个元素是"<<ls.Retrieve(ls.first()) << endl ;
    cout <<"\n按任意键结束模拟\n" ;
    getchar() ;
    return 0;
}
