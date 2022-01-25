#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

bool is_dig(char data) {
    return data >= '0' && data <= '9';
}

bool is_aph(char data) {
    return (data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z');
}

struct Node {
    string word;
    Node* next;
};

int main() {
    Node* head = NULL;
    char ch = getchar();
    int index = 0;
    while (true) {
        if (is_dig(ch)) {
           if(ch=='0'){
               break;
           }
           int num=0;
           while(is_dig(ch)){
               num=num*10+(ch-'0');
               ch = getchar();
           }
           Node *target=head,*pre=NULL;
           for(int i=1;i<num;i++){
               pre=target;
               target=target->next;
           }
            cout<<target->word;
           if(target!=head){
               pre->next=target->next;
               target->next=head;
               head=target;
           }
        }
        else if (is_aph(ch)) {
            string word="";
            while(is_aph(ch)){
                word+=ch;
                ch = getchar();
            }
            Node *t=new Node;
            t->word=word;
            t->next=head;
            head=t;
            cout<<word;
        }
        else {
            cout << ch;
            ch=getchar();
        }
    }
    return 0;
}