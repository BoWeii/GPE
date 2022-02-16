#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

struct LIS{
    int count;
    int data;
};

int main(){
    int num=0;
    while(cin>>num){
        LIS body[num];
        for(int i=0;i<num;i++){
            cin>>body[i].data;
            body[i].count=1;
        }
        // for(int i=0;i<num;i++){
        //     cout<<"data="<<body[i].data<<"count="<<body[i].count<<endl;
        // }
        int biggest=0;
        for(int j=0;j<num;j++){
            int i=0;
            while(j!=i){
                if(body[j].data>body[i].data&&body[i].count+1>body[j].count){
                    body[j].count=body[i].count+1;
                }
                i++;
            }
        }
        for(int i=0;i<num;i++){
            if(body[i].count>biggest){
                biggest=body[i].count;
            }
        }
        cout<<biggest<<endl;
    }
    return 0;
}