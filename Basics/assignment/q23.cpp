#include<iostream>
#include<cstdlib>
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
     void * operator new(unsigned int w)
     {
         A*ptr;
         cout<<"dynamic "<<endl;
         ptr=(A*)malloc(sizeof(A));
         return ptr;

     }
     void operator delete(void *p)
     {
         free(p);
         cout<<"freed"<<endl;
     }
     void set_data(int y)
     {
         x=y;
     }
     void print_data()
     {
         cout<<"x -"<<x<<endl;
     }
};
main()
{
    A*ptr;
    ptr=new A(10);
    ptr->set_data(10);
    ptr->print_data();
    delete ptr;
}
