#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
#define inf 1000000000
int min(int x, int y){
      if(x<y){
            return x;
      }
      return y;
}
typedef struct edge{
      int u,v,w;
}edge;
int n,m,s;
edge list[MAX];
int dis[MAX];
int par[MAX];
int bellman(){
      int f=0;
      for(int j=0;j<m;j++){
            int x=list[j].u;
            int y=list[j].v;
            int wt=list[j].w;

            if(dis[x]!=inf && dis[x]+wt<dis[y]){
                  dis[y]=dis[x]+wt;
                  par[y]=x;
                  f=1;
            }
      }
      return f;
}
void path(int x){
      if(x==s){
            return;
      }
      path(par[x]);
      printf("-> %d",x);
}
int main(){
      scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
            scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
      }
      for(int i=0;i<n;i++){
            dis[i]=inf;
            par[i]=-1;
      }
      scanf("%d",&s);
      dis[s]=0;
      for(int i=1;i<=n-1;i++){
            bellman();
      }

      if(bellman()){
            printf("Negative Cycle Present");
            return 0;
      }
      for(int i=0;i<n;i++){
            printf("%d-%d : [%d] : %d",s,i,dis[i],s);
            path(i);
            printf("\n");
      }
	return 0;
}