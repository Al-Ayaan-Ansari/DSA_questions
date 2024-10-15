#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void duplicate(string s){
    int asize=s.length();
    sort(s.begin(),s.end());
    int count =0;
    for(int i=0;i<asize-1;i++){
           
        if(s[i]==s[i+1]){
            count++;
            continue;
        }
            
        if(count!=0){
        cout<<s[i]<<' '<<"duplicate is"<<count<<endl;
        count=0;
        }
    }
}


int main(){
    string s="hello this is ayaan and its a dsa question";
    duplicate(s);
    return 0;
}