//binary search tree
//searching a given value
//insertion in binary search tree
//inorder traversal of tree
//finding minimum value
//deletion
#include<iostream>
using namespace std;

class BST{
    public:
    int data;
    BST *left,*right;
    BST(){ }
    BST(int d){
        data=d;
        left=right=NULL;
    }
                                                 //searching
    int searchkey(BST* root,int key){
        if(root==NULL){
            return 0;
        }
        if(root->data==key){
            return 1;
        }
        if(key<root->data){
            return searchkey(root->left,key);
        }
        if(key>root->data){
            return searchkey(root->right,key);
        }
        return 1;
    }
                                                 //insertion
    BST* insert(BST* root,int value){
        if(!root){
            return new BST(value);
        }
        if(value>root->data){
            root->right=insert(root->right,value);
        }
        else
        {
            root->left=insert(root->left,value);
        }
        return root;
    }
                                                //inorder traversal
    void inordertraversal(BST* root){
        if(!root){
            return;
        }
        inordertraversal(root->left);
        cout<<root->data<<" ";
        inordertraversal(root->right);
    }
                                              //finding minimum value
    BST* minvalue(BST* root){
        BST* current=root;
        while(current && current->left!=NULL){
            current=current->left;
        }
        return current;
    }
                                                //delete node with given key
    BST* deletenode(BST* root,int value){
        if(root==NULL){ return root; }
        // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
        if(value<root->data){
            root->left=deletenode(root->left,value);
        }
        // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (value > root->data){
        root->right=deletenode(root->right,value);
    }
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else{
        // node with only one child or no child 
        if(root->left==NULL){
            BST* temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            BST* temp=root->left;
            free(root);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        BST* temp=minvalue(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    } 
    return root;
    }
};

int main(){
    BST b,*root=NULL;
    root=b.insert(root,50);
    b.insert(root,30);
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80); 
   cout<<"inorder traversal : "<<endl;
    b.inordertraversal(root); 

//searching values
cout<<endl<<"seaching for 70 : "<<b.searchkey(root,70)<<endl;
cout<<"searching for 13: "<<b.searchkey(root,13)<<endl;
cout<<"searching for 35: "<<b.searchkey(root,35)<<endl;

//finding minimum value
    cout<<endl<<"Minimum value in tree is: "<<b.minvalue(root)->data<<endl;

//deleting nodes
    cout<<"now deleting items"<<endl;

    b.deletenode(root,20);
    cout<<"inorder traversal : "<<endl;
     b.inordertraversal(root); 
    
    cout<<endl;
    b.deletenode(root,30);
    b.inordertraversal(root); 

    cout<<endl;
    b.deletenode(root,50);
     b.inordertraversal(root); 
    


    return 0; 
}

