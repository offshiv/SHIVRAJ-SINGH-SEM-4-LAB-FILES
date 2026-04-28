#include<iostream>
using namespace std;

int partition(int arr[], int lo, int hi){
    int pivot = arr[hi], i = lo-1;
    for(int j=lo; j<hi; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[hi]);
    return i+1;
}

void quickSort(int arr[], int lo, int hi){
    if(lo<hi){
        int p = partition(arr, lo, hi);
        quickSort(arr, lo, p-1);
        quickSort(arr, p+1, hi);
    }
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    quickSort(arr, 0, n-1);
    cout<<"Sorted: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
