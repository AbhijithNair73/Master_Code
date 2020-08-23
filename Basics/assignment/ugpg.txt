#include<iostream>
using namespace std;
class student
{
char name[20];
int age;
static float avg1,avg2;
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
    float age_student2()
    {
        avg2+=age;
        return avg2;
    }
    float age_student1()
    {
        avg1+=age;
        return avg1;
    }
    void print_student()
    {
        cout<<"Roll no : "<<roll<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
};
class Ug:public student
{
    int sem;
    int fees;
    float date;
public:
   static float total;
    static int c;
        void set_ug()
        {
            cout<<"ug student"<<endl;
                set_student();
                cout<<"Enter sem 1 or 2"<<endl;
                cin>>sem;
                cout<<"Enter fees paid "<<endl;
                cin>>fees;
                cout<<"Date of fees paid"<<endl;
                cin>>date;
        }
        void print_ug()
        {
            if(sem==1)
            {
                total=age_student1();
                c++;
            cout<<"ug student"<<endl;
            print_student();
            cout<<"Sem : "<<sem<<endl;
            cout<<"fees : "<<fees<<endl;
            cout<<"Date of fees paid : "<<date<<endl;
            }
        }

};
float student::avg1;
int Ug::c;
float Ug::total;
class Pg:public student
{
    int sem;
    int fees;
    float date;
public:
        void set_pg()
        {       cout<<"Pg student"<<endl;
                set_student();
                cout<<"Enter sem 1 or 2"<<endl;
                cin>>sem;
                cout<<"Enter fees paid "<<endl;
                cin>>fees;
                cout<<"Date of fees paid"<<endl;
                cin>>date;
        }
        void print_pg()
        {
            cout<<"Pg student"<<endl;
            print_student();
            cout<<"Sem : "<<sem<<endl;
            cout<<"fees : "<<fees<<endl;
            cout<<"Date of fees paid : "<<date<<endl;
        }
};
main()
{
    Ug st[3];
    Pg mt[3];
    for(int i=0;i<3;i++)
    {
        st[i].set_ug();
    }
  /*  for(int i=0;i<3;i++)
    {
        mt[i].set_pg();
    }*/
    for(int i=0;i<3;i++)
    {
        st[i].print_ug();
    }
    /*for(int i=0;i<3;i++)
    {
        mt[i].print_pg();
    }*/
    float res;
    res=st[4].total;
    res=res/st[4].c;
    cout<<"Average age of 1st sem is "<<res<<endl;

}
