//stack using array
#include<bits/stdc++.h>
using namespace std;

#define Max 100

class Stack{
    int top;
    public:
    int a[Max];
    Stack(){
        top=-1;
    }
    void push(int x){
        if (top>=(Max-1)){
            cout<<"stack overflow"<<endl;
        }
        else
        {
            a[++top]=x;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack underfloe"<<endl;
        }
        else{
            cout<<"popped element is "<<a[top--]<<endl;
        }
    }
    void peek(){
        if(top==-1){
            cout<<"stack empty"<<endl;
        }
        else{
            cout<<"element at peek is "<<a[top]<<endl;
        }
    }
    bool isempty(){
        return (top<0);
    }
    void display(){
        for(int i=top;i>=0;i--){
            cout<<a[i]<<" "<<endl;
        }
    }
    
};

int main(){
    Stack s;
    cout<<s.isempty()<<endl;  //gives 1 if its empty
    s.push(11);
    s.push(12);
    s.push(15);
    s.pop();
    s.push(17);
    s.push(19);
    s.push(20);
    s.peek();
    s.push(22);
    cout<<"left out elements are"<<endl;
    s.display();
}
