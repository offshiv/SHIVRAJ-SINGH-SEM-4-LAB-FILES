#include<iostream>
using namespace std;

int main(){
    int n, W;
    cout<<"Enter items and capacity: ";
    cin>>n>>W;
    int w[n], v[n];
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    int dp[n+1][W+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(w[i-1]<=j)
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<"Max value = "<<dp[n][W]<<endl;
    return 0;
}
