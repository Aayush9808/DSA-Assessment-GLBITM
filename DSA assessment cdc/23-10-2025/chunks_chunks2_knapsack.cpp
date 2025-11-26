#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxChunksToMakeSorted(vector<int>& arr) {
    int chunks = 0, maxSoFar = 0;
    for(int i = 0; i < arr.size(); i++) {
        maxSoFar = max(maxSoFar, arr[i]);
        if(maxSoFar == i) chunks++;
    }
    return chunks;
}

int maxChunksToMakeSortedII(vector<int>& arr) {
    int n = arr.size();
    vector<int> maxLeft(n), minRight(n);
    
    maxLeft[0] = arr[0];
    for(int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i-1], arr[i]);
    }
    
    minRight[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        minRight[i] = min(minRight[i+1], arr[i]);
    }
    
    int chunks = 0;
    for(int i = 0; i < n-1; i++) {
        if(maxLeft[i] <= minRight[i+1]) chunks++;
    }
    return chunks + 1;
}

int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
    
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
