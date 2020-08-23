#include<iostream>
using namespace std;
class A
{
public:
   virtual  void test1()
    {
        cout<<"test1 in A"<<endl;
    }
};
class B:public A
{
public:
     void test1()
    {
        cout<<"test1 in B"<<endl;
    }
};
main()
{
    A *a;
    B b1;
    a=&b1;
    cout<<"size of A:"<<sizeof(A)<<endl;
    cout<<"size of B:"<<sizeof(B)<<endl;
    a->test1();
    b1.test1();


}
