#include<stdio.h>

int printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[10]={43,2,3,99,67,23,34,87,23,12};
    int j=0;
    int s=0;
    for(int k=0;k<10;k++)
    {
        if(arr[k]%2==0)
        {
            j++;
        }
        else{
            s++;
        }
        k++;
    }
    int evenarr[j];
    int oddarr[s];
    for(int i=0,l=0,m=0;i<10;i++)
    {
        if(arr[i]%2==0)
        {
            evenarr[l]=arr[i];
            l++;
        }
        else
        {
            oddarr[m]=arr[i];
            m++;
        }
        i++;
    }
    printarr(evenarr,j);
    printarr(oddarr,s);
}