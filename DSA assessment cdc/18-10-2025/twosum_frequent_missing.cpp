#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        if(map.count(target - nums[i])) {
            return {map[target - nums[i]], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int mostFrequent(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0, result = 0;
    for(int num : nums) {
        freq[num]++;
        if(freq[num] > maxFreq) {
            maxFreq = freq[num];
            result = num;
        }
    }
    return result;
}

vector<int> findMissing(vector<int>& nums) {
    unordered_map<int, bool> present;
    for(int num : nums) present[num] = true;
    
    vector<int> missing;
    int maxNum = *max_element(nums.begin(), nums.end());
    for(int i = 1; i <= maxNum; i++) {
        if(!present[i]) missing.push_back(i);
    }
    return missing;
}
