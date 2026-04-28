#include<iostream>
using namespace std;

int n, board[20];

bool isSafe(int row, int col){
    for(int i=0; i<row; i++)
        if(board[i]==col || abs(board[i]-col)==abs(i-row)) return false;
    return true;
}

void solve(int row, int& count){
    if(row==n){
        count++;
        for(int i=0; i<n; i++) cout<<board[i]<<" ";
        cout<<endl;
        return;
    }
    for(int col=0; col<n; col++){
        if(isSafe(row, col)){
            board[row]=col;
            solve(row+1, count);
        }
    }
}

int main(){
    cout<<"Enter n: ";
    cin>>n;
    int count=0;
    solve(0, count);
    cout<<"Total solutions = "<<count<<endl;
    return 0;
}
