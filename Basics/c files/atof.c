#include<stdio.h>
#include<stdlib.h>
float my_atof(char *);
main()
{
    float i,j;
    char s[10]="1.234";
    i=atof(s);
    printf(" pre defined %f\n",i);
    j=my_atof(s);
    printf(" user defined %f\n",j);
}
float my_atof(char *p)
{
float j=0,k=1;
int i,l=0;
char ch;
for(i=0;p[i];i++)
{
    if(p[i]=='.')
    {
     l=i;
     l++;
     continue;
    }
    j=j*10+(p[i]-48);
}
if(l)
{
    for(l;p[l];l++)
  {
      k=k*10;
  }
  j=j/k;
}
return j;
}
