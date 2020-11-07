#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};

void printl(Node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
} 

int main(){
    Node* head=new Node();
    Node* second =new Node();
    Node* third=new Node();
    head->data=13;
    head->next=second;
    second->data=25;
    second->next=third;
    third->data=15;
    third->next=NULL;
    printl(head);
    return 0;
}
