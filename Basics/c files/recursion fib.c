#include<stdio.h>
void fib (int);
main()
{
    int num;
    int i,j;
    printf("Enter number \n");
    scanf("%d",&num);
    fib(num);

}
void fib(int n)
{
    static int a=1,b=0,c=0;
    if(n)
    {
        c=a+b;
        a=b;
        b=c;
        printf("%d ",c);
        fib(n-1);
    }
}
