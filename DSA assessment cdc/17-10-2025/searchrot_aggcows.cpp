#include <vector>
using namespace std;

int searchRotatedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        
        if(nums[left] <= nums[mid]) {
            if(nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if(nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int searchRotatedArrayII(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        
        if(nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        } else if(nums[left] <= nums[mid]) {
            if(nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if(nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

vector<int> aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int left = 1, right = stalls.back() - stalls[0];
    int result = 0;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int count = 1, lastPos = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastPos >= mid) {
                count++;
                lastPos = stalls[i];
            }
        }
        
        if(count >= k) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return {result};
}
