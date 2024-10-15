/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);

        bool lefttoright = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                int index = lefttoright ? i : size - i - 1;
                ans[index] = temp->data;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            result.push_back(ans);
            lefttoright=!lefttoright;

        }
        return result;
    }
};