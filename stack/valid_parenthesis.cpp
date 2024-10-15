#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isvalid(string s){
    stack<char> open;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open.push(s[i]);
            } else {
                if (!open.empty()) {
                    char val = open.top();
                    if ((s[i] == ')' && val == '(') ||
                        (s[i] == '}' && val == '{') ||
                        (s[i] == ']' && val == '[')) {
                        open.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        if(open.empty()){
            return true;
        }
        else{
            return false;
        }
}

int main(){
    string str="{}[]({})";
    cout<<isvalid(str);
}