#include<stdio.h>
int main(){
    int a=0,b;
    int num[10]={56,3,65,23,89,54,31,36,87,44};
    for (int i = 0; i < 10; i++)
    {  
        
        if (num[i]>a)
        {
            a=num[i];
        }        
    }
    printf("The greatest value in the array is %d",a);

    
    
    
}