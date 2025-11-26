#include <queue>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

int findMaxHeap(priority_queue<int>& maxHeap) {
    return maxHeap.top();
}

vector<int> topKFrequentElements(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
    for(auto& p : freq) {
        minHeap.push({p.second, p.first});
        if(minHeap.size() > k) minHeap.pop();
    }
    
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int slidingWindowMaximum(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> maxHeap;
    int maxVal = INT_MIN;
    
    for(int i = 0; i < nums.size(); i++) {
        maxHeap.push({nums[i], i});
        
        while(!maxHeap.empty() && maxHeap.top().second <= i - k) {
            maxHeap.pop();
        }
        
        if(i >= k - 1) {
            maxVal = max(maxVal, maxHeap.top().first);
        }
    }
    return maxVal;
}
