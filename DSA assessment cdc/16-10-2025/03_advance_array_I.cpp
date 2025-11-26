#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for(int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

vector<int> sortArrayByParity(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        if(nums[left] % 2 > nums[right] % 2) {
            swap(nums[left], nums[right]);
        }
        if(nums[left] % 2 == 0) left++;
        if(nums[right] % 2 == 1) right--;
    }
    return nums;
}

bool searchInSortedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return true;
        
        if(nums[left] <= nums[mid]) {
            if(nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if(nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}
