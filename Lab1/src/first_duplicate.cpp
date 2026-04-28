#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    unordered_set<int> seen;
    for(int i=0; i<n; i++){
        if(seen.count(arr[i])){
            cout<<"First duplicate: "<<arr[i]<<endl;
            return 0;
        }
        seen.insert(arr[i]);
    }
    cout<<"No duplicate found"<<endl;
    return 0;
}
