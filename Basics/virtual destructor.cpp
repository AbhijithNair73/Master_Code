#include<iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout<<"constructor in A"<<endl;
    }
    virtual ~A()
    {
        cout<<"Destructor in A"<<endl;
    }
   void test1()
    {
        cout<<"test1 in A"<<endl;
    }
};
class B:public A
{
public:
    B():A()
    {
        cout<<"constructor in B"<<endl;
    }
        virtual~B()
    {
        cout<<"Destructor in B"<<endl;
    }
     void test1()
    {
        cout<<"test1 in B"<<endl;
    }
};

class C:public B
{
    char *s;
public:
    C()
    {
        cout<<"constructor in C"<<endl;
    }
    ~C()
    {
        cout<<"Destructor in C"<<endl;
    }
     void test1()
    {
        cout<<"test1 in C"<<endl;
    }
};

main()
{
    B *ptr;
    ptr=new C;
    ptr->test1();
    delete ptr;
}
