//18)	Check given number is strong number or not.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,rev,sum1=0,sum,m,fact,i;
    printf("Enter number:");
    scanf("%d",&n);
    m=n;
    while(n!=0)
    {
        fact=1,i=1;
        sum=n%10;
        for(i=1;i<=sum;i++)
        {
            fact=fact*i;
        }
        sum1=sum1+fact;
        n=n/10;
    }
    if(sum1== m)
        printf("It is strong number");
    else
        printf("It is not strong number");
    return 0;
}
