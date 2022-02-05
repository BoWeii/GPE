#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAX_DOLLARS 30100
using namespace std;

int main(){
    float dollars;
    int coin[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    long long int table[MAX_DOLLARS][11];
    for(int i=0;i<11;i++){
        table[0][i]=1;
    }
    for(int i=0;i<MAX_DOLLARS;i++){
        table[i][0]=1;
    }
    for(int i=1;i<MAX_DOLLARS;i++){
        for(int j=1;j<11;j++){
            table[i][j]=table[i][j-1];
            if(i>=coin[j]){
                table[i][j]+=table[i-coin[j]][j];
            }
        }
    }
    while((cin>>dollars)){
        if(dollars==0.00) break;
        int temp=dollars*100;
        printf("%6.2f%17lld\n",dollars,table[temp][10]);
    }
    return 0;

}