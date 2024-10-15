#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        //direction =0 -> undirected map;
        //direction =0 -> directed map;

        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<" ->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){
    int n;
    int m;
    cout<<"enter no. of nodes and edges. \n";
    cin>>n;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin>>u;
        cin>>v;
        //undirected graph
        g.addEdge(u,v,0);

    }

    g.printGraph();
}