#include<iostream>
#include<vector>
using namespace std;

bool dfs(int u, vector<int> adj[], bool visited[], bool recStack[]){
    visited[u]=true;
    recStack[u]=true;
    for(int v: adj[u]){
        if(!visited[v] && dfs(v, adj, visited, recStack)) return true;
        else if(recStack[v]) return true;
    }
    recStack[u]=false;
    return false;
}

int main(){
    int v, e;
    cout<<"Enter vertices and edges: ";
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0; i<e; i++){
        int u, w; cin>>u>>w;
        adj[u].push_back(w);
    }
    bool visited[v]={}, recStack[v]={};
    bool hasCycle=false;
    for(int i=0; i<v; i++)
        if(!visited[i] && dfs(i, adj, visited, recStack)) hasCycle=true;
    cout<<(hasCycle ? "Cycle detected" : "No cycle")<<endl;
    return 0;
}
