#include<iostream>
#include<cstring>
using namespace std;
main()
{
    int **p,**q,**r;
    p=new int*[2];
    for(int i=0;i<2;i++)
        p[i]=new int[2];
    cout<<"enter first"<<endl;
    for(int i=0;i<2;i++)
   {
       for(int j=0;j<2;j++)
        {
        cin>>p[i][j];
        }
   }
    q=new int*[2];
    for(int i=0;i<2;i++)
    q[i]=new int[2];
    cout<<"enter second"<<endl;
    for(int i=0;i<2;i++)
    {for(int j=0;j<2;j++)
    {
    cin>>q[i][j];
    }
    }
    r=new int*[2];
    for(int i=0;i<2;i++)
    r[i]=new int[2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            r[i][j]=0;
            for(int k=0;k<2;k++)
            {
                r[i][j]+=p[i][k]*q[k][j];
            }
        }
    }
    for(int i=0;i<2;i++)
    {for(int j=0;j<2;j++)
    {
    cout<<r[i][j]<<endl;
    }
    }

}
