#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int trapRainWater(vector<int>& height) {
    int n = height.size();
    if(n == 0) return 0;
    
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];
    
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i]);
    }
    
    for(int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i]);
    }
    
    int water = 0;
    for(int i = 0; i < n; i++) {
        water += min(leftMax[i], rightMax[i]) - height[i];
    }
    return water;
}

int maxSumNonAdjacent(vector<int>& nums) {
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    
    int prev2 = 0, prev1 = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int minCostPath(vector<vector<int>>& cost) {
    int m = cost.size(), n = cost[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = cost[0][0];
    
    for(int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
    
    for(int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = cost[i][j] + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[m-1][n-1];
}

int longestPalindromicSubsequence(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j]) {
                dp[i][j] = (len == 2) ? 2 : dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}
