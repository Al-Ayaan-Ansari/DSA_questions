//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
#include <bits/stdc++.h> 

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
        bool operator()(node* a, node* b){
            return (a->data > b->data);
        }
};


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> kArrays, int k)
    {
        priority_queue<node* ,vector<node*> , compare> q;
    

    //1. put all 0th index elemts in q
    for(int i=0;i<k;i++){
        node* temp=new node(kArrays[i][0],i,0);
        q.push(temp);
    }

    //2. putting element in ans array in asorted way
    vector<int> ans;
    while(q.size()>0){
        node* t=q.top();
        ans.push_back(t->data);
        int row=t->row;
        int col=t->col;
        q.pop();
        if(col+1 < kArrays[row].size()){
            node* next=new node(kArrays[row][col+1],row,col+1);
            q.push(next);
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends