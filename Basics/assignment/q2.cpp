#include<iostream>
using namespace std;
void func(int &x,int &y)
{
    int t;
    t=x;
    x=y;
    y=t;
}
void func(float &x,float &y)
{
    float t;
    t=x;
    x=y;
    y=t;
}
void func(char &x,char &y)
{
    char t;
    t=x;
    x=y;
    y=t;
}

main()
{
    int k,l;
    k=10,l=20;
    char m,n;
    m='a';
    n='c';
    float o,p;
    o=23.5;
    p=7.7;

    cout<<"before "<<k<<" "<<l<<endl;
    func(k,l);
    cout<<"after "<<k<<" "<<l<<endl;

    cout<<"before "<<m<<" "<<n<<endl;
    func(m,n);
    cout<<"after "<<m<<" "<<n<<endl;

    cout<<"before "<<o<<" "<<p<<endl;
    func(o,p);
    cout<<"after "<<o<<" "<<p<<endl;


}
