//evaluating postfix expression usinng stack
#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
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
    int pop(){
        if(top==-1){
            cout<<"stack underfloe"<<endl;
            return 0;
        }

        return (a[top--]);
    }
    
    bool isempty(){
        return (top<0);
    }
    int peek(){
        return a[top];
    }
};

int operate(int x,int y,char opr){
    switch(opr){
        case '+':return x+y;
        case '-':return x-y;
        case '*':return x*y;
        case '/':return x/y;
        default: return 0;
    }
}

int evaluatepostfix(char* s){
    int i=0;
    Stack st;
    for(int i=0;s[i];++i){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else
        {
            int y=st.pop();
            int x=st.pop();
            int z=operate(x,y,s[i]);
            st.push(z);
        }
    }
    return (st.pop());
}

int main(){
    char s[]="231*+9-";
    cout<<evaluatepostfix(s);
    cout<<endl;
    char s1[]="53+62/*35*+";
    cout<<evaluatepostfix(s1);
}