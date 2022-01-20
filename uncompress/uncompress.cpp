#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

bool is_dig(char data) {
    return data > '0' && data <= '9';
}

bool is_aph(char data) {
    return (data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z');
}

struct Node {
    string word;
    Node* next;
};

int main() {
    ifstream ifs;
    ofstream ofs;
    Node* head = NULL;
    char buffer[9999] = { 0 };
    ifs.open("input");
    ofs.open("output");
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
    }
    else {
        ifs.read(buffer, sizeof(buffer));
        cout << buffer;
        ifs.close();
    }
    int index = 0;


    while (buffer[index] != '0') {
        if (is_dig(buffer[index])) {
           if(buffer[index]=='0'){
               break;
           }
           int num=0;
           while(is_dig(buffer[index])){
               num=num*10+(buffer[index++]-'0');
           }
           Node *target=head,*pre;
           for(int i=1;i<num;i++){
               pre=target;
               target=target->next;
           }
            ofs<<target->word;
           if(target!=head){
               pre->next=target->next;
               target->next=head;
               head=target;
           }
        }
        else if (is_aph(buffer[index])) {
            string word="";
            while(is_aph(buffer[index])){
                word+=buffer[index];
                index++;
            }
            Node *t=new Node;
            t->word=word;
            t->next=head;
            head=t;
            ofs<<word;
        }
        else {
            ofs << buffer[index++];
        }
    }

    return 0;
}