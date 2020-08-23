#include<stdio.h>
int reverses(unsigned int);
main()
{
    int i,j;
    unsigned int num;
    printf("Enter number \n");
    scanf("%d",&num);
        for(i=31;i>=0;i--)
        printf("%d",num>>i&1);
    printf("\n");
    j=reverses(num);
    for(i=31;i>=0;i--)
        printf("%d",j>>i&1);
    printf("\n");

}
int reverses(unsigned int n)
{
    static int i=0;
    static int j=31;
    if(j>i)
    {
        if((n>>j&1)==(n>>i&1))

        {
            i++;
            j--;
        }
        else
            {
                n=n^(1<<i);
                n=n^(1<<j);
                i++;
                j--;
            }
         reverses(n);
    }
    else
    {
        return n;
    }


}

/*for(i=0,j=31;i<j;i++,j--)
{m=num>>i&1;
n=num>>j&1;
    if(m!=n)
    {
        num=num^1<<i;
        num=num^1<<j;
    }
}
for(i=31;i>=0;i--)
        printf("%d",num>>i&1);
    printf("\n");
    }
*/
