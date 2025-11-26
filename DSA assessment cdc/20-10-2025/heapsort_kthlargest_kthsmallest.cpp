#include <queue>
#include <vector>
using namespace std;

vector<int> heapSort(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

int kthLargestElement(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int num : nums) {
        minHeap.push(num);
        if(minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int kthSmallestElement(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    for(int num : nums) {
        maxHeap.push(num);
        if(maxHeap.size() > k) maxHeap.pop();
    }
    return maxHeap.top();
}
