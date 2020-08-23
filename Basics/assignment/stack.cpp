#include<iostream>
using namespace std;
int top;
template<class T1>
class A
{
    T1 stack[5];
public:
    void push();
    void pop();
    void display();

};
template<class T1>
void A<T1>::push()
{
    if(top<0)
    {
        top=0;
    }

    if(top>=5)
    {
    cout<<"stack is full"<<endl;
    return;
    }
    cout<<"enter data "<<endl;
    cin>>stack[top++];
}
template<class T1>
void A<T1>::pop()
{
    if(top<=0)
    {
        cout<<"stack empty "<<endl;
    }
    else
    cout<<"Data :"<<stack[--top]<<endl;
}
template<class T1>
void A<T1>::display()
{
    for (int i=0;i<top;i++)
        cout<<stack[i]<<"  ";
}

template<class T2>
void operation (A <T2> &m)
{
    int opt;
    do
    {
    cout<<"Enter 1 to push 2 to pop 3 to display 4 to exit\n";
    cin>>opt;
    switch (opt)
    {
        case 1: m.push();
                break;
        case 2: m.pop();
                break;
        case 3: m.display();
                break;
        case 4: cout<<"eXIT"<<endl;
                break;
        default:
            cout<<"unknown option "<<endl;
    }
    }while (opt!=4);
}

main()
{
A<int>obj1;
A<char>obj2;
A<float>obj3;

    int opt1;
    do
    {
     cout<<"Enter 1 to int 2 to char 3 to float 4 to exit\n";
    cin>>opt1;
    switch (opt1)
    {
        case 1: operation(obj1);
                break;
        case 2: operation(obj2);
                break;
        case 3: operation(obj3);
                break;
        case 4: cout<<"eXIT"<<endl;
                break;
        default:
            cout<<"unknown option "<<endl;
    }
    }while(opt1!=4);

}
