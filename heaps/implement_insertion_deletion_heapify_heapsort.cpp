#include<iostream>
using namespace std;


class heap{
    public:
        int arr[100];
        int size;
        heap(){
            arr[0]=-1;
            size=0;
        }

    void insertHeap(int d){
        size++;
        int index=size;
        arr[size]=d;
        while(index > 1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    


    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletemaxheap(){
        if(size==0){
            cout<<"nothing to delete \n";
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftchild=2*i;
            int rightchild=2*i+1;
            if(leftchild <= size && arr[leftchild] > arr[i] && arr[rightchild] < arr[leftchild]){
                swap(arr[i],arr[leftchild]);
                i=leftchild;
            }
            else if(rightchild <= size && arr[rightchild] > arr[i] && arr[rightchild] > arr[leftchild]){
                swap(arr[i],arr[rightchild]);
                i=rightchild;
            }
            else{
                return;
            }
        }
        
    }


    
};

void heapify(int arr[],int n,int i){
    int largest =i;
    int leftchild=i*2;
    int rightchild=i*2+1;

    if(leftchild <= n && (arr[largest]<arr[leftchild])){
        largest=leftchild;
    }

    if(rightchild <= n && (arr[largest] < arr[rightchild])){
        largest =rightchild;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    int t=n;
    while(t>1){
        swap(arr[1],arr[t]);
        t--;
        heapify(arr,t,1);
    }
}


int main(){
    heap h;
    h.insertHeap(70);
    h.insertHeap(50);
    h.insertHeap(60);
    h.insertHeap(30);
    h.insertHeap(20);
    h.insertHeap(55);
    h.insertHeap(40);
    h.print();
    h.deletemaxheap();
    h.print();
    h.deletemaxheap();
    h.print();

    int arr[6]= {-1,55,54,56,99,100};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"print the array now\n";

    for(int i=1;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,n);
    for(int i=1;i<6;i++){
        cout<<arr[i]<<" ";
    }
}