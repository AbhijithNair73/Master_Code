#include<stdio.h>
main()
{
    int a[7]={10,20,10,10,20,20,10},i,j,k,ele,c,l;
    ele=sizeof(a)/sizeof(a[0]);
  //  for(i=0;i<ele;i++)
    //    scanf("%d",&a[i]);
   // for(i=0;i<ele;i++)
     //   printf("%d ",a[i]);
   //printf("\n");
   for(i=0,c=ele;i<c;i++)
   {
       for(j=i+1,k=1;j<c;j++)
       {
           if(a[i]==a[j])
           {
            k++;
            for(l=j;l<c;l++)
            {
                a[l]=a[l+1];
            }
            c--;
            j--;
           }
       }
   if(k>1)
   {
    printf("%d is printed %d times\n",a[i],k);
   }
   }

}
