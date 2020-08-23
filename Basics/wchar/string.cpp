#include<iostream>
using namespace std;
class A
{
    int x;
    static int count;
public:
    A()
    { cout<<"Des"<<endl;
        A *ptr;
        if(count==0)
        {
            ptr=this;
            ptr->x=10;
            count++;
        }
        else
            {
            cout<<"singleton"<<endl;
            x=ptr->x;
            ptr=this;
            }
    }
    void print_data()
    {
        cout<<"x- "<<x<<endl;
    }
};
int A::count=0;
main()
{
    A obj1,obj2;
    obj1.print_data();
    obj2.print_data();

}
