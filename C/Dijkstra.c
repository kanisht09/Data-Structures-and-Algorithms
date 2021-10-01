#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
#define inf 1000000000
typedef struct node{
      int num;      
      int weight;
      struct node *next;
}node;
struct node *temp,*change;
typedef struct list{
      struct node *next;
}list;

list *adj[MAX];
void init(){
      for(int i=0;i<MAX;i++){
            adj[i]=(list *)malloc(sizeof(list));
            adj[i]->next=NULL;
      }
}
void join(int x, int y, int w){
      temp=(struct node *)malloc(sizeof(node));
      temp->num=y;
      temp->weight=w;
      temp->next=NULL;
      if(adj[x]->next==NULL){
            adj[x]->next=temp;
      }
      else{
            change=adj[x]->next;
            while(change->next!=NULL){
                  change=change->next;
            }
            change->next=temp;
      }
}
int main(){
	init();
	int n,m;
      printf("Enter No of nodes : ");
      scanf("%d",&n);
      printf("Enter No of edges : ");
      scanf("%d",&m);
      printf("Enter data of edges in next %d lines, each line having u v w\n",m);
      while(m--){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            join(x,y,w);
            join(y,x,w);
      }
      printf("The adjacency list looks like this : \n");
      for(int i=0;i<n;i++){
            printf("%d : ",i);
            change=adj[i]->next;
            while(change!=NULL){
                  printf("-> %d ",change->num);
                  change=change->next;
            }

            printf("\n");
      }
      int s;
      printf("Enter source vertex : ");
      scanf("%d",&s);

      int dis[n],vis[n],par[n];
      for(int i=0;i<n;i++){
            dis[i]=inf;
      }
      for(int i=0;i<n;i++){
            vis[i]=0;
      }
      for(int i=0;i<n;i++){
            par[i]=-1;
      }
      dis[s]=0;
      vis[s]=1;
      int f=1;
      int u=s;
      while(f){
            // printf("u == %d\n",u);
            // fflush(stdin);
            if(adj[u]!=NULL){
                  change=adj[u]->next;
                  while(change!=NULL){
                        int v=change->num;
                        int d=change->weight;
                        if(dis[u]+d<dis[v]){
                              dis[v]=dis[u]+d;
                              par[v]=u;
                        }
                        change=change->next;
                  }
            }
            vis[u]=1;
            int minvalue=inf;
            int cur=-1;
            for(int i=0;i<n;i++){
                  if(vis[i]==0){
                        if(dis[i]<minvalue){
                              minvalue=dis[i];
                              cur=i;
                        }
                  }
            }
            if(cur==-1){
                  f=0;
            }
            else{
                  u=cur;
            }
      }
      // for(int i=0;i<n;i++) printf("%d-%d : %d and %d \n",s,i,dis[i],par[i]);

      printf("\n \n");
      for(int i=0;i<n;i++){
            printf("%d-%d : [%d] : ",s,i,dis[i]);
            int v=i;
            while(par[v]!=-1){
                  printf("%d -> ",v);
                  v=par[v];
            }
            printf("%d\n",v);
      }
	return 0;
}