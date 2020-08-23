#include<stdio.h>
main()
{
    int a[]={10,2,4,5,2,1,3,4,6,5,8,9,2},i,j,k,ele,t[5],m[5],l,c,z=0,y=0;
    ele=sizeof(a)/sizeof(a[0]);

    for(i=0;i<ele;i++)
        printf("%d ",a[i]);
   printf("\n");
for(i=0,c=ele;i<c;i++)
   {
       for(j=i+1,l=1;j<c;j++)
       {
           if(a[i]==a[j])
           {
               for(k=j;k<c;k++)
               a[k]=a[k+1];
               c--;
               j--;
               l++;

           }
       }
       if(l==1)
       {
           t[z++]=a[i];
       }
       else
       {
           m[y++]=a[i];
       }


   }
for(i=0;i<3;i++)
        printf("%d ",m[i]);
        printf("\n");
        for(i=0;i<6;i++)
        printf("%d ",t[i]);
}
