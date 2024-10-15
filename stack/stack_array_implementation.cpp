#include <iostream>
using namespace std;

class stack
{
public:
    int top;
    int *arr;
    int size;
public:
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int data){
     if(size-top>1){
        arr[top+1]=data;
        top++;
     }
     else{
        cout<<"stack overflow"<<endl;
     }   
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            cout<<arr[top]<<endl;
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }

};


int main(){
    stack st(5);
    st.push(23);
    st.push(2);
    st.push(243);
    st.push(2);
    st.peek();
    st.pop();
    st.peek();

    
}