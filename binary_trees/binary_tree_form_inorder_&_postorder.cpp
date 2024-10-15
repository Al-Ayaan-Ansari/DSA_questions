//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    int Findposition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    Node* solve(int in[],int post[], int &index ,int inorderStart , int inorderEnd , int n){
        if(index<0 || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = post[index--] ; // At every interation index is increasing
        Node* root  = new Node(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        root->right = solve(in , post , index , position+1 , inorderEnd ,n);
        root->left = solve(in , post , index  , inorderStart , position-1 ,n);

        return root ;
        
    }

    
    Node* buildTree(int n,int in[],int post[])
    {
        // Code here
         int preorderindex  = n-1 ;  //Pre order is NLR so First element is root .
         
         Node* ans = solve(in , post , preorderindex , 0  , n-1 , n );
         return ans ;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends