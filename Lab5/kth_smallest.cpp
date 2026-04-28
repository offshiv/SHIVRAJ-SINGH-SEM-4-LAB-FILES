#include<iostream>
using namespace std;

int partition(int arr[], int lo, int hi){
    int pivot=arr[hi], i=lo-1;
    for(int j=lo; j<hi; j++)
        if(arr[j]<=pivot) swap(arr[++i], arr[j]);
    swap(arr[i+1], arr[hi]);
    return i+1;
}

int kthSmallest(int arr[], int lo, int hi, int k){
    int p=partition(arr, lo, hi);
    if(p==k-1) return arr[p];
    if(p>k-1) return kthSmallest(arr, lo, p-1, k);
    return kthSmallest(arr, p+1, hi, k);
}

int main(){
    int n, k;
    cout<<"Enter size and k: ";
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Kth smallest = "<<kthSmallest(arr, 0, n-1, k)<<endl;
    return 0;
}
