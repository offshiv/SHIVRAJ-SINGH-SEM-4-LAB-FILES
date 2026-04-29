#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct Point{ int x, y; };
Point p0;

int cross(Point O, Point A, Point B){
    return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

bool cmp(Point a, Point b){
    int o=cross(p0,a,b);
    if(o==0) return (a.x*a.x+a.y*a.y)<(b.x*b.x+b.y*b.y);
    return o>0;
}

int main(){
    int n;
    cout<<"Enter points: ";
    cin>>n;
    Point pts[n];
    for(int i=0; i<n; i++) cin>>pts[i].x>>pts[i].y;
    int mn=0;
    for(int i=1; i<n; i++)
        if(pts[i].y<pts[mn].y || (pts[i].y==pts[mn].y && pts[i].x<pts[mn].x)) mn=i;
    swap(pts[0], pts[mn]);
    p0=pts[0];
    sort(pts+1, pts+n, cmp);
    stack<Point> st;
    st.push(pts[0]); st.push(pts[1]); st.push(pts[2]);
    for(int i=3; i<n; i++){
        while(st.size()>1){
            Point top=st.top(); st.pop();
            if(cross(st.top(), top, pts[i])>0){ st.push(top); break; }
        }
        st.push(pts[i]);
    }
    cout<<"Convex Hull points:"<<endl;
    while(!st.empty()){
        cout<<"("<<st.top().x<<","<<st.top().y<<") ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
