#include<iostream>
#include<vector>
using namespace std;

int printarr(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}



int partition(vector<int>& arr,int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    //placing pivot at right position
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);

    //making left and right less than and greater than pivot respectively
    int i=s,j=e;
    while(i<pivotIndex &&j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex &&j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;
}


void quicksort(vector<int>& arr,int s,int e){
    //base case
    if(s>=e){
        return;
    }

    int p=partition(arr,s,e);
    //recursion
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}



int main(){
    vector<int> arr={2,4,3,2,5,7,73,43,5,5,5};
    quicksort(arr,0,arr.size()-1);
    printarr(arr);
    
}