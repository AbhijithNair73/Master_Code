#include<stdio.h>
int * rever(int *,int);
main()
{
    int a[]={10,90,55,48,31},ele,i;
    int *q;
    ele=sizeof(a)/sizeof(a[0]);
    q=rever(a,ele-1);
    for(i=0;i<ele;i++)
    {
        printf("%d ",a[i]);
    }

}
int * rever(int *p,int j)
{
    int t;
    static int c=0;
    if(c<j)
    {
        t=*(p+c);
        *(p+c)=*(p+j);

        *(p+j)=t;
        c++;
        j--;
        rever (p,j);
    }

    else
    {

        return p;
    }

}
