#include<iostream>
#include<queue>
using namespace std;



class ListNode{
    //node call to make nodes
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
    //destructor
    ~ListNode(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};



class compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return (a->val > b->val);
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> ,compare> q;
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        for(int i=0;i<k;i++){
            if(lists[i]!=NULL){
                q.push(lists[i]);
            }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(q.size()>0){
            ListNode* tmp=q.top();
            q.pop();
            
            if(head==NULL){
                head=tmp;
                tail=tmp;
            }
            else{
                tail->next=tmp;
                tail=tmp;
            }
            if(tail->next!=NULL){
                q.push(tail->next);
            }
        }
        return head;
    }
};