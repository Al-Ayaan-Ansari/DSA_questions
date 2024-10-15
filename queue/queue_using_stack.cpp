#include <bits/stdc++.h> 
#include<iostream>
using namespace std;


class MyQueue {
private:
    stack<int> reverse(stack<int> s){
        stack<int> ans;
        while(!s.empty()){
            ans.push(s.top());
            s.pop();
            
        }
        return ans;
    }
public:
    int n;
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        s2=reverse(s1);
        int a=s2.top();
        s2.pop();
        s1=reverse(s2);
        return a;
    }
    
    int peek() {
        s2=reverse(s1);
    
        return s2.top();
    }
    
    bool empty() {
        return s1.empty();

    }

};