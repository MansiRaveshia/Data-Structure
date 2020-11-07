#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;

#define Max 100

class Stack{
    public:
    int top;
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

int prec(char c){
    if(c=='^')
    return 3;
    else if(c=='*'|| c=='/')
    return 2;
    else if(c=='+'|| c=='-')
    return 1;
    else
    return -1;
}

void infixToPostfix(string s){
    Stack st;
    st.push('N');  //N becomes 1st element of stack
    int l=s.length();
    string ns;
    for(int i=0;i<l;i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
            ns+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(st.peek()!='N' && st.peek()!='('){
                char c=st.peek();
                st.pop();
                ns+=c;
            }
            if(st.peek()=='('){
                st.pop();
            }
        }
        else
        {
            while(st.peek()!='N' && prec(s[i])<=prec(st.peek())){
                char c=st.peek();
                st.pop();
                ns+=c;
            }
            st.push(s[i]);
        }
    }
        while(st.peek()!='N'){
            char c=st.peek();
            st.pop();
            ns+=c;
        }
    cout<<ns<<endl;
}


int main() 
{ 
    string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp); 
    return 0; 
} 