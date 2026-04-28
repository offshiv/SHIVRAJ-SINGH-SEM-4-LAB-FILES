#include<iostream>
using namespace std;

int color[100], g[100][100], v, m;

bool isSafe(int node, int c){
    for(int i=0; i<v; i++)
        if(g[node][i] && color[i]==c) return false;
    return true;
}

bool solve(int node){
    if(node==v) return true;
    for(int c=1; c<=m; c++){
        if(isSafe(node, c)){
            color[node]=c;
            if(solve(node+1)) return true;
            color[node]=0;
        }
    }
    return false;
}

int main(){
    cout<<"Enter vertices, edges, colors: ";
    int e; cin>>v>>e>>m;
    for(int i=0; i<e; i++){
        int u, w; cin>>u>>w;
        g[u][w]=g[w][u]=1;
    }
    if(solve(0)){
        cout<<"Colors assigned:"<<endl;
        for(int i=0; i<v; i++) cout<<"Vertex "<<i<<" -> Color "<<color[i]<<endl;
    } else cout<<"No solution with "<<m<<" colors"<<endl;
    return 0;
}
