#include<stdio.h>
int recur(int);
main()
{
   int num,i,sum=0;
 //  printf("Enter number\n");
   //scanf("%d",&num);

  for(num=1;num<50;num++)
  {

   sum=recur(num);
  if(sum==num)
   printf("%d ",num);

  }
   /*for(i=1;i<num;i++)
   {
       if(num%i==0)
       {
           sum=sum+i;
       }
   }
   printf("sum %d\n",sum);
   if(sum==num)
   {
       printf("%d armstrong\n",num);
   }
   else
    printf("not ");
*/
}

int recur(int n)
{
static int i=1;
static int sum=0;
int nfs;
    if(i<n)
       {
            if(n%i==0)
                {
                    sum=sum+i;
                }
                i++;
                recur(n);
       }

       else
       {
           nfs=sum;
            i=1;
            sum=0;
           //printf("%d",sum);
           return nfs;
       }
}
