/*
CYK algorithm using a recursive call

The grammar and the string are fixed.

The algorithm only finds the first viable path - better than the psuedo code!


*/


#include<stdio.h>
#define n 6 //variables
#define N 5 //string length

//Variables are given integers
#define  S  0
#define  A  1
#define  B  2
#define  C  3
#define  a  4
#define  b  5

char Var[] = {'S','A','B','C'}; // for printing purposes

//CFG contains the grammar
int CFG[n][n][n]={0};

int s[]={b,a,a,b,a}; //trial string


// V contains the chart of the resulting grammar

int V(int i,int j,int k){
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

CFG[A][B][S] = 1;   // S -> AB
CFG[A][B][C] = 1;   // C -> AB
CFG[B][C][S] = 1;   // S -> BC
CFG[C][C][B] = 1;   // B -> CC
CFG[B][A][A] = 1;   // A -> BA
CFG[a][a][A] = 1;   // A -> a   in fact we only use the first slot; see line 43
CFG[a][a][C] = 1;   // C -> a                   ""
CFG[b][b][B] = 1;   // B -> b                   ""



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



if(V(0,4,0)==1)
    printf("accept\n");
else    
    printf("reject\n");
}