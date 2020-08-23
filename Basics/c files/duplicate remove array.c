#include<stdio.h>
main()
{
    int a[5],i,j,k,ele,c;
    ele=sizeof(a)/sizeof(a[0]);
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    for(i=0;i<ele;i++)
        printf("%d ",a[i]);
   printf("\n");
   for(i=0,c=ele;i<c;i++)
   {
       for(j=i+1;j<c;j++)
       {
           if(a[i]==a[j])
           {
               for(k=j;k<c;k++)
               a[k]=a[k+1];
               c--;

               j--;
           }
       }
   }
   for(i=0;i<c;i++)
        printf("%d ",a[i]);
}
