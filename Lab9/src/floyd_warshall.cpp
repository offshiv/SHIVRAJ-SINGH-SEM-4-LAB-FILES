#include<iostream>
#include<climits>
using namespace std;

int main(){
    int v;
    cout<<"Enter vertices: ";
    cin>>v;
    int dist[v][v];
    cout<<"Enter adjacency matrix (0=self, large=no edge):"<<endl;
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++) cin>>dist[i][j];
    for(int k=0; k<v; k++)
        for(int i=0; i<v; i++)
            for(int j=0; j<v; j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    cout<<"Shortest distances:"<<endl;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++) cout<<dist[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
