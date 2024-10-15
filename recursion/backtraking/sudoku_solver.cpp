#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    class Solution {
    bool isSafe(int curr_row,int curr_col,vector<vector<char>>& board,char value){
        //for row
    for(int col=0;col<9;col++){
      if(board[curr_row][col] == value)
      return false;
      }
      
      //column check
      for(int row=0;row<9;row++){
          if(board[row][curr_col] == value)
          return false;
      }
        
      //3*3 matrix check
      for(int i=0;i<9;i++){
          if(board[3*(curr_row/3)+(i/3)][3*(curr_col/3)+(i%3)] == value)
          return false;
      }
      return true;
    }
    bool solve(vector<vector<char>>& board){
        //no base case in this
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char i='1';i<='9';i++){
                        if(isSafe(row,col,board,i)){
                            board[row][col]=i;
                            
                            if(solve(board)){
                                return true;
                            }
                            board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};