#include<iostream>
using namespace std;

int ap() {
    int n;
    cin>>n;
    int nth;
    nth=3*n+7;
    return nth;
}

int butadd(){
    int a;
    int b;
    cout<<"working";
    cin>>a >>b;
    int sum=0;
    while(a!=0 || b!=0 ){
        int bit1= a&1;
        int bit2= b&1;
        sum = sum + bit1 +bit2;
        a<<1;
        b<<1;
    }
    return sum;
}

int main(){
    
    cout<<"sum is"<<butadd();
}