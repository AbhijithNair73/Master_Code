#include<iostream>
using namespace std;
void func(int &,int &);
main()
{
int x;
int y;
x=10;
y=20;
func(x,y);
cout<<"x- "<<x<<"y- "<<y<<endl;
}
void func(int &k,int &l)
{
    int t;
    t=k;
    k=l;
    l=t;
}
