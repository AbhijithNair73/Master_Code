#include<stdio.h>
main()
{
int num,d1,d2,d3,i;
for(num=100;num<=999;num++)
{
i=num;
d1=i%10;i/=10;
d2=i%10;i/=10;
d3=i;
//printf("%d %d %d\n",d3,d2,d1);
if(d2==(2*d1)&&d3==(3*d1))
    printf("%d\n",num);
}

}
