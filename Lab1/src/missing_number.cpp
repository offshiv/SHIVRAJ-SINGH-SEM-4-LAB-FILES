#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n-1];
    for(int i=0; i<n-1; i++) cin>>arr[i];
    int expected = n*(n+1)/2;
    int actual = 0;
    for(int i=0; i<n-1; i++) actual+=arr[i];
    cout<<"Missing number: "<<expected-actual<<endl;
    return 0;
}
