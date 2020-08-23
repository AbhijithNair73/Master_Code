#include<iostream>
using namespace std;
class B;
class C;
class A
{
    int a[5];
public:
   void set_data()
   {
       cout<<"Enter data for array"<<endl;
       for(int i=0;i<5;i++)
        cin>>a[i];
   }
   void print_data()
   {
       for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
   }
   friend void addition(A &a1,B &b1,C &c1);
};
class B
{
    int b[5];
public:
   void set_data()
   {
       cout<<"Enter data for array"<<endl;
       for(int i=0;i<5;i++)
        cin>>b[i];
   }
   void print_data()
   {
       for(int i=0;i<5;i++)
        cout<<b[i]<<" ";
   }
   friend void addition(A &a1,B &b1,C &c1);
};
class C
{
    int c[5];
public:
    void print_data()
   {
       for(int i=0;i<5;i++)
        cout<<c[i]<<" ";
   }
   friend void addition(A &a1,B &b1,C &c1);
};

void addition(A &a1,B &b1,C &c1)
{
    int i;
    for(i=0;i<5;i++)
        c1.c[i] = b1.b[i]+a1.a[i];
}

main()
{
 A a1;
 B b1;
 C c1;
 a1.set_data();
 b1.set_data();
 cout<<"********************************"<<endl;
 a1.print_data();
 b1.print_data();
 addition(a1,b1,c1);
 cout<<"********************************"<<endl;
 c1.print_data();

}
