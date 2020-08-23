#include<iostream>
using namespace std;
class B;
class C;
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
    friend void print_data(A &a1,B &b1,C &c1);
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
      friend void print_data(A &a1,B &b1,C &c1);
};
class C
{
  int m;
  int n;
  public:
      void set_data()
      {
          cout<<"Enter data"<<endl;
          cin>>m>>n;
      }
      friend void print_data(A &a1,B &b1,C &c1);
};

main()
{
    A a1;
    B b1;
    C c1;
    a1.set_data();
    b1.set_data();
    c1.set_data();
    print_data(a1,b1,c1);
}
void print_data(A &a1,B &b1,C &c1)
{
    cout<<" "<<a1.x<<" "<<a1.y<<endl;
    cout<<" "<<b1.a<<" "<<b1.b<<endl;
    cout<<" "<<c1.m<<" "<<c1.n<<endl;
}
