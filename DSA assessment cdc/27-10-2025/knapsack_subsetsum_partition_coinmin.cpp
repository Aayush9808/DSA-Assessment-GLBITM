#include <vector>
using namespace std;

int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= capacity; w++) {
            if(weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][capacity];
}

bool subsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            if(nums[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int num : nums) sum += num;
    
    if(sum % 2 != 0) return false;
    return subsetSum(nums, sum / 2);
}

int coinChangeMinCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
