#include<stdio.h>
void rever(char *,int);
main()
{
    char s[]="abcd_1234";
    char ch;
     printf("%s",s);
    int i,j,k;
    for(i=0;s[i];i++)
    {
        if(s[i]=='_')
        {
            j=i-1;
            k=i+1;
        }
    }
    printf("%d\n",i);
    i--;
    for(k;k<i;k++)
    {
        ch=s[k];
        s[k]=s[i];
        s[i]=ch;
        i--;
    }
    i=0;
    for(j;j>i;j--)
    {
        ch=s[i];
        s[i]=s[j];
        s[j]=ch;
        i++;

    }
    printf("%s",s);

}
