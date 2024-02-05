#include<stdio.h>
#include<stdbool.h> 
#define INF 999
#define V 3

int main() {
  int no_edge,v, G[V][V],i,j;
  printf("Enter number of vertices: ");
  scanf("%d", &v);
  for(i = 0; i < v; i++)
    {
        for(j = 0; j < v; j++)
        {
            printf("weight of edge V%d - V%d (0 for no edge) : ",i+1,j+1);
            scanf("%d", &G[i][j]);
        }
    }
  int selected[V];
  memset(selected, false, sizeof(selected));
  no_edge = 0;
  selected[0] = true;
  int x;  //  row number
  int y;  //  col number
  printf("Edge : Weight\n");
  while (no_edge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;
    for (i = 0; i < V; i++) {
      if (selected[i]) {
        for (j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
              if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }}}}
    if(G[x][y]!=0)
        printf("%d - %d : %d\n", x+1, y+1, G[x][y]);
    selected[y] = true;
    no_edge++;
  }
  return 0;
}