#include<iostream>
#include<cstring>
using namespace std;
main()
{
    char **p;
    p=new char*[5];
    for(int i=0;i<5;i++)
        p[i]=new char[10];
    cout<<"enter names"<<endl;
    for(int i=0;i<5;i++)
    {
    cin>>p[i];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
            {
                if(strcmp(p[i],p[j])>=1)
                {
                    char d[15];
                    strcpy(d,p[i]);
                    strcpy(p[i],p[j]);
                    strcpy(p[j],d);
                }
            }
    }
    for(int i=0;i<5;i++)
    {
    cout<<p[i]<<endl;
    }
}
/*
#include<iostream>
using namespace std;
int main()
{
int i,j,k;
char **p;
char *temp;
p = new char *[5];
for(i=0;i<5;i++)
p[i] = new char [10];
cout << "Enter Data : " << endl;
for(i=0;i<5;i++)
cin >> p[i];
for(i=0;i<4;i++)
{
for(j=0;j<4-i;j++)
{
for(k=0;;)
{
if(p[j+1][k] < p[j][k])
{
temp = p[j];
p[j] = p[j+1];
p[j+1] = temp;
}
else if(p[j+1][k] == p[j][k])
{
k++;
}
else
break;
}
}
}
cout << "After Sorting " << endl;
for(i=0;i<5;i++)
cout << p[i] << endl;
}
*/
