#include<iostream>
using namespace std;

int printarr(int arr[],int asize)
{
    for(int i=0;i<asize;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int insertionsort(int arr[],int asize)
{
    for(int i=1;i<asize;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0&& arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int arr[10]={5,525,235,5684,36,234,4326,657,345,769};
    printarr(arr,10);
    cout<<endl;
    insertionsort(arr,10);
    printarr(arr,10);
}