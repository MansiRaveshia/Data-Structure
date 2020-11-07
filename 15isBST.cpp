//tell if the given binary tree tree is binary search tree or not
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

int isBST(Node* node,int min,int max){
    /* an empty tree is BST */
    if (node==NULL) {
        return 1;
    } 
    if((node->data<min)||(node->data>max)){
        return 0;
    }
    return
    isBST(node->left,min,node->data-1) &&
    isBST(node->right,node->data+1,max);
}

int main(){
    Node *root1 = new Node(4);  
    root1->left = new Node(2);  
    root1->right = new Node(5);  
    root1->left->left = new Node(1);  
    root1->left->right = new Node(3);
    cout<<"in output 1 means its bst and 0 means its not bst"<<endl;
    cout<<isBST(root1,INT_MIN,INT_MAX)<<endl;

    Node *root2 = new Node(4);  
    root2->left = new Node(2);  
    root2->right = new Node(5);  
    root2->left->left = new Node(10);  
    root2->left->right = new Node(3);
    cout<<isBST(root2,INT_MIN,INT_MAX);
}

