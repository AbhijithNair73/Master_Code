#include<stdio.h>
int large (int *,int);
main()
{
    int a[]={10,90,55,48,31},ele,m;

    ele=sizeof(a)/sizeof(a[0]);
    m=large(a,ele);
    printf("%d\n",m);
}
int large (int *x,int ele)
{
    static int l=0,c=0;
    if(c<ele)
    {
        if(*x>l)
        {
            l=*x;
            x++;
            c++;
            large(x,ele);
        }
        else
        {
          x++;
          c++;
          large(x,ele);
        }
    }
    else
    {
        return l;
    }
}
