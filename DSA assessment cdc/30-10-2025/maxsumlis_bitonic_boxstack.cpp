#include <vector>
#include <algorithm>
using namespace std;

int maxSumIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(nums);
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }
    
    int maxSum = 0;
    for(int sum : dp) maxSum = max(maxSum, sum);
    return maxSum;
}

int longestBitonicSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis(n, 1), lds(n, 1);
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    
    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(nums[j] < nums[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        maxLen = max(maxLen, lis[i] + lds[i] - 1);
    }
    return maxLen;
}

int boxStacking(vector<vector<int>>& boxes) {
    vector<vector<int>> allRotations;
    
    for(auto& box : boxes) {
        allRotations.push_back({box[0], box[1], box[2]});
        allRotations.push_back({box[1], box[0], box[2]});
        allRotations.push_back({box[2], box[0], box[1]});
        allRotations.push_back({box[2], box[1], box[0]});
        allRotations.push_back({box[0], box[2], box[1]});
        allRotations.push_back({box[1], box[2], box[0]});
    }
    
    sort(allRotations.begin(), allRotations.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] * a[1] > b[0] * b[1];
    });
    
    int n = allRotations.size();
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++) {
        dp[i] = allRotations[i][2];
        
        for(int j = 0; j < i; j++) {
            if(allRotations[j][0] > allRotations[i][0] && 
               allRotations[j][1] > allRotations[i][1]) {
                dp[i] = max(dp[i], dp[j] + allRotations[i][2]);
            }
        }
    }
    
    int maxHeight = 0;
    for(int h : dp) maxHeight = max(maxHeight, h);
    return maxHeight;
}
