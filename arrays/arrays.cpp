#include<iostream>
using namespace std;

void printarr(int a[],int size){
    
    for(int i; i<size;i++){
        cout<<a[i] <<" ";
    }
}
int sumarr(int a[],int size){
    int sum=0;
     for(int i=0; i<size;i++){
        sum=a[i]+sum;
    }
    return sum;
}

int main(){
    int a[5]={1,2,3,4,89};
    fill_n(a,5,7);
    printarr(a,5);
    cout<<sumarr(a,5);
}