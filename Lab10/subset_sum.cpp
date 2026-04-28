#include<iostream>
using namespace std;

int arr[100], n, target;

void solve(int idx, int curr, vector<int>& path){
    if(curr==target){
        cout<<"{ ";
        for(int x: path) cout<<x<<" ";
        cout<<"}"<<endl;
        return;
    }
    if(idx==n || curr>target) return;
    path.push_back(arr[idx]);
    solve(idx+1, curr+arr[idx], path);
    path.pop_back();
    solve(idx+1, curr, path);
}

int main(){
    cout<<"Enter size and target: ";
    cin>>n>>target;
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> path;
    solve(0, 0, path);
    return 0;
}
