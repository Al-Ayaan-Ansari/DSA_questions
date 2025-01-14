#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){

    queue<int> q;

    q.push(node);

    visited[node] = 1;



    while(!q.empty()){

        int frontNode = q.front();

        q.pop();



        ans.push_back(frontNode);



        for(auto i: adj[frontNode]){

            if(!visited[i]){

                q.push(i);

                visited[i] = 1;

            }

        }

    }

}


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    vector<int> ans;

    unordered_map<int, bool> visited;

    BFS(adj, visited, ans, 0);

    return ans;

}