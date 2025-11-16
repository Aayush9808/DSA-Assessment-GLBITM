#include <vector>
#include <algorithm>
using namespace std;

int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 1;
    
    int minIdx = 0, maxIdx = 0;
    
    for(int i = 0; i < n; i++) {
        if(nums[i] < nums[minIdx]) minIdx = i;
        if(nums[i] > nums[maxIdx]) maxIdx = i;
    }
    
    int left = max(minIdx, maxIdx) + 1;
    int right = n - min(minIdx, maxIdx);
    int both = min(minIdx, maxIdx) + 1 + (n - max(minIdx, maxIdx));
    
    return min({left, right, both});
}
