//JOPAUL23
#include <stdio.h>
struct proc
{
    int val;
    int count;
    int st;
};
struct proc frame[20], p[20];
int fn, pn, top = -1;
int faults;
int main()
{
    for(int i= 0;i<fn;i++){
        frame[i].val = 0;
        frame[i].count = -1;
        frame[i].st = 0;
    }
    printf("ENTER THE NO OF PAGES ");
    scanf("%d", &pn);
    printf("ENTER THE NO OF FRAMES ");
    scanf("%d", &fn);
    printf("ENTER THE PAGES ");
    for (int i = 0; i < pn; i++)
    {
        scanf("%d", &p[i].val);
        p[i].count = -1;
        p[i].st = 0;
    }
int count = 0;
    for (int i = 0; i < pn; i++)
    {
        count ++;
        int flag = 0;
        if (top < fn - 1)
        {
            top++;
            frame[top].val = p[i].val;
            frame[top].st = count;
            faults++;
            printf("\nMISS %d", p[i].val);
        }
        else
        {
            for (int j = 0; j < fn; j++)
            {
                if (frame[j].val == p[i].val)
                {
                    printf("\nHIT %d", p[i].val);
                    frame[j].count++;
                    frame[j].st =  count;
                    flag++;
                    break;
                }
            }
            if (flag == 0)
            {
                int temp =  0;
                for (int j = 0; j < fn; j++)
                {
                    if(frame[j].count<=frame[temp].count&&frame[j].st<frame[temp].st){
                        temp =j;
                    }
                }

                 printf("\nMISS %d", p[i].val);
                 frame[temp].val = p[i].val;
                 faults++;
                    frame[temp].count++;
                    frame[temp].st =  count;
            }
        }
        printf("\n");
        for(int j = 0;j<fn;j++){
            printf("%d ",frame[j].val);
        }
        printf("\nFAULTS %d",faults);

    }
}