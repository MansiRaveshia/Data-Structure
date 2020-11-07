//queue usig array
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Queue{
    public:
    int front,rear;
    int a[5]; //Queue of 5 members
    Queue(){
        front=rear=-1;
        for(int i=0;i<5;i++){
            a[i]=0;
        }
    }
    bool isempty(){
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    bool isfull(){
        if(front==0 && rear==4){
            return true;
        }
        return false;
    }
    void enque(int d){
        if(isfull()){
            return;
        }
        if(isempty()){
            front=rear=0;
        }
        else{
            rear++;
        }
        a[rear]=d;
    }
    int deque(){
        int x=0;
        if(isempty()){
            return 0;
        }
        else if(front==rear){
            x=a[front];
            front=rear=-1;
        }
        else{
            x=a[front++];
        }
        return x;
    }
    void display(){
        if(isempty()){
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<a[i]<<" ";
        }
    }
};

int main(){
    Queue q;
    cout<<q.isempty()<<endl;
    q.enque(3);
    q.enque(5);
    q.enque(9);
    cout<<q.deque()<<endl;
    cout<<q.isempty()<<endl;
    cout<<q.isfull()<<endl;
    cout<<endl<<"displaying queue ";
    q.display();
}