//check if given string has balanced paranthesis using stack
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

bool balanced(string s){
    int l=s.length();
    Stack st;
    for(int i=0;i<l;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
            continue;
        }
        switch(s[i]){
            case ')':
            if(st.peek()=='('){
                st.pop();
                break;
            }
            else{
                return false;
            }
            case ']':
            if(st.peek()=='['){
                st.pop();
                break;
            }
            else{
                return false;
            }
            case '}':
            if(st.peek()=='{'){
                st.pop();
                break;
            }
            else{
                return false;
            }
            default: return false;
        }

    }
    return (st.isempty());
}

int main(){
string expr = "{()}[]"; 
string e="[]{)";
string s=".";
string x="([{}])";
cout<<" 1 means balanced and 0 means not balanced"<<endl;
cout<<balanced(expr)<<endl;
cout<<balanced(e)<<endl;
cout<<balanced(s)<<endl; 
cout<<balanced(x)<<endl; 
return 0; 
}