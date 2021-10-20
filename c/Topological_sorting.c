#include <stdio.h>
#define MAX 30

static int graph[MAX][MAX]={0},noOfVertices, order[MAX];

void readGraph()
{
    int numberOfEdges, startv, endv;
    printf("Enter the number of vertices & edges: \n");
    scanf("%d %d", &noOfVertices, &numberOfEdges);
    printf("\nEnter %d edges:", numberOfEdges);
    for (int edge = 0; edge < numberOfEdges; ++edge)
    {
            printf("Enter start & end vertex of edge: %d", (edge + 1));
            scanf("%d %d", &startv, &endv);
            graph[startv][endv] = 1;

    }
}
void sort()
{

    int count=0,indegree[MAX]={0},visited[MAX]={0};
    for(int v2=1;v2<=noOfVertices;v2++)
        for(int v1=1; v1<=noOfVertices;v1++)
            if(graph[v1][v2]==1)
                indegree[v2]++;

    while(count<noOfVertices)
    {

        for(int v = 1; v <= noOfVertices; v++)
        {
            if ((indegree[v] == 0) && !visited[v])
            {
                order[count++] = v;
                visited[v] = 1;
                for (int i = 1; i <= noOfVertices; i++)
                    if (graph[v][i] == 1)
                        indegree[i]--;
            }
        }
    }
}

void printOrder()
{
    printf("\nTopological Sorted Order: ");
    for (int i = 0; i < noOfVertices; i++)
        printf("%d ", order[i]);
}

int main()
{
    readGraph();
    sort();
    printOrder();
    return 0;
}
