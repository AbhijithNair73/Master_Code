#include<stdio.h>
int fact(int );
main()
{
    int n,i,f;
    printf("Enter number\n");
    scanf("%d",&n);
    f=fact(n);

 /*   while(n)
    {

    v    f=f*n;
        n=n-1;

    }*/
    printf("fact %d\n",f);
}
int fact(int n)
{
   static int x=1;
   if(n)
   {
       x=x*n;
       fact(n-1);
   }
   else
    return x;
}
