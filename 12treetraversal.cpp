//binary tree Depth first traversal
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left,*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void printPreorder(struct Node* n){
    if(n==NULL){
        return;
    }
    cout<<n->data<<" ";
    printPreorder(n->left);
    printPreorder(n->right);
}

void printInorder(struct Node* n){
    if(n==NULL){
        return;
    }
    printInorder(n->left);
    cout<<n->data<<" ";
    printInorder(n->right);
}

void printPostorder(struct Node* n){
    if(n==NULL){
        return;
    }
    printPostorder(n->left);
    printPostorder(n->right);
    cout<<n->data<<" ";
}

int main(){
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 
  
    return 0; 
}

