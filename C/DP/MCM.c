#include <stdio.h>
#include <stdlib.h>
#define MAX 1005
#define inf 1000000000
int m[MAX][MAX],s[MAX][MAX];
void PrintFinal(int i, int j){
      if(i==j){
            printf("%c",i+64);
            return;
      }
      printf("(");
      PrintFinal(i,s[i][j]);
      PrintFinal(s[i][j]+1,j);
      printf(")");
}
void fun(int n, int d[]){
      
      for(int i=0;i<n;i++){
            m[i][i]=0;
            s[i][i]=0;
      }

      for(int l=2;l<n;l++){
            for(int i=1;i<n-l+1;i++){
                  int j=i+l-1;
                  m[i][j]=inf;
                  for(int k=i;k<=j-1;k++){
                        int q=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
                        if(q<m[i][j]){
                              m[i][j]=q;
                              s[i][j]=k;
                        }
                  }
            }
      }

      printf("Matrix M is : \n");
      for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                  if(i<=j){
                        printf("%d\t",m[i][j]);
                  }
                  else{
                        printf(" \t");
                  }
                  
            }
            printf("\n");
      }
      printf("\n\n");
      printf("Matrix S is : \n");
      for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                  if(i<=j){
                        printf("%d\t",s[i][j]);
                  }
                  else{
                        printf(" \t");
                  }
            }
            printf("\n");
      }

      printf("\nOptimal Cost is : %d\n",m[1][n-1]);
      printf("Final Ordering is : ");
      PrintFinal(1,n-1);
}
int main(){

      int n;
      scanf("%d",&n);
      int d[n];
      for(int i=0;i<n;i++){
            scanf("%d",&d[i]);
      }
      printf("Dimensions are : ");
      for(int i=0;i<n-1;i++){
            printf("(%d X %d) ",d[i],d[i+1]);
      }
      printf("\n\n");
      fun(n,d);

      

      return 0;
}