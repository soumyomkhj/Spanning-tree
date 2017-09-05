#include <stdio.h>
#include <limits.h>
#define V 5
int minKey(int key[], bool set_MST[]);
int printMST(int parent[], int n, int graph[V][V]);
void primeALGO(int graph[V][V]);


int main(void)
{
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    primeALGO(graph);
    return 0;
}

int minKey(int key[], bool set_MST[])
{
   int min = INT_MAX, min;

   for (int v = 0; v < V; v++)
     if (set_MST[v] == false && key[v] < min)
         min = key[v], min = v;

   return min;
}

int printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primeALGO(int graph[V][V])
{
     int parent[V];
     int key[V];
     bool set_MST[V];

     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, set_MST[i] = false;

     key[0] = 0;
     parent[0] = -1;

     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, set_MST);

        set_MST[u] = true;

        for (int v = 0; v < V; v++)
          if (graph[u][v] && set_MST[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     printMST(parent, V, graph);
}
