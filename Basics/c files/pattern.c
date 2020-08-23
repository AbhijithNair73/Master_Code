#include<stdio.h>
main()
{
    int i,j,k;
    char ch='A';
    for(i=0;i<4;i++)
    {
        for(j=0,ch='A';j<i;j++)
            printf(" ");
        for(k=0;k<(4-i);k++)
            printf("%c ",ch++);
        printf("\n");
    }
}
