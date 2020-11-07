//insertion and deletion at front and end of circularsinglylinklist
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void atbegin(Node** headref,Node** lastref,int d){
    Node* n=new Node();
    n->data=d;
    if((*headref)==NULL && (*lastref)==NULL){
        (*headref)=n;
        (*lastref)=n;
        n->next=(*headref);
        return;
    }
    n->next=(*headref);
    (*lastref)->next=n;
    (*headref)=n;
    
}

void append(Node** headref,Node** lastref,int d){
    Node* n=new Node();
    n->data=d;
    if((*headref)==NULL && (*lastref)==NULL){
        (*headref)=n;
        (*lastref)=n;
        n->next=(*headref);
        return;
    }
    (*lastref)->next=n;
    n->next=(*headref);
    (*lastref)=n;
    
}

void deletebeg(Node** headref,Node** lastref){
    if((*headref)==NULL){
        return;
    }
    Node* temp=(*headref);
    if((*headref)==(*lastref)){   //when only 1 element is there in list
        (*headref)=(*lastref)=NULL;
        free(temp);
        return;
    }

    (*headref)=temp->next;
    (*lastref)->next=(*headref);

    free(temp);
}

void deleteend(Node** headref,Node** lastref){
    if((*headref)==NULL){
        return;
    }
    Node* temp=(*headref);
    if((*headref)==(*lastref)){
        (*headref)=(*lastref)=NULL;
        free(temp);
        return;
    }
    while(temp->next!=(*lastref)){
        temp=temp->next;
    }//temp equals last 2nd element of list
    free(temp->next);
    temp->next=(*headref);
    (*lastref)=temp;
}

void display(Node** headref){
    Node* temp=*headref;
    while((temp->next)!=(*headref)){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

int main(){
Node* start=NULL;
Node* last=NULL; // start points to 1st element of list and last points to last element of list
append(&start,&last,9);
atbegin(&start,&last,10);
atbegin(&start,&last,11);
append(&start,&last,13);
atbegin(&start,&last,12);
append(&start,&last,15);
display(&start);
deletebeg(&start,&last);
deleteend(&start,&last);
cout<<"after deleting:"<<endl;
display(&start);

}