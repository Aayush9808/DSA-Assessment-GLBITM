#include <vector>
using namespace std;

class LazySegmentTree {
    vector<int> tree, lazy;
    int n;
    
public:
    LazySegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
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
    
    void updateRange(int L, int R, int val) {
        updateRangeHelper(0, 0, n - 1, L, R, val);
    }
    
    void updateRangeHelper(int node, int start, int end, int L, int R, int val) {
        if(lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if(start != end) {
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        
        if(start > R || end < L) return;
        
        if(start >= L && end <= R) {
            tree[node] += (end - start + 1) * val;
            if(start != end) {
                lazy[2*node + 1] += val;
                lazy[2*node + 2] += val;
            }
            return;
        }
        
        int mid = (start + end) / 2;
        updateRangeHelper(2*node + 1, start, mid, L, R, val);
        updateRangeHelper(2*node + 2, mid + 1, end, L, R, val);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
    
    int queryRange(int L, int R) {
        return queryHelper(0, 0, n - 1, L, R);
    }
    
    int queryHelper(int node, int start, int end, int L, int R) {
        if(start > R || end < L) return 0;
        
        if(lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if(start != end) {
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        
        if(start >= L && end <= R) return tree[node];
        
        int mid = (start + end) / 2;
        int leftSum = queryHelper(2*node + 1, start, mid, L, R);
        int rightSum = queryHelper(2*node + 2, mid + 1, end, L, R);
        return leftSum + rightSum;
    }
};

class FenwickTree {
    vector<int> BIT;
    int n;
    
public:
    FenwickTree(int size) {
        n = size;
        BIT.resize(n + 1, 0);
    }
    
    void update(int idx, int val) {
        idx++;
        while(idx <= n) {
            BIT[idx] += val;
            idx += idx & (-idx);
        }
    }
    
    int query(int idx) {
        idx++;
        int sum = 0;
        while(idx > 0) {
            sum += BIT[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    
    int rangeQuery(int L, int R) {
        return query(R) - (L > 0 ? query(L - 1) : 0);
    }
};
