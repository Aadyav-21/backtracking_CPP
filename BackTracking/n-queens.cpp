#include<iostream>
using namespace std;
#include<vector>
//N-quuen puzzle-place N chess queens on an N*N chessboard sych that no quuens 2 attack each other
void add(vector<vector<int>>& ans,vector<vector<int>>& board){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<){
    int x=row;
    int y=col;
    //check for same row
    while(y>=0){
        if(board[x][y]==1)return false;
        y--;
    }
    x=row;
    y=col;
    //check for digonal
    while(x>=0 && y>=0){
        if(board[x][y]==1)return false;
        x--;
        y--;
    }
    x=row;
    y=col;
    while(x<n && y>-0){
        if(board[x][y]==1)return false;
        y--;
        x++;
    }
    return true;
}
void solve(int col,vector<vector<int>>&ans,vector<vector<int>&board,int n){
    //base case
    if(col==n){
        add(ans,board,n);
        return;
    }
    //solve 1 case
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            //if placing queen is safe
            board[row][col]=1;
            solve(col+1,ans,board,n);
            //backtracking
            board[row][col]=0;
        }
    }
}
vector<vector<int>>nQueens(int n){
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;
    solve(0,ans,board,n);
    return ans;
}