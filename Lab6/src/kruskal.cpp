#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Edge{ int u, v, w; };
int parent[100], rnk[100];

int find(int x){ return parent[x]==x ? x : parent[x]=find(parent[x]); }

void unite(int x, int y){
    int px=find(x), py=find(y);
    if(rnk[px]<rnk[py]) swap(px,py);
    parent[py]=px;
    if(rnk[px]==rnk[py]) rnk[px]++;
}

int main(){
    int v, e;
    cout<<"Enter vertices and edges: ";
    cin>>v>>e;
    vector<Edge> edges(e);
    for(int i=0; i<e; i++) cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w<b.w; });
    for(int i=0; i<v; i++){ parent[i]=i; rnk[i]=0; }
    int total=0;
    cout<<"MST edges:"<<endl;
    for(auto& e: edges){
        if(find(e.u)!=find(e.v)){
            cout<<e.u<<" - "<<e.v<<" : "<<e.w<<endl;
            total+=e.w;
            unite(e.u, e.v);
        }
    }
    cout<<"Total cost = "<<total<<endl;
    return 0;
}
