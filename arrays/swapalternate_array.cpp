#include <iostream>
using namespace std;
void printarr(int a[],int size){
    
    for(int i=0; i<size;i++){
        cout<<a[i] <<" ";
    }
}

int main(){
    int size=6;
    int a[6]={2,4,5,7,824,41};
    int n=0;
    while(n<size){
        if(n+1<size){
            swap(a[n],a[n+1]);
            n+=2;
        }
    }
    
printarr(a,6);
cout<<"working";
}