#include <vector>
#include <string>
using namespace std;

void generateParentheses(int n, int open, int close, string current, vector<string>& result) {
    if(current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    if(open < n) {
        generateParentheses(n, open + 1, close, current + "(", result);
    }
    if(close < open) {
        generateParentheses(n, open, close + 1, current + ")", result);
    }
}

bool solveSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == '.') {
                for(char c = '1'; c <= '9'; c++) {
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if(solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}
