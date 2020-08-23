#include<iostream>
using namespace std;

class interest
{
    int p;
    int r;
    int n;
    int inter;
public:
    void set_data()
    {
        cout<<"Enter p r and n"<<endl;
        cin>>p>>r>>n;
        inter=(p*r*n)/100;

    }
 friend void print(interest &k)
{
    int a;
    a=k.p+k.inter;
    cout<<"interest :"<<k.inter<<endl;
    cout<<"total amount :"<<a<<endl;
}

};
main()
{
    interest a;
    a.set_data();
    print(a);
}
