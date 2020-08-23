#include<iostream>
using namespace std;
class marks;
class student
{
char name[20];
int age;
int roll;
public:
    void set_student()
    {
        cout<<"enter Name age and then roll no "<<endl;
        cin>>name;
        cout<<"Age :";
        cin>>age;
        cout<<"\nroll no :";
        cin>>roll;
    }
    void print_student()
    {
        cout<<"Roll no : "<<roll<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
 //  friend void sorting(marks (&st)[4]);
};

class marks:public student
{
    int sub[3];
public:
    void set_marks()
    {
        set_student();
        cout<<"Enter marks for 3 subjects :"<<endl;
        cin>>sub[0]>>sub[1]>>sub[2];
    }
    void print_marks()
    {
        print_student();
        for(int i=0;i<3;i++)
            cout<<sub[i]<<endl;
    }
    void sorting(marks (&st)[4]);

};

main()
{
    marks s[4];
    for(int i=0;i<4;i++)
    s[i].set_marks();
    cout<<"*********unsorted *************"<<endl;
    for(int i=0;i<4;i++)
    s[i].print_marks();
    s[1].sorting(s);
    cout<<"************sorted ****************"<<endl;
    for(int i=0;i<4;i++)
    s[i].print_marks();
}
void marks::sorting(marks(&st)[4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            if(st[i].sub[0]>st[j].sub[0])
            {
                marks temp;
                temp=st[i];
                st[i]=st[j];
                st[j]=temp;
            }
        }
    }

}
