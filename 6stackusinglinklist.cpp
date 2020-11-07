//stack using link list
#include<bits/stdc++.h>
using namespace std;

//do insertion and poping from front of link list
//so elements will go on inserting at front of link list and top pointer will point to newly inserted node

class Node{
    public:
    int data;
    Node* next;
};

Node* top=NULL;

void push(int d){
    Node* n=new Node();
    n->data=d;
    n->next=top;
    top=n;
}

void peek(){
    if(top==NULL){
        cout<<"no elements "<<endl;
        return;
    }
    cout<<"element at peek is "<<top->data<<endl;
}

void pop(){
    if(top==NULL){
        cout<<"no elemets"<<endl;
        return;
    }
    Node* temp=top;
    cout<<"popped element is: "<<temp->data<<endl;
    top=top->next;
    free(temp);
}

void display(){
    if(top==NULL){
        cout<<"No elements"<<endl;
        return;
    }
    Node* temp=top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
push(13);
push(15);
push(17);
push(19);
push(12);
push(10);
display();
pop();
pop();
peek();
cout<<"after popping stack is "<<endl;
display();
}