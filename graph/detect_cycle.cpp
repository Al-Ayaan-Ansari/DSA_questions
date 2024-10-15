#include<unordered_map>
#include<list>
#include <queue>
#include <string>
#include<iostream>
using namespace std;

//in undirected graph

bool iscyclicbfs(unordered_map<int,list<int>> &AdjList,unordered_map<int,bool> &visited,int src){
    unordered_map<int,int> parent;

    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        for(auto neighbour: AdjList[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return false;

}
bool iscyclicDFS(unordered_map<int,list<int>> &AdjList,unordered_map<int,bool> &visited,
int parent,int src){
    visited[src]=true;
    for(auto neighbour: AdjList[src]){
        if(!visited[neighbour]){
            bool ans=iscyclicDFS(AdjList,visited,src,neighbour);                                ///detect cycle by Depth first search
            if(ans==1){
                return true;
            }
        } else if (neighbour != parent) {
            return true;
        }
    }
    return false;
    }


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //adjancy list is made
    unordered_map<int,list<int>> AdjList;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=iscyclicbfs(AdjList,visited,i); // or bool ans=iscycleDFS(adjList,visited,-1,i);
            if(ans==1){
                return "Yes";
            }

        }
    }
    return "No";

}