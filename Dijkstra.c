#include<stdio.h>
#define N 8
int D[N][N]={0};

//function finds minimum element of L w.r.t.l[i]
int minL(int L[],int l[]){
    int i,ii,min=9999;
    for(i=0;i<N;i++)
        if(L[i]==1){ //only find min if in queue
            if(l[i]<min){
            ii = i;
            min = l[i];
        }
    }
    return(ii);
}


int main(){
    //set up graph D with weights on edges
D[0][3]=15;
D[0][1]=9;
D[0][2]=14;
D[1][5]=23;
D[2][4]=30;
D[2][3]=5;
D[2][5]=18;
D[3][4]=20;
D[3][7]=44;
D[4][6]=11;
D[4][7]=16;
D[5][4]=2;
D[5][7]=19;
D[6][7]=16;
D[6][5]=5;

int s = 0; //start vertex
int v;
int visited[N]={0};
int l[N]={0};   //array for distance to each vertex
int L[N]={0};   
int F[N][N]={0};//final tree with optimal paths 
int p[N] = {0}; // previous node
int Lq = N;     // counter as list L reduces in size
for(v=1;v<N;v++){
    visited[v]=0; //visited < - false
    l[v]=9999; //l[v] <- infinity
    L[v]=1; 
}
visited[s] = 1; //visited = true
l[s] = 0;
for(v=1;v<N;v++)
    if(L[v]==0){
        l[v]=D[s][v];   //distance to neighbours of start node 0
        p[v]=s;         //neighbour previous node is start node
    }
int u;

while(Lq>0){  // L not null
    u = minL(L,l);//choose u ∈ L with smallest l[u]
    printf("u is %d\n",u);
    L[u] = 0; //L ← L \ {u}
    Lq--;
    F[p[u]][u] = D[p[u]][u]; // add edge
    visited[u] = 1; //visited <- true
    for(v=0;v<N;v++)
        if(D[u][v]>0){ //v ∈ N(u) (neighbour of u)
            if((visited[v]==0)&&(l[v]>l[u]+D[u][v])){
                l[v]=l[u]+D[u][v];  //l[v] ← l[u] + w(u, v); 
                p[v] = u;           //p[v] ← u;
            }

        }

}
printf("Final subset contaning optimal paths\n");
for(u=0;u<N;u++){
    for(v=0;v<N;v++)
        printf("%4d",F[u][v]);
    printf("\n");

}
printf("\nDistances to nodes 0 to 7\n");
for(u=0;u<N;u++)
    printf("%4d",l[u]);
printf("\n");

}