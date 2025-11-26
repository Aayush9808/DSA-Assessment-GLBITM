#include <vector>
#include <unordered_map>
using namespace std;

int largestSubarrayWithZeroSum(vector<int>& arr) {
    unordered_map<int, int> sumIndex;
    int sum = 0, maxLen = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        
        if(sum == 0) maxLen = i + 1;
        
        if(sumIndex.find(sum) != sumIndex.end()) {
            maxLen = max(maxLen, i - sumIndex[sum]);
        } else {
            sumIndex[sum] = i;
        }
    }
    return maxLen;
}

int countZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, int> sumFreq;
    int sum = 0, count = 0;
    sumFreq[0] = 1;
    
    for(int num : arr) {
        sum += num;
        count += sumFreq[sum];
        sumFreq[sum]++;
    }
    return count;
}

int longestSubarrayWithContiguous(vector<int>& arr) {
    unordered_map<int, int> sumIndex;
    int sum = 0, maxLen = 0;
    sumIndex[0] = -1;
    
    for(int i = 0; i < arr.size(); i++) {
        sum += (arr[i] == 1 ? 1 : -1);
        
        if(sumIndex.find(sum) != sumIndex.end()) {
            maxLen = max(maxLen, i - sumIndex[sum]);
        } else {
            sumIndex[sum] = i;
        }
    }
    return maxLen;
}
