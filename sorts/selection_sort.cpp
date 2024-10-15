#include<iostream>
using namespace std;
void printarr(int a[],int size){
    
    for(int i=0; i<size;i++){
        cout<<a[i] <<" ";
    }
}

int selectionsort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {   
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        


    }
    return -1;
}
int main()
{
    int a[9]={2,3,4,56,234,6,264,25,564};
    printarr(a,9);
    cout<<endl;
    selectionsort(a,9);
    printarr(a,9);
    return 0;
}