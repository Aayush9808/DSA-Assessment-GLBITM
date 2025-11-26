#include <vector>
#include <limits.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node + 1, start, mid);
            build(arr, 2*node + 2, mid + 1, end);
            tree[node] = tree[2*node + 1] + tree[2*node + 2];
        }
    }
    
    int query(int L, int R) {
        return queryHelper(0, 0, n - 1, L, R);
    }
    
    int queryHelper(int node, int start, int end, int L, int R) {
        if(R < start || L > end) return 0;
        
        if(L <= start && end <= R) return tree[node];
        
        int mid = (start + end) / 2;
        int leftSum = queryHelper(2*node + 1, start, mid, L, R);
        int rightSum = queryHelper(2*node + 2, mid + 1, end, L, R);
        return leftSum + rightSum;
    }
    
    void update(int idx, int val) {
        updateHelper(0, 0, n - 1, idx, val);
    }
    
    void updateHelper(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if(idx <= mid) {
                updateHelper(2*node + 1, start, mid, idx, val);
            } else {
                updateHelper(2*node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2*node + 1] + tree[2*node + 2];
        }
    }
};

int rangeMinQuery(vector<int>& arr, int L, int R) {
    int minVal = INT_MAX;
    for(int i = L; i <= R; i++) {
        minVal = min(minVal, arr[i]);
    }
    return minVal;
}

int rangeMaxQuery(vector<int>& arr, int L, int R) {
    int maxVal = INT_MIN;
    for(int i = L; i <= R; i++) {
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}
