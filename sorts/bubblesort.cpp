#include<iostream>
using namespace std;

int printarr(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int bubblesort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[10]={5,6,3,56,3,8,4,2,7,9};
    printarr(arr,10);
    bubblesort(arr,10);
    cout<<endl;
    printarr(arr,10);
}