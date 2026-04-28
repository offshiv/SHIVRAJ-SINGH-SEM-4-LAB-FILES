#include<iostream>
#include<vector>
using namespace std;

bool dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack){
    visited[u]=true;
    recStack[u]=true;
    for(int nei: adj[u]){
        if(!visited[nei] && dfs(nei, adj, visited, recStack)) return true;
        else if(recStack[nei]) return true;
    }
    recStack[u]=false;
    return false;
}

int main(){
    int v, e;
    cout<<"Enter vertices and edges: ";
    cin>>v>>e;
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        int u, w; cin>>u>>w;
        adj[u].push_back(w);
    }
    vector<bool> visited(v, false), recStack(v, false);
    bool hasCycle=false;
    for(int i=0; i<v; i++)
        if(!visited[i] && dfs(i, adj, visited, recStack)) hasCycle=true;
    cout<<(hasCycle ? "Cycle detected" : "No cycle")<<endl;
    return 0;
}
