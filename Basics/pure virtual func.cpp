#include<iostream>
using namespace std;
class A
{
public:
     void test2()
    {
        cout<<"test2 in A"<<endl;
    }

    virtual void test1()=0;
};
class B:public A
{
public:
    void test1()
    {
        cout<<"test1 in B"<<endl;
    }
    void test2()
    {
        cout<<"test2 in B"<<endl;
    }
};
main()
{
    A *a1;
    B b1;
    a1=&b1;
    a1->test2();
    b1.test2();
    a1->test1();
    b1.test1();
}
