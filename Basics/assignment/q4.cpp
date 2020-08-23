#include<iostream>
using namespace std;
class employee
{
int age;
float salary;
char name[20];
int yos;
public:
    void set_data()
    {
        cout<<"Enter name age year of service and salary of employee"<<endl;
        cin>>name>>age>>yos>>salary;
    }
    void check_data()
    {
        if(salary>15000)
        {
            salary=20000;
            cout<<"Name :"<<name<<"\n Age :"<<age<<"\n Year of service:"<<yos<<"\n salary:"<<salary<<endl;
        }
    }
    void print_data()
    {
        cout<<"Name :"<<name<<"\n Age :"<<age<<"\n Year of service:"<<yos<<"\n salary:"<<salary<<endl;
    }

};

main()
{
    int i;
    employee a[5];
    for(i=0;i<4;i++)
    a[i].set_data();

        for(i=0;i<4;i++)
    a[i].print_data();
    cout<<"*****************************"<<endl;

    for(i=0;i<4;i++)
    a[i].check_data();

}
