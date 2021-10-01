#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
#define N 1005
#define inf 1000000000
int min(int x, int y){
      if(x<y){
            return x;
      }
      return y;
}
int n,m,s;
int adj[N][N];
int path[N][N];
void init(){
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(i==j){
                        adj[i][j]=0;
                  }
                  else{
                        adj[i][j]=inf;   
                  }
                  path[i][j]=i;
            }
      }
}
void printpath(int x){
      if(s==x){
            printf("%d -> ",x);
      }
      else{
            printpath(path[s][x]);
            printf("%d -> ",x);
      }
}
int main(){
      
      scanf("%d %d",&n,&m);
      init();
      for(int i=1;i<=m;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            //x--;
            //y--;
            adj[x][y]=w;
            adj[y][x]=w;   //undirected
      }
      for(int k=0;k<=n-1;k++){
            for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                        if(adj[i][k]+adj[k][j] < adj[i][j]){
                              adj[i][j]=adj[i][k]+adj[k][j];
                              path[i][j]=path[k][j];
                        }
                  }
            }
      }
      for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  if(adj[i][j]==inf){
                        printf("-1 ");
                  }
                  else{
                        printf("%d ",adj[i][j]);
                  }
                  
            }
            printf("\n");
      }
      printf("\n\n");
      scanf("%d",&s);
      for(int i=0;i<n;i++){
            printf("%d-%d : [%d] : ",s,i,adj[s][i]);
            printpath(path[s][i]);
            printf("%d\n",i);
      }
	return 0;
}