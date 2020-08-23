#include<iostream>
using namespace std;
class A
{
 int x;
 public:
     A()
     {
        cout<<"Constructor "<<endl;
     }
     A(int a):x(a){
     cout<<"paramterized constructor"<<endl;
     }
     friend void print_data(A &temp)
     {
         cout<<"X- "<<temp.x<<endl;
     }
     friend istream & operator >>(istream &in,A &temp);
     friend ostream & operator <<(ostream &out,A &temp);

};
     istream & operator >>(istream &in,A &temp)
     {
     cout<<"enter data"<<endl;
     in>>temp.x;
     return in;
     }

     ostream& operator <<(ostream &out,A &temp)
      {
     out<<"X-"<<endl;
     out<<temp.x;
     return out;
      }

main()
{
A obj1,obj2;
print_data(obj1);
cin>>obj1;
cin>>obj2;
cout<<obj1;
cout<<obj2;
//print_data(obj1);
//print_data(obj2);
}
