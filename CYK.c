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

//CFG contains the grammar
int CFG[n][n][n]={0};

// V contains the chart of the resulting grammar
int V[N][N][n]={0};

int counter =0;

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

int s[]={b,a,a,b,a}; //trial string



int i,j,k,m,p,q,r;


for(i=0;i<N;i++)
    for(j=0;j<n;j++)
        if(CFG[s[i]][s[i]][j]==1){
            V[i][i][j] = 1;  
            counter++;
        }
char Var[4]={'S','A','B','C'}; // used for printing

for(k=0;k<N;k++) //N string length
    for(i=0;i<N-k-1;i++){
        j=i+1+k;
        for(m=i;m<j;m++) //m is the middle index
            for(p=0;p<n;p++) //n : number of variables
                for(q=0;q<n;q++)
                    if(V[i][m][p]==1&&V[m+1][j][q]==1)
                        for(r=0;r<N;r++)
                            if(CFG[p][q][r]==1){
                                V[i][j][r]=1; //add the value, r, in table
                                counter++;
                            }
    }


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
printf("Number of table updates: %d\n", counter);
}