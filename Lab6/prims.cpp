#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int v;
    cout<<"Enter vertices: ";
    cin>>v;
    int g[v][v];
    cout<<"Enter adjacency matrix:"<<endl;
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++) cin>>g[i][j];
    vector<int> key(v, INT_MAX), parent(v,-1);
    vector<bool> inMST(v, false);
    key[0]=0;
    for(int cnt=0; cnt<v-1; cnt++){
        int u=-1;
        for(int i=0; i<v; i++)
            if(!inMST[i] && (u==-1 || key[i]<key[u])) u=i;
        inMST[u]=true;
        for(int w=0; w<v; w++){
            if(g[u][w] && !inMST[w] && g[u][w]<key[w]){
                key[w]=g[u][w];
                parent[w]=u;
            }
        }
    }
    int total=0;
    cout<<"MST edges:"<<endl;
    for(int i=1; i<v; i++){
        cout<<parent[i]<<" - "<<i<<" : "<<g[i][parent[i]]<<endl;
        total+=g[i][parent[i]];
    }
    cout<<"Total cost = "<<total<<endl;
    return 0;
}
