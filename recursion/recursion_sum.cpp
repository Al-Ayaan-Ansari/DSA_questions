#include<iostream>
#include<array>
using namespace std;
int sum(int arr[],int size){
    if(size==0){
        return 0;
    }
    int val=0;
    val=arr[0]+sum(arr+1,size-1);
    return val;
    
}

int main(){
    int size=1;
    int arr[]={99};
    cout<<sum(arr,size);
}