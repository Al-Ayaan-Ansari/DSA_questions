#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//using recursion
void reverse(queue < int > q) {
    if(q.empty()){
        return;
    }
    int s=q.front();
    q.pop();
    //recursion
    reverse(q);
    q.push(s);
}
//using stacks

// void reverse(queue < int > & q) {
//     stack<int> s;
//     while(!q.empty()){
//         s.push(q.front());
//         q.pop();
//     }
//     while(!s.empty()){
//         q.push(s.top());
//         s.pop();
//     }
// }

int main(){
    queue<int> q;
    q.push(2);
    q.push(24);
    q.push(12);
    q.push(2865);


}