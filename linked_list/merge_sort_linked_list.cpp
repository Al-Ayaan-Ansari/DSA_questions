#include<iostream>
using namespace std;


class ListNode{
    //node call to make nodes
    public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data=data;
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



class Solution {
private:
    ListNode* getmid(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while (left != NULL && right != NULL) {
            if (left->data <= right->data) {
                temp->next = left;
                left = left->next;
                temp = temp->next;
            } else {
                temp->next = right;
                right = right->next;
                temp = temp->next;
            }
        }
        while (left != NULL) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        while (right != NULL) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
        ans=ans->next;
        return ans;
    }

    ListNode* mergesort(ListNode* head) {
        // basecase
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // handling the first case
        ListNode* mid = getmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // recursion handling all other cases
        left = mergesort(left);
        right = mergesort(right);

        // merging together

        ListNode* result = merge(left, right);

        return result;
    }
};