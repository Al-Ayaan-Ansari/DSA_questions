#include<iostream>
#include<stack>
using namespace std;


int main(){
    stack<int> a;
    stack<int> b;
    a.push(23);
    a.push(3);
    a.push(5);
    a.push(1);
    a.push(25);
    while(!a.empty()){
        b.push(a.top());
        a.pop();
    }
    while(!b.empty()){
        cout<<b.top()<<" ";
        b.pop();
    }
}