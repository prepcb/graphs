/*
CYK algorithm using a recursive call

The grammar and the string are fixed.

The algorithm only finds the first viable path - better than the psuedo code!


*/


#include<stdio.h>
#define n 10 //variables
#define N 9 //string length

//Variables are given integers
#define  R  0
#define  Q  1
#define  Y  2
#define  Z  3
#define  T  4
#define  X  5
#define  A  6
#define  B  7
#define  a  8
#define  b  9

char Var[] = {'R','Q','Y','Z','T','X','A','B','a','b'}; // for printing purposes
int counter = 0;
//CFG contains the grammar
int CFG[n][n][n]={0};

int W[N][N][n]={0}; //This table array is used to avoid repeated function calls lines 54 and 55.


int s[]={b,a,b,b,a,b,b,a,b}; //trial string



// V contains the chart of the resulting grammar

int V(int i,int j,int k){
    counter++;
    int m,p,q;
    if(i==j){
        W[i][j][k]=CFG[s[i]][s[i]][k];
        return(W[i][j][k]);
    }
    else
            for(p=0;p<n-2;p++)
                for(q=0;q<n-2;q++)
                    if(CFG[p][q][k]==1) //check all places in the grammar with an entry
                        for(m=i;m<j;m++){
                            if(W[i][m][p]<0)W[i][m][p]=V(i,m,p); //don't do call unnecessarily
                            if(W[m+1][j][q]<0)W[m+1][j][q]=V(m+1,j,q);
                            if(W[i][m][p]==1&&W[m+1][j][q]==1){
                                W[i][j][k]=1;
                                return(1);
                            }
                        }
    W[i][j][k]=0;
    return(0);
}


int main(){




// Here we set up the Context Free Grammar productions
// this cannot be done without Chomsky normal form!
/*
Below is the Chomsky normal form of the grammar

R->XRX|S
S->aTb|bTa
T->XTX|X|e
X->a|b

this accepts non palindromes
*/

CFG[X][Q][R] = 1;  
CFG[A][Y][R] = 1;  
CFG[B][Z][R] = 1;  
CFG[A][B][R] = 1;  
CFG[B][A][R] = 1;  
CFG[R][X][Q] = 1;  
CFG[T][B][Y] = 1;
CFG[T][A][Z] = 1; 
CFG[X][T][T] = 1;
CFG[a][a][T] = 1;
CFG[b][b][T] = 1;
CFG[a][a][X] = 1;
CFG[b][b][X] = 1;
CFG[a][a][A] = 1;
CFG[b][b][B] = 1;



int i,j,k,l,m;

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


if(V(0,N-1,0)==1)
    printf("accept\n");
else    
    printf("reject\n");

printf("Number of recursive calls: %d\n", counter);
}