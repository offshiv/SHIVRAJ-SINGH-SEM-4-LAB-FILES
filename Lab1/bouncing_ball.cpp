#include<iostream>
using namespace std;

int main(){
    float h, r;
    cout<<"Enter height and rebound factor: ";
    cin>>h>>r;
    float total = h;
    while(h*r > 0.01){
        h = h*r;
        total += 2*h;
    }
    cout<<"Total distance = "<<total<<endl;
    return 0;
}
