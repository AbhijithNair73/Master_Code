#include<iostream>
using namespace std;
class A
{
    int x;
public:
    A(){cout<<"Default constructor in A"<<endl;}
    A(int b)
    {
        x=b;
        cout<<"Parametrized Constructor A"<<endl;
    }
    ~A()
    {
        cout<<"destructor A"<<endl;
    }
    void print_data()
    {
    cout<<"x -"<<x<<endl;
    }
};

class B
{
int y;
public:
    B(){cout<<"Default Constructor in B"<<endl;}
    B(int c)
    {
        y=c;
        cout<<"Parametrized Constructor B"<<endl;
    }
    ~B()
    {
        cout<<"destructor B"<<endl;
    }
    void print_data()
    {

    cout<<"y -"<<y<<endl;

    }
};
class C:public A,public B
{
    int z;
public:
    C(){
    	cout<<"Default constructor in C"<<endl;
    }
    C(int a,int b,int c):A(b),B(c)
    {
        z=a;
        cout<<"Parametrized Constructor C"<<endl;
    }
    ~C()
    {
        cout<<"destructor C"<<endl;
    }
    void print_data()
    {
        A::print_data();
        B::print_data();
    cout<<"z -"<<z<<endl;
    }
};
main()
{
    C obj(10,20,30);
    cout<<sizeof(obj)<<endl;
    obj.print_data();
}
