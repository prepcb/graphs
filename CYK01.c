#include<stdio.h>

void CFG(char X,char Y,char *s){
    if(X=='A'&&Y=='B'){
        s[0]='S';
        s[1]='C';
        }
    else if(X=='B'&&Y=='C'){
        s[0]='S';
        s[1]=0;
    }
    else if(X=='C'&&Y=='C'){
        s[0]='B';
        s[1]=0;
    }
    else if(X=='B'&&Y=='A'){
        s[0]='A';
        s[1]=0;
    }
    else if(X=='a'){
        s[0]='A';
        s[1]='C';
    }
    else if(X=='b'){
        s[0]='B';
        s[1]=0;
    }
    else{
        s[0]=0;
        s[1]=0;
    }       
}
int main(){
    char s[99]={0};
    int i,j,k;
    CFG('a','B',s);
    for(i=0;i<99;i++)
        if(s!=0)
            printf("%c",s[i]);
    char c[]={'b','a','a','b','a'};


}