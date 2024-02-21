#include<stdio.h>
int d[] ={3,2,5,2,4,3};

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
                jj = d[i-1]*d[j]*d[k];
            }
                
        }
        printf("(%d,%d) %d %d\n",i,k,jj,r);
    }
    //printf("M(%d, %d)= %d\n ",i,k,r);
    return(r);
}

int main(){
    M(1,5);
}