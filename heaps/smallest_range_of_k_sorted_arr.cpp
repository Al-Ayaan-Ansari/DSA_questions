#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;



class node{
    public:
    int data;
    int row;
    int col;
    node(int data, int row, int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node* ,vector<node*>, compare> q;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int k=nums.size();
        for(int i=0;i<k;i++){
            int element=nums[i][0];
            maxi=max(maxi,element);
            mini=min(mini,element);
            node* tmp=new node(element,i,0);
            q.push(tmp);
        }

        int start=mini;
        int end=maxi;
        while(!q.empty()){
            node* temp=q.top();
            q.pop();
            
            mini=temp->data;

            if(maxi-mini < end-start){
                end=maxi;
                start=mini;
            }
            if(temp->col+1 < nums[temp->row].size()){
                maxi=max(maxi,nums[temp->row][temp->col+1]);
                q.push(new node(nums[temp->row][temp->col+1], temp->row,temp->col+1));

            }
            else{
                break;
            }
        }
        return {start,end};
    }
};