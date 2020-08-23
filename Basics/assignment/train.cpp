#include<iostream>
using namespace std;
int top1,top2,top3;
class A
{
    int tier1;
    int tier2;
    int tier3;
public:

    A(int i,int j,int k):tier1(i),tier2(j),tier3(k)
    {
        cout<<"tier 1 :"<<tier1<<endl;
        cout<<"tier 2 :"<<tier2<<endl;
        cout<<"tier 3 :"<<tier3<<endl;
    }
    int total1()
    {
    return tier1;
    }
    int total2()
    {
        return tier2;
    }
    int total3()
    {
        return tier3;
    }

};
class R:public A
{
    int bkt1;
    int bkt2;
    int bkt3;
public:
    R(int i,int j,int k):A(i,j,k)
    {
        bkt1=0;
        bkt2=0;
        bkt3=0;

    }
    void reservation(int op,int n)
    {int t1,t2,t3;
        t1=total1();
        t2=total2();
        t3=total3();
        switch(op)
        {
           case 1: if((bkt1+n)<=t1)
                    bkt1+=n;
                    else
                        cout<<"not available "<<endl;
                    break;

           case 2:  if((bkt2+n)<=t2)
                    bkt2+=n;
                    else
                        cout<<"not available "<<endl;
                    break;
           case 3:  if((bkt3+n)<=t3)
                    bkt3+=n;
                    else
                        cout<<"not available "<<endl;
                    break;
            default :cout<<"unknown option\n";
        }
    }
    void cancellation(int op,int n)
    {
        switch(op)
        {
        case 1: if (n<=bkt1)
                    bkt1-=n;
                    else
                        cout<<"not available "<<endl;
                    break;

           case 2:  if(n<=bkt2)
                    bkt2-=n;
                    else
                        cout<<"not available "<<endl;
                    break;
           case 3:  if (n<=bkt3)
                    bkt3-=n;
                    else
                        cout<<"not available "<<endl;
                    break;
            default :cout<<"unknown option\n";
        }
    }
    void display()
    {
        int t1,t2,t3;
        t1=total1();
        t2=total2();
        t3=total3();
    cout<<"tickets available in tier 1 :"<<t1-bkt1<<endl;
    cout<<"tickets available in tier 2  :"<<t2-bkt2<<endl;
    cout<<"tickets available in tier 3  :"<<t3-bkt3<<endl;
    }
};
main()
{
    int n,m,l;
    cout<<"Enter total seats in tier1"<<endl;
    cin>>n;
    cout<<"Enter total seats in tier2"<<endl;
    cin>>m;
    cout<<"Enter total seats in tier3"<<endl;
    cin>>l;
    R s1(n,m,l);
    int opt1;
    int seat;
    do
    {
    cout<<"enter tier which you want 1)tier1 2)tier2 3)tier3 4)exit"<<endl;
    cin>>opt1;
    switch(opt1)
    {
        case 1: cout<<"How many seats you want in tier 1?"<<endl;
                cin>>seat;
                s1.reservation(opt1,seat);
                break;
        case 2: cout<<"How many seats you want in tier 2?"<<endl;
                cin>>seat;
                s1.reservation(opt1,seat);
                break;
        case 3: cout<<"How many seats you want in tier 3?"<<endl;
                cin>>seat;
                s1.reservation(opt1,seat);
                break;

        default: cout<<"Unknown option selected"<<endl;
                    break;
    }
    s1.display();
    }while(opt1!=4);
    int opt2;
    do{
    cout<<"enter tier which you want to cancel 1)tier1 2)tier2 3)tier3 4)exit"<<endl;
    cin>>opt2;
    switch(opt2)
    {
        case 1: cout<<"How many seats you want cancel in tier 1?"<<endl;
                cin>>seat;
                s1.cancellation(opt2,seat);
                break;
        case 2: cout<<"How many seats you want cancel in tier 2?"<<endl;
                cin>>seat;
                s1.cancellation(opt2,seat);
                break;
        case 3: cout<<"How many seats you want cancel in tier 3?"<<endl;
                cin>>seat;
                s1.cancellation(opt2,seat);
                break;

        default: cout<<"Unknown option selected"<<endl;
                    break;
    }
    s1.display();
    }while(opt2!=4);
}
