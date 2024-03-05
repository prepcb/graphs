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

int s[]={b,a,b,a,a,b,a,a,a,b}; //trial string


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
                        for(m=i;m<j;m++)
                            if(V(i,m,p)==1&&V(m+1,j,q)==1)
                                {
                                    printf("V(%d,%d) = %c\n",i,j,Var[k]);
                                    return(1);
                                }
    return(0);
}


int main(){




// Here we set up the Context Free Grammar productions
// this cannot be done without Chomsky normal form!

CFG[A][Q][R] = 1;   // S -> AB
CFG[T][B][Q] = 1;   // C -> AB
CFG[B][C][R] = 1;   // S -> BC
CFG[T][A][C] = 1;   // B -> CC
CFG[X][Y][R] = 1;   // A -> BA
CFG[R][X][Y] = 1;   // A -> a   in fact we only use the first slot; see line 43
CFG[X][Z][T] = 1;   // C -> a                   ""
CFG[T][X][Z] = 1;   // B -> b                   ""
CFG[a][a][T] = 1;
CFG[b][b][T] = 1;
CFG[a][a][X] = 1;
CFG[b][b][X] = 1;
CFG[a][a][A] = 1;
CFG[b][b][B] = 1;



int i,j,k,l,m;


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

k=1;
for(i=0;i<10;i++)
    for(j=0;j<N;j++){
        s[j] = i&k;
        k=2*k;
}

if(V(0,N-1,0)==1)
    printf("accept\n");
else    
    printf("reject\n");

printf("Number of recursive calls: %d\n", counter);
}