#include<stdio.h>
#define n 6
#define N 5

int S = 0;
int A = 1;
int B = 2;
int C = 3;
int a = 4;
int b = 5;

//CFG contains the grammar
int CFG[n][n][n]={0};

// V contains the chart of the resulting grammar
int V[N][N][n]={0};

void G(int i,int j,int V[N][N][n],CFG[n][n][n]){
    int m;
    if(i==j)
        if(CFG[i][j][m]=1{
        V[i][i][CFG[i][m]]=1 
    }
}

int main(){
CFG[A][B][S] = 1;
CFG[A][B][C] = 1;
CFG[B][C][S] = 1;
CFG[C][C][B] = 1;
CFG[B][A][A] = 1;
CFG[a][a][A] = 1;
CFG[a][a][C] = 1;
CFG[b][b][B] = 1;  

int s[]={b,a,a,b,a}; //trial string
int i,j,k,l,m,mm;
for(i=0;i<N;i++)
    for(j=0;j<n;j++)
        if(CFG[s[i]][s[i]][j]==1)
            V[i][i][j] = 1;  
char Var[4]={'S','A','B','C'};
for(mm=1;mm<N;mm++){
printf("\n");
    for(i=0;i<N-1;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                for(l=0;l<n;l++)
                    for(m=0;m<mm;m++)
                        if(V[i][i+m][j]==1&&V[i+m+1][i+mm][k]==1)
                            if(CFG[j][k][l]==1)
                                V[i][i+mm][l] = 1;
}
for(mm=0;mm<N;mm++){
    printf("elements \n");
    for(i=0;i<N-mm;i++){
        printf("(%d %d) {",i,i+mm);
            for(j=0;j<n;j++)
                if(V[i][i+mm][j]==1)
                    printf(" %c",Var[j]);
    printf("}\n");
    }
}
}