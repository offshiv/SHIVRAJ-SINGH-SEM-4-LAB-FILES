#include<iostream>
#include<vector>
using namespace std;

int v, g[100][100], path[100];
bool visited[100];

bool solve(int pos){
    if(pos==v){
        // check if last vertex connects back to start (circuit)
        if(g[path[pos-1]][path[0]]) return true;
        return false;
    }
    for(int node=1; node<v; node++){
        if(g[path[pos-1]][node] && !visited[node]){
            path[pos]=node;
            visited[node]=true;
            if(solve(pos+1)) return true;
            visited[node]=false;
        }
    }
    return false;
}

int main(){
    int e;
    cout<<"Enter vertices and edges: ";
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int u, w; cin>>u>>w;
        g[u][w]=g[w][u]=1;
    }
    path[0]=0; visited[0]=true;
    if(solve(1)){
        cout<<"Hamiltonian Circuit: ";
        for(int i=0; i<v; i++) cout<<path[i]<<" ";
        cout<<path[0]<<endl;
    } else cout<<"No Hamiltonian Circuit found"<<endl;
    return 0;
}
