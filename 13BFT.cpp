//breath first traversal or level order traversal

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;
    Node(int data){
        this->data=data;
        right=left=NULL;
    }
};

int height(Node* n){
    if(n==NULL){
        return 0;
    }
    return(max(height(n->left),height(n->right))+1);
}

void printgivenlevel(Node* n,int level){
    if(n==NULL){
        return ;
    }
    if(level==1){
        cout<<n->data<<" ";
    }
    else if(level>1){
        printgivenlevel(n->left,level-1);
        printgivenlevel(n->right,level-1);
    }
}

void printlevelorder(Node* root){
    int h=height(root);
    int i;
    for(i=1;i<=h;i++){
        printgivenlevel(root,i);
    }
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    printlevelorder(root);
}