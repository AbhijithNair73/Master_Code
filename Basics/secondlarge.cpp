#include<iostream>
using namespace std;
class A
{
    int *a;
public:
    A()
    {
        a=new int[5];
        cout<<"enter data "<<endl;
        for(int i=0;i<5;i++)
            cin>>a[i];
    }
    void large()
    {
        int l,sl;
        if(a[0]>a[1])
        {
            l=a[0];
            sl=a[1];
        }
        if(a[0]<a[1])
        {
            l=a[1];
            sl=a[0];
        }
        for(int i=2;i<5;i++)
        {
            if(a[i]>l)
            {
                sl=l;
                l=a[i];
            }
            else if(a[i]>sl)
            {
                sl=a[i];
            }
        }
        cout<<"large -"<<l<<"second large -"<<sl<<endl;
    }
};
main()
{
    A obj;
    obj.large();
}
