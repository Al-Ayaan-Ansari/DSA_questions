#include<iostream>
using namespace std;

class queue{
    public:
        int front;
        int back;
        int* arr;
        int size;
        queue(int size){
            this->size=size;
            arr=new int[size];
            front=-1;
            back=-1;
        }
        void push(int data){
            if(back==size-1){
                cout<<"queue is full";
            }
            if(front==-1 && back==-1){
                front++;
                back++;
                arr[back]=data;
            }
            else{
                back++;
                arr[back]=data;
            }
        }
        void pop(){
            if(front==back){
                cout<<"queue is empty";
            }
            else{
                front++;
                if(back==front){
                    front=-1;
                    back=-1;

                }
            }
        }
        int ahead(){
            if(this->front==-1){
                cout<<"empty";
            }
            else{
                cout<<arr[front];
            }
        }

};

int main(){
    queue q(8);
    q.push(23);
    q.push(87);
    q.ahead();
    q.pop();

}