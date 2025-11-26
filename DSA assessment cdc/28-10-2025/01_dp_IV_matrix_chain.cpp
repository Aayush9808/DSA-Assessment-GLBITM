#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int len = 2; len < n; len++) {
        for(int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}

bool isPalindrome(string s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            if(isPalindrome(s, i, j)) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][n-1];
}

int eggDrop(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1));
    
    for(int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    for(int j = 1; j <= floors; j++) {
        dp[1][j] = j;
    }
    
    for(int i = 2; i <= eggs; i++) {
        for(int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;
            for(int k = 1; k <= j; k++) {
                int breaks = dp[i-1][k-1];
                int doesntBreak = dp[i][j-k];
                int worstCase = 1 + max(breaks, doesntBreak);
                dp[i][j] = min(dp[i][j], worstCase);
            }
        }
    }
    return dp[eggs][floors];
}
