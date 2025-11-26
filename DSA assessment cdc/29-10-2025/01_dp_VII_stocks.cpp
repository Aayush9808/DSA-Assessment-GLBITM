#include <vector>
#include <limits.h>
using namespace std;

int maxProfitOneTransaction(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    
    for(int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int maxProfitUnlimitedTransactions(vector<int>& prices) {
    int maxProfit = 0;
    
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]) {
            maxProfit += prices[i] - prices[i-1];
        }
    }
    return maxProfit;
}

int maxProfitTwoTransactions(vector<int>& prices) {
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;
    
    for(int price : prices) {
        buy1 = min(buy1, price);
        profit1 = max(profit1, price - buy1);
        buy2 = min(buy2, price - profit1);
        profit2 = max(profit2, price - buy2);
    }
    return profit2;
}

int maxProfitKTransactions(int k, vector<int>& prices) {
    int n = prices.size();
    if(n == 0 || k == 0) return 0;
    
    if(k >= n / 2) {
        int maxProfit = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
    
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    
    for(int i = 1; i <= k; i++) {
        int maxDiff = -prices[0];
        for(int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
        }
    }
    return dp[k][n-1];
}
