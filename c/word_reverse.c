#include<stdio.h>
#include<string.h>
int fact(int);
int main()
{
char a[30],b[30];
int i,n,f;
printf("Enter the number of letters of the word : ");
scanf("%d",&n);
printf("Enter the word : ");
scanf("%s",a);
f=n;
for(i=0;i<n;i++)
{
b[f-1]=a[i];
--f;
}
printf("The reverse of the word is %s",b);
return 0;
}