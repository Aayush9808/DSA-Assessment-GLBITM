#include <vector>
#include <limits.h>
using namespace std;

int rodCutting(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], prices[j-1] + dp[i-j]);
        }
    }
    return dp[n];
}

int unboundedKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
    vector<int> dp(capacity + 1, 0);
    
    for(int w = 1; w <= capacity; w++) {
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] <= w) {
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }
    }
    return dp[capacity];
}

int coinChangeWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    
    for(int coin : coins) {
        for(int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int minimumJumps(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    
    for(int i = 0; i < n; i++) {
        if(dp[i] == INT_MAX) continue;
        
        for(int j = 1; j <= nums[i] && i + j < n; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    return dp[n-1] == INT_MAX ? -1 : dp[n-1];
}
