/*
CYK algorithm using a recursive call

The grammar and the string are fixed.

The algorithm only finds the first viable path - better than the psuedo code!


*/


#include<stdio.h>

#define n 11 //variables
#define N 10 //string length

//Variables are given integers
#define  R  0
#define  A  1
#define  B  2
#define  C  3
#define  Q  4
#define  T  5
#define  X  6
#define  Y  7
#define  Z  8
#define  a  9
#define  b  10

char Var[] = {'R','A','B','C','Q','T','X','Y','Z'}; // for printing purposes


int counter = 0;
//CFG contains the grammar
int CFG[n][n][n]={0};

int s[]={b,a,a,a,b,b,a,a,a,b}; //trial string
int W[N][N][n]={0};

// V contains the chart of the resulting grammar

int V(int i,int j,int k){
    counter++;
    int m,p,q;
    if(i==j)
        if(CFG[s[i]][s[i]][k]==1){
            printf("V(%d,%d) = %c\n",i,i,Var[k]);
            return(1);
        }
        else
            return(0);
    else
            for(p=0;p<n-2;p++)
                for(q=0;q<n-2;q++)
                    if(CFG[p][q][k]==1) //check all places in the grammar with an entry
                        for(m=i;m<j;m++){
                            if(W[i][m][p]<0)
                                W[i][m][p]=V(i,m,p);
                            if(W[m+1][j][q]<0)
                                W[m+1][j][q]=V(m+1,j,q);
                            if(W[i][m][p]==1)
                                if(W[m+1][j][q]==1)
                                    {
                                        printf("V(%d,%d) = %c\n",i,j,Var[k]);
                                        W[i][j][k]=1;
                                        return(1);
                                }
                        }
    return(0);
}


int main(){

// Here we set up the Context Free Grammar productions
// this cannot be done without Chomsky normal form!

CFG[A][Q][R] = 1;   //R -> AQ etc
CFG[T][B][Q] = 1;  
CFG[B][C][R] = 1;  
CFG[T][A][C] = 1;  
CFG[X][Y][R] = 1;  
CFG[R][X][Y] = 1;  
CFG[X][Z][T] = 1;   
CFG[T][X][Z] = 1; 
CFG[a][a][T] = 1;
CFG[b][b][T] = 1;
CFG[a][a][X] = 1;
CFG[b][b][X] = 1;
CFG[a][a][A] = 1;
CFG[b][b][B] = 1;



int i,j,k,l,m;

//initialise table: used to avoid too many function calls
for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        for(k=0;k<n;k++)
            W[i][j][k]=-1;
/*
// This reproduces the whole table
    for(k=0;k<N;k++)
    for(i=0;i<N-k;i++){
        printf("(%d,%d)",i,i+k);
        for(j=0;j<n-2;j++)
            if(V(i,i+k,j)==1)
                printf("%c ",Var[j]);
        printf("\n");
    }
  */ 



if(V(0,4,0)==1)
    printf("accept\n");
else    
    printf("reject\n");

printf("Number of recursive calls: %d\n", counter);
}