//find first and last occurence of the given element in the array

#include<iostream>
using namespace std;

int firstOcc(int arr[],int size,int key){
    int mid;
    int ans=-1;
    int s=0;
    int e=size-1;
    mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            e=mid-1;
            ans=mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;

}


int lastOcc(int arr[],int size,int key){
    int mid;
    int ans=-1;
    int s=0;
    int e=size-1;
    mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            s=mid+1;
            ans=mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;

}


int main(){
    int arr1[9]={1,3,3,3,3,3,3,3,10};
    cout<<firstOcc(arr1,9,3)<<endl;
    cout<<lastOcc(arr1,9,3);


}