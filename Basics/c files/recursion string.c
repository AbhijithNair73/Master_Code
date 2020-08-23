#include<stdio.h>
void rever (char *,int);
main()
{
    int i,ele;
    char s[]="Abhijith";
    for(ele=0;s[ele];ele++);
    ele--;
    rever(s,ele);
    printf("%s\n",s);
}

 void rever (char *p,int j)
{
    static int i=0;
    int t;
    if(j>i)
    {
        t=p[i];
        p[i]=p[j];
        p[j]=t;
        i++;
        j--;
        rever (p,j);
    }

 /*   else
    {
        for(t=0;p[t];t++);
        p[t]='\0';
    }
*/

}
