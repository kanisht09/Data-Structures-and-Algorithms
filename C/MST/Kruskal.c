//O(ElogV) sol,using DSU(Path Compression)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1005
#define MAX 100005
#define inf 1000000000

typedef struct edge{
	int u, v, w;
}edge;
edge elist[MAX];

int cnt=0;
int n,m;
int adj[N][N];
int par[MAX];
void sort() {
  int i, j;
  edge temp;

  for (i = 1; i <cnt; i++)
    for (j = 0; j < cnt- 1; j++)
      if (elist[j].w > elist[j + 1].w) {
        temp = elist[j];
        elist[j] = elist[j + 1];
        elist[j + 1] = temp;
      }
}
void init(){
	
	while(m--){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		x--;
		y--;
		adj[x][y]=w;
		adj[y][x]=w;
	}
	for(int i=0;i<n;i++){
		printf("%d : ",i);
		for(int j=0;j<n;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adj[i][j]!=0){
				elist[cnt].u=i;
				elist[cnt].v=j;
				elist[cnt].w= adj[i][j];
				cnt++;
			}
		}
	}
	sort();
	for(int i=0;i<cnt;i++){
		printf("%d %d : %d\n",elist[i].u, elist[i].v, elist[i].w);
	}
	printf("\n");
}


int kruskal1(){
	for(int i=0;i<n;i++){
		par[i]=i;
	}
	int sum=0;
	for(int i=0;i<cnt;i++){
		if(par[elist[i].u]!=par[elist[i].v]){
			sum+=elist[i].w;
			printf("%d %d : %d\n",elist[i].u, elist[i].v, elist[i].w);

			int x=par[elist[i].u];
			int y=par[elist[i].v];
			for(int j=0;j<n;j++){
				if(par[j]==x){
					par[j]=y;
				}
			}
			
		}
	}
	// for(int i=0;i<n;i++){
	// 	printf("(%d:%d) ",i,par[i]);
	// }
	printf("\n");
	return sum;
}

int Find(int u){
	if(u==par[u]){
		return u;
	}
	return par[u]=Find(par[u]);
}

void Union(int u, int v) {
	u=Find(u);
	v=Find(v);
	par[u]=v;
}
int kruskal2(){
	for(int i=0;i<n;i++){
		par[i]=i;
	}
	int sum=0;
	for(int i=0;i<cnt;i++){
		int x=Find(elist[i].u);
		int y=Find(elist[i].v);
		if(x!=y){
			sum+=elist[i].w;
			printf("%d %d : %d\n",elist[i].u, elist[i].v, elist[i].w);
			Union(elist[i].u,elist[i].v);
		}
	}
	// for(int i=0;i<n;i++){
	// 	printf("(%d:%d) ",i,par[i]);
	// }
	printf("\n");
	return sum;
}
int main(){

	init();
	int res1=kruskal1();
	printf("res1 is : %d\n\n",res1);
	int res2=kruskal2();
	printf("res2 is : %d\n\n",res2);
	return 0;
}