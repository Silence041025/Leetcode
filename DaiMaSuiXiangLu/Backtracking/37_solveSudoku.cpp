#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    bool result = false;
    bool is_valid(vector<vector<char>>& board,int row,int col,char num) {
        for (int c=0;c<board[row].size();c++) {
            if (c==col) {
                continue;
            }
            if (board[row][c]==num) {
                return false;
            }
        }

        for (int r=0;r<board.size();r++) {
            if (r==row) {
                continue;
            }
            if (board[r][col]==num) {
                return false;
            }
        }

        int start_row = 3*(row / 3);
        int start_col = 3*(col / 3);
        for (int r=start_row;r<start_row+3;r++) {
            for (int c=start_col;c<start_col+3;c++) {
                if (r==row&&c==col) {
                    continue;
                }
                if (board[r][c]==num) {
                    return false;
                }
            }
        }

        return true;
    }

    void backtracking(vector<vector<char>>& board) {
        for (int row=0;row<9;row++) {
            for (int col=0;col<9;col++) {
                if (board[row][col]=='.') {
                    for (char num='1';num<='9';num++) {
                        if (is_valid(board,row,col,num)) {
                            board[row][col] = num;
                            backtracking(board);
                            if (result) {
                                return;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return;
                }
            }
        }
        result = true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
int main() {
    
}