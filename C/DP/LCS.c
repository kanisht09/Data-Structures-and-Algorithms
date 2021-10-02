#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **c;
char **b;
char ch[20];
char **st;
int sz;
int m,n;

void calc(int i,int j,char *s1, char *s2,int k)
{       char ch1[200]; int i1,f=1;
        if(c[i][j]==0){     // char**  malloc(sizeof(char)*100) /  char[100]
            strcpy(ch1,ch);
            for(i1=0;i1<sz;i1++)
            {
                if(!strcmp(st[i1],ch)){
                    f=0; break;
                }
            }
            if(f){
            strcpy(st[sz],ch);sz++;
            printf("%s \n",strrev(ch1));
            }
            return ;}
            if(s1[i-1]==s2[j-1]){
               ch[k]=s1[i-1];

               k++;
               calc(i-1,j-1,s1,s2,k);

               ch[k]='\0';
            }
            else if(c[i][j-1]==c[i-1][j])
            {
                calc(i-1,j,s1,s2,k);
                calc(i,j-1,s1,s2,k);
            }
            else if(c[i][j-1]<c[i-1][j])
            {
                calc(i-1,j,s1,s2,k);
            }
            else{

                calc(i,j-1,s1,s2,k);
            }
            return ;
}
int main()
{
    char *s1,*s2; int i,j; sz=0;
    s1=(char*)malloc(sizeof(char)*25);
    s2=(char*)malloc(sizeof(char)*25);

    printf("Enter the two Strings ::: \n");
    scanf("%s%s",s1,s2);
    m=strlen(s1);      //   int * <--- int var   int ** <--  int* var
    n=strlen(s2); m++; n++;

    c=(int**)malloc(sizeof(int*)*m);
    b=(char**)malloc(sizeof(char*)*m);
    st=(char**)malloc(sizeof(char*)*100);
    for(i=0;i<m;i++)
    {
        *(c+i)=(int*)malloc(sizeof(int)*n);
        *(b+i)=(char*)malloc(sizeof(char)*n);
        *(st+i)=(char*)malloc(sizeof(char)*30);
    }
    for(i=0;i<m;i++)
    {
        for( j=0;j<n;j++)
        {
            b[i][j]=' ';
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0||j==0){
                c[i][j]=0;  b[i][j]='n';
                continue;}
            if(s1[i-1]==s2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1; b[i][j]='d';
            }
            else{
                if(c[i-1][j]>=c[i][j-1])
                {
                     c[i][j]=c[i-1][j]; b[i][j]='u';

                }
                else{
                     c[i][j]=c[i][j-1]; b[i][j]='l';
                }
            }
        }
    }

    printf("The length of LCS is :: %d\n",c[m-1][n-1]);
    printf("The Different possibilities of LCS are \n");
    calc(m-1,n-1,s1,s2,0);
    printf("The Matrix C is :: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    printf("The Matrix B is :: \n");
    for( i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           printf("%c ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
