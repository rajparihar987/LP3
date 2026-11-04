#include <bits/stdc++.h>
using namespace std;

int board[8][8];
int fixedRow, fixedCol;

bool isSafe(int row,int col){
    for(int i=0;i<8;i++){
        if(board[i][col] == 1) return false;
    }

    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1;
         i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row + 1, j = col - 1;
         i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row + 1, j = col + 1;
         i < 8 && j < 8; i++, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row){
    if(row == 8){
        return true;
    }

    if(row == fixedRow){
        solve(row+1);
    }

    for(int col = 0; col < 8 ; col++){
        if(isSafe(row,col)){
            board[row][col] = 1;
            if(solve(row+1)) return true;
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int r, c;
    cout<<"Enter the first queen position (Enter its row and col)"<<endl;
    cin>>r>>c;

    int fixedRow = r-1;
    int fixedCol = c-1;

    board[fixedRow][fixedCol] = 1;

    if(solve(0)){
        cout<<"Final 8 Queens are placed"<<endl;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution exist"<<endl;
    }
}