#include<stdio.h>
#define n 6
int W[n][n];

int min(int a,int b){
    if(a<b)
        return(a);
    else    
        return(b);
}
void Mult(int A[n][n],int B[n][n],int C[n][n]){
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            C[i][j]=999;
            for(k=0;k<n;k++){
                C[i][j] = min(A[i][k]+B[k][j],C[i][j]);
                }
        }
}

int main(){
int i,j,W2[n][n],W4[n][n],D[n][n];

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        W[i][j]=999;



for(i=0;i<n;i++)
    W[i][i]=0;

W[0][1]=5;
W[0][2]=3;
W[1][3]=5;
W[2][1]=4;
W[2][4]=3;
W[3][1]=8;
W[3][4]=-5;
W[3][5]=12;
W[4][1]=7;
W[4][2]=-2;
W[4][5]=-1;
W[5][4]=8;


printf("\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        printf("%4d",W[i][j]);
    printf("\n");
}
Mult(W,W,W2);
Mult(W2,W2,W4);
Mult(W,W4,D);

printf("\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        printf("%4d",D[i][j]);
    printf("\n");
}

}