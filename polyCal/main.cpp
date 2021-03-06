#include <iostream>
using namespace std;
/**
    **程序名称：多项式的运算
    **实现功能：实现多项式的输入，运算（加法，减法，乘法）
    **数据结构：类封装的线性表（链表实现）
*/
class PolyNode
{
public :
    PolyNode()
    {
        coef = 0.0 ;
        exp = 0.0 ;
        next = NULL ;
    }
    PolyNode(double coef,int exp,PolyNode * next)
    {
        this->coef = coef ;
        this->exp = exp ;
        this->next = next ;
    }
    PolyNode * attach(PolyNode * x)
    {
        setNext(x) ;
        return x ;
    }
    double getCoef()
    {
        return coef ;
    }
    int getExp()
    {
        return exp ;
    }
    PolyNode * getNext()
    {
        return next ;
    }
    void setCoef(double new_coef)
    {
        coef = new_coef ;
    }
    void setExp(int new_exp)
    {
        exp = new_exp ;
    }
    void setNext(PolyNode* new_next)
    {
        next = new_next ;
    }
private :
    double coef ;
    int exp ;
    PolyNode * next ;
} ;
class Poly
{
public :
    Poly() ;
    Poly(PolyNode * val) ;
    ~Poly() ;
    void polyNumIncrease() ;
    int getNumOfPoly() ;
    void insertNode(PolyNode * node) ;
    Poly * negate() ;
    Poly * add(Poly * factor) ;
    Poly * sub(Poly * factor) ;
    Poly * mul(Poly * factor) ;
    PolyNode * getHead() ;
    void printPoly(char variable) ;
private :
    PolyNode * head ;
    int num_of_poly ; //多项式包含的项数
} ;
Poly::Poly()
{
    head = new PolyNode(0.0,0,NULL) ;
    num_of_poly = 0 ;
}
Poly::Poly(PolyNode * val)
{
    head = new PolyNode(0.0,0,val) ;
    num_of_poly = 0 ;
}
Poly::~Poly()
{
    while(head != NULL)
    {
        PolyNode * tmp = head ->getNext() ;
        delete head ;
        head = NULL ;
        head = tmp ;
    }
}
void Poly::polyNumIncrease()
{
    num_of_poly++ ;
}
int Poly::getNumOfPoly()
{
    return num_of_poly ;
}
void Poly::insertNode(PolyNode* node)
{
    PolyNode * pos = head ;
    while(pos->getNext()!= NULL)
    {
        if(node->getExp() < pos->getNext()->getExp())
        {
            pos = pos->getNext() ;
        }
        else
        {
            break ;
        }
    }
    if(pos->getNext()!=NULL&&pos->getNext()->getExp() == node->getExp())//指数相同，只更改系数
    {
        pos->getNext()->setCoef(pos->getNext()->getCoef()+node->getCoef()) ;
        return ;
    }
    node->setNext(pos->getNext()) ;
    pos->setNext(node) ;
    polyNumIncrease() ;

}
Poly * Poly::negate()
{
    Poly * negative = new Poly() ;
    PolyNode * rear = negative->getHead() ;
    PolyNode * pos = head->getNext() ;
    while(pos != NULL)
    {
        PolyNode * node = new PolyNode(-pos->getCoef(),pos->getExp(),NULL) ;
        rear = rear->attach(node) ;
        pos = pos->getNext() ;
    }
    return negative ;
}
Poly * Poly::add(Poly * factor)
{
    PolyNode * pos_this  = head->getNext() ;
    PolyNode * pos_that = factor->getHead()->getNext() ;
    Poly * result = new Poly() ;
    PolyNode * rear  = result->getHead() ;//指向result链表的末尾节点
    while(pos_this != NULL && pos_that != NULL)
    {
        int exp_this = pos_this->getExp() ;
        int exp_that = pos_that->getExp() ;
        if(exp_this == exp_that)
        {
            int sum = pos_this->getCoef()+pos_that->getCoef() ;
            if(sum != 0)
            {

                PolyNode * node = new PolyNode(sum,exp_this,NULL) ;
                rear = rear->attach(node) ;
            }
            pos_this = pos_this->getNext() ;
            pos_that = pos_that->getNext() ;
        }
        else if(exp_this > exp_that)
        {
            PolyNode * node = new PolyNode(pos_this->getCoef(),exp_this,NULL) ;
            rear=rear->attach(node) ;
            pos_this = pos_this->getNext() ;
        }
        else
        {
            PolyNode * node = new PolyNode(pos_that->getCoef(),exp_that,NULL) ;
            rear=rear->attach(node) ;
            pos_that =pos_that->getNext() ;
        }
    }
    while(pos_this != NULL)
    {
        PolyNode * node = new PolyNode(pos_this->getCoef(),pos_this->getExp(),NULL) ;
        rear = rear->attach(node) ;
        pos_this = pos_this->getNext() ;
    }
    while(pos_that != NULL)
    {
        PolyNode * node =  new PolyNode(pos_that->getCoef(),pos_that->getExp(),NULL) ;
        rear = rear->attach(node) ;
        pos_that = pos_that->getNext() ;
    }
    return result ;

}
Poly * Poly::sub(Poly * factor)
{
    Poly * negative = factor->negate() ;
    return this->add(negative) ;
}
Poly * Poly::mul(Poly * factor)
{
    if(num_of_poly > factor->getNumOfPoly())
    {
        return factor->mul(this) ;
    }
    Poly * devide[num_of_poly] ;
    PolyNode * this_pos = head->getNext() ;
    PolyNode * that_pos = factor->getHead()->getNext() ;
    if(this_pos == NULL || that_pos == NULL)
    {
        cout <<"无意义\n" ;
        return NULL ;
    }
    double coef ;
    int exp ;
    for(int i = 0 ; i < num_of_poly ; i++)
    {
        devide[i] = new Poly() ;
        that_pos = factor->getHead()->getNext() ;//每次从起始位置开始
        while(that_pos != NULL)
        {
            coef = this_pos->getCoef()*that_pos->getCoef() ;
            exp = this_pos->getExp()+that_pos->getExp() ;
            PolyNode * node = new PolyNode(coef,exp,NULL) ;
            devide[i]->insertNode(node) ;
            that_pos = that_pos->getNext() ;
        }
        this_pos = this_pos->getNext() ;
    }
    Poly * sum = new Poly() ;
    for(int i = 0 ; i < num_of_poly ; i++)
    {
        sum = sum->add(devide[i]) ;
    }
    delete [] devide ;
    return sum ;
}
PolyNode *Poly::getHead()
{
    return head ;
}
void Poly::printPoly(char variable)
{
    //系数是1不输出系数，指数是零不输出指数
    PolyNode * pos = head->getNext() ;
    double coef ;
    int exp ;
    if(pos != NULL)
    {
        coef = pos->getCoef() ;
        exp = pos->getExp() ;
        if(exp == 0)
        {
            cout <<coef ;
        }
        else
        {
            if(coef == 1)
            {
                cout <<variable <<"^" <<exp ;
            }
            else
            {
                cout <<coef <<variable <<"^" <<exp ;
            }
        }
        pos = pos->getNext() ;

    }
    else
    {
        cout <<"空\n" ;
        return ;
    }
    while(pos != NULL)
    {
        coef = pos->getCoef() ;
        exp = pos->getExp() ;
        if(exp == 0)
        {
            if(coef > 0)
            {
                cout <<"+" <<coef ;
            }
            else
            {
                cout <<coef ;
            }
        }
        else if(exp >0)
        {
            if(coef>0)
            {
                cout <<"+" <<coef <<variable ;

            }
            else
            {
                cout <<coef <<variable ;
            }
            if(exp != 1)
            {
                cout <<"^" <<exp ;
            }
        }
        else
        {
            if(coef > 0)
            {
                cout <<"+" <<coef <<variable <<"^(" <<exp <<")" ;
            }
            else
            {
                cout <<coef <<variable <<"^(" <<exp <<")" ;  ;
            }
        }
        pos = pos->getNext() ;
    }
    cout <<endl ;

}
int main()
{
    char variable ;
    cout <<"请输入你喜欢的变量名，如 t \n" ;
    cin >> variable ;
    cout <<"请按照 系数 指数 的格式输入多项式 P(1)的各项\n"
         <<"并以0.0 0 结束输入\n如 2.3 3 4 5 1 0 0.0 0 \n" ;
    double coef ;
    int exp ;
    Poly * p1 = new Poly() ;
    Poly * p2 = new Poly() ;
    while(cin >> coef >>exp)
    {
        if(coef == 0.0 && exp == 0)
            break ;
        PolyNode * node = new PolyNode(coef,exp,NULL) ;
        p1->insertNode(node) ;
    }
    cout <<"P(1)输入完成，P(1)=" ;
    p1->printPoly(variable) ;
    cout <<endl ;
    cout <<"请按照相同的方式输入P(2)\n" ;
    while(cin >> coef >>exp)
    {
        if(coef == 0.0 && exp == 0)
            break ;
        PolyNode * node = new PolyNode(coef,exp,NULL) ;
        p2->insertNode(node) ;
    }
    cout <<"P(2)输入完成，P(2)=" ;
    p2->printPoly(variable) ;
    cout <<endl ;

    char * menus = "请选择运算方式\n1.加法\t2.减法\n3.乘法\t4.退出\n" ;
    int choice ;
    while(cout <<menus)
    {
        cin >> choice ;
        cout <<"P(1)= " ;
        p1->printPoly(variable) ;
        cout <<endl ;
        cout <<"P(2)= " ;
        p2->printPoly(variable) ;
        cout <<endl ;
        switch(choice)
        {
            case 1 :
            {
                cout <<"P(1) + P(2) = " ;
                p1->add(p2)->printPoly(variable) ;
                break ;
            }
            case 2 :
            {
                cout <<"请选择：\n1.P(2)-P(1)\n2.P(1)-P(2)\n" ;
                int choice_sub ;
                cin >> choice_sub ;
                if(choice_sub == 1)
                {
                    cout <<"P(2) - P(1) = " ;
                    p2->sub(p1) ->printPoly(variable) ;
                }
                else if(choice_sub == 2)
                {
                    cout <<"P(1) - P(2) = " ;
                    p1->sub(p2) ->printPoly(variable) ;
                }
                else
                {
                    cout <<"不合法的输入\n" ;
                }


                break ;
            }
            case 3 :
            {
                cout <<"P(1) * P(2) = " ;
                p1->mul(p2)->printPoly(variable) ;
                break ;
            }
            case 4 :
            return 0 ;
            default :
            cout <<"无效的输入\n" ;
        }
    }
    return 0;
}
