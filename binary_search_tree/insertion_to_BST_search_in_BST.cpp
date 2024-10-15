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
        cout<<"insert value "<<endl;
        cin>>d;
        
    }
    return root;
}

bool searchBST(Node* root,int x){
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        else if(temp->data > x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
    
}

int main(){
    Node* root=NULL;
    root=insert(root);
    DepthFirstTranverse(root);
    cout<<searchBST(root,15);
}