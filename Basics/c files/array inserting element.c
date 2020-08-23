#include<stdio.h>
main()
{
int i,j,size,pos,dat;
int a[5];
size=sizeof(a)/sizeof(a[0]);
for(i=0;i<size;i++)
    scanf("%d",&a[i]);
for(i=0;i<size;i++)
    printf("%d ",a[i]);
printf("ENter position and data to be inserted\n");
scanf("%d%d",&pos,&dat);
pos--;
for(i=0;i<size;i++)
{
if(i==pos)
{
j=a[i];
a[i]=dat;
size++;
break;
}
}
for(i=size-1;i>pos+1;i--)
{
a[i]=a[i-1];
}
a[i]=j;

for(i=0;i<size;i++)
    printf("%d ",a[i]);

}
