#include<iostream>
#include<cstring>
using namespace std;
class student
{
    int rollno;
    float marks;
    char name[20];
public:
    void set_data()
    {
    cout<<"Enter roll no ,marks,name "<<endl;
    cin>>rollno>>marks>>name;
    }
    void print_data()
    {
        cout<<"rollno :"<<rollno<<"\n Name :"<<name<<"\n marks : "<<marks<<endl;
    }
     void sort_data(student *s)
{
     student temp;
     int i,j;
     for(i=0;i<4;i++)
     {
         for(j=i+1;j<4;j++)
         {
             if((strcmp(s[i].name,s[j].name))>=1)
             {
                 temp=s[i];
                 s[i]=s[j];
                 s[j]=temp;
             }
         }
     }
    }

};
main()
{
    student s[4],k;
    for(int i=0;i<4;i++)
        s[i].set_data();
    cout<<"*************************************"<<endl;
    for(int i=0;i<4;i++)
        s[i].print_data();
    k.sort_data(s);
     cout<<"*************************************"<<endl;
    for(int i=0;i<4;i++)
        s[i].print_data();
}
