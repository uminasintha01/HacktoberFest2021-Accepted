#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int top = -1;
char s[50];
void push(char a)
{
    if (top==50)
    	printf("stack is full");
    else{
    	top=top+1;
    	s[top]=a;
	}
}

char pop()
{
    if(top == -1)
        printf("stack is empty");
    else
        return s[top--];
}

int order(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
int main()
{
    char exp[100];
    char *x, a;
    printf("please enter the infix expression that you want to convert to postfix : ");
    scanf("%s",exp);
    printf("\n");
    x = exp;
    
    while(*x != '\0')
    {
        if(isalnum(*x))
            printf("%c ",*x);
        else if(*x == '(')
            push(*x);
        else if(*x == ')')
        {
            while((a = pop()) != '(')
                printf("%c ", a);
        }
        else
        {
            while(order(s[top]) >= order(*x))
                printf("%c ",pop());
            push(*x);
        }
        x++;
    }
	while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
