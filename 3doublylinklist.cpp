//insertion deletion reversal 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
};

void atfront(Node** headref,int d){
    Node* newn=new Node();
    newn->data=d;
    newn->prev=NULL;
    newn->next=(*headref);
    if((*headref)!=NULL){
        (*headref)->prev=newn;
    }
    *headref=newn;
}

void append(Node** headref,int d){
    Node* newn=new Node();
    newn->data=d;
    newn->next=NULL;
    if((*headref)==NULL){
        newn->prev=NULL;
        *headref=newn;
        return;
    }
    Node* temp=*headref;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newn;
    newn->prev=temp;
    return;
}

void aftergiven(Node* pre,int d){
    if(pre==NULL){
        cout<<"previous node doesnt exist"<<endl;
        return;
    }
    Node* newn=new Node();
    newn->data=d;
    newn->next=pre->next;
    pre->next=newn;
    newn->prev=pre;
    if(newn->next!=NULL){
        newn->next->prev=newn;
    }
}

void beforegiven(Node** headref,Node* after,int d){
    if(after==NULL){
        cout<<"after node doesnt exist"<<endl;
        return;
    }
    Node* n=new Node();
    n->data=d;
    n->prev=after->prev;
    n->next=after;
    after->prev=n;
    if(n->prev!=NULL){
        n->prev->next=n;
    }
    else{
        *headref=n;
    }
}

void deleteNode(Node** headref,Node* n){
    if((*headref)==NULL || n==NULL){
        return;
    }
    if(n==(*headref)){
        *headref=n->next;
    }
    if(n->prev!=NULL){
        n->prev->next=n->next;
    }
    if(n->next!=NULL){
        n->next->prev=n->prev;
    }
    free(n);
    return;
}

void printl(Node* n){
    if((n)==NULL){
        cout<<"no elements"<<endl;
        return;
    }
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}

void reversel(Node** headref){
    Node *temp = NULL;  
    Node *current = *headref;  
      
    /* swap next and prev for all nodes of  
    doubly linked list */
    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  
      
    /* Before changing the head, check for the cases like empty  
        list and list with only one node */
    if(temp != NULL )  
        *headref = temp->prev;  
}

int main(){
    Node* head=NULL  ;
    atfront(&head, 7);  
  
    atfront(&head, 1);  
  
    atfront(&head, 4);  
  
    // Insert 8, before 1. So linked list becomes 4->8->1->7->NULL  
    beforegiven(&head, head->next, 8);
    aftergiven(head->next->next,5);
    append(&head,9);
    cout<<"after insertion elements are: "<<endl;
    printl(head);
    reversel(&head);
    cout<<"after reversing list: "<<endl;
    printl(head);
    deleteNode(&head,head->next->next);
    deleteNode(&head,head);
    cout<<"after deleting: "<<endl;
    printl(head);
}