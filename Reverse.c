#include<stdio.h>
int main(){
  int num,rem,rev=0;
  printf("enter a no.:");
  scanf("%d",&num);
  while(num>=1){
    rem=num%10;
    rev=rev*10+rem;
    num=num/10;
  }
  printf("the reverse of %d is:%d",num,rev);
  return 0;
}
