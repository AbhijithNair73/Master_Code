#include<stdio.h>
main()
{
    int a[5],i,j,ele;
    int l,s,sl,ss;
    ele=sizeof(a)/sizeof(a[0]);
    printf("enter data\n");
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    for(i=0;i<ele;i++)
        printf("%d ",a[i]);
    if(a[0]>a[1])
    {
        l=a[0];
        sl=a[1];
    }
    else
    {
        l=a[1];
        sl=a[0];
    }
    for(i=2;i<ele;i++)
    {
        if(a[i]>l)
        {
            sl=l;
            l=a[i];
        }
        else if(a[i]>sl)
        {
            sl=a[i];
        }
    }
    if(a[0]<a[1])
    {
        s=a[0];
        ss=a[1];
    }
    else
    {
        s=a[1];
        ss=a[0];
    }
    for(i=2;i<ele;i++)
    {
        if(a[i]<s)
        {
            ss=s;
            s=a[i];
        }
        else if(a[i]<ss)
        {
            ss=a[i];
        }
    }
    printf("large %d and second large %d \n",l,sl);
    printf("small %d and second small %d \n",s,ss);
}
