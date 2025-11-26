#include <vector>
#include <string>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if(grid[0][0] == 1) return 0;
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                dp[i][j] = 0;
            } else if(i > 0 || j > 0) {
                dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
            }
        }
    }
    return dp[m-1][n-1];
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    
    for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int numDistinct(string s, string t) {
    int m = s.length(), n = t.length();
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    
    for(int i = 0; i <= m; i++) dp[i][0] = 1;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}
