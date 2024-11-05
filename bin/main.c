#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

void initgraph(int adjmat[][maxsize], int n)
{
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adjmat[i][j] = 0;
}

void creategraph(int adjmat[][maxsize])
{
    int i, j;
    while (1)
    {
        printf("Enter node and adjacency info: ");
        scanf("%d %d", &i, &j);
        if (i == 0 && j == 0)
            break;
        adjmat[i][j] = 1;
    }
}

void display(int adjmat[][maxsize], int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%5d", adjmat[i][j]);
        }
        printf("\n");
    }
}

void initvisited(int *visited, int n)
{
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
}

void dfs(int adjmat[][maxsize], int s, int *visited, int n)
{
    visited[s] = 1;
    printf("\n %d", s);
    for (int v = 1; v <= n; v++)
    {
        if (adjmat[s][v] == 1 && visited[v] != 1)
            dfs(adjmat, v, visited, n);
    }
}

void bfs(int adjmat[][maxsize], int s, int *visited, int n)
{
    int q[maxsize], f = 0, r = -1; // Initialize queue, front and rear
    q[++r] = s; // Enqueue the source node
    visited[s] = 1; // Mark the source node as visited
    printf("\n %d", s); // Print the source node
    while (f <= r) // While the queue is not empty
    {
        s = q[f++]; // Dequeue a node
        for (int v = 1; v <= n; v++) // Check all adjacent nodes
        {
            if (adjmat[s][v] == 1 && visited[v] != 1) // If an adjacent node is found and not visited
            {
                q[++r] = v; // Enqueue the adjacent node
                visited[v] = 1; // Mark the adjacent node as visited
                printf("\n %d", v); // Print the adjacent node
            }
        }
    }
}

void checkconnectivity(int adjmat[][maxsize], int s, int *visited, int n)
{
    bfs(adjmat, s, visited, n);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            printf("\nGraph is not connected.\n");
            return;
        }
    }
    printf("\nGraph is connected.\n");
}



void bfs_recur(int adjmat[][maxsize], int *q,int *visited,int n , int f , int r){
    if(f>r)
        return;
    int s = q[f++];
    for(int v=1;v<=n;v++){
        if(adjmat[s][v]==1 && visited[v]!=1){
            q[++r] = v;
            visited[v] = 1;
            printf("\n %d",v);
        }
    }
    bfs_recur(adjmat,q,visited,n,f,r);
}


int main()
{
    int visited[maxsize], ch;
    int adjmat[maxsize][maxsize];
    int n, s;

    do
    {
        printf("1:Creategraph() 2:Display() 3:DFS 4:Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number of nodes: ");
            scanf("%d", &n);
            initgraph(adjmat, n);
            creategraph(adjmat);
            initvisited(visited, n);
            break;
        case 2:
            display(adjmat, n);
            break;
        case 3:
            printf("Enter the source node: ");
            scanf("%d", &s);
            dfs(adjmat, s, visited, n);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 4);

    return 0;
}