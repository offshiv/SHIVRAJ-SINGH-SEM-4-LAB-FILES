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
    int lo=0, hi=n-1, pos=-1;
    while(lo<=hi){
        int m1=lo+(hi-lo)/3;
        int m2=hi-(hi-lo)/3;
        if(arr[m1]==key){ pos=m1; break; }
        if(arr[m2]==key){ pos=m2; break; }
        if(key<arr[m1]) hi=m1-1;
        else if(key>arr[m2]) lo=m2+1;
        else{ lo=m1+1; hi=m2-1; }
    }
    if(pos==-1) cout<<"Not found"<<endl;
    else cout<<"Found at index "<<pos<<endl;
    return 0;
}
