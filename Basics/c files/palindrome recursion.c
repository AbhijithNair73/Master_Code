#include<stdio.h>
int palind (int,int);
main()
{
   static int num=100;
    int res;
    int k=0;
    res=palind(num,k);
   if(num<500)
    {
        if(res==num)
    {
        printf("%d ",num);
    }
    num++;
    main();
   }

}
//int s=0;
int palind (int n,int s)
{

    if(n)
    {
    s=s*10+n%10;
    palind(n/10,s);
    }
    else
    {
        return s;
    }
}
