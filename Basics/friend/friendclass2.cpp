#include<iostream>
using namespace std;
class A;
class other
{
public:
    void print_data1(A&a1);
    void print_data1(A*a1);
    void print_data2(A a1);
};

class A
{
int x;
int y;
public:
    void set_data(int a, int b);
    friend void other::print_data1(A*);
    friend void other::print_data1(A&a1);
    friend void other::print_data2(A a1);
};
void A::set_data(int a,int b)
{
    x=a;
    y=b;
}
void other::print_data1(A&a1)
   {
        cout<<"refrence"<<endl;
        cout<<"x-"<<a1.x<<"  "<<"y-"<<a1.y<<endl;
    }
void other::print_data1(A*a1)
  {
        cout<<"pointers"<<endl;
        cout<<"x-"<<a1->x<<"  "<<"y-"<<a1->y<<endl;
    }
void other::print_data2(A a1)
    {
        cout<<"normal"<<endl;
        cout<<"x-"<<a1.x<<"  "<<"y-"<<a1.y<<endl;
    }
main()
{
A a1;
A &x=a1;
other s;
a1.set_data(10,20);
s.print_data1(&a1);
s.print_data1(x);
s.print_data2(a1);
}
