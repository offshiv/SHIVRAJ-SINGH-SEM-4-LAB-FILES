#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n;
int dist[10][10];
int dp[1024][10];

int tsp(int mask, int pos){
    if(mask==(1<<n)-1) return dist[pos][0];
    if(dp[mask][pos]!=-1) return dp[mask][pos];
    int res=INT_MAX;
    for(int city=0; city<n; city++){
        if(!(mask & (1<<city)) && dist[pos][city]){
            int val=dist[pos][city]+tsp(mask|(1<<city), city);
            res=min(res, val);
        }
    }
    return dp[mask][pos]=res;
}

int main(){
    cout<<"Enter cities: ";
    cin>>n;
    cout<<"Enter distance matrix:"<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin>>dist[i][j];
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++) dp[i][j]=-1;
    cout<<"Min tour cost = "<<tsp(1, 0)<<endl;
    return 0;
}
