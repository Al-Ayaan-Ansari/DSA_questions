#include<iostream>
using namespace std;
int power(int n,int s){
    if(s==0){
        return 1;
    }
    if(s==1){
        return n;
    }
    int ans =power(n,s/2);
    if(s%2==0){
        return ans*ans;
    }
    else{
        return ans*ans*n;
    }
}


int main(){
    int n,s;
    cin>>n;
    cin>>s;
    cout<<power(n,s);
}