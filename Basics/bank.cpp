#include<iostream>
using namespace std;
class A
{
    int acc_no;
    float bal;
    char name[20];
public:
    void open_account()
    {
        cout<<"Enter name :"<<"   ";
        cin>>name;
        cout<<"Account no : "<<"   ";
        cin>>acc_no;
        cout<<"Enter balance : "<<"  ";
        cin>>bal;

    }
    void display()
    {
        cout<<"Name :"<<name<<endl;
        cout<<"Account no : "<<acc_no<<endl;
        cout<<"Balance : "<<bal<<endl;
    }
    void deposit(int m)
    {
        if(acc_no == m)
        {
            float s;
            cout<<"Enter amount to deposit ";
            cin>>s;
            bal+=s;
        }

    }
    void withdraw(int m)
    {
        if(acc_no == m)
        {
            float w;
            L1:
            cout<<name<<"current balance is : "<<bal<<endl;

            cout<<"Enter amount to withdraw ";
            cin>>w;
            if(w<=bal)
            bal-=w;
            else
            {
                cout<<"Not sufficient balance try less amount"<<endl;
                goto L1;
            }
        }
    }
    void balance(int m)
    {
        if(acc_no == m)
        {
            cout<<name<<" current balance is : "<<bal<<endl;

        }
    }
};
main()
{   A obj[3];
    int x=0;
    int n;
    int opt;
    do{
    cout<<"Bank Application "<<endl;
    cout<<"********************"<<endl;
    cout<<"Enter options "<<endl;
    cout<<"1)open "<<endl;
    cout<<"2)withdraw "<<endl;
    cout<<"3)deposit "<<endl;
    cout<<"4)display "<<endl;
    cout<<"5)check balance "<<endl;
    cout<<"6)Exit "<<endl;
    cin>>opt;
    switch(opt)
    {
        case 1:if(x<=4)
                obj[x].open_account();
                x++;
                break;
        case 2:cout<<"Enter account number  ";
               cin>>n;
               for(int i=0;i<x;i++)
                    obj[i].withdraw(n);
                    break;
        case 3:cout<<"Enter account number  ";
               cin>>n;
               for(int i=0;i<x;i++)
                    obj[i].deposit(n);
                    break;
        case 4:for(int i=0;i<x;i++)
                    obj[i].display();
                    break;
        case 5:cout<<"Enter account number  ";
               cin>>n;
               for(int i=0;i<x;i++)
                    obj[i].balance(n);
                    break;
        case 6:cout<<"Exit"<<endl;
                break;
        default:cout<<"Unknown option selexcted"<<endl;

    }}while(opt!=6);

}
