#include<iostream>
using namespace std;
class A
{
    static bool flag;
    static A* single;
    A()
    {
        cout<<"const"<<endl;
    }
public:

    static A* get_inst();
    ~A(){flag=false;
    cout<<"dest"<<endl;}
};
 bool A::flag=false;
     A* A::single=NULL;
 A* A::get_inst()
{
        if(!flag)
        {
           single=new A;
           flag=true;
        }
        else{
                return single;}

}
main()
{
A *s1,*s2;
s1=A::get_inst();
s2=A::get_inst();

}
