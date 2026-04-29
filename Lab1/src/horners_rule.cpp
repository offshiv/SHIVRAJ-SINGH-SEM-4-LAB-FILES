#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter degree: ";
    cin>>n;
    float coef[n+1], x;
    cout<<"Enter coefficients (highest to lowest): ";
    for(int i=0; i<=n; i++) cin>>coef[i];
    cout<<"Enter x: ";
    cin>>x;
    float result = coef[0];
    for(int i=1; i<=n; i++)
        result = result*x + coef[i];
    cout<<"Result = "<<result<<endl;
    return 0;
}
