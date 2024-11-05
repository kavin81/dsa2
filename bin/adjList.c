#include <stdio.h>
#include <stdlib.h>

#define maxnodes 10

struct node {
    int adj;
    struct node *link;
};

typedef struct node graph;

void initgraph(graph **listptr) {
    for (int i = 1; i <= maxnodes; i++)
        listptr[i] = NULL;
}

void creategraph(graph **listptr, int n) {
    int i, j;
    while (1) {
        printf("Enter node and adjacency info (or 0 0 to stop): ");
        scanf("%d %d", &i, &j);
        if (i == 0 && j == 0)
            break;
        insert_rear(listptr, i, j);
    }
}
void initvisited(int *visited,int n)
{
    for(int i=1;i<=n;i++)
}


void dfs(graph **listptr,int s,int n,int *visited)
{
    int adj;
    visited[s]=1;
    printf("\n%d",s);
    for (graph *cur=listptr[s];cur!=NULL;cur=cur->link)
    {
        adj=cur->adj;
        if(visited[adj]!=1)
            dfs(listptr,adj,n,visited);
    }
}

void insert_rear(graph **listptr, int i, int j) {
    graph *temp, *cur;
    temp = (graph *)malloc(sizeof(graph));
    temp->adj = j;
    temp->link = NULL;

    if (listptr[i] == NULL) {
        listptr[i] = temp;
    } else {
        cur = listptr[i];
        while (cur->link != NULL)
            cur = cur->link;
        cur->link = temp;
    }
}


void display(graph **listptr, int n) {
    graph *cur;
    for (int i = 1; i <= n; i++) {
        cur = listptr[i];
        printf("\nNodes adjacent to %d are:", i);
        while (cur != NULL) {
            printf(" %d ->", cur->adj);
            cur = cur->link;
        }
        printf(" NULL");
    }
    printf("\n");
}

int main() {
    graph *listnode[maxnodes];
    int n, s, conn;
    int ch;
    do {
        printf("\n1: Create Graph\n2: Display\n3: DFS\n4: BFS\n5: Check Connectivity\n6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                initgraph(listnode, n);
                creategraph(listnode,n);
                initvisited(visited, n);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the source node for DFS: ");
                scanf("%d", &s);
                initvisited(visited, n);
                dfs();
                break;
            case 4:
                printf("Enter the source node for BFS: ");
                scanf("%d", &s);
                initvisited(listnode,s,visited, n);
                bfs();
                break;
            case 5:
                initvisited(visited, n);
                dfs();
                conn = check_connect(visited, n);
                if (conn == 1)
                    printf("The graph is connected.\n");
                else
                    printf("The graph is not connected.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 6);

    return 0;
}