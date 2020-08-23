#include<iostream>
using namespace std;
class wife;
class husband
{
    char name[20];
    float sal;
public:
    void set_data()
    {
        cout<<"Enter data"<<endl;
        cin>>name>>sal;
    }
    friend float incometax(husband &h,wife &w);
};
class wife
{
    char name[20];
    float sal;
public:
    void set_data()
    {
        cout<<"Enter data"<<endl;
        cin>>name>>sal;
    }
    friend float incometax(husband &h,wife &w);
};
float incometax(husband &h,wife &w)
{
    return h.sal+w.sal;
}
main()
{
    husband h1;
    wife w1;
    h1.set_data();
    w1.set_data();
    float amount;
    amount= incometax(h1,w1);
    cout<<"amount :"<<amount<<endl;
}
