#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    float w, v;
};

bool cmp(Item a, Item b){
    return (a.v/a.w) > (b.v/b.w);
}

int main(){
    int n; float W;
    cout<<"Enter items and capacity: ";
    cin>>n>>W;
    Item items[n];
    for(int i=0; i<n; i++) cin>>items[i].w>>items[i].v;
    sort(items, items+n, cmp);
    float total=0;
    for(int i=0; i<n; i++){
        if(W>=items[i].w){
            total+=items[i].v;
            W-=items[i].w;
        } else {
            total+=(W/items[i].w)*items[i].v;
            break;
        }
    }
    cout<<"Max value = "<<total<<endl;
    return 0;
}
