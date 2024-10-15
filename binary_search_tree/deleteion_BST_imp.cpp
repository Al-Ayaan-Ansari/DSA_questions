#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void DepthFirstTranverse(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* insertToBst(Node* &root,int d){
    //basecase
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(root->data>d){
        root->left=insertToBst(root->left,d);
    }
    else{
        root->right=insertToBst(root->right,d);
    }
    return root;


}

Node* insert(Node* &root){
    cout<<"insert data"<<endl;
    int d;
    cin>>d;

    while(d!=-1){
        root =insertToBst(root,d);
        cout<<"insert dataue "<<endl;
        cin>>d;
        
    }
    return root;
}

Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}


Node* deleteNode(Node* root, int key) {
       if(root == NULL) {
        return root;
    }

    if(root->data == key) { 
        // 0 Child
        if(root->left==NULL && root->right==NULL) {
            delete root;
            return NULL;
        }
        // 1 Child
        // Left Child
        if(root->left!=NULL && root->right==NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right Child
        if(root->left==NULL && root->right!=NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 Children
        if(root->left!=NULL && root->right!=NULL) {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }

    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        root->left = deleteNode(root->left, key);
    }
    
    return root;
}
void inorderTransverse(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorderTransverse(root->left);
    cout<<root->data<<" ";
    inorderTransverse(root->right);
}


int main(){
    Node* root=NULL;
    root=insert(root);
    inorderTransverse(root);
    deleteNode(root,14);
    inorderTransverse(root);
}