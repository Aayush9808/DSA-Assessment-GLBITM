#include <vector>
#include <limits.h>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    int maxProd = nums[0], minProd = nums[0], result = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        int temp = maxProd;
        maxProd = max({nums[i], maxProd * nums[i], minProd * nums[i]});
        minProd = min({nums[i], temp * nums[i], minProd * nums[i]});
        result = max(result, maxProd);
    }
    return result;
}

int maxSumSubarray(vector<int>& nums) {
    int maxSum = nums[0], currSum = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int maxSumCircularSubarray(vector<int>& nums) {
    int totalSum = 0, maxSum = INT_MIN, minSum = INT_MAX;
    int currMax = 0, currMin = 0;
    
    for(int num : nums) {
        totalSum += num;
        currMax = max(currMax + num, num);
        maxSum = max(maxSum, currMax);
        currMin = min(currMin + num, num);
        minSum = min(minSum, currMin);
    }
    
    if(maxSum < 0) return maxSum;
    return max(maxSum, totalSum - minSum);
}

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxSide = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == '1') {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}
