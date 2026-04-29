#include<iostream>
#include<algorithm>
using namespace std;

struct Activity{ int s, f; };

bool cmp(Activity a, Activity b){ return a.f < b.f; }

int main(){
    int n;
    cout<<"Enter number of activities: ";
    cin>>n;
    Activity act[n];
    for(int i=0; i<n; i++) cin>>act[i].s>>act[i].f;
    sort(act, act+n, cmp);
    cout<<"Selected: ";
    int last=0;
    cout<<0<<" ";
    for(int i=1; i<n; i++){
        if(act[i].s>=act[last].f){
            cout<<i<<" ";
            last=i;
        }
    }
    cout<<endl;
    return 0;
}
