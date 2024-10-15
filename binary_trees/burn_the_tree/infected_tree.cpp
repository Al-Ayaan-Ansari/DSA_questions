//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    Node* mapping(Node* root,int start,map<Node*,Node*> &NodeToParent){
        queue<Node*> q;
        q.push(root);
        Node* target=NULL;
        NodeToParent[root]=NULL;
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front->data==start){
                target=front;
            }
            if(front->left){
                NodeToParent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                NodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        return target;

    }
    int infected(Node* root,map<Node*,Node*> NodeToParent){
        map<Node*,bool> infected;
        queue<Node*> q;
        q.push(root);
        infected[root]=true;
        int ans=0;

        while(!q.empty()){
            
            int flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                if(front->left&& !infected[front->left]){
                    q.push(front->left);
                    infected[front->left]=1;
                    flag=1;
                }
                if(front->right&& !infected[front->right]){
                    q.push(front->right);
                    infected[front->right]=1;
                    flag=1;
                }
                if(NodeToParent[front] && !infected[NodeToParent[front]]){
                    q.push(NodeToParent[front]);
                    infected[NodeToParent[front]]=1;
                    flag=1;
                }

                
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;


    }
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> NodeToParent;
        Node* start= mapping(root, target, NodeToParent);
        int ans=infected(start, NodeToParent);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends