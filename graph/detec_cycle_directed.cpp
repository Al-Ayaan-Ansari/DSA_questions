#include<unordered_map>
#include <list>
#include<vector>
#include<iostream>
using namespace std;

bool iscycledfs(unordered_map<int,list<int>> &AdjList,unordered_map<int,bool> &visited,
unordered_map<int,bool> &dfsvisited,int node){
  visited[node]=true;
  dfsvisited[node]=true;

  for(auto neighbour : AdjList[node]){
    if(!visited[neighbour]){
      bool cyclefound= iscycledfs(AdjList,visited,dfsvisited,neighbour);
      if(cyclefound==true){
        return true;
      }
      

    }
    else if(dfsvisited[neighbour]==true){
        //visited one
        return true;
      }

  }
  dfsvisited[node]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> AdjList;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    AdjList[u].push_back(v);
  }

  //call dfs for all components
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      bool cycledetected=iscycledfs(AdjList,visited,dfsvisited,i);
      if(cycledetected==true){
        return true;
      }
    }
  }
  return false;
}