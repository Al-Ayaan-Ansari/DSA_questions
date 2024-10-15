#include<iostream>
#include<string>
using namespace std;

bool ispalindrome(string&str,int s){
    int n=str.length();
    if(s>=n-s-1){
        return true;
    }
    if(str[s]!=str[n-s-1]){
        return false;
    }
    s++;
    
    ispalindrome(str,s);

}

int main(){
    string str="asdfghjkllkjhgfdsa";
    cout<<ispalindrome(str,0);
}