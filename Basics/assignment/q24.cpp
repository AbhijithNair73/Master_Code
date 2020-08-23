#include<iostream>
using namespace std;
class A
{
    int x[5];
public:
    A(){
    cout<<"constructor "<<endl;
    }
    ~A(){
    cout<<"Destructor"<<endl;
    }
    int& operator[](int a)
    {
            return x[a];
    }
    void set_data(){
    for(int i=0;i<5;i++)
        x[i]=i;
    }
};
main()
{
    A obj;
    int i;
    //obj.set_data();
    for (i=0;i<5;i++)
    cin>>obj[i];

    for (i=0;i<5;i++)
    cout<<obj[i];

}
