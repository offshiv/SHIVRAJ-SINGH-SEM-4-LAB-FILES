#include<iostream>
using namespace std;

long long power(long long a, long long n){
    if(n==0) return 1;
    long long half = power(a, n/2);
    if(n%2==0) return half*half;
    return a*half*half;
}

int main(){
    long long a, n;
    cout<<"Enter base and exponent: ";
    cin>>a>>n;
    cout<<a<<"^"<<n<<" = "<<power(a,n)<<endl;
    return 0;
}
