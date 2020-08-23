#include<stdio.h>
main()
{
    int i,pos;
double d=3.5;
float f=3.5;
char *fp,*dp;
fp=&f;
fp=fp+3;
dp=&d;
dp=dp+7;
for(i=0;i<4;i++)
{
for(pos=7;pos>=0;pos--)
{
 printf("%d",(*fp)>>pos&1);
}
printf(" ");
fp=fp-1;
}
printf("now double\n");
for(i=0;i<8;i++)
{
for(pos=7;pos>=0;pos--)
{
 printf("%d",(*dp)>>pos&1);
}
printf(" ");
dp=dp-1;
}


}
