#include <stdio.h>
#include <limits.h>

int minKey(float key[], bool set_MST[]);
int printMST(int parent[], int n, float graph[V][V]);
void primeALGO(float graph[V][V]);
void calc_w(int *graph,int num,float *weight);
float SD(int* x1,int* x2);

int main(void)
{
   int i,V, graph[V][2];
   printf("Enter number of points\n");
   scanf("%d",&V );
   for (i = 0; i < V; i++) {
     printf("enter X , Y for %i: ",i+1);
     scanf("%d %d",&graph[i][0],&graph[i][1]);
   }
   int edg;
   printf("enter number of Edges\n");
   scanf("%d",&edg);
   float weight[V][V]={0};
   calc_w(graph,edg,weight);
    primeALGO(weight);
    return 0;
}
float SD(int *x1,int *x2)
{
  int x=x1[0]-x2[0];
  int y=x1[1]-x2[1];
  return sqrt(x*x+y*y);
}

void calc_w(int *graph,int num,float *weight)
{
  int i,val[2];
  for ( i = 0; i < num; i++) {
    printf("Enter the btween of Edge : %d\n",i+1 );
    scanf("%d %d",&val[0],&val[1] );
    weight[(val[0]-1),(val[1]-1)]=sqrt(graph[val[0]-1],graph[val[1]-1]);
  }
}

int minKey(float key[], bool set_MST[])
{
   float max = 10000, min;

   for (int v = 0; v < V; v++)
     if (set_MST[v] == false && key[v] < min)
         min = key[v], min = v;

   return min;
}

int printMST(int parent[], int n, float graph[V][V])
{
   printf("Edge   Weight\n");
   int i;
   for (i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primeALGO(float graph[V][V])
{
     int parent[V];
     float key[V];
     bool set_MST[V];

     for (i = 0; i < V; i++)
        key[i] = INT_MAX, set_MST[i] = false;

     key[0] = 0;
     parent[0] = -1;

     for (count = 0; count < V-1; count++)
     {
        int u = minKey(key, set_MST);

        set_MST[u] = true;

        for (v = 0; v < V; v++)
          if (graph[u][v] && set_MST[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     printMST(parent, V, graph);
}
