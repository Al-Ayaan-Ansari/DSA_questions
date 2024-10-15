#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        next=NULL;
    }
};

class stack
{
private:
    int data;
    Node* top;
public:
    stack(){
        top=NULL;
    }
    void push(int d){
        Node* temp=new Node(d);
        temp->next=top;
        top=temp;
    }
    void pop(){
        if(top==NULL){
            cout<<"stack Underflow"<<endl;
        }
        else{
            top=top->next;
        }
    }
    
    int peek(){
        if(top==NULL){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else{
            cout<<top->data<<endl;
            return top->data;
        }
    }
    bool isempty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    stack st;
    st.push(34);
    st.peek();
    st.push(56);
    st.peek();
    st.pop();
    st.peek();
    }

