#include<iostream>
#include<stack>
using namespace std;

int partition(int arr[], int lo, int hi){
    int pivot=arr[hi], i=lo-1;
    for(int j=lo; j<hi; j++)
        if(arr[j]<=pivot) swap(arr[++i], arr[j]);
    swap(arr[i+1], arr[hi]);
    return i+1;
}

void quickSortIter(int arr[], int lo, int hi){
    stack<int> st;
    st.push(lo); st.push(hi);
    while(!st.empty()){
        hi=st.top(); st.pop();
        lo=st.top(); st.pop();
        int p=partition(arr, lo, hi);
        if(p-1>lo){ st.push(lo); st.push(p-1); }
        if(p+1<hi){ st.push(p+1); st.push(hi); }
    }
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    quickSortIter(arr, 0, n-1);
    cout<<"Sorted: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
