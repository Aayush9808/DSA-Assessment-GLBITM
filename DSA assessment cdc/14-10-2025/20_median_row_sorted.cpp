#include <vector>
#include <algorithm>
using namespace std;

int findMedianRowSorted(vector<vector<int>>& matrix) {
    int low = 1, high = 1e9;
    int n = matrix.size(), m = matrix[0].size();
    int required = (n * m + 1) / 2;
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        
        if(count < required) low = mid + 1;
        else high = mid;
    }
    return low;
}
