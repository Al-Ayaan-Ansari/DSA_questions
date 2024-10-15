#include<iostream>
using namespace std;

int pivot(int arr[],int size){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        
        }

        mid=s+(e-s)/2;

    }
    ;
    if(mid==e){
        return 0;
    }
    return mid;
}


int binarysearch(int arr[],int s,int e,int key){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            s=mid+1;
        }
        else{e=mid-1;
        }
        mid=s+(e-s)/2;

    }
    return -1;
}


int main(){
    int key=0;
    int n=2;
    int arr[2]={1,3};
    int piv= pivot(arr,2);
    cout<<piv;
    if(key>arr[piv]&&key>arr[n-1]){
        cout<<binarysearch(arr,0,piv-1,key);
            }
    else{
        cout<<binarysearch(arr,piv,n-1,key);
    }
}