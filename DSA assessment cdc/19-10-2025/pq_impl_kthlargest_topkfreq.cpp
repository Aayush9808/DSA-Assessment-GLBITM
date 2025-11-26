#include <queue>
#include <vector>
using namespace std;

class PriorityQueueImpl {
    priority_queue<int> pq;
public:
    void push(int x) {
        pq.push(x);
    }
    
    int pop() {
        int top = pq.top();
        pq.pop();
        return top;
    }
    
    int top() {
        return pq.top();
    }
    
    bool empty() {
        return pq.empty();
    }
};

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int num : nums) {
        minHeap.push(num);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    
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
