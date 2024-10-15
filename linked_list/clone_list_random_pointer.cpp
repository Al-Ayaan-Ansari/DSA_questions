#include<iostream>
#include<list>
using namespace std;
class Node{
    //node call to make nodes
    public:
    int val;
    Node* next;
    Node* random;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->random=NULL;
        
    }
    //destructor
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

class Solution
{
   private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }


    public:
    Node *copyRandomList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next1=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next1;

            Node* next2=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next2;

        }
        
        // step 3: Random pointer copy
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random
                ? temp->random->next :temp->random;
            }
            temp=temp->next->next;
        }
        
       
        
        //step 4: revert step 2 changes
        Node* original = head;
        Node* copy = cloneHead;
        
         while (original!=NULL && copy!=NULL)
            {   original->next=copy->next;
                original=original->next;
                if(original!=NULL){
                copy->next=original->next;
                }
                else{
                    copy->next=NULL;
                }
                copy=copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }
};