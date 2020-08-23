#include<iostream>
using namespace std;
class A
{
 int x;
 public:
     A()
     {
        cout<<"Constructor "<<endl;
     }
     A(int a):x(a){
     cout<<"paramterized constructor"<<endl;
     }
     A operator -( )
     {
         A ret;
         ret.x=-x;
         return ret;
     }
   friend void print_data(A &temp)
     {
         cout<<"X- "<<temp.x<<endl;
     }

};

main()
{
A obj1(20),obj2;
obj2=-obj1;
print_data(obj1);
print_data(obj2);
}
