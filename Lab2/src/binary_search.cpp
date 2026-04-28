#include<iostream>
using namespace std;

int main(){
    int n, key;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Enter key: ";
    cin>>key;
    int lo=0, hi=n-1, mid, pos=-1;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(arr[mid]==key){ pos=mid; break; }
        else if(arr[mid]<key) lo=mid+1;
        else hi=mid-1;
    }
    if(pos==-1) cout<<"Not found"<<endl;
    else cout<<"Found at index "<<pos<<endl;
    return 0;
}
