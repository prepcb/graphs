#include<stdio.h>

int S = 0;
int A = 1;
int B = 2;
int C = 3;
int a = 4;
int b = 5;

int CFG[6][6][6]={0};
int V[5][5][6]={0};
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
int i,j,k;
for(i=0;i<5;i++)
    for(j=0;j<5;j++)
        if(CFG[s[i]][s[i]][j]==1)
            V[i][i][j] = 1;  
    
printf("Diagonal elements, where [S,A,B,C] =[0,1,2,3] are:\n");
for(i=0;i<5;i++){
    printf("\n");
    for(j=0;j<5;j++)
        if(V[i][i][j]==1)
            printf("%d ",j);
}
printf("\n");
for(i=0;i<4;i++)
    for(j=0;j<5;j++)
        for(k=0;k<5;k++)
            if(CFG[V[i][i][j]][V[i+1][i+1][k]]==1){
                V[i][i+1][j] = 1;
                V[i][i+1][k] = 1;
        }
}