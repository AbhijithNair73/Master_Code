#include<iostream>
using namespace std;
class A
{
  mutable  int x;
    int y;
public:

    A(int a=0,int b=0)
    {
        cout<<"parametrized"<<endl;
        x=a,y=b;
    }
    void print_data1()
    {
        cout<<"normal call"<<endl;
        cout<<x<<" "<<y<<endl;
    }
     void print_data() const;

};
//void print_data() const;
main()
{
    A b;
    const A x;
   b.print_data1();
    x.print_data();
   // delete ptr;
    //delete ptr1;
}
// void print_data() const
void A::print_data() const
 {
        cout<<"const call"<<endl;
        cout<<x<<" "<<y<<endl;
    }
