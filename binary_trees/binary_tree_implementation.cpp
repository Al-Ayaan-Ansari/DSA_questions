#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

node* BuildTree(node* &root){
    int data;
    cout<<"enter value"<<endl;
    cin>>data;
    root=new node(data);
    //basecase
    if(data==-1){
        return NULL;
    }

    cout<<"Enter data left of "<<root->data<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter data right of"<<root->data<<endl;
    root->right=BuildTree(root->right);

    return root;
}
int main(){
    node* root=NULL;
    root =BuildTree(root);
    

}