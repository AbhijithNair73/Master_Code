#include<stdio.h>
main()
{
/*    int a[5],i,j,ele,c=0,b[5],k=0;
    ele=sizeof(a)/sizeof(a[0]);
    printf("enter data\n");
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    for(i=0;i<ele;i++)
       {
        for(j=2;j<a[i];j++)
        {
            if(a[i]%j==0)
                break;
        }
        if(a[i]==j)
        {
            b[k]=a[i];
            k++;
            c++;
        }
       }
       printf("c=%d  k=%d  ",c,k);
       for(i=0;i<c;i++)
        printf("%d ",b[i]);
*/
int a[5]={10,20,30,40,50};
int (*p)[2]=a;
printf("%d\n",sizeof(p));
}
