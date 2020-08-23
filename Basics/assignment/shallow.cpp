#include<iostream>
#include<cstring>
using namespace std;
class shallow
{
    char *p;
public:
   shallow()
   {

   }
   shallow(shallow &temp)
   {
       p=new char[strlen(temp.p)+1];
       strcpy(p,temp.p);
   }
   void set_data(char *s)
   {
       strcpy(p,s);
   }
   void modify()
   {
       p[0]='s';
   }
   void print_data()
   {
       cout<<" "<<p<<endl;
   }
};
main()
{
    char *q="vector";
    shallow s1;
    s1.set_data(q);
    shallow s2(s1);
    s1.print_data();
    s2.print_data();
    s1.modify();
    s1.print_data();
    s2.print_data();
}
