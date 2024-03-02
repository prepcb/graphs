#include<stdio.h>
#define n 6 //variables
#define N 5 //string length

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




int i,j,k,m,p,q,r;


for(i=0;i<N;i++)
    for(j=0;j<n;j++)
        if(CFG[s[i]][s[i]][j]==1)
            V[i][i][j] = 1;  
char Var[4]={'S','A','B','C'};

for(k=0;k<N;k++)
    for(i=0;i<n-k-1;i++){
        j=i+1+k;
        for(m=i;m<j;m++)
            for(p=0;p<N;p++)
                for(q=0;q<N;q++)
                    if(V[i][m][p]==1&&V[m+1][j][q]==1)
                        for(r=0;r<N;r++)
                            if(CFG[p][q][r]==1){
                                V[i][j][r]=1;

                                //start: next bit only lets S be in the final V(0,N-1) position
                                if(i==0&j==N-1){
                                }
                                else if(r==S)
                                    V[i][j][r]=0;
                                // end:
                            }
    }


/*
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
}*/
for(k=0;k<N;k++){
    printf("elements \n");
    for(i=0;i<N-k;i++){
        printf("(%d %d) {",i,i+k);
            for(j=0;j<n;j++)
                if(V[i][i+k][j]==1)
                    printf(" %c",Var[j]);
    printf("}\n");
    }
}
}