#include <iostream>
#include <string>
#include <fstream>
#include "../lib_x/Heap_max.h"
/**
    **程序名称：打饭顺序（堆排序）
    **数据结构：堆
    **问题：c++ 的文件读取操作中，eof判断会延迟（导致文件最后一行重复读取两次）

*/
using namespace std;

int main()
{
    ifstream source("info.txt") ;
    if(source == NULL)
    {
        cout <<"数据读入失败\n" ;
        return 0 ;
    }
    MaxHeap<string> OrderInEating ;
    Element<string> tmp ;
    int key ;
    string tmpInfo ;
    cout <<"进食堂打饭的顺序是:\n\n" ;
    while(!source.eof())
    {
        source>> key >>tmpInfo ;
        tmp.setKey(key) ;
        tmp.setInfo(tmpInfo) ;
        cout <<tmpInfo <<"\t" ;
        OrderInEating.Insert(tmp) ;
    }
    cout <<"\n\n公司打饭的顺序是：\n\n" ;
    while(!OrderInEating.isHeapEmpty())
    {
        cout <<OrderInEating.DeleteMax()->getInfo() <<"\t" ;
    }
    return 0;
}
