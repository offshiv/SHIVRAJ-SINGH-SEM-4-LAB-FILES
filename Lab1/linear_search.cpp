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
    int pos = -1;
    for(int i=0; i<n; i++){
        if(arr[i]==key){ pos=i; break; }
    }
    if(pos==-1) cout<<"Not found"<<endl;
    else cout<<"Found at index "<<pos<<endl;
    return 0;
}
