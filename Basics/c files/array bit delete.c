#include<stdio.h>
main()
{
    int a[5],i,j,pos,ele;
    ele=sizeof(a)/sizeof(a[0]);
    printf("enter data\n");
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    for(i=0;i<ele;i++)
        printf("%d ",a[i]);
   printf("Enter position to delete\n");
   scanf("%d",&pos);
   pos=pos-1;
   for(pos;pos<ele;pos++)
   {
       a[pos]=a[pos+1];
   }
   for(i=0;i<ele-1;i++)
        printf("%d ",a[i]);
}
