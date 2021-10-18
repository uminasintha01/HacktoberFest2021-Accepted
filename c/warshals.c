#include <stdio.h>
#include <time.h>
int max(int, int);
void warshal(int A[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                A[i][j] = max(A[i][j], A[i][k] && A[k][j]);
}
int max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}
void main()
{
    int city[10][10] = {0};
    int n_city, n_path, from, to, i, j;
    double clk;
    clock_t starttime, endtime;
    printf("\n Enter the number of cities:");
    scanf("%d", &n_city);
    printf("\n Enter the number of paths:");
    scanf("%d", &n_path);
    for (i = 1; i <= n_city; i++)
    {
        printf("\n Enter the starting and ending city of the path %d:", i);
        scanf("%d%d", &from, &to);
        city[from][to] = 1;
    }
    printf("\n Matrix representation of input data: \n");
    for (i = 1; i <= n_city; i++)
    {
        for (j = 1; j <= n_city; j++)
            printf("%d\t", city[i][j]);
        printf("\n");
    }
    starttime = clock();
    warshal(city, n_city);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\n Transitive closure: \n");
    for (i = 1; i <= n_city; i++)
    {
        for (j = 1; j <= n_city; j++)
            printf("%d\t", city[i][j]);
        printf("\n");
    }
    printf("\nThe run time is %f seconds\n", clk);
}
