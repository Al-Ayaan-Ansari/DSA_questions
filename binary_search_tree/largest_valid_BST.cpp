#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    
    TreeNode(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;

};

info solve(TreeNode* root, int &maxSize){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left=solve(root->left,maxSize);
    info right=solve(root->right,maxSize);

    info CurrNode;
    CurrNode.size= left.size+right.size+1;
    CurrNode.maxi=max(root->data,right.maxi);
    CurrNode.mini=min(root->data,left.mini);

    if(left.isBST&&right.isBST && (root->data>left.maxi) && (root->data<right.mini)){
        CurrNode.isBST=true;
    }
    else{
        CurrNode.isBST=false;
    }
    if(CurrNode.isBST){
        maxSize=max(maxSize,CurrNode.size);
    }
    return CurrNode;
}


int largestBST(TreeNode * root){
        int maxSize=0;
        info temp = solve(root,maxSize);
        return maxSize;
    }