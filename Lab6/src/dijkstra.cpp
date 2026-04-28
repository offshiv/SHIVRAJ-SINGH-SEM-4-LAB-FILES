#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main(){
    int v, e;
    cout<<"Enter vertices and edges: ";
    cin>>v>>e;
    vector<pair<int,int>> adj[v];
    for(int i=0; i<e; i++){
        int u, w, wt;
        cin>>u>>w>>wt;
        adj[u].push_back({w,wt});
        adj[w].push_back({u,wt});
    }
    int src;
    cout<<"Enter source: ";
    cin>>src;
    vector<int> dist(v, INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [nv, wt]: adj[u]){
            if(dist[u]+wt < dist[nv]){
                dist[nv]=dist[u]+wt;
                pq.push({dist[nv], nv});
            }
        }
    }
    cout<<"Distances from "<<src<<":"<<endl;
    for(int i=0; i<v; i++) cout<<i<<" -> "<<dist[i]<<endl;
    return 0;
}
