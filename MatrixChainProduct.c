#include<stdio.h>
int d[] ={3,2,5,2,4,3};
int W[6][6];
int J[6][6];

void Brackets(int i,int k){
    if(i==k)
        printf("A[%d]",i);
    else if(k==i+1)
        printf("(A[%d],A[%d])",i,k);
    else{
        printf("(");
        Brackets(i,J[i][k]);
        Brackets(J[i][k]+1,k);
        printf(")");
    }
    return;
}

int min(int a, int b){
    if(a<b)
        return(a);
    else
        return(b);

}
int M(int i,int k){
    int j,r,jj;
    if(i==k)
        return(0);
    else{
        //printf("(%d,",i);
        r = 999;
        for(j=i;j<k;j++){
            if(M(i,j)+d[i-1]*d[j]*d[k]+M(j+1,k)<r){
                r = M(i,j)+d[i-1]*d[j]*d[k]+M(j+1,k);
                jj = j;
            }
                
        }
    }
    W[i][k]=r;
    J[i][k]=jj;
    return(r);
}

int main(){
    M(1,5);

    int i,j;
    for(i=1;i<6;i++){
        printf("\n");
        for(j=1;j<6;j++)
            if(j<i)
                printf("          ");
            else
                printf("%4d,(j=%d)",W[i][j],J[i][j]);
    
    }
    printf("\n");
    Brackets(1,4);
    printf("\n");
    
}