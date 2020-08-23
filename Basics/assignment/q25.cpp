#include<iostream>
using namespace std;
class A
{
    int x;
public:
    A(){
    cout<<"constructor "<<endl;
    }
    ~A(){
    cout<<"Destructor"<<endl;
    }
    void operator()(int a){
    x=a;
    cout<<x<<endl;
    }

};
main()
{
    A obj;
    int i;
    obj(10);
}
