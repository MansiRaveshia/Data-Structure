//inserting at front,after specific node and at end of singly link lst 
// deleting node by key and position
//swapping nodes
//reversig the list
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void printl(Node* n){
    int c=0;
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
        c++;
    }
    cout<<endl<<"length of list is "<<c<<endl;
}


void swapNodes(Node **head_ref, int x, int y)  
{  
// Nothing to do if x and y are same  
if (x == y) return;  
  
// Search for x (keep track of prevX and CurrX  
Node *prevX = NULL, *currX = *head_ref;  
while (currX && currX->data != x)  
{  
    prevX = currX;  
    currX = currX->next;  
}  
  
// Search for y (keep track of prevY and CurrY  
Node *prevY = NULL, *currY = *head_ref;  
while (currY && currY->data != y)  
{  
    prevY = currY;  
    currY = currY->next;  
}  
  
// If either x or y is not present, nothing to do  
if (currX == NULL || currY == NULL)  
    return;  
  
// If x is not head of linked list  
if (prevX != NULL)  
    prevX->next = currY;  
else // Else make y as new head  
    *head_ref = currY;  
  
// If y is not head of linked list  
if (prevY != NULL)  
    prevY->next = currX;  
else // Else make x as new head  
    *head_ref = currX;  
  
// Swap next pointers  
Node *temp = currY->next;  
currY->next = currX->next;  
currX->next = temp;  
}  


void push(Node** refhead,int d){
    Node* newnode=new Node();
    newnode->data=d;
    newnode->next=*refhead;
    *refhead=newnode;

}

void reverselist(Node** refhead){
    Node *current=*refhead;
    Node* prev =NULL;
    Node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *refhead=prev;
}

void pushafter(Node* ptr,int d){
    if(ptr==NULL){
        cout<<"Cant push after null ptr";
        return;
    }
    Node* newnode=new Node();
    newnode->data=d;
    newnode->next=ptr->next;
    ptr->next=newnode;
}

void append(Node** refhead,int d){
    Node* newnode=new Node();
    newnode->data=d;
    if(*refhead==NULL){
        *refhead=newnode;
        return;
    }
    Node* l=*refhead;
    while(l->next!=NULL){
        l=l->next;
    }
    l->next=newnode;
}

void deletebykey(Node** refhead,int k){
    Node* temp=*refhead;
    Node *prev=*refhead;
    if(temp!=NULL && temp->data==k){
        *refhead=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=k){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<k<<" Not found";
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void deletebyposition(Node** refhead,int p){
    Node* temp=*refhead;
    Node *prev=*refhead;
    int x=0;
    if(temp==NULL){
        return;
    }
    if(p==0){
        *refhead=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL and x<p){
        prev=temp;
        temp=temp->next;
        x+=1;
    }
    if(temp==NULL){
        cout<<endl<<"element at position "<<p<<" not found"<<endl;
        return;
    }
    prev->next=temp->next;
    free(temp);
}

int main(){
    Node* head=NULL;
    append(&head,6);
    push(&head,7);
    push(&head,1);
    append(&head,4);
    pushafter(head->next,8);
    push(&head,25);
    push(&head,13);
    push(&head,15);
    cout<<"Created link list after adding all nodes is: ";
    printl(head);
    swapNodes(&head,1,6);
    cout<<"after swapping"<<endl;
    printl(head);
    reverselist(&head);
    cout<<"after reversing list"<<endl;
    printl(head);
    cout<<endl;
    deletebyposition(&head,0);
    deletebyposition(&head,4);
    deletebyposition(&head,100);
    deletebykey(&head,6);
    deletebykey(&head,20);
    cout<<endl<<"list after deleting is "<<endl;
    printl(head);

}