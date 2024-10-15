#include<iostream>
using namespace std;


class Node{
    //node call to make nodes
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void InsertAtHead(Node* &head,int d){
    //insert node at head and updates the head
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;

}




void InsertAtTail(Node*&tail,int d){
    //insert element at tail and update tail
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;          //here it can also be tail=temp;
}




void InsertAtPosition(Node* &head,Node*&tail,int position,int d){
    
    if(position==1){
        //handles edge case when element inserted at starting position
        InsertAtHead(head,d);
        return;
    }
    Node*temp=head;
    int count=1;

    while(count<position-1){
        temp=temp->next;
        count++;
    }
    
    if(temp->next=NULL){
        //edge case of ending insertion
        InsertAtTail(tail,d);
        return;
    }
    Node* ToBeInsert=new Node(d);                   //inserts element at middle position
    ToBeInsert->next=temp->next;
    temp->next=ToBeInsert;


}

void deleteNode(int Position,Node* &head,Node*&tail){
    if(Position==1){
        //to delete head/position=1 
        Node* temp=head;
        head=head->next;
        //free memory
        temp->next=NULL;
        delete temp;
    }
    else{
        //delete any middle or last node in the list
        Node* currnt=head;
        Node* prev=NULL;
        
        int count=1;
        while(count<Position){
            prev=currnt;
            currnt=currnt->next;
            count++;
        }
        if(currnt->next=NULL){
            tail=prev;
        }
        prev->next=currnt->next;
        //free memory
        currnt->next=NULL;
        delete currnt;


    }
}




void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<"data is "<<temp->data<<" "<<"next is "<<temp->next<<" "<<endl;
        temp=temp->next;
    }
    cout<< endl;
}

int main(){
    Node n1(10);
    Node* head=&n1;
    Node* tail=&n1;
    InsertAtTail(tail,90);
    InsertAtTail(tail,20);
    InsertAtHead(head,904);
    InsertAtTail(tail,62);
    InsertAtPosition(head,tail,3,67);
    
    print(head);
}