#include<stdio.h>
#include<stdlib.h>
int my_atoi(char *);
main()
{
    int i,j;
    char s[10]="1234";
    i=atoi(s);
    printf(" pre defined %d\n",i);
    j=my_atoi(s);
    printf(" user defined %d\n",j);
}
int my_atoi(char *p)
{
int i,j=0;
char ch;
for(i=0;p[i];i++)
{
    if(p[i]>='0'&& p[i]<='9')
    j=j*10+(p[i]-48);
}
return j;
}
