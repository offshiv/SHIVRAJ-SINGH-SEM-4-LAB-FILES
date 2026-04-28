#include<iostream>
using namespace std;

void permute(int arr[], int l, int r){
    if(l==r){
        for(int i=0; i<=r; i++) cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=l; i<=r; i++){
        swap(arr[l], arr[i]);
        permute(arr, l+1, r);
        swap(arr[l], arr[i]);
    }
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    permute(arr, 0, n-1);
    return 0;
}
