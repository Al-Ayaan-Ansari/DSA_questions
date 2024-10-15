#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;
    
    TreeNode(int d){
        this->val=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//method 1
class Solution {
    void inorder(TreeNode* root,vector<int> & ans){
        if(root==NULL){
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        vector<int> ans;
        inorder(root,ans);
        if(ans.size()==1){
            return true;
        }
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1]){
            return false;
            }
        }
        return true;
    }
};

//method 2

class Solution {
    bool solve(TreeNode* root,int min,int max){
        if(root==NULL){
            return true;
        }
        if(root->val>min &&root->val<max){
            bool left=solve(root->left,min,root->val);
            bool right=solve(root->right,root->val,max);
            return left && right;
        }
        else{
            return false;
        }

    }
public:
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return solve(root,INT_MIN,INT_MAX);
    }
};