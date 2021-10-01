//O(V^3) sol
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1005
#define MAX 100005
#define inf 1000000000
int adj[N][N];
int vis[N];
int edges[N][3];
int main(){

	int n,m;
	scanf("%d %d",&n,&m);
	memset(adj,-1,sizeof(adj));
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
	vis[0]=1;
	int sum=0;
	for(int k=0;k<n-1;k++){
		int minw=inf;
		int x=-1,y=-1;
		for(int i=0;i<n;i++){
			if(vis[i]){
				for(int j=0;j<n;j++){
					if(adj[i][j]!=-1 && !vis[j] && adj[i][j]<minw){
						minw=adj[i][j];
						x=i;
						y=j;
					}
				}
			}
		}
		if(x==-1 && y==-1){
			printf("Spanning tree not possible\n");
			return;
		}
		vis[y]=1;
		edges[k][0]=x;
		edges[k][1]=y;
		edges[k][2]=adj[x][y];
		sum+=adj[x][y];
	}

	for(int i=0;i<n-1;i++){
		printf("%d %d : %d\n",edges[i][0],edges[i][1],edges[i][2]);
	}
	printf("The MST weight is : %d",sum);
	return 0;
}