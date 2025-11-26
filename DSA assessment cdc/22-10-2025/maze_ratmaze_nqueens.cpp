#include <vector>
using namespace std;

bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    int n = maze.size();
    if(x == n-1 && y == n-1) {
        sol[x][y] = 1;
        return true;
    }
    
    if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1) {
        sol[x][y] = 1;
        
        if(solveMaze(maze, x+1, y, sol)) return true;
        if(solveMaze(maze, x, y+1, sol)) return true;
        
        sol[x][y] = 0;
        return false;
    }
    return false;
}

bool ratInMazeAllPaths(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol, vector<string>& paths, string path) {
    int n = maze.size();
    if(x == n-1 && y == n-1) {
        paths.push_back(path);
        return true;
    }
    
    if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && sol[x][y] == 0) {
        sol[x][y] = 1;
        
        ratInMazeAllPaths(maze, x+1, y, sol, paths, path + "D");
        ratInMazeAllPaths(maze, x, y+1, sol, paths, path + "R");
        ratInMazeAllPaths(maze, x-1, y, sol, paths, path + "U");
        ratInMazeAllPaths(maze, x, y-1, sol, paths, path + "L");
        
        sol[x][y] = 0;
    }
    return false;
}

void solveNQueens(int n, int col, vector<int>& board, vector<vector<int>>& solutions) {
    if(col >= n) {
        solutions.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++) {
        if(isSafe(board, row, col, n)) {
            board[col] = row;
            solveNQueens(n, col + 1, board, solutions);
        }
    }
}

bool isSafe(vector<int>& board, int row, int col, int n) {
    for(int i = 0; i < col; i++) {
        if(board[i] == row || abs(board[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}
