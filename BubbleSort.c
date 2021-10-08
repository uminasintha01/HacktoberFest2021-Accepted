#include<stdio.h>
#include<stdlib.h>


void Swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void Bubble(int A[],int n)
{
	int i,j,flag=0;
	for(i=0;i<n-1;i++)
	{
		flag=0;

		for(j=0;j<n-1-i;j++)
		{

		if(A[j]>A[j+1])
		{
			Swap(&A[j],&A[j+1]);
			flag=1;
		}
	}
		if(flag==0)
			break;

	}

}
void printArr (int A[],int n) {
    int i;
	for (i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}

int main()
{
	int i,A[100],n;
    printf("Enter the number of elements \n" );
    scanf("%d" , &n);
    printf("Enter the array elements \n");
    for( i = 0 ; i < n ; i++ ) {
        scanf("%d" , &A[i]);
    }
	Bubble(A,n);
    printArr( A , n);
	return 0;
}
