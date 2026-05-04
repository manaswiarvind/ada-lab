#include<stdio.h>
#define MAX 50

int max(int a,int b){
return(a>b)?a:b;
}

int main(){
int m,n;
int w[MAX],v[MAX];
int V[MAX][MAX];
int x[MAX];
int i,j;

printf("Enter no. of items:");
scanf("%d",&n);

printf("Enter weights of items:\n");
for(int i=1;i<=n;i++){
    scanf("%d",&w[i]);
}

printf("Enter values of items:\n");
for(i=1;i<=n;i++){
    scanf("%d",&v[i]);
}

printf("Enter capacity of knapsack:");
scanf("%d",&m);

for(i=0;i<=n;i++){
    for(j=0;j<=m;j++){
        if(i==0 || j==0){
            V[i][j]=0;
        }
        else if(w[i]<=j){
            V[i][j]=max(V[i-1][j],v[i]+V[i-1][j-w[i]]);
        }
        else{
            V[i][j]=V[i-1][j];
        }
    }
}
    for(i=1;i<=n;i++){
        x[i]=0;
    }
    i=n;
    j=m;
    while(i>0 && j>0){
        if(V[i][j]!=V[i-1][j]){
            x[i]=1;
            j=j-w[i];
        }
        i=i-1;
    }

    printf("\nSelected items:\n");
    for(i=1;i<=n;i++){
        if(x[i]==1){
            printf("Item %d (Weight =%d,Value=%d)\n",i,w[i],v[i]);
        }
    }
    printf("\nMaximum value=%d\n",V[n][m]);
    return 0;
}
