#include<stdio.h>
main()
{
    int a[5],i,j,pos,ele,t,l;
    ele=sizeof(a)/sizeof(a[0]);
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    for(i=0;i<ele;i++)
        printf("%d ",a[i]);
   printf("\n");
   printf("Enter position to enter\n");
   scanf("%d",&pos);
   pos=pos-1;
   l=pos;
   printf("Now enter value to be inserted\n");
   scanf("%d",&j);
    for(i=ele-1;i>=pos;i--)
        a[i+1]=a[i];

    a[pos]=j;

    for(i=0;i<ele;i++)
        printf("%d ",a[i]);
}
