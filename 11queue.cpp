//queue using link list
#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
    public:
    int data; 
    Node* next; 
    Node(int d) 
    { 
        data = d; 
        next = NULL; 
    } 
}; 

class Queue{
    public:
    Node *front,*rear;
    Queue(){
        front=rear=NULL;
    }
    void enque(int d){
        Node* n =new Node(d);
        if(front==NULL){
            front=rear=n;
            return;
        }
        rear->next=n;
        rear=n;
    }
    void deque(){
        if(rear==NULL){
            return;
        }
        Node* n=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        free(n);
    }
};

int main() 
{ 
  
    Queue q; 
    q.enque(10); 
    q.enque(20); 
    q.deque(); 
    q.deque(); 
    q.enque(30); 
    q.enque(40); 
    q.enque(7);
    q.enque(50); 
    q.deque(); 
    cout << "Queue Front : " << (q.front)->data << endl; 
    cout << "Queue Rear : " << (q.rear)->data; 
} 