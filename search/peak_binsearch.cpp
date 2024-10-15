//find the peak element in the mountain array
#include<iostream>
using namespace std;
int peak(int arr[],int size){
    int s=0;
    int e=size-1;
    int mid=s +(e-s)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return arr[mid];

}

int main(){
    int arr1[5]={1,2,4,11,10};
    cout<<peak(arr1,5);

}