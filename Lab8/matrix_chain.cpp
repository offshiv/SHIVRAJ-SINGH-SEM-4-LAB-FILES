#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of matrices: ";
    cin>>n;
    int p[n+1];
    cout<<"Enter dimensions: ";
    for(int i=0; i<=n; i++) cin>>p[i];
    int dp[n][n]={};
    for(int len=2; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i; k<j; k++){
                int cost=dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(cost<dp[i][j]) dp[i][j]=cost;
            }
        }
    }
    cout<<"Min multiplications = "<<dp[0][n-1]<<endl;
    return 0;
}
