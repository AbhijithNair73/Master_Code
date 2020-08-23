#include<iostream>
using namespace std;
class B;
class A
{
    int x;
    int y;
public:
    void set_data( )
    {
        cout<<"enter data"<<endl;
        cin>>x>>y;
    }
    friend void print_data(A &a1,B &b1);
};
class B
{
  int a;
  int b;
  public:
      void set_data()
      {
          cout<<"enter data"<<endl;
          cin>>a>>b;
      }
      friend void print_data(A &a1,B &b1);
};
main()
{
    A a1;
    B b1;
    a1.set_data();
    b1.set_data();
    print_data(a1,b1);
}
void print_data(A &a1,B &b1)
{
    int t;
    t=a1.x;
    a1.x=b1.a;
    b1.a=t;
    t=a1.y;
    a1.y=b1.b;
    b1.b=t;
    cout<<" "<<a1.x<<" "<<a1.y<<endl;
    cout<<" "<<b1.a<<" "<<b1.b<<endl;
}
